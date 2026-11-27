#include <unity.h>

#define WITHOUT_PREFIX
#include "jlu/mul_check_overflow.h"

static void mul_check_overflow_sint8_test_1(void) {
    I8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I8)10, (I8)12, &result));
    TEST_ASSERT_EQUAL_INT8((I8)120, result);
}

static void mul_check_overflow_sint8_test_2(void) {
    I8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I8)(I8_MIN / 2), (I8)2, &result));
    TEST_ASSERT_EQUAL_INT8(I8_MIN, result);
}

static void mul_check_overflow_sint8_test_3(void) {
    I8 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I8)((I8_MAX / 2) + 1), (I8)2, &result));
    TEST_ASSERT_EQUAL_INT8(I8_MIN, result);
}

static void mul_check_overflow_sint8_test_4(void) {
    I8 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I8)((I8_MIN / 2) - 1), (I8)2, &result));
    TEST_ASSERT_EQUAL_INT8((I8)(I8_MAX - 1), result);
}

static void mul_check_overflow_sint8_test_5(void) {
    I8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I8)0, (I8)32, &result));
    TEST_ASSERT_EQUAL_INT8((I8)0, result);
}

static void mul_check_overflow_sint8_test_6(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((I8)10, (I8)12));
    TEST_ASSERT_TRUE(mulCheckOverflow((I8)(I8_MIN / 2), (I8)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I8)((I8_MAX / 2) + 1), (I8)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I8)((I8_MIN / 2) - 1), (I8)2));
    TEST_ASSERT_TRUE(mulCheckOverflow((I8)0, (I8)32));
}

static void mul_check_overflow_sint16_test_1(void) {
    I16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I16)100, (I16)100, &result));
    TEST_ASSERT_EQUAL_INT16((I16)10000, result);
}

static void mul_check_overflow_sint16_test_2(void) {
    I16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I16)(I16_MIN / 2), (I16)2, &result));
    TEST_ASSERT_EQUAL_INT16(I16_MIN, result);
}

static void mul_check_overflow_sint16_test_3(void) {
    I16 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I16)((I16_MAX / 2) + 1), (I16)2, &result));
    TEST_ASSERT_EQUAL_INT16(I16_MIN, result);
}

static void mul_check_overflow_sint16_test_4(void) {
    I16 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I16)((I16_MIN / 2) - 1), (I16)2, &result));
    TEST_ASSERT_EQUAL_INT16((I16)(I16_MAX - 1), result);
}

static void mul_check_overflow_sint16_test_5(void) {
    I16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I16)0, (I16)32, &result));
    TEST_ASSERT_EQUAL_INT16((I16)0, result);
}

static void mul_check_overflow_sint16_test_6(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((I16)100, (I16)100));
    TEST_ASSERT_TRUE(mulCheckOverflow((I16)(I16_MIN / 2), (I16)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I16)((I16_MAX / 2) + 1), (I16)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I16)((I16_MIN / 2) - 1), (I16)2));
    TEST_ASSERT_TRUE(mulCheckOverflow((I16)0, (I16)32));
}

static void mul_check_overflow_sint32_test_1(void) {
    I32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I32)40000, (I32)40000, &result));
    TEST_ASSERT_EQUAL_INT32((I32)1600000000, result);
}

static void mul_check_overflow_sint32_test_2(void) {
    I32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I32)(I32_MIN / 2), (I32)2, &result));
    TEST_ASSERT_EQUAL_INT32(I32_MIN, result);
}

static void mul_check_overflow_sint32_test_3(void) {
    I32 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I32)((I32_MAX / 2) + 1), (I32)2, &result));
    TEST_ASSERT_EQUAL_INT32(I32_MIN, result);
}

static void mul_check_overflow_sint32_test_4(void) {
    I32 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I32)((I32_MIN / 2) - 1), (I32)2, &result));
    TEST_ASSERT_EQUAL_INT32((I32)(I32_MAX - 1), result);
}

