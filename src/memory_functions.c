#include "jlu/memory_functions.h"

void* _JLU_mallocWrapper_SDL(void* context, JLU_U64 size) {
    SDL_assert(context == nullptr);
    return SDL_malloc(size);
}

void* _JLU_callocWrapper_SDL(void* context, JLU_U64 num, JLU_U64 size) {
    SDL_assert(context == nullptr);
    return SDL_malloc(size);
}

void* _JLU_reallocWrapper_SDL(void* context, void* ptr, JLU_U64 new_size) {
    SDL_assert(context == nullptr);
    return SDL_realloc(ptr, new_size);
}

void _JLU_freeWrapper_SDL(void* context, void* ptr) {
    SDL_assert(context == nullptr);
    SDL_free(ptr);
}