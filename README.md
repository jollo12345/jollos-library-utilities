# jollos-library-utilities

A collection of basic features for library development, written in
C23.

## Features

- [Error checking](#error-checking)
- [Int types](#int-types)
- [Float types](#float-types)
- [Over- and underflow checking](#over--and-underflow-checking)
- [Macros for generic functions](#macros-for-generic-functions)

## Requirements

- C23-capable compiler (GCC, Clang)
- CMake 3.21 or newer
- [SDL3](https://github.com/libsdl-org/SDL)
- Optional for tests: git and network access at configure time
  (fetches [Unity](https://github.com/ThrowTheSwitch/Unity)) and
  [gcovr](https://gcovr.com) for coverage

## Building

```sh
cmake -S . -B build
cmake --build build
```

## CMake Options

| Option                | Description                       |
| --------------------- | --------------------------------- |
| `JLU_BUILD_SHARED`    | Build the shared library          |
| `JLU_BUILD_STATIC`    | Build the static library          |
| `JLU_STATIC_SDL`      | Link SDL3 statically              |
| `JLU_BUILD_TESTS`     | Build the unit tests              |
| `JLU_ENABLE_COVERAGE` | Instrument the build for coverage |

Either `JLU_BUILD_SHARED` or `JLU_BUILD_STATIC` must be enabled.

## Error Checking

Macros to make error checking clearer. Assumes that function returns
indicate a erronious result when !(expr) evaluates to true which is
the case for `nullptr` and `false` and most SDL functions use to
indicate errors. Be aware that most standard library functions do not
follow this convention.

```c
bool func() {
    Foo* foo = nullptr;
    int* buffer = nullptr;

    foo = Foo_create();
    if(!foo) {
        SDL_SetError("can't create 'Foo'.");
        goto error;
    }

    buffer = malloc(Foo_getBufferSize(foo) * sizeof(int));
    if(!foo) {
        goto error;
    }

    Bar* bar = Foo_getBar(foo);
    if(!bar) {
        bar = Foo_getDefaultBar(foo);
    }

    ... // code

error:
    free(buffer);
    Foo_destroy(foo);
    return false;
}

#define WITHOUT_PREFIX
#include <jlu/check_error.h>

bool func() {
    Foo* foo = nullptr;
    int* buffer = nullptr;

    CHECK_ERROR_MESSAGE(
        foo = Foo_create(),
        error,
        "can't create 'Foo'."
    );

    CHECK_ERROR_GOTO(
        buffer = malloc(Foo_getBufferSize(foo) * sizeof(int)),
        error
    );

    Bar* bar;
    CHECK_ERROR_RECOVER(
        bar = Foo_getBar(foo)
    ) {
        bar = Foo_getDefaultBar(foo);
    }

    ... // code

error:
    free(buffer);
    Foo_destroy(foo);
    return false;
}
```

## Int Types

Definitions for common signed and unsigned integer types aswell as
their maximum and minimum values. Names are shortend to keep code
concise.

| Name   | Type                                      |
| ------ | ----------------------------------------- |
| `Byte` | 8-bit type mostly for raw data buffers.   |
| `C8`   | 8-bit character type for UTF-8 and ASCII. |
| `C16`  | 16-bit character type for UTF-16.         |
| `S8`   | 8-bit signed integer.                     |
| `S16`  | 16-bit signed integer.                    |
| `S32`  | 32-bit signed integer.                    |
| `S64`  | 64-bit signed integer.                    |
| `U8`   | 8-bit unsigned integer.                   |
| `U16`  | 16-bit unsigned integer.                  |
| `U32`  | 32-bit unsigned integer.                  |
| `U64`  | 64-bit unsigned integer.                  |

## Float Types

Definitions for common float types aswell as their maximum and
minimum values. Names are shortend to keep code concise.

| Name   | Type           |
| ------ | -------------- |
| `F32`  | 32-bit float.  |
| `F64`  | 64-bit double. |

## Over- and Underflow Checking

Overflow checking for signed unsigned types. Provides functions for
each type and a generic function.

## Macros for Generic Functions

Usefull macros for implementing generic functions.