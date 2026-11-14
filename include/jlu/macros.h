#ifndef JLU_MACROS_H
#define JLU_MACROS_H

#define JLU_NARGS_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, N, ...) N
#define JLU_NARGS(...) JLU_NARGS_HELPER(__VA_ARGS__, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define JLU_CONCAT(a, b) a##b
#define JLU_CONCAT_EXPAND(a, b) JLU_CONCAT(a, b)

#define JLU_DISPATCH(macro, ...) macro(__VA_ARGS__)

void JLU_INVALID_ARGUMENT_TYPES();

#endif  // JLU_MACROS_H