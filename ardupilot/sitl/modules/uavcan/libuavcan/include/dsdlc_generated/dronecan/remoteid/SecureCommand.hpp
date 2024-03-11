/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/user/cyberimmune-systems-autonomous-delivery-drone-with-kos-contest/modules/DroneCAN/DSDL/dronecan/remoteid/64.SecureCommand.uavcan
 */

#ifndef DRONECAN_REMOTEID_SECURECOMMAND_HPP_INCLUDED
#define DRONECAN_REMOTEID_SECURECOMMAND_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
# DroneCAN version of MAVLink2 SECURE_COMMAND. Please see MAVLink2 spec for more details

uint32 sequence

uint32 SECURE_COMMAND_GET_SESSION_KEY = 0
uint32 SECURE_COMMAND_GET_REMOTEID_SESSION_KEY = 1
uint32 SECURE_COMMAND_REMOVE_PUBLIC_KEYS = 2
uint32 SECURE_COMMAND_GET_PUBLIC_KEYS = 3
uint32 SECURE_COMMAND_SET_PUBLIC_KEYS = 4
uint32 SECURE_COMMAND_GET_REMOTEID_CONFIG = 5
uint32 SECURE_COMMAND_SET_REMOTEID_CONFIG = 6
uint32 operation

uint8 sig_length
uint8[<=220] data

---

uint32 sequence
uint32 operation

uint8 RESULT_ACCEPTED = 0
uint8 RESULT_TEMPORARILY_REJECTED = 1
uint8 RESULT_DENIED = 2
uint8 RESULT_UNSUPPORTED = 3
uint8 RESULT_FAILED = 4
uint8 result

uint8[<=220] data
******************************************************************************/

/********************* DSDL signature source definition ***********************
dronecan.remoteid.SecureCommand
saturated uint32 sequence
saturated uint32 operation
saturated uint8 sig_length
saturated uint8[<=220] data
---
saturated uint32 sequence
saturated uint32 operation
saturated uint8 result
saturated uint8[<=220] data
******************************************************************************/

#undef sequence
#undef operation
#undef sig_length
#undef data
#undef SECURE_COMMAND_GET_SESSION_KEY
#undef SECURE_COMMAND_GET_REMOTEID_SESSION_KEY
#undef SECURE_COMMAND_REMOVE_PUBLIC_KEYS
#undef SECURE_COMMAND_GET_PUBLIC_KEYS
#undef SECURE_COMMAND_SET_PUBLIC_KEYS
#undef SECURE_COMMAND_GET_REMOTEID_CONFIG
#undef SECURE_COMMAND_SET_REMOTEID_CONFIG
#undef sequence
#undef operation
#undef result
#undef data
#undef RESULT_ACCEPTED
#undef RESULT_TEMPORARILY_REJECTED
#undef RESULT_DENIED
#undef RESULT_UNSUPPORTED
#undef RESULT_FAILED

namespace dronecan
{
namespace remoteid
{

struct UAVCAN_EXPORT SecureCommand_
{
    template <int _tmpl>
    struct Request_
    {
        typedef const Request_<_tmpl>& ParameterType;
        typedef Request_<_tmpl>& ReferenceType;

        struct ConstantTypes
        {
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_GET_SESSION_KEY;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_GET_REMOTEID_SESSION_KEY;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_REMOVE_PUBLIC_KEYS;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_GET_PUBLIC_KEYS;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_SET_PUBLIC_KEYS;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_GET_REMOTEID_CONFIG;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SECURE_COMMAND_SET_REMOTEID_CONFIG;
        };

        struct FieldTypes
        {
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > sequence;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > operation;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > sig_length;
            typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 220 > data;
        };

        enum
        {
            MinBitLen
                = FieldTypes::sequence::MinBitLen
                + FieldTypes::operation::MinBitLen
                + FieldTypes::sig_length::MinBitLen
                + FieldTypes::data::MinBitLen
        };

        enum
        {
            MaxBitLen
                = FieldTypes::sequence::MaxBitLen
                + FieldTypes::operation::MaxBitLen
                + FieldTypes::sig_length::MaxBitLen
                + FieldTypes::data::MaxBitLen
        };

        // Constants
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_GET_SESSION_KEY >::Type SECURE_COMMAND_GET_SESSION_KEY; // 0
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_GET_REMOTEID_SESSION_KEY >::Type SECURE_COMMAND_GET_REMOTEID_SESSION_KEY; // 1
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_REMOVE_PUBLIC_KEYS >::Type SECURE_COMMAND_REMOVE_PUBLIC_KEYS; // 2
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_GET_PUBLIC_KEYS >::Type SECURE_COMMAND_GET_PUBLIC_KEYS; // 3
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_SET_PUBLIC_KEYS >::Type SECURE_COMMAND_SET_PUBLIC_KEYS; // 4
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_GET_REMOTEID_CONFIG >::Type SECURE_COMMAND_GET_REMOTEID_CONFIG; // 5
        static const typename ::uavcan::StorageType< typename ConstantTypes::SECURE_COMMAND_SET_REMOTEID_CONFIG >::Type SECURE_COMMAND_SET_REMOTEID_CONFIG; // 6

