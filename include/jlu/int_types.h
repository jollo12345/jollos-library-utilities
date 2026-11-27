#ifndef JLU_INT_TYPES_H
#define JLU_INT_TYPES_H

typedef unsigned char JLU_Byte;
static_assert(sizeof(JLU_Byte) == 1);

typedef unsigned char JLU_C8;
static_assert(sizeof(JLU_C8) == 1);

typedef unsigned short JLU_C16;
static_assert(sizeof(JLU_C16) == 2);

typedef signed char JLU_S8;
static_assert(sizeof(JLU_S8) == 1);

constexpr JLU_S8 JLU_S8_MIN = ~0x7F; /* -128 */
constexpr JLU_S8 JLU_S8_MAX = 0x7F;  /* 127 */

typedef signed short JLU_S16;
static_assert(sizeof(JLU_S16) == 2);
constexpr JLU_S16 JLU_S16_MIN = ~0x7FFF; /* -32,768 */
constexpr JLU_S16 JLU_S16_MAX = 0x7FFF;  /* 32,767 */

typedef signed JLU_S32;
static_assert(sizeof(JLU_S32) == 4);
constexpr JLU_S32 JLU_S32_MIN = ~0x7FFF'FFFF; /* -2,147,483,648 */
constexpr JLU_S32 JLU_S32_MAX = 0x7FFF'FFFF;  /* 2,147,483,647 */

typedef signed long long JLU_S64;
static_assert(sizeof(JLU_S64) == 8);
constexpr JLU_S64 JLU_S64_MIN = ~0x7FFF'FFFF'FFFF'FFFF; /* -9,223,372,036,854,775,808 */
constexpr JLU_S64 JLU_S64_MAX = 0x7FFF'FFFF'FFFF'FFFF;  /* 9,223,372,036,854,775,807 */

typedef unsigned char JLU_U8;
static_assert(sizeof(JLU_U8) == 1);
constexpr JLU_U8 JLU_U8_MAX = 0xFF; /* 255 */

typedef unsigned short JLU_U16;
static_assert(sizeof(JLU_U16) == 2);
constexpr JLU_U16 JLU_U16_MAX = 0xFFFF; /* 65,535 */

typedef unsigned JLU_U32;
static_assert(sizeof(JLU_U32) == 4);
constexpr JLU_U32 JLU_U32_MAX = 0xFFFF'FFFF; /* 4,294,967,295 */

typedef unsigned long long JLU_U64;
static_assert(sizeof(JLU_U64) == 8);
constexpr JLU_U64 JLU_U64_MAX = 0xFFFF'FFFF'FFFF'FFFF; /* 18,446,744,073,709,551,615 */

#endif  // JLU_INT_TYPES_H

#if defined(JLU_WITHOUT_PREFIX) && !defined(JLU_INT_TYPES_H_WITHOUT_PREFIX)
#define JLU_INT_TYPES_H_WITHOUT_PREFIX

typedef JLU_Byte Byte;

typedef JLU_C8 C8;
typedef JLU_C16 C16;

typedef JLU_S8 S8;
constexpr S8 S8_MIN = JLU_S8_MIN; /* -128 */
constexpr S8 S8_MAX = JLU_S8_MAX; /* 127 */

typedef JLU_S16 S16;
constexpr S16 S16_MIN = JLU_S16_MIN; /* -32,768 */
constexpr S16 S16_MAX = JLU_S16_MAX; /* 32,767 */

typedef JLU_S32 S32;
constexpr S32 S32_MIN = JLU_S32_MIN; /* -2,147,483,648 */
constexpr S32 S32_MAX = JLU_S32_MAX; /* 2,147,483,647 */

typedef JLU_S64 S64;
constexpr S64 S64_MIN = JLU_S64_MIN; /* -9,223,372,036,854,775,808 */
constexpr S64 S64_MAX = JLU_S64_MAX; /* 9,223,372,036,854,775,807 */

typedef JLU_U8 U8;
constexpr U8 U8_MAX = JLU_U8_MAX; /* 255 */

typedef JLU_U16 U16;
constexpr U16 U16_MAX = JLU_U16_MAX; /* 65,535 */

typedef JLU_U32 U32;
constexpr U32 U32_MAX = JLU_U32_MAX; /* 4,294,967,295 */

typedef JLU_U64 U64;
constexpr U64 U64_MAX = JLU_U64_MAX; /* 18,446,744,073,709,551,615 */

#endif  // JLU_INT_TYPES_H_WITHOUT_PREFIX