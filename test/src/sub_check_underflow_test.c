#include <unity.h>

#define JLU_WITHOUT_PREFIX
#include "jlu/sub_check_underflow.h"

static void sub_check_underflow_uint8_test_1() {
    Uint8 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((Uint8)24u, (Uint8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8((Uint8)12u, result);
}

static void sub_check_underflow_uint8_test_2() {
    Uint8 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((Uint8)0u, (Uint8)1u, &result));
    TEST_ASSERT_EQUAL_UINT8((Uint8)UINT8_MAX, result);
}

static void sub_check_underflow_uint16_test_1() {
    Uint16 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((Uint16)24u, (Uint16)12u, &result));
    TEST_ASSERT_EQUAL_UINT16((Uint16)12u, result);
}

static void sub_check_underflow_uint16_test_2() {
    Uint16 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((Uint16)0u, (Uint16)1u, &result));
    TEST_ASSERT_EQUAL_UINT16((Uint16)UINT16_MAX, result);
}

static void sub_check_underflow_uint32_test_1() {
    Uint32 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((Uint32)24u, (Uint32)12u, &result));
    TEST_ASSERT_EQUAL_UINT32((Uint32)12u, result);
}

static void sub_check_underflow_uint32_test_2() {
    Uint32 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((Uint32)0u, (Uint32)1u, &result));
    TEST_ASSERT_EQUAL_UINT32((Uint32)UINT32_MAX, result);
}

static void sub_check_underflow_uint64_test_1() {
    Uint64 result;
    TEST_ASSERT_TRUE(subCheckUnderflow((Uint64)24u, (Uint64)12u, &result));
    TEST_ASSERT_EQUAL_UINT64((Uint64)12u, result);
}

static void sub_check_underflow_uint64_test_2() {
    Uint64 result;
    TEST_ASSERT_FALSE(subCheckUnderflow((Uint64)0u, (Uint64)1u, &result));
    TEST_ASSERT_EQUAL_UINT64((Uint64)UINT64_MAX, result);
}

void setUp() {}

void tearDown() {}

int main(int argc, char* argv[]) {
    UNITY_BEGIN();

    RUN_TEST(sub_check_underflow_uint8_test_1);
    RUN_TEST(sub_check_underflow_uint8_test_2);

    RUN_TEST(sub_check_underflow_uint16_test_1);
    RUN_TEST(sub_check_underflow_uint16_test_2);

    RUN_TEST(sub_check_underflow_uint32_test_1);
    RUN_TEST(sub_check_underflow_uint32_test_2);

    RUN_TEST(sub_check_underflow_uint64_test_1);
    RUN_TEST(sub_check_underflow_uint64_test_2);

    return UNITY_END();
}