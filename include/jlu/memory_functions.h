#ifndef JLU_MEMORY_FUNCTIONS_H
#define JLU_MEMORY_FUNCTIONS_H

#include <SDL3/SDL_assert.h>

#include "jlu/int_types.h"

typedef void*(JLU_MallocFunc)(void* context, JLU_U64 size);
typedef void*(JLU_CallocFunc)(void* context, JLU_U64 num, JLU_U64 size);
typedef void*(JLU_ReallocFunc)(void* context, void* ptr, JLU_U64 new_size);
typedef void(JLU_FreeFunc)(void* context, void* ptr);

typedef struct JLU_MemoryFunctions {
    void* context;
    JLU_MallocFunc* malloc;
    JLU_CallocFunc* calloc;
    JLU_ReallocFunc* realloc;
    JLU_FreeFunc* free;
} JLU_MemoryFunctions;

void* _JLU_mallocWrapper_SDL(void* context, JLU_U64 size);

void* _JLU_callocWrapper_SDL(void* context, JLU_U64 num, JLU_U64 size);

void* _JLU_reallocWrapper_SDL(void* context, void* ptr, JLU_U64 new_size);

void _JLU_freeWrapper_SDL(void* context, void* ptr);

constexpr JLU_MemoryFunctions JLU_MEMORY_FUNCTIONS_SDL = (JLU_MemoryFunctions){
    .context = nullptr,
    .malloc = &_JLU_mallocWrapper_SDL,
    .calloc = &_JLU_callocWrapper_SDL,
    .realloc = &_JLU_reallocWrapper_SDL,
    .free = &_JLU_freeWrapper_SDL,
};

#endif  // JLU_MEMORY_FUNCTIONS_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_MEMORY_FUNCTIONS_H_WITHOUT_PREFIX)

typedef JLU_MallocFunc MallocFunc;
typedef JLU_CallocFunc CallocFunc;
typedef JLU_ReallocFunc ReallocFunc;
typedef JLU_FreeFunc FreeFunc;

typedef JLU_MemoryFunctions MemoryFunctions;

constexpr JLU_MemoryFunctions MEMORY_FUNCTIONS_SDL = JLU_MEMORY_FUNCTIONS_SDL;

#endif  // JLU_MEMORY_FUNCTIONS_H_WITHOUT_PREFIX