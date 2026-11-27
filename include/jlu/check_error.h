#ifndef JLU_CHECK_ERROR_H
#define JLU_CHECK_ERROR_H

#include <SDL3/SDL_error.h>

/*
 * A set of macros to shorten error checking. it assumes that a erronious result will evaluate to 0.
 * Meaning either returning 'false' or 'nullptr'.
 * This is a the case for most functions in SDL and should be true for the functions i intend to write.
 */

#define JLU_CHECK_ERROR_GOTO(expr, label) \
    do {                                  \
        if (!(expr)) {                    \
            goto label;                   \
        }                                 \
    } while (0)

#define JLU_CHECK_ERROR_MESSAGE(expr, label, fmt, ...)     \
    do {                                                   \
        if (!(expr)) {                                     \
            SDL_SetError((fmt)__VA_OPT__(, ) __VA_ARGS__); \
            goto label;                                    \
        }                                                  \
    } while (0)

#define JLU_CHECK_ERROR_RECOVER(expr) \
    if ((expr)) {                     \
    } else

#endif  // JLU_CHECK_ERROR_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_CHECK_ERROR_H_WITHOUT_PREFIX)
#define JLU_CHECK_ERROR_H_WITHOUT_PREFIX

#define CHECK_ERROR_GOTO(expr, label) \
    JLU_CHECK_ERROR_GOTO((expr), label)

#define CHECK_ERROR_MESSAGE(expr, label, fmt, ...) \
    JLU_CHECK_ERROR_MESSAGE((expr), label, (fmt)__VA_OPT__(, ) __VA_ARGS__)

#define CHECK_ERROR_RECOVER(expr) \
    JLU_CHECK_ERROR_RECOVER((expr))

#endif  // JLU_CHECK_ERROR_H_WITHOUT_PREFIX