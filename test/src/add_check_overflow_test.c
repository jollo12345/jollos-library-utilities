#include <unity.h>

#define JLU_WITHOUT_PREFIX
#include "jlu/add_check_overflow.h"

static void add_check_overflow_uint8_test_1() {
    Uint8 result;
    TEST_ASSERT_TRUE(addCheckOverflow((Uint8)12u, (Uint8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8(result, (Uint8)24u);
}

static void add_check_overflow_uint8_test_2() {
    Uint8 result;
    TEST_ASSERT_FALSE(addCheckOverflow((Uint8)UINT8_MAX, (Uint8)1u, &result));
    TEST_ASSERT_EQUAL_UINT8(result, (Uint8)0u);
}

static void add_check_overflow_uint16_test_1() {
    Uint16 result;
    TEST_ASSERT_TRUE(addCheckOverflow((Uint16)12u, (Uint16)12u, &result));
    TEST_ASSERT_EQUAL_UINT16(result, (Uint16)24u);
}

static void add_check_overflow_uint16_test_2() {
    Uint16 result;
    TEST_ASSERT_FALSE(addCheckOverflow((Uint16)UINT16_MAX, (Uint16)1u, &result));
    TEST_ASSERT_EQUAL_UINT16(result, (Uint16)0u);
}

static void add_check_overflow_uint32_test_1() {
    Uint32 result;
    TEST_ASSERT_TRUE(addCheckOverflow((Uint32)12u, (Uint32)12u, &result));
    TEST_ASSERT_EQUAL_UINT32(result, (Uint32)24u);
}

static void add_check_overflow_uint32_test_2() {
    Uint32 result;
    TEST_ASSERT_FALSE(addCheckOverflow((Uint32)UINT32_MAX, (Uint32)1u, &result));
    TEST_ASSERT_EQUAL_UINT32(result, (Uint32)0u);
}

static void add_check_overflow_uint64_test_1() {
    Uint64 result;
    TEST_ASSERT_TRUE(addCheckOverflow((Uint64)12u, (Uint64)12u, &result));
    TEST_ASSERT_EQUAL_UINT64(result, (Uint64)24u);
}

static void add_check_overflow_uint64_test_2() {
    Uint64 result;
    TEST_ASSERT_FALSE(addCheckOverflow((Uint64)UINT64_MAX, (Uint64)1u, &result));
    TEST_ASSERT_EQUAL_UINT64(result, (Uint64)0u);
}

void setUp() {}

void tearDown() {}

int main(int argc, char* argv[]) {
    UNITY_BEGIN();

    RUN_TEST(add_check_overflow_uint8_test_1);
    RUN_TEST(add_check_overflow_uint8_test_2);

    RUN_TEST(add_check_overflow_uint16_test_1);
    RUN_TEST(add_check_overflow_uint16_test_2);

    RUN_TEST(add_check_overflow_uint32_test_1);
    RUN_TEST(add_check_overflow_uint32_test_2);

    RUN_TEST(add_check_overflow_uint64_test_1);
    RUN_TEST(add_check_overflow_uint64_test_2);

    return UNITY_END();
}