/**
 * @file    course1.h
 * @brief   Declarations for Course 1 final assessment test functions
 *
 * @author  Choden
 * @date     MAy 10, 2026
 *
 * These functions exercise every major deliverable from Course 1:
 * data conversion, memory manipulation, and array operations.
 * Each test returns 0 on success and a negative code on failure.
 */

#ifndef __COURSE1_H__
#define __COURSE1_H__

#include <stdint.h>

/**
 * @brief  Top-level course 1 assessment entry point
 *         Calls all sub-tests below exactly once.
 * @return 0 on overall success, negative on any sub-test failure
 */
int8_t course1(void);

/** @brief Test my_itoa / my_atoi (data set 1) */
int8_t test_data1(void);

/** @brief Test my_itoa / my_atoi (data set 2) */
int8_t test_data2(void);

/** @brief Test my_memmove with non-overlapping regions */
int8_t test_memmove1(void);

/** @brief Test my_memmove where end of dst overlaps start of src */
int8_t test_memmove2(void);

/** @brief Test my_memmove where start of dst overlaps end of src */
int8_t test_memmove3(void);

/** @brief Test my_memcopy */
int8_t test_memcopy(void);

/** @brief Test my_memset and my_memzero */
int8_t test_memset(void);

/** @brief Test my_reverse */
int8_t test_reverse(void);

#endif /* __COURSE1_H__ */
