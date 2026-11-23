#ifndef JLU_MUL_CHECK_OVERFLOW_H
#define JLU_MUL_CHECK_OVERFLOW_H

#include <jlu/int_types.h>
#include <jlu/macros.h>

bool JLU_mulCheckOverflowS8(
    JLU_S8 value_1,
    JLU_S8 value_2,
    JLU_S8* restrict result_out
);

bool JLU_mulCheckOverflowS16(
    JLU_S16 value_1,
    JLU_S16 value_2,
    JLU_S16* restrict result_out
);

bool JLU_mulCheckOverflowS32(
    JLU_S32 value_1,
    JLU_S32 value_2,
    JLU_S32* restrict result_out
);

bool JLU_mulCheckOverflowS64(
    JLU_S64 value_1,
    JLU_S64 value_2,
    JLU_S64* restrict result_out
);

bool JLU_mulCheckOverflowU8(
    JLU_U8 value_1,
    JLU_U8 value_2,
    JLU_U8* restrict result_out
);

bool JLU_mulCheckOverflowU16(
    JLU_U16 value_1,
    JLU_U16 value_2,
    JLU_U16* restrict result_out
);

bool JLU_mulCheckOverflowU32(
    JLU_U32 value_1,
    JLU_U32 value_2,
    JLU_U32* restrict result_out
);

bool JLU_mulCheckOverflowU64(
    JLU_U64 value_1,
    JLU_U64 value_2,
    JLU_U64* restrict result_out
);

#define JLU_mulCheckOverflow_GENERIC_2(value_1, value_2) _Generic( \
    (value_1),                                                     \
    JLU_S8: _Generic(                                              \
        (value_2),                                                 \
        JLU_S8: JLU_mulCheckOverflowS8,                            \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_S16: _Generic(                                             \
        (value_2),                                                 \
        JLU_S16: JLU_mulCheckOverflowS16,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_S32: _Generic(                                             \
        (value_2),                                                 \
        JLU_S32: JLU_mulCheckOverflowS32,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_S64: _Generic(                                             \
        (value_2),                                                 \
        JLU_S64: JLU_mulCheckOverflowS64,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U8: _Generic(                                              \
        (value_2),                                                 \
        JLU_U8: JLU_mulCheckOverflowU8,                            \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U16: _Generic(                                             \
        (value_2),                                                 \
        JLU_U16: JLU_mulCheckOverflowU16,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U32: _Generic(                                             \
        (value_2),                                                 \
        JLU_U32: JLU_mulCheckOverflowU32,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    JLU_U64: _Generic(                                             \
        (value_2),                                                 \
        JLU_U64: JLU_mulCheckOverflowU64,                          \
        default: JLU_INVALID_ARGUMENT_TYPES                        \
    ),                                                             \
    default: JLU_INVALID_ARGUMENT_TYPES                            \
)(value_1, value_2, nullptr)

#define JLU_mulCheckOverflow_GENERIC_3(value_1, value_2, result_out) _Generic( \
    (value_1),                                                                 \
    JLU_S8: _Generic(                                                          \
        (value_2),                                                             \
        JLU_S8: _Generic(                                                      \
            (result_out),                                                      \
            JLU_S8*: JLU_mulCheckOverflowS8,                                   \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_S16: _Generic(                                                         \
        (value_2),                                                             \
        JLU_S16: _Generic(                                                     \
            (result_out),                                                      \
            JLU_S16*: JLU_mulCheckOverflowS16,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_S32: _Generic(                                                         \
        (value_2),                                                             \
        JLU_S32: _Generic(                                                     \
            (result_out),                                                      \
            JLU_S32*: JLU_mulCheckOverflowS32,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_S64: _Generic(                                                         \
        (value_2),                                                             \
        JLU_S64: _Generic(                                                     \
            (result_out),                                                      \
            JLU_S64*: JLU_mulCheckOverflowS64,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U8: _Generic(                                                          \
        (value_2),                                                             \
        JLU_U8: _Generic(                                                      \
            (result_out),                                                      \
            JLU_U8*: JLU_mulCheckOverflowU8,                                   \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U16: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U16: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U16*: JLU_mulCheckOverflowU16,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U32: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U32: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U32*: JLU_mulCheckOverflowU32,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    JLU_U64: _Generic(                                                         \
        (value_2),                                                             \
        JLU_U64: _Generic(                                                     \
            (result_out),                                                      \
            JLU_U64*: JLU_mulCheckOverflowU64,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    default: JLU_INVALID_ARGUMENT_TYPES                                        \
)(value_1, value_2, result_out)

#define JLU_mulCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_mulCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_MUL_CHECK_OVERFLOW_H

#if defined(WITHOUT_PREFIX) && !defined(JLU_MUL_CHECK_OVERFLOW_H_WITHOUT_PREFIX)
#define JLU_MUL_CHECK_OVERFLOW_H_WITHOUT_PREFIX

#define mulCheckOverflowJLU_S8 JLU_mulCheckOverflowJLU_S8

#define mulCheckOverflowJLU_S16 JLU_mulCheckOverflowJLU_S16

#define mulCheckOverflowJLU_S32 JLU_mulCheckOverflowJLU_S32

#define mulCheckOverflowJLU_S64 JLU_mulCheckOverflowJLU_S64

#define mulCheckOverflowJLU_U8 JLU_mulCheckOverflowJLU_U8

#define mulCheckOverflowJLU_U16 JLU_mulCheckOverflowJLU_U16

#define mulCheckOverflowJLU_U32 JLU_mulCheckOverflowJLU_U32

#define mulCheckOverflowJLU_U64 JLU_mulCheckOverflowJLU_U64

#define mulCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_mulCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_MUL_CHECK_OVERFLOW_H_WITHOUT_PREFIX