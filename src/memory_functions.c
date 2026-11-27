#include "jlu/memory_functions.h"

#define JLU_WITHOUT_PREFIX
#include "jlu/int_types.h"

void* _JLU_mallocWrapper_SDL(void* context, U64 size) {
    SDL_assert(context == nullptr);
    return SDL_malloc(size);
}

void* _JLU_callocWrapper_SDL(void* context, U64 num, U64 size) {
    SDL_assert(context == nullptr);
    return SDL_malloc(size);
}

void* _JLU_reallocWrapper_SDL(void* context, void* ptr, U64 new_size) {
    SDL_assert(context == nullptr);
    return SDL_realloc(ptr, new_size);
}

void _JLU_freeWrapper_SDL(void* context, void* ptr) {
    SDL_assert(context == nullptr);
    SDL_free(ptr);
}