/**
 * @file    stats.h
 * @brief   Declarations for array statistical analysis functions
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * Provides function declarations for computing minimum, maximum,
 * mean, median, sorting, and printing of a uint8_t data array.
 */

#ifndef __STATS_H__
#define __STATS_H__

#include <stdint.h>

/**
 * @brief  Print statistics (min, max, mean, median) of an array
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 */
void print_statistics(uint8_t *arr, uint32_t length);

/**
 * @brief  Print the elements of an array (controlled by VERBOSE flag)
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 */
void print_array(uint8_t *arr, uint32_t length);

/**
 * @brief  Return the median value of an array
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 * @return         Median value as uint8_t
 */
uint8_t find_median(uint8_t *arr, uint32_t length);

/**
 * @brief  Return the mean (average) of an array
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 * @return         Mean value as uint8_t
 */
uint8_t find_mean(uint8_t *arr, uint32_t length);

/**
 * @brief  Return the maximum value in an array
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 * @return         Maximum value as uint8_t
 */
uint8_t find_maximum(uint8_t *arr, uint32_t length);

/**
 * @brief  Return the minimum value in an array
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 * @return         Minimum value as uint8_t
 */
uint8_t find_minimum(uint8_t *arr, uint32_t length);

/**
 * @brief  Sort an array from largest to smallest
 * @param  arr     Pointer to the data array
 * @param  length  Number of elements in the array
 */
void sort_array(uint8_t *arr, uint32_t length);

#endif /* __STATS_H__ */
