#ifndef STATS_H
#define STATS_H

#include <stdio.h>

/**
 * @brief Prints the statistics of an array (mean, median, max, min)
 * @param array Pointer to data array
 * @param length Size of array
 */
void print_statistics(unsigned char *array, unsigned int length);

/**
 * @brief Prints the array
 * @param array Pointer to data array
 * @param length Size of array
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest
 * @param array Pointer to data array
 * @param length Size of array
 */
void sort_array(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median value
 * @param array Pointer to data array
 * @param length Size of array
 * @return median value
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief Finds the mean value
 * @param array Pointer to data array
 * @param length Size of array
 * @return mean value
 */
unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Finds the maximum value
 * @param array Pointer to data array
 * @param length Size of array
 * @return max value
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum value
 * @param array Pointer to data array
 * @param length Size of array
 * @return min value
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

#endif