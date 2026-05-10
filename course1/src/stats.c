/**
 * @file    stats.c
 * @brief   Implementation of array statistical analysis functions
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * Provides min, max, mean, median, sort, and conditional print
 * operations for uint8_t arrays.  print_array() is guarded by
 * the VERBOSE compile-time switch; define -DVERBOSE to enable output.
 */

#include "stats.h"
#include "platform.h"

/* ------------------------------------------------------------------ */
/*  Public API                                                          */
/* ------------------------------------------------------------------ */

void print_array(uint8_t *arr, uint32_t length)
{
#ifdef VERBOSE
    uint32_t i;
    PRINTF("Array contents:\n");
    for (i = 0; i < length; i++)
    {
        PRINTF("  arr[%u] = %u\n", i, *(arr + i));
    }
    PRINTF("\n");
#else
    /* Suppress unused-parameter warnings when VERBOSE is not defined */
    (void)arr;
    (void)length;
#endif
}

void print_statistics(uint8_t *arr, uint32_t length)
{
    PRINTF("========== Array Statistics ==========\n");
    PRINTF("  Minimum : %u\n", find_minimum(arr, length));
    PRINTF("  Maximum : %u\n", find_maximum(arr, length));
    PRINTF("  Mean    : %u\n", find_mean(arr, length));
    PRINTF("  Median  : %u\n", find_median(arr, length));
    PRINTF("======================================\n\n");
}

uint8_t find_maximum(uint8_t *arr, uint32_t length)
{
    uint8_t  max = *arr;
    uint32_t i;

    for (i = 1; i < length; i++)
    {
        if (*(arr + i) > max)
        {
            max = *(arr + i);
        }
    }
    return max;
}

uint8_t find_minimum(uint8_t *arr, uint32_t length)
{
    uint8_t  min = *arr;
    uint32_t i;

    for (i = 1; i < length; i++)
    {
        if (*(arr + i) < min)
        {
            min = *(arr + i);
        }
    }
    return min;
}

uint8_t find_mean(uint8_t *arr, uint32_t length)
{
    uint32_t sum = 0;
    uint32_t i;

    for (i = 0; i < length; i++)
    {
        sum += *(arr + i);
    }
    return (uint8_t)(sum / length);
}

/* Sort helper: bubble sort descending */
void sort_array(uint8_t *arr, uint32_t length)
{
    uint32_t i, j;
    uint8_t  tmp;

    for (i = 0; i < length - 1; i++)
    {
        for (j = 0; j < length - 1 - i; j++)
        {
            if (*(arr + j) < *(arr + j + 1))
            {
                tmp           = *(arr + j);
                *(arr + j)    = *(arr + j + 1);
                *(arr + j + 1) = tmp;
            }
        }
    }
}

uint8_t find_median(uint8_t *arr, uint32_t length)
{
    /* Work on a local copy so we do not disturb the caller's array */
    uint8_t  tmp[256];   /* max length we expect in this assignment  */
    uint32_t i;

    if (length > 256) { length = 256; }

    for (i = 0; i < length; i++)
    {
        *(tmp + i) = *(arr + i);
    }

    sort_array(tmp, length);

    if (length % 2 == 0)
    {
        return (uint8_t)((*(tmp + length / 2 - 1) + *(tmp + length / 2)) / 2);
    }
    else
    {
        return *(tmp + length / 2);
    }
}
