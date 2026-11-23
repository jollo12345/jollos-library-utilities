#include <unity.h>

#define WITHOUT_PREFIX
#include "jlu/sub_check_underflow.h"

static void sub_check_underflow_uint8_test_1(void) {
    U8 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((U8)24u, (U8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)12u, result);
}

static void sub_check_underflow_uint8_test_2(void) {
    U8 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((U8)0u, (U8)1u, &result));
    TEST_ASSERT_EQUAL_UINT8((U8)UINT8_MAX, result);
}

static void sub_check_underflow_uint8_test_3(void) {
    TEST_ASSERT_TRUE(subCheckUnderflow((U8)24u, (U8)12u));
    TEST_ASSERT_FALSE(subCheckUnderflow((U8)0u, (U8)1u));
}

static void sub_check_underflow_uint16_test_1(void) {
    U16 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((U16)24u, (U16)12u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)12u, result);
}

static void sub_check_underflow_uint16_test_2(void) {
    U16 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((U16)0u, (U16)1u, &result));
    TEST_ASSERT_EQUAL_UINT16((U16)UINT16_MAX, result);
}

static void sub_check_underflow_uint16_test_3(void) {
    TEST_ASSERT_TRUE(subCheckUnderflow((U16)24u, (U16)12u));
    TEST_ASSERT_FALSE(subCheckUnderflow((U16)0u, (U16)1u));
}

static void sub_check_underflow_uint32_test_1(void) {
    U32 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((U32)24u, (U32)12u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)12u, result);
}

static void sub_check_underflow_uint32_test_2(void) {
    U32 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((U32)0u, (U32)1u, &result));
    TEST_ASSERT_EQUAL_UINT32((U32)UINT32_MAX, result);
}

static void sub_check_underflow_uint32_test_3(void) {
    TEST_ASSERT_TRUE(subCheckUnderflow((U32)24u, (U32)12u));
    TEST_ASSERT_FALSE(subCheckUnderflow((U32)0u, (U32)1u));
}

static void sub_check_underflow_uint64_test_1(void) {
    U64 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((U64)24u, (U64)12u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)12u, result);
}

static void sub_check_underflow_uint64_test_2(void) {
    U64 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((U64)0u, (U64)1u, &result));
    TEST_ASSERT_EQUAL_UINT64((U64)UINT64_MAX, result);
}

static void sub_check_underflow_uint64_test_3(void) {
    TEST_ASSERT_TRUE(subCheckUnderflow((U64)24u, (U64)12u));
    TEST_ASSERT_FALSE(subCheckUnderflow((U64)0u, (U64)1u));
}

void setUp(void) {}

void tearDown(void) {}

int main(void) {
    UNITY_BEGIN();

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