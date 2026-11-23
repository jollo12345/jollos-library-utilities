#include <unity.h>

#define WITHOUT_PREFIX
#include "jlu/sub_check_overflow.h"

static void sub_check_underflow_sint8_test_1(void) {
    S8 result;
    TEST_ASSERT_TRUE(subCheckOverflow((S8)24, (S8)12, &result));
    TEST_ASSERT_EQUAL_INT8((S8)12, result);
}

static void sub_check_underflow_sint8_test_2(void) {
    S8 result;
    TEST_ASSERT_TRUE(subCheckOverflow(S8_MAX, (S8)0, &result));
    TEST_ASSERT_EQUAL_INT8(S8_MAX, result);
}

static void sub_check_underflow_sint8_test_3(void) {
    S8 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S8_MIN, (S8)1, &result));
    TEST_ASSERT_EQUAL_INT8(S8_MAX, result);
}

static void sub_check_underflow_sint8_test_4(void) {
    S8 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S8_MAX, (S8)-1, &result));
    TEST_ASSERT_EQUAL_INT8(S8_MIN, result);
}

static void sub_check_underflow_sint8_test_5(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((S8)24, (S8)12));
    TEST_ASSERT_TRUE(subCheckOverflow(S8_MAX, (S8)0));
    TEST_ASSERT_FALSE(subCheckOverflow(S8_MIN, (S8)1));
    TEST_ASSERT_FALSE(subCheckOverflow(S8_MAX, (S8)-1));
}

static void sub_check_underflow_sint16_test_1(void) {
    S16 result;
    TEST_ASSERT_TRUE(subCheckOverflow((S16)24, (S16)12, &result));
    TEST_ASSERT_EQUAL_INT16((S16)12, result);
}

static void sub_check_underflow_sint16_test_2(void) {
    S16 result;
    TEST_ASSERT_TRUE(subCheckOverflow(S16_MAX, (S16)0, &result));
    TEST_ASSERT_EQUAL_INT16(S16_MAX, result);
}

static void sub_check_underflow_sint16_test_3(void) {
    S16 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S16_MIN, (S16)1, &result));
    TEST_ASSERT_EQUAL_INT16(S16_MAX, result);
}

static void sub_check_underflow_sint16_test_4(void) {
    S16 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S16_MAX, (S16)-1, &result));
    TEST_ASSERT_EQUAL_INT16(S16_MIN, result);
}

static void sub_check_underflow_sint16_test_5(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((S16)24, (S16)12));
    TEST_ASSERT_TRUE(subCheckOverflow(S16_MAX, (S16)0));
    TEST_ASSERT_FALSE(subCheckOverflow(S16_MIN, (S16)1));
    TEST_ASSERT_FALSE(subCheckOverflow(S16_MAX, (S16)-1));
}

static void sub_check_underflow_sint32_test_1(void) {
    S32 result;
    TEST_ASSERT_TRUE(subCheckOverflow((S32)24, (S32)12, &result));
    TEST_ASSERT_EQUAL_INT32((S32)12, result);
}

static void sub_check_underflow_sint32_test_2(void) {
    S32 result;
    TEST_ASSERT_TRUE(subCheckOverflow(S32_MAX, (S32)0, &result));
    TEST_ASSERT_EQUAL_INT32(S32_MAX, result);
}

static void sub_check_underflow_sint32_test_3(void) {
    S32 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S32_MIN, (S32)1, &result));
    TEST_ASSERT_EQUAL_INT32(S32_MAX, result);
}

static void sub_check_underflow_sint32_test_4(void) {
    S32 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S32_MAX, (S32)-1, &result));
    TEST_ASSERT_EQUAL_INT32(S32_MIN, result);
}

static void sub_check_underflow_sint32_test_5(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((S32)24, (S32)12));
    TEST_ASSERT_TRUE(subCheckOverflow(S32_MAX, (S32)0));
    TEST_ASSERT_FALSE(subCheckOverflow(S32_MIN, (S32)1));
    TEST_ASSERT_FALSE(subCheckOverflow(S32_MAX, (S32)-1));
}

static void sub_check_underflow_sint64_test_1(void) {
    S64 result;
    TEST_ASSERT_TRUE(subCheckOverflow((S64)24, (S64)12, &result));
    TEST_ASSERT_EQUAL_INT64((S64)12, result);
}

static void sub_check_underflow_sint64_test_2(void) {
    S64 result;
    TEST_ASSERT_TRUE(subCheckOverflow(S64_MAX, (S64)0, &result));
    TEST_ASSERT_EQUAL_INT64(S64_MAX, result);
}

static void sub_check_underflow_sint64_test_3(void) {
    S64 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S64_MIN, (S64)1, &result));
    TEST_ASSERT_EQUAL_INT64(S64_MAX, result);
}

static void sub_check_underflow_sint64_test_4(void) {
    S64 result;
    TEST_ASSERT_FALSE(subCheckOverflow(S64_MAX, (S64)-1, &result));
    TEST_ASSERT_EQUAL_INT64(S64_MIN, result);
}

