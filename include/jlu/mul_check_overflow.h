#ifndef JLU_MUL_CHECK_OVERFLOW_H
#define JLU_MUL_CHECK_OVERFLOW_H

#include <SDL3/SDL_stdinc.h>
#include <jlu/macros.h>

static inline bool JLU_mulCheckOverflowUint8(
    const Uint8 value_1,
    const Uint8 value_2,
    Uint8* const result_out
) {
    *result_out = value_1 * value_2;
    return (value_1 == 0u) || (value_2 < UINT8_MAX / value_1);
}

static inline bool JLU_mulCheckOverflowUint16(
    const Uint16 value_1,
    const Uint16 value_2,
    Uint16* const result_out
) {
    *result_out = value_1 * value_2;
    return (value_1 == 0u) || (value_2 < UINT16_MAX / value_1);
}

static inline bool JLU_mulCheckOverflowUint32(
    const Uint32 value_1,
    const Uint32 value_2,
    Uint32* const result_out
) {
    *result_out = value_1 * value_2;
    return (value_1 == 0u) || (value_2 < UINT32_MAX / value_1);
}

static inline bool JLU_mulCheckOverflowUint64(
    const Uint64 value_1,
    const Uint64 value_2,
    Uint64* const result_out
) {
    *result_out = value_1 * value_2;
    return (value_1 == 0u) || (value_2 < UINT64_MAX / value_1);
}

#define JLU_mulCheckOverflow_GENERIC_3(value_1, value_2, result_out) _Generic( \
    (value_1),                                                                 \
    Uint8: _Generic(                                                           \
        (value_2),                                                             \
        Uint8: _Generic(                                                       \
            (result_out),                                                      \
            Uint8*: JLU_mulCheckOverflowUint8,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    Uint16: _Generic(                                                          \
        (value_2),                                                             \
        Uint16: _Generic(                                                      \
            (result_out),                                                      \
            Uint16*: JLU_mulCheckOverflowUint16,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    Uint32: _Generic(                                                          \
        (value_2),                                                             \
        Uint32: _Generic(                                                      \
            (result_out),                                                      \
            Uint32*: JLU_mulCheckOverflowUint32,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    Uint64: _Generic(                                                          \
        (value_2),                                                             \
        Uint64: _Generic(                                                      \
            (result_out),                                                      \
            Uint64*: JLU_mulCheckOverflowUint64,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    default: JLU_INVALID_ARGUMENT_TYPES                                        \
)(value_1, value_2, result_out)

#define JLU_mulCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_mulCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_MUL_CHECK_OVERFLOW_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_MUL_CHECK_OVERFLOW_H_WITHOUT_PREFIX)
#define JLU_MUL_CHECK_OVERFLOW_H_WITHOUT_PREFIX

#define mulCheckOverflowUint8 JLU_mulCheckOverflowUint8

#define mulCheckOverflowUint16 JLU_mulCheckOverflowUint16

#define mulCheckOverflowUint32 JLU_mulCheckOverflowUint32

#define mulCheckOverflowUint64 JLU_mulCheckOverflowUint64

#define mulCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_mulCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_MUL_CHECK_OVERFLOW_H_WITHOUT_PREFIX