static void mul_check_overflow_sint32_test_5(void) {
    I32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I32)0, (I32)32, &result));
    TEST_ASSERT_EQUAL_INT32((I32)0, result);
}

static void mul_check_overflow_sint32_test_6(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((I32)40000, (I32)40000));
    TEST_ASSERT_TRUE(mulCheckOverflow((I32)(I32_MIN / 2), (I32)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I32)((I32_MAX / 2) + 1), (I32)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I32)((I32_MIN / 2) - 1), (I32)2));
    TEST_ASSERT_TRUE(mulCheckOverflow((I32)0, (I32)32));
}

static void mul_check_overflow_sint64_test_1(void) {
    I64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I64)3000000000, (I64)3000000000, &result));
    TEST_ASSERT_EQUAL_INT64((I64)9000000000000000000, result);
}

static void mul_check_overflow_sint64_test_2(void) {
    I64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I64)(I64_MIN / 2), (I64)2, &result));
    TEST_ASSERT_EQUAL_INT64(I64_MIN, result);
}

static void mul_check_overflow_sint64_test_3(void) {
    I64 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I64)((I64_MAX / 2) + 1), (I64)2, &result));
    TEST_ASSERT_EQUAL_INT64(I64_MIN, result);
}

static void mul_check_overflow_sint64_test_4(void) {
    I64 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((I64)((I64_MIN / 2) - 1), (I64)2, &result));
    TEST_ASSERT_EQUAL_INT64((I64)(I64_MAX - 1), result);
}

static void mul_check_overflow_sint64_test_5(void) {
    I64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((I64)0, (I64)32, &result));
    TEST_ASSERT_EQUAL_INT64((I64)0, result);
}

static void mul_check_overflow_sint64_test_6(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((I64)3000000000, (I64)3000000000));
    TEST_ASSERT_TRUE(mulCheckOverflow((I64)(I64_MIN / 2), (I64)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I64)((I64_MAX / 2) + 1), (I64)2));
    TEST_ASSERT_FALSE(mulCheckOverflow((I64)((I64_MIN / 2) - 1), (I64)2));
    TEST_ASSERT_TRUE(mulCheckOverflow((I64)0, (I64)32));
}

static void mul_check_overflow_uint8_test_1(void) {
    U8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U8)12u, (U8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)144u, result);
}

static void mul_check_overflow_uint8_test_2(void) {
    U8 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((U8)((U8_MAX / 2u) + 1u), (U8)2u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)0u, result);
}

static void mul_check_overflow_uint8_test_3(void) {
    U8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U8)0u, (U8)32u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)0u, result);
}

static void mul_check_overflow_uint8_test_4(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((U8)12u, (U8)12u));
    TEST_ASSERT_TRUE(mulCheckOverflow(U8_MAX, (U8)0u));
    TEST_ASSERT_TRUE(mulCheckOverflow(U8_MAX, (U8)0u));
}

static void mul_check_overflow_uint16_test_1(void) {
    U16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U16)200u, (U16)200u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)40000u, result);
}

static void mul_check_overflow_uint16_test_2(void) {
    U16 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((U16)((U16_MAX / 2u) + 1u), (U16)2u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)0u, result);
}

static void mul_check_overflow_uint16_test_3(void) {
    U16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U16)0u, (U16)32u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)0u, result);
}

static void mul_check_overflow_uint16_test_4(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((U16)200u, (U16)200u));
    TEST_ASSERT_FALSE(mulCheckOverflow((U16)((U16_MAX / 2u) + 1u), (U16)2u));
    TEST_ASSERT_TRUE(mulCheckOverflow(U16_MAX, (U16)0u));
}

static void mul_check_overflow_uint32_test_1(void) {
    U32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U32)50000u, (U32)50000u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)2500000000u, result);
}

static void mul_check_overflow_uint32_test_2(void) {
    U32 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((U32)((U32_MAX / 2u) + 1u), (U32)2u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)0u, result);
}

static void mul_check_overflow_uint32_test_3(void) {
    U32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U32)0u, (U32)32u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)0u, result);
}

