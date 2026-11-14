#ifndef JLU_SUB_CHECK_OVERFLOW_H
#define JLU_SUB_CHECK_OVERFLOW_H

#include <SDL3/SDL_stdinc.h>
#include <jlu/macros.h>

static inline bool JLU_subCheckUnderflowUint8(
    const Uint8 value_1,
    const Uint8 value_2,
    Uint8* const result_out
) {
    *result_out = value_1 - value_2;
    return value_1 >= value_2;
}

static inline bool JLU_subCheckUnderflowUint16(
    const Uint16 value_1,
    const Uint16 value_2,
    Uint16* const result_out
) {
    *result_out = value_1 - value_2;
    return value_1 >= value_2;
}

static inline bool JLU_subCheckUnderflowUint32(
    const Uint32 value_1,
    const Uint32 value_2,
    Uint32* const result_out
) {
    *result_out = value_1 - value_2;
    return value_1 >= value_2;
}

static inline bool JLU_subCheckUnderflowUint64(
    const Uint64 value_1,
    const Uint64 value_2,
    Uint64* const result_out
) {
    *result_out = value_1 - value_2;
    return value_1 >= value_2;
}

#define JLU_subCheckUnderflow_GENERIC_3(value_1, value_2, result_out) _Generic( \
    (value_1),                                                                  \
    Uint8: _Generic(                                                            \
        (value_2),                                                              \
        Uint8: _Generic(                                                        \
            (result_out),                                                       \
            Uint8*: JLU_subCheckUnderflowUint8,                                 \
            default: JLU_INVALID_ARGUMENT_TYPES                                 \
        ),                                                                      \
        default: JLU_INVALID_ARGUMENT_TYPES                                     \
    ),                                                                          \
    Uint16: _Generic(                                                           \
        (value_2),                                                              \
        Uint16: _Generic(                                                       \
            (result_out),                                                       \
            Uint16*: JLU_subCheckUnderflowUint16,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                 \
        ),                                                                      \
        default: JLU_INVALID_ARGUMENT_TYPES                                     \
    ),                                                                          \
    Uint32: _Generic(                                                           \
        (value_2),                                                              \
        Uint32: _Generic(                                                       \
            (result_out),                                                       \
            Uint32*: JLU_subCheckUnderflowUint32,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                 \
        ),                                                                      \
        default: JLU_INVALID_ARGUMENT_TYPES                                     \
    ),                                                                          \
    Uint64: _Generic(                                                           \
        (value_2),                                                              \
        Uint64: _Generic(                                                       \
            (result_out),                                                       \
            Uint64*: JLU_subCheckUnderflowUint64,                               \
            default: JLU_INVALID_ARGUMENT_TYPES                                 \
        ),                                                                      \
        default: JLU_INVALID_ARGUMENT_TYPES                                     \
    ),                                                                          \
    default: JLU_INVALID_ARGUMENT_TYPES                                         \
)(value_1, value_2, result_out)

#define JLU_subCheckUnderflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_subCheckUnderflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_SUB_CHECK_OVERFLOW_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_SUB_CHECK_OVERFLOW_H_WITHOUT_PREFIX)
#define JLU_SUB_CHECK_OVERFLOW_H_WITHOUT_PREFIX

#define subCheckUnderflowUint8 JLU_subCheckUnderflowUint8

#define subCheckUnderflowUint16 JLU_subCheckUnderflowUint16

#define subCheckUnderflowUint32 JLU_subCheckUnderflowUint32

#define subCheckUnderflowUint64 JLU_subCheckUnderflowUint64

#define subCheckUnderflow(...) \
    JLU_DISPATCH(JLU_CONCAT_EXPAND(JLU_subCheckUnderflow_GENERIC_, JLU_NARGS(__VA_ARGS__)), __VA_ARGS__)

#endif  // JLU_SUB_CHECK_OVERFLOW_H_WITHOUT_PREFIX