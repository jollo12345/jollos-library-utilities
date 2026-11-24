#include <unity.h>

#define WITHOUT_PREFIX
#include "jlu/add_check_overflow.h"

static void add_check_overflow_sint8_test_1(void) {
    I8 result;
    TEST_ASSERT_TRUE(addCheckOverflow((I8)12, (I8)12, &result));
    TEST_ASSERT_EQUAL_INT8((I8)24, result);
}

static void add_check_overflow_sint8_test_2(void) {
    I8 result;
    TEST_ASSERT_TRUE(addCheckOverflow(I8_MAX, (I8)0, &result));
    TEST_ASSERT_EQUAL_INT8(I8_MAX, result);
}

static void add_check_overflow_sint8_test_3(void) {
    I8 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I8_MAX, (I8)1, &result));
    TEST_ASSERT_EQUAL_INT8(I8_MIN, result);
}

static void add_check_overflow_sint8_test_4(void) {
    I8 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I8_MIN, (I8)-1, &result));
    TEST_ASSERT_EQUAL_INT8(I8_MAX, result);
}

static void add_check_overflow_sint8_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((I8)12, (I8)12));
    TEST_ASSERT_TRUE(addCheckOverflow(I8_MAX, I8_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(I8_MAX, (I8)1));
    TEST_ASSERT_FALSE(addCheckOverflow(I8_MIN, (I8)-1));
}

static void add_check_overflow_sint16_test_1(void) {
    I16 result;
    TEST_ASSERT_TRUE(addCheckOverflow((I16)12, (I16)12, &result));
    TEST_ASSERT_EQUAL_INT16((I16)24, result);
}

static void add_check_overflow_sint16_test_2(void) {
    I16 result;
    TEST_ASSERT_TRUE(addCheckOverflow(I16_MAX, (I16)0, &result));
    TEST_ASSERT_EQUAL_INT16(I16_MAX, result);
}

static void add_check_overflow_sint16_test_3(void) {
    I16 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I16_MAX, (I16)1, &result));
    TEST_ASSERT_EQUAL_INT16(I16_MIN, result);
}

static void add_check_overflow_sint16_test_4(void) {
    I16 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I16_MIN, (I16)-1, &result));
    TEST_ASSERT_EQUAL_INT16(I16_MAX, result);
}

static void add_check_overflow_sint16_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((I16)12, (I16)12));
    TEST_ASSERT_TRUE(addCheckOverflow(I16_MAX, I16_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(I16_MAX, (I16)1));
    TEST_ASSERT_FALSE(addCheckOverflow(I16_MIN, (I16)-1));
}

static void add_check_overflow_sint32_test_1(void) {
    I32 result;
    TEST_ASSERT_TRUE(addCheckOverflow((I32)12, (I32)12, &result));
    TEST_ASSERT_EQUAL_INT32((I32)24, result);
}

static void add_check_overflow_sint32_test_2(void) {
    I32 result;
    TEST_ASSERT_TRUE(addCheckOverflow(I32_MAX, (I32)0, &result));
    TEST_ASSERT_EQUAL_INT32(I32_MAX, result);
}

static void add_check_overflow_sint32_test_3(void) {
    I32 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I32_MAX, (I32)1, &result));
    TEST_ASSERT_EQUAL_INT32(I32_MIN, result);
}

static void add_check_overflow_sint32_test_4(void) {
    I32 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I32_MIN, (I32)-1, &result));
    TEST_ASSERT_EQUAL_INT32(I32_MAX, result);
}

static void add_check_overflow_sint32_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((I32)12, (I32)12));
    TEST_ASSERT_TRUE(addCheckOverflow(I32_MAX, I32_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(I32_MAX, (I32)1));
    TEST_ASSERT_FALSE(addCheckOverflow(I32_MIN, (I32)-1));
}

static void add_check_overflow_sint64_test_1(void) {
    I64 result;
    TEST_ASSERT_TRUE(addCheckOverflow((I64)12, (I64)12, &result));
    TEST_ASSERT_EQUAL_INT64((I64)24, result);
}

static void add_check_overflow_sint64_test_2(void) {
    I64 result;
    TEST_ASSERT_TRUE(addCheckOverflow(I64_MAX, (I64)0, &result));
    TEST_ASSERT_EQUAL_INT64(I64_MAX, result);
}

static void add_check_overflow_sint64_test_3(void) {
    I64 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I64_MAX, (I64)1, &result));
    TEST_ASSERT_EQUAL_INT64(I64_MIN, result);
}

static void add_check_overflow_sint64_test_4(void) {
    I64 result;
    TEST_ASSERT_FALSE(addCheckOverflow(I64_MIN, (I64)-1, &result));
    TEST_ASSERT_EQUAL_INT64(I64_MAX, result);
}

static void add_check_overflow_sint64_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((I64)12, (I64)12));
    TEST_ASSERT_TRUE(addCheckOverflow(I64_MAX, I64_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(I64_MAX, (I64)1));
    TEST_ASSERT_FALSE(addCheckOverflow(I64_MIN, (I64)-1));
}