static void mul_check_overflow_uint32_test_4(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((U32)50000u, (U32)50000));
    TEST_ASSERT_FALSE(mulCheckOverflow((U32)((U32_MAX / 2u) + 1u), (U32)2u));
    TEST_ASSERT_TRUE(mulCheckOverflow(U32_MAX, (U32)0u));
}

static void mul_check_overflow_uint64_test_1(void) {
    U64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U64)3000000000u, (U64)3000000000u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)9000000000000000000u, result);
}

static void mul_check_overflow_uint64_test_2(void) {
    U64 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((U64)((U64_MAX / 2u) + 1u), (U64)2u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)0u, result);
}

static void mul_check_overflow_uint64_test_3(void) {
    U64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((U64)0u, (U64)32u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)0u, result);
}

static void mul_check_overflow_uint64_test_4(void) {
    TEST_ASSERT_TRUE(mulCheckOverflow((U32)50000u, (U32)50000u));
    TEST_ASSERT_FALSE(mulCheckOverflow((U64)((U64_MAX / 2u) + 1u), (U64)2u));
    TEST_ASSERT_TRUE(mulCheckOverflow(U64_MAX, (U64)0u));
}

void setUp(void) {}

void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(mul_check_overflow_sint8_test_1);
    RUN_TEST(mul_check_overflow_sint8_test_2);
    RUN_TEST(mul_check_overflow_sint8_test_3);
    RUN_TEST(mul_check_overflow_sint8_test_4);
    RUN_TEST(mul_check_overflow_sint8_test_5);
    RUN_TEST(mul_check_overflow_sint8_test_6);

    RUN_TEST(mul_check_overflow_sint16_test_1);
    RUN_TEST(mul_check_overflow_sint16_test_2);
    RUN_TEST(mul_check_overflow_sint16_test_3);
    RUN_TEST(mul_check_overflow_sint16_test_4);
    RUN_TEST(mul_check_overflow_sint16_test_5);
    RUN_TEST(mul_check_overflow_sint16_test_6);

    RUN_TEST(mul_check_overflow_sint32_test_1);
    RUN_TEST(mul_check_overflow_sint32_test_2);
    RUN_TEST(mul_check_overflow_sint32_test_3);
    RUN_TEST(mul_check_overflow_sint32_test_4);
    RUN_TEST(mul_check_overflow_sint32_test_5);
    RUN_TEST(mul_check_overflow_sint32_test_6);

    RUN_TEST(mul_check_overflow_sint64_test_1);
    RUN_TEST(mul_check_overflow_sint64_test_2);
    RUN_TEST(mul_check_overflow_sint64_test_3);
    RUN_TEST(mul_check_overflow_sint64_test_4);
    RUN_TEST(mul_check_overflow_sint64_test_5);
    RUN_TEST(mul_check_overflow_sint64_test_6);

    RUN_TEST(mul_check_overflow_uint8_test_1);
    RUN_TEST(mul_check_overflow_uint8_test_2);
    RUN_TEST(mul_check_overflow_uint8_test_3);
    RUN_TEST(mul_check_overflow_uint8_test_4);

    RUN_TEST(mul_check_overflow_uint16_test_1);
    RUN_TEST(mul_check_overflow_uint16_test_2);
    RUN_TEST(mul_check_overflow_uint16_test_3);
    RUN_TEST(mul_check_overflow_uint16_test_4);

    RUN_TEST(mul_check_overflow_uint32_test_1);
    RUN_TEST(mul_check_overflow_uint32_test_2);
    RUN_TEST(mul_check_overflow_uint32_test_3);
    RUN_TEST(mul_check_overflow_uint32_test_4);

    RUN_TEST(mul_check_overflow_uint64_test_1);
    RUN_TEST(mul_check_overflow_uint64_test_2);
    RUN_TEST(mul_check_overflow_uint64_test_3);
    RUN_TEST(mul_check_overflow_uint64_test_4);

    return UNITY_END();
}