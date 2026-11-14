#include <unity.h>

#define JLU_WITHOUT_PREFIX
#include "jlu/mul_check_overflow.h"

static void mul_check_overflow_uint8_test_1() {
    Uint8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint8)12u, (Uint8)12u, &result));
    TEST_ASSERT_EQUAL_UINT8((Uint8)144u, result);
}

static void mul_check_overflow_uint8_test_2() {
    Uint8 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((Uint8)(UINT8_MAX / 2 + 1), (Uint8)2u, &result));
    TEST_ASSERT_EQUAL_UINT8((Uint8)0u, result);
}

static void mul_check_overflow_uint8_test_3() {
    Uint8 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint8)UINT8_MAX, (Uint8)0u, &result));
    TEST_ASSERT_EQUAL_UINT8((Uint8)0u, result);
}

static void mul_check_overflow_uint16_test_1() {
    Uint16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint16)200u, (Uint16)200u, &result));
    TEST_ASSERT_EQUAL_UINT16((Uint16)40000u, result);
}

static void mul_check_overflow_uint16_test_2() {
    Uint16 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((Uint16)(UINT16_MAX / 2 + 1), (Uint16)2u, &result));
    TEST_ASSERT_EQUAL_UINT16((Uint16)0u, result);
}

static void mul_check_overflow_uint16_test_3() {
    Uint16 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint16)UINT16_MAX, (Uint16)0u, &result));
    TEST_ASSERT_EQUAL_UINT16((Uint16)0u, result);
}

static void mul_check_overflow_uint32_test_1() {
    Uint32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint32)50000u, (Uint32)50000u, &result));
    TEST_ASSERT_EQUAL_UINT32((Uint32)2500000000u, result);
}

static void mul_check_overflow_uint32_test_2() {
    Uint32 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((Uint32)(UINT32_MAX / 2 + 1), (Uint32)2u, &result));
    TEST_ASSERT_EQUAL_UINT32((Uint32)0u, result);
}

static void mul_check_overflow_uint32_test_3() {
    Uint32 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint32)UINT32_MAX, (Uint32)0u, &result));
    TEST_ASSERT_EQUAL_UINT32((Uint32)0u, result);
}

static void mul_check_overflow_uint64_test_1() {
    Uint64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint64)3000000000u, (Uint64)3000000000u, &result));
    TEST_ASSERT_EQUAL_UINT64((Uint64)9000000000000000000u, result);
}

static void mul_check_overflow_uint64_test_2() {
    Uint64 result;
    TEST_ASSERT_FALSE(mulCheckOverflow((Uint64)(UINT64_MAX / 2 + 1), (Uint64)2u, &result));
    TEST_ASSERT_EQUAL_UINT64((Uint64)0u, result);
}

static void mul_check_overflow_uint64_test_3() {
    Uint64 result;
    TEST_ASSERT_TRUE(mulCheckOverflow((Uint64)UINT64_MAX, (Uint64)0u, &result));
    TEST_ASSERT_EQUAL_UINT64((Uint64)0u, result);
}

void setUp() {}

void tearDown() {}

int main(int argc, char* argv[]) {
    UNITY_BEGIN();

    RUN_TEST(mul_check_overflow_uint8_test_1);
    RUN_TEST(mul_check_overflow_uint8_test_2);
    RUN_TEST(mul_check_overflow_uint8_test_3);

    RUN_TEST(mul_check_overflow_uint16_test_1);
    RUN_TEST(mul_check_overflow_uint16_test_2);
    RUN_TEST(mul_check_overflow_uint16_test_3);

    RUN_TEST(mul_check_overflow_uint32_test_1);
    RUN_TEST(mul_check_overflow_uint32_test_2);
    RUN_TEST(mul_check_overflow_uint32_test_3);

    RUN_TEST(mul_check_overflow_uint64_test_1);
    RUN_TEST(mul_check_overflow_uint64_test_2);
    RUN_TEST(mul_check_overflow_uint64_test_3);

    return UNITY_END();
}