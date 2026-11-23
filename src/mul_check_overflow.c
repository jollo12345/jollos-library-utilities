#include "jlu/mul_check_overflow.h"

#define WITHOUT_PREFIX
#include "jlu/int_types.h"

bool JLU_mulCheckOverflowS8(
    const S8 value_1,
    const S8 value_2,
    S8* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S8)((U8)value_1 * (U8)value_2);
    }

    return (
        (value_1 == 0) ||
        (value_2 == 0) ||
        ((value_1 > 0) && (value_2 > 0) && (value_1 <= S8_MAX / value_2)) ||
        ((value_1 > 0) && (value_2 < 0) && (value_2 >= S8_MIN / value_1)) ||
        ((value_1 < 0) && (value_2 > 0) && (value_1 >= S8_MIN / value_2)) ||
        ((value_1 < 0) && (value_2 < 0) && (value_1 >= S8_MAX / value_2))
    );
}

bool JLU_mulCheckOverflowS16(
    const S16 value_1,
    const S16 value_2,
    S16* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S16)((U32)value_1 * (U32)value_2);
    }

    return (
        (value_1 == 0) ||
        (value_2 == 0) ||
        ((value_1 > 0) && (value_2 > 0) && (value_1 <= S16_MAX / value_2)) ||
        ((value_1 > 0) && (value_2 < 0) && (value_2 >= S16_MIN / value_1)) ||
        ((value_1 < 0) && (value_2 > 0) && (value_1 >= S16_MIN / value_2)) ||
        ((value_1 < 0) && (value_2 < 0) && (value_1 >= S16_MAX / value_2))
    );
}

bool JLU_mulCheckOverflowS32(
    const S32 value_1,
    const S32 value_2,
    S32* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S32)((U32)value_1 * (U32)value_2);
    }

    return (
        (value_1 == 0) ||
        (value_2 == 0) ||
        ((value_1 > 0) && (value_2 > 0) && (value_1 <= S32_MAX / value_2)) ||
        ((value_1 > 0) && (value_2 < 0) && (value_2 >= S32_MIN / value_1)) ||
        ((value_1 < 0) && (value_2 > 0) && (value_1 >= S32_MIN / value_2)) ||
        ((value_1 < 0) && (value_2 < 0) && (value_1 >= S32_MAX / value_2))
    );
}

bool JLU_mulCheckOverflowS64(
    const S64 value_1,
    const S64 value_2,
    S64* const result_out
) {
    if (result_out != nullptr) {
        *result_out = (S64)((U64)value_1 * (U64)value_2);
    }

    return (
        (value_1 == 0) ||
        (value_2 == 0) ||
        ((value_1 > 0) && (value_2 > 0) && (value_1 <= S64_MAX / value_2)) ||
        ((value_1 > 0) && (value_2 < 0) && (value_2 >= S64_MIN / value_1)) ||
        ((value_1 < 0) && (value_2 > 0) && (value_1 >= S64_MIN / value_2)) ||
        ((value_1 < 0) && (value_2 < 0) && (value_1 >= S64_MAX / value_2))
    );
}

bool JLU_mulCheckOverflowU8(
    const U8 value_1,
    const U8 value_2,
    U8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (
        (value_1 == 0u) ||
        (value_2 <= U8_MAX / value_1)
    );
}

bool JLU_mulCheckOverflowU16(
    const U16 value_1,
    const U16 value_2,
    U16* const result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (
        (value_1 == 0u) ||
        (value_2 <= U16_MAX / value_1)
    );
}

bool JLU_mulCheckOverflowU32(
    const U32 value_1,
    const U32 value_2,
    U32* const result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (
        (value_1 == 0u) ||
        (value_2 <= U32_MAX / value_1)
    );
}

bool JLU_mulCheckOverflowU64(
    const U64 value_1,
    const U64 value_2,
    U64* const result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (
        (value_1 == 0u) ||
        (value_2 <= U64_MAX / value_1)
    );
}