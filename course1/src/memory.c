/**
 * @file    memory.c
 * @brief   Implementation of custom memory manipulation functions
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * All functions use pointer arithmetic exclusively — no array indexing.
 *
 * my_memmove  — overlap-safe byte move
 * my_memcopy  — fast byte copy (undefined behaviour on overlap)
 * my_memset   — fill region with a constant byte value
 * my_memzero  — fill region with zero bytes
 * my_reverse  — reverse byte order of a region
 * reserve_words — dynamic allocation of 32-bit words
 * free_words    — release a previously allocated block
 */

#include "memory.h"

/* ------------------------------------------------------------------ */

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
    uint8_t *s = src;
    uint8_t *d = dst;
    size_t   i;

    if (src == dst || length == 0)
    {
        return dst;
    }

    /*
     * If destination is BEFORE source, or the regions do not overlap,
     * copy forward (low address → high address).
     * If destination is AFTER source and they overlap, copy backward
     * (high address → low address) to avoid corrupting src data.
     */
    if (d < s || (d >= s + length))
    {
        /* Forward copy — safe for non-overlap and dst-before-src */
        for (i = 0; i < length; i++)
        {
            *(d + i) = *(s + i);
        }
    }
    else
    {
        /* Backward copy — dst is inside src region, copy tail first */
        for (i = length; i > 0; i--)
        {
            *(d + i - 1) = *(s + i - 1);
        }
    }

    return dst;
}

/* ------------------------------------------------------------------ */

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
    uint8_t *s = src;
    uint8_t *d = dst;
    size_t   i;

    /* Overlap behaviour is explicitly undefined; copy forward unconditionally */
    for (i = 0; i < length; i++)
    {
        *(d + i) = *(s + i);
    }

    return dst;
}

/* ------------------------------------------------------------------ */

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
    uint8_t *p = src;
    size_t   i;

    for (i = 0; i < length; i++)
    {
        *(p + i) = value;
    }

    return src;
}

/* ------------------------------------------------------------------ */

uint8_t * my_memzero(uint8_t * src, size_t length)
{
    uint8_t *p = src;
    size_t   i;

    for (i = 0; i < length; i++)
    {
        *(p + i) = 0;
    }

    return src;
}

/* ------------------------------------------------------------------ */

uint8_t * my_reverse(uint8_t * src, size_t length)
{
    uint8_t *lo = src;
    uint8_t *hi = src + length - 1;
    uint8_t  tmp;

    while (lo < hi)
    {
        tmp  = *lo;
        *lo  = *hi;
        *hi  = tmp;
        lo++;
        hi--;
    }

    return src;
}

/* ------------------------------------------------------------------ */

int32_t * reserve_words(size_t length)
{
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));
    return ptr;   /* returns NULL automatically if malloc fails */
}

/* ------------------------------------------------------------------ */

void free_words(int32_t * src)
{
    free(src);
}