static void sub_check_underflow_sint64_test_5(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((S64)24, (S64)12));
    TEST_ASSERT_TRUE(subCheckOverflow(S64_MAX, (S64)0));
    TEST_ASSERT_FALSE(subCheckOverflow(S64_MIN, (S64)1));
    TEST_ASSERT_FALSE(subCheckOverflow(S64_MAX, (S64)-1));
}

static void sub_check_underflow_uint8_test_1(void) {
    U8 result;
    TEST_ASSERT_TRUE(subCheckOverflow((U8)24u, (U8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)12u, result);
}

static void sub_check_underflow_uint8_test_2(void) {
    U8 result;
    TEST_ASSERT_FALSE(subCheckOverflow((U8)0u, (U8)1u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)UINT8_MAX, result);
}

static void sub_check_underflow_uint8_test_3(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((U8)24u, (U8)12u));
    TEST_ASSERT_FALSE(subCheckOverflow((U8)0u, (U8)1u));
}

static void sub_check_underflow_uint16_test_1(void) {
    U16 result;
    TEST_ASSERT_TRUE(subCheckOverflow((U16)24u, (U16)12u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)12u, result);
}

static void sub_check_underflow_uint16_test_2(void) {
    U16 result;
    TEST_ASSERT_FALSE(subCheckOverflow((U16)0u, (U16)1u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)UINT16_MAX, result);
}

static void sub_check_underflow_uint16_test_3(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((U16)24u, (U16)12u));
    TEST_ASSERT_FALSE(subCheckOverflow((U16)0u, (U16)1u));
}

static void sub_check_underflow_uint32_test_1(void) {
    U32 result;
    TEST_ASSERT_TRUE(subCheckOverflow((U32)24u, (U32)12u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)12u, result);
}

static void sub_check_underflow_uint32_test_2(void) {
    U32 result;
    TEST_ASSERT_FALSE(subCheckOverflow((U32)0u, (U32)1u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)UINT32_MAX, result);
}

static void sub_check_underflow_uint32_test_3(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((U32)24u, (U32)12u));
    TEST_ASSERT_FALSE(subCheckOverflow((U32)0u, (U32)1u));
}

static void sub_check_underflow_uint64_test_1(void) {
    U64 result;
    TEST_ASSERT_TRUE(subCheckOverflow((U64)24u, (U64)12u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)12u, result);
}

static void sub_check_underflow_uint64_test_2(void) {
    U64 result;
    TEST_ASSERT_FALSE(subCheckOverflow((U64)0u, (U64)1u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)UINT64_MAX, result);
}

static void sub_check_underflow_uint64_test_3(void) {
    TEST_ASSERT_TRUE(subCheckOverflow((U64)24u, (U64)12u));
    TEST_ASSERT_FALSE(subCheckOverflow((U64)0u, (U64)1u));
}

void setUp(void) {}

void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

    RUN_TEST(sub_check_underflow_sint8_test_1);
    RUN_TEST(sub_check_underflow_sint8_test_2);
    RUN_TEST(sub_check_underflow_sint8_test_3);
    RUN_TEST(sub_check_underflow_sint8_test_4);
    RUN_TEST(sub_check_underflow_sint8_test_5);

    RUN_TEST(sub_check_underflow_sint16_test_1);
    RUN_TEST(sub_check_underflow_sint16_test_2);
    RUN_TEST(sub_check_underflow_sint16_test_3);
    RUN_TEST(sub_check_underflow_sint16_test_4);
    RUN_TEST(sub_check_underflow_sint16_test_5);

    RUN_TEST(sub_check_underflow_sint32_test_1);
    RUN_TEST(sub_check_underflow_sint32_test_2);
    RUN_TEST(sub_check_underflow_sint32_test_3);
    RUN_TEST(sub_check_underflow_sint32_test_4);
    RUN_TEST(sub_check_underflow_sint32_test_5);

    RUN_TEST(sub_check_underflow_sint64_test_1);
    RUN_TEST(sub_check_underflow_sint64_test_2);
    RUN_TEST(sub_check_underflow_sint64_test_3);
    RUN_TEST(sub_check_underflow_sint64_test_4);
    RUN_TEST(sub_check_underflow_sint64_test_5);

    RUN_TEST(sub_check_underflow_uint8_test_1);
    RUN_TEST(sub_check_underflow_uint8_test_2);
    RUN_TEST(sub_check_underflow_uint8_test_3);

    RUN_TEST(sub_check_underflow_uint16_test_1);
    RUN_TEST(sub_check_underflow_uint16_test_2);
    RUN_TEST(sub_check_underflow_uint16_test_3);

    RUN_TEST(sub_check_underflow_uint32_test_1);
    RUN_TEST(sub_check_underflow_uint32_test_2);
    RUN_TEST(sub_check_underflow_uint32_test_3);

    RUN_TEST(sub_check_underflow_uint64_test_1);
    RUN_TEST(sub_check_underflow_uint64_test_2);
    RUN_TEST(sub_check_underflow_uint64_test_3);

    return UNITY_END();
}