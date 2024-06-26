import math
import os, sys
import time
from hashlib import sha256
from Cryptodome import Random
from Cryptodome.PublicKey import RSA
from models import *
from utils.db_utils import *


ORVD_KEY_SIZE = 1024

ARMED = 0
DISARMED = 1

KILL_SWITCH_OFF = 1
KILL_SWITCH_ON = 0

MISSION_ACCEPTED = 0
MISSION_NOT_ACCEPTED = 1

NOT_FOUND = '$-1'
OK = '$OK'

loaded_keys = {}


def get_sha256_hex(message: str) -> str:
    return hex(int.from_bytes(sha256(message.encode()).digest(), byteorder='big', signed=False))[2:]

def parse_mission(mission: str) -> list:
    cmds = mission.split('&')
    for idx, cmd in enumerate(cmds):
        cmds[idx] = [cmd[0], *cmd[1:].split('_')]
    return cmds

def read_mission(file_str: str) -> list:
    
    missionlist=[]
    split_str = '\r\n' if '\r' in file_str else '\n'
    for i, line in enumerate(file_str.split(split_str)):
        if line == '':
            break
        if i==0:
            if not line.startswith('QGC WPL 110'):
                raise Exception('File is not supported WP version')
        else:
            linearray=line.split('\t')
            ln_index=int(linearray[0])
            ln_currentwp=int(linearray[1])
            ln_frame=int(linearray[2])
            ln_command=int(linearray[3])
            ln_param1=float(linearray[4])
            ln_param2=float(linearray[5])
            #ln_param3=float(linearray[6])
            #ln_param4=float(linearray[7])
            ln_param5=float(linearray[8])
            ln_param6=float(linearray[9])
            ln_param7=float(linearray[10])
            #ln_autocontinue=int(linearray[11].strip())
            
            if ln_index == 0 and ln_currentwp == 1 and ln_frame == 0:
                cmd = home_handler(lat=ln_param5, lon=ln_param6, alt=ln_param7)
            elif ln_command == 22:
                cmd = takeoff_handler(alt=ln_param7)
            elif ln_command == 16:
                cmd = waypoint_handler(hold=ln_param1, lat=ln_param5, lon=ln_param6, alt=ln_param7)
            elif ln_command == 183:
                cmd = servo_handler(number=ln_param1, pwm=ln_param2)
            elif ln_command == 21:
                if len(missionlist) != 0 and missionlist[0][0] == 'H':
                    drone_home = missionlist[0]
                else:
                    drone_home = None
                cmd = land_handler(lat=ln_param5, lon=ln_param6, alt=ln_param7, home=drone_home)
            else:
                print('Ошибка: использована неизвестная команда. Список разрешенных команд: 16, 21, 22, 183.')
                missionlist = []
                break
            
            missionlist.append(cmd)
    return missionlist

def home_handler(lat: float, lon: float, alt: float) -> list:
    return ['H', str(lat), str(lon), str(alt)]

def takeoff_handler(alt: float) -> list:
    return ['T', str(alt)]

def waypoint_handler(hold: float, lat: float, lon: float, alt: float) -> list:
    return ['W', str(hold), str(lat), str(lon), str(alt)]

def servo_handler(number: float, pwm: float) -> list:
    return ['S', str(number), str(pwm)]

def land_handler(lat: float, lon: float, alt: float, home: list = None) -> list:
    if home == None:
        ret_lat = str(lat)
        ret_lon = str(lon)
        ret_alt = str(alt)
    else:
        ret_lat = home[1] if lat == 0. else str(lat)
        ret_lon = home[2] if lon == 0. else str(lon)
        ret_alt = home[3] if alt == 0. else str(alt)
    
    return ['L', ret_lat, ret_lon, ret_alt]


def encode_mission(mission_list: list) -> list:
    for idx, cmd in enumerate(mission_list):
        mission_list[idx] = f'{cmd[0]}' + '_'.join(cmd[1:])
    #mission = '&'.join(mission_list)
    
    return mission_list


def sign(message: str, key_group: str) -> int:
    key = get_key(key_group, private=True)
    n, d = key.n, key.d
    msg_bytes = message.encode()
    hash = int.from_bytes(sha256(msg_bytes).digest(), byteorder='big', signed=False)
    signature = pow(hash, d, n)
    
    return signature


def verify(message: str, signature: int, key_group: str) -> bool:
    n, e = get_key(key_group, private=False)
    msg_bytes = message.encode()
    hash = int.from_bytes(sha256(msg_bytes).digest(), byteorder='big', signed=False)
    hashFromSignature = pow(signature, e, n)
    return hash == hashFromSignature

# для теста
def mock_verifier(*args, **kwargs):
    return True
        
def get_key(key_group: str, private: bool):
    if private == True:
        if key_group in loaded_keys:
            return loaded_keys[key_group]
        else:
            return None
    
    else:
        if 'kos' in key_group:
            id = int(key_group.split('kos')[1])
            key = get_entity_by_key(UavPublicKeys, id)
            if key == None:
                return -1
            n, e = int(key.n), int(key.e)
            
        elif 'ms' in key_group:
            id = int(key_group.split('ms')[1])
            key = get_entity_by_key(MissionSenderPublicKeys, id)
            if key == None:
                return -1
            n, e = int(key.n), int(key.e)
        
        elif key_group == 'orvd':
            key = loaded_keys[key_group].publickey()
            n, e = key.n, key.e
            
        else:
            print('Wrong group')
            return -1
        
        return n, e


def generate_keys(keysize: int, key_group: str) -> list:
    random_generator = Random.new().read
    key = RSA.generate(keysize, random_generator)
    loaded_keys[key_group] = key


def save_public_key(n: str, e: str, key_group: str) -> None:
    if 'kos' in key_group:
        id = int(key_group.split('kos')[1])
        entity = UavPublicKeys(uav_id=id, n=n, e=e)
    elif 'ms' in key_group:
        id = int(key_group.split('ms')[1])
        entity = MissionSenderPublicKeys(uav_id=id, n=n, e=e)
    else:
        print('Wrong group in utils.save_public_key')
    add_and_commit(entity)
    

def haversine(lat1, lon1, lat2, lon2):
    R = 6366037  # radius of Earth in meters
    phi_1 = math.radians(lat1)
    phi_2 = math.radians(lat2)

    delta_phi = math.radians(lat2 - lat1)
    delta_lambda = math.radians(lon2 - lon1)

    a = math.sin(delta_phi / 2.0) ** 2 + math.cos(phi_1) * math.cos(phi_2) * math.sin(delta_lambda / 2.0) ** 2
    
    c = 2 * math.atan2(math.sqrt(a), math.sqrt(1 - a))

    meters = R * c
    meters = round(meters, 3)
    return meters

def cast_wrapper(element, cast_function):
    if element is None: 
        return None
    try:
        return cast_function(element)
    except ValueError:
        return None