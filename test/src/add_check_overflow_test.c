#include <unity.h>

#define WITHOUT_PREFIX
#include "jlu/add_check_overflow.h"

static void add_check_overflow_sint8_test_1(void) {
    S8 result;
    TEST_ASSERT_TRUE(addCheckOverflow((S8)12, (S8)12, &result));
    TEST_ASSERT_EQUAL_INT8((S8)24, result);
}

static void add_check_overflow_sint8_test_2(void) {
    S8 result;
    TEST_ASSERT_TRUE(addCheckOverflow(S8_MAX, (S8)0, &result));
    TEST_ASSERT_EQUAL_INT8(S8_MAX, result);
}

static void add_check_overflow_sint8_test_3(void) {
    S8 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S8_MAX, (S8)1, &result));
    TEST_ASSERT_EQUAL_INT8(S8_MIN, result);
}

static void add_check_overflow_sint8_test_4(void) {
    S8 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S8_MIN, (S8)-1, &result));
    TEST_ASSERT_EQUAL_INT8(S8_MAX, result);
}

static void add_check_overflow_sint8_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((S8)12, (S8)12));
    TEST_ASSERT_TRUE(addCheckOverflow(S8_MAX, S8_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(S8_MAX, (S8)1));
    TEST_ASSERT_FALSE(addCheckOverflow(S8_MIN, (S8)-1));
}

static void add_check_overflow_sint16_test_1(void) {
    S16 result;
    TEST_ASSERT_TRUE(addCheckOverflow((S16)12, (S16)12, &result));
    TEST_ASSERT_EQUAL_INT16((S16)24, result);
}

static void add_check_overflow_sint16_test_2(void) {
    S16 result;
    TEST_ASSERT_TRUE(addCheckOverflow(S16_MAX, (S16)0, &result));
    TEST_ASSERT_EQUAL_INT16(S16_MAX, result);
}

static void add_check_overflow_sint16_test_3(void) {
    S16 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S16_MAX, (S16)1, &result));
    TEST_ASSERT_EQUAL_INT16(S16_MIN, result);
}

static void add_check_overflow_sint16_test_4(void) {
    S16 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S16_MIN, (S16)-1, &result));
    TEST_ASSERT_EQUAL_INT16(S16_MAX, result);
}

static void add_check_overflow_sint16_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((S16)12, (S16)12));
    TEST_ASSERT_TRUE(addCheckOverflow(S16_MAX, S16_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(S16_MAX, (S16)1));
    TEST_ASSERT_FALSE(addCheckOverflow(S16_MIN, (S16)-1));
}

static void add_check_overflow_sint32_test_1(void) {
    S32 result;
    TEST_ASSERT_TRUE(addCheckOverflow((S32)12, (S32)12, &result));
    TEST_ASSERT_EQUAL_INT32((S32)24, result);
}

static void add_check_overflow_sint32_test_2(void) {
    S32 result;
    TEST_ASSERT_TRUE(addCheckOverflow(S32_MAX, (S32)0, &result));
    TEST_ASSERT_EQUAL_INT32(S32_MAX, result);
}

static void add_check_overflow_sint32_test_3(void) {
    S32 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S32_MAX, (S32)1, &result));
    TEST_ASSERT_EQUAL_INT32(S32_MIN, result);
}

static void add_check_overflow_sint32_test_4(void) {
    S32 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S32_MIN, (S32)-1, &result));
    TEST_ASSERT_EQUAL_INT32(S32_MAX, result);
}

static void add_check_overflow_sint32_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((S32)12, (S32)12));
    TEST_ASSERT_TRUE(addCheckOverflow(S32_MAX, S32_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(S32_MAX, (S32)1));
    TEST_ASSERT_FALSE(addCheckOverflow(S32_MIN, (S32)-1));
}

static void add_check_overflow_sint64_test_1(void) {
    S64 result;
    TEST_ASSERT_TRUE(addCheckOverflow((S64)12, (S64)12, &result));
    TEST_ASSERT_EQUAL_INT64((S64)24, result);
}

static void add_check_overflow_sint64_test_2(void) {
    S64 result;
    TEST_ASSERT_TRUE(addCheckOverflow(S64_MAX, (S64)0, &result));
    TEST_ASSERT_EQUAL_INT64(S64_MAX, result);
}

static void add_check_overflow_sint64_test_3(void) {
    S64 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S64_MAX, (S64)1, &result));
    TEST_ASSERT_EQUAL_INT64(S64_MIN, result);
}

static void add_check_overflow_sint64_test_4(void) {
    S64 result;
    TEST_ASSERT_FALSE(addCheckOverflow(S64_MIN, (S64)-1, &result));
    TEST_ASSERT_EQUAL_INT64(S64_MAX, result);
}

static void add_check_overflow_sint64_test_5(void) {
    TEST_ASSERT_TRUE(addCheckOverflow((S64)12, (S64)12));
    TEST_ASSERT_TRUE(addCheckOverflow(S64_MAX, S64_MIN));
    TEST_ASSERT_FALSE(addCheckOverflow(S64_MAX, (S64)1));
    TEST_ASSERT_FALSE(addCheckOverflow(S64_MIN, (S64)-1));
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