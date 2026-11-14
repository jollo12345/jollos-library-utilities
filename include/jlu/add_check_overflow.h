#ifndef JLU_ADD_CHECK_OVERFLOW_H
#define JLU_ADD_CHECK_OVERFLOW_H

#include <SDL3/SDL_stdinc.h>
#include <jlu/macros.h>

static inline bool JLU_addCheckOverflowUint8(
    const Uint8 value_1,
    const Uint8 value_2,
    Uint8* const result_out
) {
    *result_out = value_1 + value_2;
    return value_1 < UINT8_MAX - value_2;
}

static inline bool JLU_addCheckOverflowUint16(
    const Uint16 value_1,
    const Uint16 value_2,
    Uint16* const result_out
) {
    *result_out = value_1 + value_2;
    return value_1 < UINT16_MAX - value_2;
}

static inline bool JLU_addCheckOverflowUint32(
    const Uint32 value_1,
    const Uint32 value_2,
    Uint32* const result_out
) {
    *result_out = value_1 + value_2;
    return value_1 < UINT32_MAX - value_2;
}

static inline bool JLU_addCheckOverflowUint64(
    const Uint64 value_1,
    const Uint64 value_2,
    Uint64* const result_out
) {
    *result_out = value_1 + value_2;
    return value_1 < UINT64_MAX - value_2;
}

#define JLU_addCheckOverflow_GENERIC_3(value_1, value_2, result_out) _Generic( \
    (value_1),                                                                 \
    Uint8: _Generic(                                                           \
        (value_2),                                                             \
        Uint8: _Generic(                                                       \
            (result_out),                                                      \
            Uint8*: JLU_addCheckOverflowUint8,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    Uint16: _Generic(                                                          \
        (value_2),                                                             \
        Uint16: _Generic(                                                      \
            (result_out),                                                      \
            Uint16*: JLU_addCheckOverflowUint16,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    Uint32: _Generic(                                                          \
        (value_2),                                                             \
        Uint32: _Generic(                                                      \
            (result_out),                                                      \
            Uint32*: JLU_addCheckOverflowUint32,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    Uint64: _Generic(                                                          \
        (value_2),                                                             \
        Uint64: _Generic(                                                      \
            (result_out),                                                      \
            Uint64*: JLU_addCheckOverflowUint64,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                \
        ),                                                                     \
        default: JLU_INVALID_ARGUMENT_TYPES                                    \
    ),                                                                         \
    default: JLU_INVALID_ARGUMENT_TYPES                                        \
)(value_1, value_2, result_out)

#define JLU_addCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_addCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_ADD_CHECK_OVERFLOW_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_ADD_CHECK_OVERFLOW_H_WITHOUT_PREFIX)
#define JLU_ADD_CHECK_OVERFLOW_H_WITHOUT_PREFIX

#define addCheckOverflowUint8 JLU_addCheckOverflowUint8

#define addCheckOverflowUint16 JLU_addCheckOverflowUint16

#define addCheckOverflowUint32 JLU_addCheckOverflowUint32

#define addCheckOverflowUint64 JLU_addCheckOverflowUint64

#define addCheckOverflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_addCheckOverflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_ADD_CHECK_OVERFLOW_H_WITHOUT_PREFIX