        // Fields
        typename ::uavcan::StorageType< typename FieldTypes::sequence >::Type sequence;
        typename ::uavcan::StorageType< typename FieldTypes::operation >::Type operation;
        typename ::uavcan::StorageType< typename FieldTypes::sig_length >::Type sig_length;
        typename ::uavcan::StorageType< typename FieldTypes::data >::Type data;

        Request_()
            : sequence()
            , operation()
            , sig_length()
            , data()
        {
            ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

    #if UAVCAN_DEBUG
            /*
             * Cross-checking MaxBitLen provided by the DSDL compiler.
             * This check shall never be performed in user code because MaxBitLen value
             * actually depends on the nested types, thus it is not invariant.
             */
            ::uavcan::StaticAssert<1840 == MaxBitLen>::check();
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

    };

    template <int _tmpl>
    struct Response_
    {
        typedef const Response_<_tmpl>& ParameterType;
        typedef Response_<_tmpl>& ReferenceType;

        struct ConstantTypes
        {
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > RESULT_ACCEPTED;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > RESULT_TEMPORARILY_REJECTED;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > RESULT_DENIED;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > RESULT_UNSUPPORTED;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > RESULT_FAILED;
        };

        struct FieldTypes
        {
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > sequence;
            typedef ::uavcan::IntegerSpec< 32, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > operation;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > result;
            typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 220 > data;
        };

        enum
        {
            MinBitLen
                = FieldTypes::sequence::MinBitLen
                + FieldTypes::operation::MinBitLen
                + FieldTypes::result::MinBitLen
                + FieldTypes::data::MinBitLen
        };

        enum
        {
            MaxBitLen
                = FieldTypes::sequence::MaxBitLen
                + FieldTypes::operation::MaxBitLen
                + FieldTypes::result::MaxBitLen
                + FieldTypes::data::MaxBitLen
        };

        // Constants
        static const typename ::uavcan::StorageType< typename ConstantTypes::RESULT_ACCEPTED >::Type RESULT_ACCEPTED; // 0
        static const typename ::uavcan::StorageType< typename ConstantTypes::RESULT_TEMPORARILY_REJECTED >::Type RESULT_TEMPORARILY_REJECTED; // 1
        static const typename ::uavcan::StorageType< typename ConstantTypes::RESULT_DENIED >::Type RESULT_DENIED; // 2
        static const typename ::uavcan::StorageType< typename ConstantTypes::RESULT_UNSUPPORTED >::Type RESULT_UNSUPPORTED; // 3
        static const typename ::uavcan::StorageType< typename ConstantTypes::RESULT_FAILED >::Type RESULT_FAILED; // 4

        // Fields
        typename ::uavcan::StorageType< typename FieldTypes::sequence >::Type sequence;
        typename ::uavcan::StorageType< typename FieldTypes::operation >::Type operation;
        typename ::uavcan::StorageType< typename FieldTypes::result >::Type result;
        typename ::uavcan::StorageType< typename FieldTypes::data >::Type data;

        Response_()
            : sequence()
            , operation()
            , result()
            , data()
        {
            ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

    #if UAVCAN_DEBUG
            /*
             * Cross-checking MaxBitLen provided by the DSDL compiler.
             * This check shall never be performed in user code because MaxBitLen value
             * actually depends on the nested types, thus it is not invariant.
             */
            ::uavcan::StaticAssert<1840 == MaxBitLen>::check();
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

    };

    typedef Request_<0> Request;
    typedef Response_<0> Response;

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindService };
    enum { DefaultDataTypeID = 64 };

