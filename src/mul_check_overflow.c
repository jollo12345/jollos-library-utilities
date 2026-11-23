#include "jlu/mul_check_overflow.h"

#define WITHOUT_PREFIX
#include "jlu/int_types.h"

bool JLU_mulCheckOverflowU8(
    const U8 value_1,
    const U8 value_2,
    U8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (bool)((value_1 == 0u) || (value_2 <= U8_MAX / value_1));
}

bool JLU_mulCheckOverflowU16(
    const U16 value_1,
    const U16 value_2,
    U16* const result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (bool)((value_1 == 0u) || (value_2 <= U16_MAX / value_1));
}

bool JLU_mulCheckOverflowU32(
    const U32 value_1,
    const U32 value_2,
    U32* const result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (bool)((value_1 == 0u) || (value_2 <= U32_MAX / value_1));
}

bool JLU_mulCheckOverflowU64(
    const U64 value_1,
    const U64 value_2,
    U64* const result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 * value_2;
    }
    return (bool)((value_1 == 0u) || (value_2 <= U64_MAX / value_1));
}