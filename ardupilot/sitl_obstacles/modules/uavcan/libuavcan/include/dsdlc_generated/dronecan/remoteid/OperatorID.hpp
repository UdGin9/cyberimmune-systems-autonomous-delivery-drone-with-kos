/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/user/cyberimmune-systems-autonomous-delivery-drone-with-kos-contest/modules/DroneCAN/DSDL/dronecan/remoteid/20034.OperatorID.uavcan
 */

#ifndef DRONECAN_REMOTEID_OPERATORID_HPP_INCLUDED
#define DRONECAN_REMOTEID_OPERATORID_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# DroneCAN version of MAVLink OPEN_DRONE_ID_OPERATOR_ID
# see MAVLink XML for detailed description
#
uint8[<=20] id_or_mac

uint8 ODID_OPERATOR_ID_TYPE_CAA = 0 # CAA (Civil Aviation Authority) registered operator ID
uint8 operator_id_type

uint8[<=20] operator_id
******************************************************************************/

/********************* DSDL signature source definition ***********************
dronecan.remoteid.OperatorID
saturated uint8[<=20] id_or_mac
saturated uint8 operator_id_type
saturated uint8[<=20] operator_id
******************************************************************************/

#undef id_or_mac
#undef operator_id_type
#undef operator_id
#undef ODID_OPERATOR_ID_TYPE_CAA

namespace dronecan
{
namespace remoteid
{

template <int _tmpl>
struct UAVCAN_EXPORT OperatorID_
{
    typedef const OperatorID_<_tmpl>& ParameterType;
    typedef OperatorID_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ODID_OPERATOR_ID_TYPE_CAA;
    };

    struct FieldTypes
    {
        typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 20 > id_or_mac;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > operator_id_type;
        typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 20 > operator_id;
    };

    enum
    {
        MinBitLen
            = FieldTypes::id_or_mac::MinBitLen
            + FieldTypes::operator_id_type::MinBitLen
            + FieldTypes::operator_id::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::id_or_mac::MaxBitLen
            + FieldTypes::operator_id_type::MaxBitLen
            + FieldTypes::operator_id::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::ODID_OPERATOR_ID_TYPE_CAA >::Type ODID_OPERATOR_ID_TYPE_CAA; // 0

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::id_or_mac >::Type id_or_mac;
    typename ::uavcan::StorageType< typename FieldTypes::operator_id_type >::Type operator_id_type;
    typename ::uavcan::StorageType< typename FieldTypes::operator_id >::Type operator_id;

    OperatorID_()
        : id_or_mac()
        , operator_id_type()
        , operator_id()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<338 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 20034 };

    static const char* getDataTypeFullName()
    {
        return "dronecan.remoteid.OperatorID";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool OperatorID_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        id_or_mac == rhs.id_or_mac &&
        operator_id_type == rhs.operator_id_type &&
        operator_id == rhs.operator_id;
}

template <int _tmpl>
bool OperatorID_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(id_or_mac, rhs.id_or_mac) &&
        ::uavcan::areClose(operator_id_type, rhs.operator_id_type) &&
        ::uavcan::areClose(operator_id, rhs.operator_id);
}

template <int _tmpl>
int OperatorID_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::id_or_mac::encode(self.id_or_mac, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operator_id_type::encode(self.operator_id_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operator_id::encode(self.operator_id, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int OperatorID_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::id_or_mac::decode(self.id_or_mac, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operator_id_type::decode(self.operator_id_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operator_id::decode(self.operator_id, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature OperatorID_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x581E7FC7F03AF935ULL);

    FieldTypes::id_or_mac::extendDataTypeSignature(signature);
    FieldTypes::operator_id_type::extendDataTypeSignature(signature);
    FieldTypes::operator_id::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename OperatorID_<_tmpl>::ConstantTypes::ODID_OPERATOR_ID_TYPE_CAA >::Type
    OperatorID_<_tmpl>::ODID_OPERATOR_ID_TYPE_CAA = 0U; // 0

/*
 * Final typedef
 */
typedef OperatorID_<0> OperatorID;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::dronecan::remoteid::OperatorID > _uavcan_gdtr_registrator_OperatorID;

}

} // Namespace remoteid
} // Namespace dronecan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::dronecan::remoteid::OperatorID >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::dronecan::remoteid::OperatorID::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::dronecan::remoteid::OperatorID >::stream(Stream& s, ::dronecan::remoteid::OperatorID::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "id_or_mac: ";
    YamlStreamer< ::dronecan::remoteid::OperatorID::FieldTypes::id_or_mac >::stream(s, obj.id_or_mac, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "operator_id_type: ";
    YamlStreamer< ::dronecan::remoteid::OperatorID::FieldTypes::operator_id_type >::stream(s, obj.operator_id_type, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "operator_id: ";
    YamlStreamer< ::dronecan::remoteid::OperatorID::FieldTypes::operator_id >::stream(s, obj.operator_id, level + 1);
}

}

namespace dronecan
{
namespace remoteid
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::dronecan::remoteid::OperatorID::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::dronecan::remoteid::OperatorID >::stream(s, obj, 0);
    return s;
}

} // Namespace remoteid
} // Namespace dronecan

#endif // DRONECAN_REMOTEID_OPERATORID_HPP_INCLUDED