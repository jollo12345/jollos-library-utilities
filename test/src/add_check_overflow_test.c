#include <unity.h>

#define WITHOUT_PREFIX
#include "jlu/add_check_overflow.h"

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