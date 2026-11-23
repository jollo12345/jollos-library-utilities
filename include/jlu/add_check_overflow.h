#ifndef JLU_ADD_CHECK_OVERFLOW_H
#define JLU_ADD_CHECK_OVERFLOW_H

#include <jlu/int_types.h>
#include <jlu/macros.h>

bool JLU_addCheckOverflowU8(
    JLU_U8 value_1,
    JLU_U8 value_2,
    JLU_U8* restrict result_out
);

bool JLU_addCheckOverflowU16(
    JLU_U16 value_1,
    JLU_U16 value_2,
    JLU_U16* restrict result_out
);

bool JLU_addCheckOverflowU32(
    JLU_U32 value_1,
    JLU_U32 value_2,
    JLU_U32* restrict result_out
);

bool JLU_addCheckOverflowU64(
    JLU_U64 value_1,
    JLU_U64 value_2,
    JLU_U64* restrict result_out
);

#define JLU_addCheckOverflow_GENERIC_2(value_1, value_2) _Generic( \
    (value_1),                                                     \
    JLU_U8: _Generic(                                              \
        (value_2),                                                 \
        JLU_U8: JLU_addCheckOverflowU8,                            \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U16: _Generic(                                             \
        (value_2),                                                 \
        JLU_U16: JLU_addCheckOverflowU16,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U32: _Generic(                                             \
        (value_2),                                                 \
        JLU_U32: JLU_addCheckOverflowU32,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U64: _Generic(                                             \
        (value_2),                                                 \
        JLU_U64: JLU_addCheckOverflowU64,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    default: JLU_INVALID_ARGUMENT_TYPES                            \
)(value_1, value_2, nullptr)

#define JLU_addCheckOverflow_GENERIC_3(value_1, value_2, result_out) _Generic( \
    (value_1),                                                                 \
    JLU_U8: _Generic(                                                          \
        (value_2),                                                             \
        JLU_U8: _Generic(                                                      \
            (result_out),                                                      \
            JLU_U8*: JLU_addCheckOverflowU8,                                   \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U16: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U16: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U16*: JLU_addCheckOverflowU16,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U32: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U32: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U32*: JLU_addCheckOverflowU32,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U64: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U64: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U64*: JLU_addCheckOverflowU64,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    default: JLU_INVALID_ARGUMENT_TYPES                                        \
)(value_1, value_2, result_out)

#define JLU_addCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_addCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_ADD_CHECK_OVERFLOW_H

#if defined(WITHOUT_PREFIX) && !defined(JLU_ADD_CHECK_OVERFLOW_H_WITHOUT_PREFIX)
#define JLU_ADD_CHECK_OVERFLOW_H_WITHOUT_PREFIX

#define addCheckOverflowJLU_U8 JLU_addCheckOverflowJLU_U8

#define addCheckOverflowJLU_U16 JLU_addCheckOverflowJLU_U16

#define addCheckOverflowJLU_U32 JLU_addCheckOverflowJLU_U32

#define addCheckOverflowJLU_U64 JLU_addCheckOverflowJLU_U64

#define addCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_addCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_ADD_CHECK_OVERFLOW_H_WITHOUT_PREFIX