#ifndef JLU_SUB_CHECK_OVERFLOW_H
#define JLU_SUB_CHECK_OVERFLOW_H

#include <jlu/int_types.h>
#include <jlu/macros.h>

bool JLU_subCheckOverflowS8(
    JLU_S8 value_1,
    JLU_S8 value_2,
    JLU_S8* restrict result_out
);

bool JLU_subCheckOverflowS16(
    JLU_S16 value_1,
    JLU_S16 value_2,
    JLU_S16* restrict result_out
);

bool JLU_subCheckOverflowS32(
    JLU_S32 value_1,
    JLU_S32 value_2,
    JLU_S32* restrict result_out
);

bool JLU_subCheckOverflowS64(
    JLU_S64 value_1,
    JLU_S64 value_2,
    JLU_S64* restrict result_out
);

bool JLU_subCheckOverflowU8(
    JLU_U8 value_1,
    JLU_U8 value_2,
    JLU_U8* restrict result_out
);

bool JLU_subCheckOverflowU16(
    JLU_U16 value_1,
    JLU_U16 value_2,
    JLU_U16* restrict result_out
);

bool JLU_subCheckOverflowU32(
    JLU_U32 value_1,
    JLU_U32 value_2,
    JLU_U32* restrict result_out
);

bool JLU_subCheckOverflowU64(
    JLU_U64 value_1,
    JLU_U64 value_2,
    JLU_U64* restrict result_out
);

#define JLU_subCheckOverflow_GENERIC_2(value_1, value_2) _Generic( \
    (value_1),                                                     \
    JLU_S8: _Generic(                                              \
        (value_2),                                                 \
        JLU_S8: JLU_subCheckOverflowS8,                            \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_S16: _Generic(                                             \
        (value_2),                                                 \
        JLU_S16: JLU_subCheckOverflowS16,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_S32: _Generic(                                             \
        (value_2),                                                 \
        JLU_S32: JLU_subCheckOverflowS32,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_S64: _Generic(                                             \
        (value_2),                                                 \
        JLU_S64: JLU_subCheckOverflowS64,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U8: _Generic(                                              \
        (value_2),                                                 \
        JLU_U8: JLU_subCheckOverflowU8,                            \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U16: _Generic(                                             \
        (value_2),                                                 \
        JLU_U16: JLU_subCheckOverflowU16,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U32: _Generic(                                             \
        (value_2),                                                 \
        JLU_U32: JLU_subCheckOverflowU32,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U64: _Generic(                                             \
        (value_2),                                                 \
        JLU_U64: JLU_subCheckOverflowU64,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    default: JLU_INVALID_ARGUMENT_TYPES                            \
)(value_1, value_2, nullptr)

#define JLU_subCheckOverflow_GENERIC_3(value_1, value_2, result_out) _Generic( \
    (value_1),                                                                 \
    JLU_S8: _Generic(                                                          \
        (value_2),                                                             \
        JLU_S8: _Generic(                                                      \
            (result_out),                                                      \
            JLU_S8*: JLU_subCheckOverflowS8,                                   \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_S16: _Generic(                                                         \
        (value_2),                                                             \
        JLU_S16: _Generic(                                                     \
            (result_out),                                                      \
            JLU_S16*: JLU_subCheckOverflowS16,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_S32: _Generic(                                                         \
        (value_2),                                                             \
        JLU_S32: _Generic(                                                     \
            (result_out),                                                      \
            JLU_S32*: JLU_subCheckOverflowS32,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_S64: _Generic(                                                         \
        (value_2),                                                             \
        JLU_S64: _Generic(                                                     \
            (result_out),                                                      \
            JLU_S64*: JLU_subCheckOverflowS64,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U8: _Generic(                                                          \
        (value_2),                                                             \
        JLU_U8: _Generic(                                                      \
            (result_out),                                                      \
            JLU_U8*: JLU_subCheckOverflowU8,                                   \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U16: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U16: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U16*: JLU_subCheckOverflowU16,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U32: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U32: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U32*: JLU_subCheckOverflowU32,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U64: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U64: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U64*: JLU_subCheckOverflowU64,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    default: JLU_INVALID_ARGUMENT_TYPES                                        \
)(value_1, value_2, result_out)

#define JLU_subCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_subCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_SUB_CHECK_OVERFLOW_H

#if defined(WITHOUT_PREFIX) && !defined(JLU_SUB_CHECK_OVERFLOW_H_WITHOUT_PREFIX)
#define JLU_SUB_CHECK_OVERFLOW_H_WITHOUT_PREFIX

#define subCheckOverflowJLU_S8 JLU_subCheckOverflowJLU_S8

#define subCheckOverflowJLU_S16 JLU_subCheckOverflowJLU_S16

#define subCheckOverflowJLU_S32 JLU_subCheckOverflowJLU_S32

#define subCheckOverflowJLU_S64 JLU_subCheckOverflowJLU_S64

#define subCheckOverflowJLU_U8 JLU_subCheckOverflowJLU_U8

#define subCheckOverflowJLU_U16 JLU_subCheckOverflowJLU_U16

#define subCheckOverflowJLU_U32 JLU_subCheckOverflowJLU_U32

#define subCheckOverflowJLU_U64 JLU_subCheckOverflowJLU_U64

#define subCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_subCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_SUB_CHECK_OVERFLOW_H_WITHOUT_PREFIX