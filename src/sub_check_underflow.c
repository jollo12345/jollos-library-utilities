#include "jlu/sub_check_underflow.h"

#define WITHOUT_PREFIX
#include "jlu/int_types.h"

bool JLU_subCheckUnderflowU8(
    const U8 value_1,
    const U8 value_2,
    U8* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}

bool JLU_subCheckUnderflowU16(
    const U16 value_1,
    const U16 value_2,
    U16* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}

bool JLU_subCheckUnderflowU32(
    const U32 value_1,
    const U32 value_2,
    U32* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}

bool JLU_subCheckUnderflowU64(
    const U64 value_1,
    const U64 value_2,
    U64* const restrict result_out
) {
    if (result_out != nullptr) {
        *result_out = value_1 - value_2;
    }
    return value_1 >= value_2;
}