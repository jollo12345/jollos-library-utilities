#include "jlu/sub_check_overflow.h"

#define WITHOUT_PREFIX
#include "jlu/int_types.h"

bool JLU_subCheckOverflowS8(
    const S8 value_1,
    const S8 value_2,
    S8* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S8)((U8)value_1 - (U8)value_2);
    }
    return (
        ((value_2 >= 0) && (value_1 >= S8_MIN + value_2)) ||
        ((value_2 < 0) && (value_1 <= S8_MAX + value_2))
    );
}

bool JLU_subCheckOverflowS16(
    const S16 value_1,
    const S16 value_2,
    S16* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S16)((U16)value_1 - (U16)value_2);
    }
    return (
        ((value_2 >= 0) && (value_1 >= S16_MIN + value_2)) ||
        ((value_2 < 0) && (value_1 <= S16_MAX + value_2))
    );
}

bool JLU_subCheckOverflowS32(
    const S32 value_1,
    const S32 value_2,
    S32* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S32)((U32)value_1 - (U32)value_2);
    }
    return (
        ((value_2 >= 0) && (value_1 >= S32_MIN + value_2)) ||
        ((value_2 < 0) && (value_1 <= S32_MAX + value_2))
    );
}

bool JLU_subCheckOverflowS64(
    const S64 value_1,
    const S64 value_2,
    S64* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S64)((U64)value_1 - (U64)value_2);
    }
    return (
        ((value_2 >= 0) && (value_1 >= S64_MIN + value_2)) ||
        ((value_2 < 0) && (value_1 <= S64_MAX + value_2))
    );
}

bool JLU_subCheckOverflowU8(
    const U8 value_1,
    const U8 value_2,
    U8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}

bool JLU_subCheckOverflowU16(
    const U16 value_1,
    const U16 value_2,
    U16* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}

bool JLU_subCheckOverflowU32(
    const U32 value_1,
    const U32 value_2,
    U32* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}

bool JLU_subCheckOverflowU64(
    const U64 value_1,
    const U64 value_2,
    U64* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}