static void add_check_overflow_uint8_test_1(void) {
    U8 result;
    TEST_ASSERT_TRUE(addCheckOverflow((U8)12u, (U8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8(result, (U8)24u);
}

static void add_check_overflow_uint8_test_2(void) {
    U8 result;
    TEST_ASSERT_FALSE(addCheckOverflow(U8_MAX, (U8)1u, &result));
    TEST_ASSERT_EQUAL_UINT8(result, (U8)0u);
}

static void add_check_overflow_uint8_test_3(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((U8)12u, (U8)12u));
    TEST_ASSERT_FALSE(addCheckOverflow(U8_MAX, (U8)1u));
}

static void add_check_overflow_uint16_test_1(void) {
    U16 result;
    TEST_ASSERT_TRUE(addCheckOverflow((U16)12u, (U16)12u, &result));
    TEST_ASSERT_EQUAL_UINT16(result, (U16)24u);
}

static void add_check_overflow_uint16_test_2(void) {
    U16 result;
    TEST_ASSERT_FALSE(addCheckOverflow(U16_MAX, (U16)1u, &result));
    TEST_ASSERT_EQUAL_UINT16(result, (U16)0u);
}

static void add_check_overflow_uint16_test_3(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((U16)12u, (U16)12u));
    TEST_ASSERT_FALSE(addCheckOverflow(U16_MAX, (U16)1u));
}

static void add_check_overflow_uint32_test_1(void) {
    U32 result;
    TEST_ASSERT_TRUE(addCheckOverflow((U32)12u, (U32)12u, &result));
    TEST_ASSERT_EQUAL_UINT32(result, (U32)24u);
}

static void add_check_overflow_uint32_test_2(void) {
    U32 result;
    TEST_ASSERT_FALSE(addCheckOverflow(U32_MAX, (U32)1u, &result));
    TEST_ASSERT_EQUAL_UINT32(result, (U32)0u);
}

static void add_check_overflow_uint32_test_3(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((U32)12u, (U32)12u));
    TEST_ASSERT_FALSE(addCheckOverflow(U32_MAX, (U32)1u));
}

static void add_check_overflow_uint64_test_1(void) {
    U64 result;
    TEST_ASSERT_TRUE(addCheckOverflow((U64)12u, (U64)12u, &result));
    TEST_ASSERT_EQUAL_UINT64(result, (U64)24u);
}

static void add_check_overflow_uint64_test_2(void) {
    U64 result;
    TEST_ASSERT_FALSE(addCheckOverflow(U64_MAX, (U64)1u, &result));
    TEST_ASSERT_EQUAL_UINT64(result, (U64)0u);
}

static void add_check_overflow_uint64_test_3(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((U64)12u, (U64)12u));
    TEST_ASSERT_FALSE(addCheckOverflow(U64_MAX, (U64)1u));
}

void setUp(void) {}

void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(add_check_overflow_sint8_test_1);
    RUN_TEST(add_check_overflow_sint8_test_2);
    RUN_TEST(add_check_overflow_sint8_test_3);
    RUN_TEST(add_check_overflow_sint8_test_4);
    RUN_TEST(add_check_overflow_sint8_test_5);

    RUN_TEST(add_check_overflow_sint16_test_1);
    RUN_TEST(add_check_overflow_sint16_test_2);
    RUN_TEST(add_check_overflow_sint16_test_3);
    RUN_TEST(add_check_overflow_sint16_test_4);
    RUN_TEST(add_check_overflow_sint16_test_5);

    RUN_TEST(add_check_overflow_sint32_test_1);
    RUN_TEST(add_check_overflow_sint32_test_2);
    RUN_TEST(add_check_overflow_sint32_test_3);
    RUN_TEST(add_check_overflow_sint32_test_4);
    RUN_TEST(add_check_overflow_sint32_test_5);

    RUN_TEST(add_check_overflow_sint64_test_1);
    RUN_TEST(add_check_overflow_sint64_test_2);
    RUN_TEST(add_check_overflow_sint64_test_3);
    RUN_TEST(add_check_overflow_sint64_test_4);
    RUN_TEST(add_check_overflow_sint64_test_5);

    RUN_TEST(add_check_overflow_uint8_test_1);
    RUN_TEST(add_check_overflow_uint8_test_2);
    RUN_TEST(add_check_overflow_uint8_test_3);

    RUN_TEST(add_check_overflow_uint16_test_1);
    RUN_TEST(add_check_overflow_uint16_test_2);
    RUN_TEST(add_check_overflow_uint16_test_3);

    RUN_TEST(add_check_overflow_uint32_test_1);
    RUN_TEST(add_check_overflow_uint32_test_2);
    RUN_TEST(add_check_overflow_uint32_test_3);

    RUN_TEST(add_check_overflow_uint64_test_1);
    RUN_TEST(add_check_overflow_uint64_test_2);
    RUN_TEST(add_check_overflow_uint64_test_3);

    return UNITY_END();
}