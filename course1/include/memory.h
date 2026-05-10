/**
 * @file    memory.h
 * @brief   Declarations for memory manipulation functions
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * Provides function declarations for custom memory move, copy,
 * set, zero, reverse, reserve, and free operations. All
 * implementations use pointer arithmetic only — no array indexing.
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * @brief  Move length bytes from src to dst, handling overlapping regions
 * @param  src     Pointer to source memory location
 * @param  dst     Pointer to destination memory location
 * @param  length  Number of bytes to move
 * @return         Pointer to the destination (dst)
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief  Copy length bytes from src to dst (undefined behaviour on overlap)
 * @param  src     Pointer to source memory location
 * @param  dst     Pointer to destination memory location
 * @param  length  Number of bytes to copy
 * @return         Pointer to the destination (dst)
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief  Set length bytes starting at src to a given value
 * @param  src     Pointer to source memory location
 * @param  length  Number of bytes to set
 * @param  value   Byte value to write to every location
 * @return         Pointer to the source (src)
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief  Zero out length bytes starting at src
 * @param  src     Pointer to source memory location
 * @param  length  Number of bytes to zero
 * @return         Pointer to the source (src)
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief  Reverse the order of length bytes starting at src
 * @param  src     Pointer to source memory location
 * @param  length  Number of bytes to reverse
 * @return         Pointer to the source (src)
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief  Dynamically allocate length 32-bit words
 * @param  length  Number of 32-bit words to allocate
 * @return         Pointer to allocated memory, or NULL on failure
 */
int32_t * reserve_words(size_t length);

/**
 * @brief  Free a previously allocated dynamic memory block
 * @param  src  Pointer to the memory block to free
 */
void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
