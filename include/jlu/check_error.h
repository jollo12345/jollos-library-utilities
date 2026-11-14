#ifndef JLU_CHECK_ERROR_H
#define JLU_CHECK_ERROR_H

#include <SDL3/SDL_error.h>

#define JLU_CHECK_ERROR_GOTO(expr, label) \
    if ((expr)) {                         \
    } else {                              \
        goto label;                       \
    }

#define JLU_CHECK_ERROR_MESSAGE(expr, label, ...) \
    if ((expr)) {                                 \
    } else {                                      \
        SDL_SetError(__VA_ARGS__);                \
        goto label;                               \
    }

#define JLU_CHECK_ERROR_RECOVER(expr) \
    if ((expr)) {                     \
    } else

#endif  // JLU_CHECK_ERROR_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_CHECK_ERROR_H_WITHOUT_PREFIX)
#define JLU_CHECK_ERROR_H_WITHOUT_PREFIX

#define JLU_CHECK_ERROR_GOTO(expr, label) \
    if ((expr)) {                         \
    } else {                              \
        goto label;                       \
    }

#define JLU_CHECK_ERROR_MESSAGE(expr, label, ...) \
    if ((expr)) {                                 \
    } else {                                      \
        SDL_SetError(__VA_ARGS__);                \
        goto label;                               \
    }

#define JLU_CHECK_ERROR_RECOVER(expr) \
    if ((expr)) {                     \
    } else

#endif  // JLU_CHECK_ERROR_H_WITHOUT_PREFIX