    static const char* getDataTypeFullName()
    {
        return "dronecan.remoteid.SecureCommand";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

private:
    SecureCommand_(); // Don't create objects of this type. Use Request/Response instead.
};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool SecureCommand_::Request_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        sequence == rhs.sequence &&
        operation == rhs.operation &&
        sig_length == rhs.sig_length &&
        data == rhs.data;
}

template <int _tmpl>
bool SecureCommand_::Request_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(sequence, rhs.sequence) &&
        ::uavcan::areClose(operation, rhs.operation) &&
        ::uavcan::areClose(sig_length, rhs.sig_length) &&
        ::uavcan::areClose(data, rhs.data);
}

template <int _tmpl>
int SecureCommand_::Request_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::sequence::encode(self.sequence, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operation::encode(self.operation, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sig_length::encode(self.sig_length, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::data::encode(self.data, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int SecureCommand_::Request_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::sequence::decode(self.sequence, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operation::decode(self.operation, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sig_length::decode(self.sig_length, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::data::decode(self.data, codec,  tao_mode);
    return res;
}

template <int _tmpl>
bool SecureCommand_::Response_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        sequence == rhs.sequence &&
        operation == rhs.operation &&
        result == rhs.result &&
        data == rhs.data;
}

template <int _tmpl>
bool SecureCommand_::Response_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(sequence, rhs.sequence) &&
        ::uavcan::areClose(operation, rhs.operation) &&
        ::uavcan::areClose(result, rhs.result) &&
        ::uavcan::areClose(data, rhs.data);
}

template <int _tmpl>
int SecureCommand_::Response_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::sequence::encode(self.sequence, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operation::encode(self.operation, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::result::encode(self.result, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::data::encode(self.data, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int SecureCommand_::Response_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::sequence::decode(self.sequence, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::operation::decode(self.operation, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::result::decode(self.result, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::data::decode(self.data, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
inline ::uavcan::DataTypeSignature SecureCommand_::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x126A47C9C17A8BD7ULL);

    Request::FieldTypes::sequence::extendDataTypeSignature(signature);
    Request::FieldTypes::operation::extendDataTypeSignature(signature);
    Request::FieldTypes::sig_length::extendDataTypeSignature(signature);
    Request::FieldTypes::data::extendDataTypeSignature(signature);

    Response::FieldTypes::sequence::extendDataTypeSignature(signature);
    Response::FieldTypes::operation::extendDataTypeSignature(signature);
    Response::FieldTypes::result::extendDataTypeSignature(signature);
    Response::FieldTypes::data::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_GET_SESSION_KEY >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_GET_SESSION_KEY = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_GET_REMOTEID_SESSION_KEY >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_GET_REMOTEID_SESSION_KEY = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_REMOVE_PUBLIC_KEYS >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_REMOVE_PUBLIC_KEYS = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_GET_PUBLIC_KEYS >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_GET_PUBLIC_KEYS = 3U; // 3

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_SET_PUBLIC_KEYS >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_SET_PUBLIC_KEYS = 4U; // 4

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_GET_REMOTEID_CONFIG >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_GET_REMOTEID_CONFIG = 5U; // 5

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Request_<_tmpl>::ConstantTypes::SECURE_COMMAND_SET_REMOTEID_CONFIG >::Type
    SecureCommand_::Request_<_tmpl>::SECURE_COMMAND_SET_REMOTEID_CONFIG = 6U; // 6

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Response_<_tmpl>::ConstantTypes::RESULT_ACCEPTED >::Type
    SecureCommand_::Response_<_tmpl>::RESULT_ACCEPTED = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Response_<_tmpl>::ConstantTypes::RESULT_TEMPORARILY_REJECTED >::Type
    SecureCommand_::Response_<_tmpl>::RESULT_TEMPORARILY_REJECTED = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Response_<_tmpl>::ConstantTypes::RESULT_DENIED >::Type
    SecureCommand_::Response_<_tmpl>::RESULT_DENIED = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Response_<_tmpl>::ConstantTypes::RESULT_UNSUPPORTED >::Type
    SecureCommand_::Response_<_tmpl>::RESULT_UNSUPPORTED = 3U; // 3

template <int _tmpl>
const typename ::uavcan::StorageType< typename SecureCommand_::Response_<_tmpl>::ConstantTypes::RESULT_FAILED >::Type
    SecureCommand_::Response_<_tmpl>::RESULT_FAILED = 4U; // 4

/*
 * Final typedef
 */
typedef SecureCommand_ SecureCommand;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::dronecan::remoteid::SecureCommand > _uavcan_gdtr_registrator_SecureCommand;

}

} // Namespace remoteid
} // Namespace dronecan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::dronecan::remoteid::SecureCommand::Request >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::dronecan::remoteid::SecureCommand::Request::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::dronecan::remoteid::SecureCommand::Request >::stream(Stream& s, ::dronecan::remoteid::SecureCommand::Request::ParameterType obj, const int level)
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
    s << "sequence: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Request::FieldTypes::sequence >::stream(s, obj.sequence, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "operation: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Request::FieldTypes::operation >::stream(s, obj.operation, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "sig_length: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Request::FieldTypes::sig_length >::stream(s, obj.sig_length, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "data: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Request::FieldTypes::data >::stream(s, obj.data, level + 1);
}

template <>
class UAVCAN_EXPORT YamlStreamer< ::dronecan::remoteid::SecureCommand::Response >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::dronecan::remoteid::SecureCommand::Response::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::dronecan::remoteid::SecureCommand::Response >::stream(Stream& s, ::dronecan::remoteid::SecureCommand::Response::ParameterType obj, const int level)
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
    s << "sequence: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Response::FieldTypes::sequence >::stream(s, obj.sequence, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "operation: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Response::FieldTypes::operation >::stream(s, obj.operation, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "result: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Response::FieldTypes::result >::stream(s, obj.result, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "data: ";
    YamlStreamer< ::dronecan::remoteid::SecureCommand::Response::FieldTypes::data >::stream(s, obj.data, level + 1);
}

}

namespace dronecan
{
namespace remoteid
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::dronecan::remoteid::SecureCommand::Request::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::dronecan::remoteid::SecureCommand::Request >::stream(s, obj, 0);
    return s;
}

template <typename Stream>
inline Stream& operator<<(Stream& s, ::dronecan::remoteid::SecureCommand::Response::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::dronecan::remoteid::SecureCommand::Response >::stream(s, obj, 0);
    return s;
}

} // Namespace remoteid
} // Namespace dronecan

#endif // DRONECAN_REMOTEID_SECURECOMMAND_HPP_INCLUDED