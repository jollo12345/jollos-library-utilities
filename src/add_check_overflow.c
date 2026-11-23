#include "jlu/add_check_overflow.h"

#define WITHOUT_PREFIX
#include "jlu/int_types.h"

bool JLU_addCheckOverflowU8(
    const U8 value_1,
    const U8 value_2,
    U8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (bool)(value_1 <= U8_MAX - value_2);
}

bool JLU_addCheckOverflowU16(
    const U16 value_1,
    const U16 value_2,
    U16* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (bool)(value_1 <= U16_MAX - value_2);
}

bool JLU_addCheckOverflowU32(
    const U32 value_1,
    const U32 value_2,
    U32* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (bool)(value_1 <= U32_MAX - value_2);
}

bool JLU_addCheckOverflowU64(
    const U64 value_1,
    const U64 value_2,
    U64* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 + value_2;
    }
    return (bool)(value_1 <= U64_MAX - value_2);
}