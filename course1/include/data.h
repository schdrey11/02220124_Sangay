/**
 * @file    data.h
 * @brief   Declarations for integer ↔ ASCII conversion functions
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * Provides declarations for my_itoa (integer to ASCII string)
 * and my_atoi (ASCII string to integer). Supports bases 2 – 16.
 * All implementations use pointer arithmetic only.
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief  Convert a signed 32-bit integer to an ASCII string
 *
 * Converts data into a null-terminated ASCII string stored at ptr.
 * Supports bases 2 through 16. Handles negative numbers.
 *
 * @param  data   Signed 32-bit integer to convert
 * @param  ptr    Destination buffer for the ASCII string
 * @param  base   Numeric base for conversion (2 – 16)
 * @return        Length of the converted string INCLUDING the null terminator
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief  Convert an ASCII string to a signed 32-bit integer
 *
 * Reads digits characters from the string at ptr and converts them
 * back to an integer using the specified base. Handles negative numbers
 * (leading '-' character).
 *
 * @param  ptr     Pointer to the ASCII string
 * @param  digits  Number of characters in the string (including sign, excluding null)
 * @param  base    Numeric base for conversion (2 – 16)
 * @return         Converted signed 32-bit integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
