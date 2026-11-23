#ifndef JLU_FLOAT_TYPES_H
#define JLU_FLOAT_TYPES_H

#ifndef __STDC_IEC_60559_BFP__
#error Float type not supported.
#endif

typedef float JLU_F32;
static_assert(sizeof(JLU_F32) == 4);
constexpr JLU_F32 JLU_F32_MIN = 0x1p-126f;        /* 1.17549435e-38 */
constexpr JLU_F32 JLU_F32_MAX = 0x1.fffffep+127f; /* 3.40282347e+38 */

typedef double JLU_F64;
static_assert(sizeof(JLU_F64) == 8);
constexpr JLU_F64 JLU_F64_MIN = 0x1p-1022;               /* 2.2250738585072014e-308 */
constexpr JLU_F64 JLU_F64_MAX = 0x1.fffffffffffffp+1023; /* 1.7976931348623157e+308 */

#endif  // JLU_FLOAT_TYPES_H

#if defined(WITHOUT_PREFIX) && !defined(JLU_FLOAT_TYPES_H_WITHOUT_PREFIX)
#define JLU_FLOAT_TYPES_H_WITHOUT_PREFIX

typedef JLU_F32 F32;
constexpr F32 F32_MIN = JLU_F32_MIN; /* 1.17549435e-38 */
constexpr F32 F32_MAX = JLU_F32_MAX; /* 3.40282347e+38 */

typedef JLU_F64 F64;
constexpr F64 F64_MIN = JLU_F64_MIN; /* 2.2250738585072014e-308 */
constexpr F64 F64_MAX = JLU_F64_MAX; /* 1.7976931348623157e+308 */

#endif  // JLU_FLOAT_TYPES_H_WITHOUT_PREFIX