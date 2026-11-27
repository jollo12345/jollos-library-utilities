#include "jlu/add_check_overflow.h"

#define JLU_WITHOUT_PREFIX
#include "jlu/int_types.h"

bool JLU_addCheckOverflowI8(
    const I8 value_1,
    const I8 value_2,
    I8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = (I8)((U8)value_1 + (U8)value_2);
    }
    return (
        (value_2 >= 0 && value_1 <= I8_MAX - value_2) ||
        (value_2 < 0 && value_1 >= I8_MIN - value_2)
    );
}

bool JLU_addCheckOverflowI16(
    const I16 value_1,
    const I16 value_2,
    I16* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = (I16)((U16)value_1 + (U16)value_2);
    }
    return (
        (value_2 >= 0 && value_1 <= I16_MAX - value_2) ||
        (value_2 < 0 && value_1 >= I16_MIN - value_2)
    );
}

bool JLU_addCheckOverflowI32(
    const I32 value_1,
    const I32 value_2,
    I32* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = (I32)((U32)value_1 + (U32)value_2);
    }
    return (
        (value_2 >= 0 && value_1 <= I32_MAX - value_2) ||
        (value_2 < 0 && value_1 >= I32_MIN - value_2)
    );
}

bool JLU_addCheckOverflowI64(
    const I64 value_1,
    const I64 value_2,
    I64* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = (I64)((U64)value_1 + (U64)value_2);
    }
    return (
        (value_2 >= 0 && value_1 <= I64_MAX - value_2) ||
        (value_2 < 0 && value_1 >= I64_MIN - value_2)
    );
}

bool JLU_addCheckOverflowU8(
    const U8 value_1,
    const U8 value_2,
    U8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (value_1 <= U8_MAX - value_2);
}

bool JLU_addCheckOverflowU16(
    const U16 value_1,
    const U16 value_2,
    U16* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (value_1 <= U16_MAX - value_2);
}

bool JLU_addCheckOverflowU32(
    const U32 value_1,
    const U32 value_2,
    U32* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (value_1 <= U32_MAX - value_2);
}

bool JLU_addCheckOverflowU64(
    const U64 value_1,
    const U64 value_2,
    U64* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (value_1 <= U64_MAX - value_2);
}