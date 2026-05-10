/**
 * @file    data.c
 * @brief   Implementation of integer ↔ ASCII string conversion functions
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * my_itoa — converts a signed 32-bit integer to a null-terminated
 *            ASCII string in any base from 2 to 16.
 *
 * my_atoi — converts a null-terminated ASCII string back to a signed
 *            32-bit integer for any base from 2 to 16.
 *
 * Both functions use pointer arithmetic exclusively — no array indexing.
 * No string library functions are used.
 */

#include "data.h"

/* ------------------------------------------------------------------ */
/*  Internal helpers                                                    */
/* ------------------------------------------------------------------ */

/**
 * Digit map for bases 2 – 16. Index == numeric value of the digit.
 */
static const uint8_t DIGIT_MAP[] = "0123456789ABCDEF";

/**
 * @brief  Reverse the bytes in the half-open range [start, end)
 */
static void reverse_range(uint8_t *start, uint8_t *end)
{
    end--;  /* point to last valid byte */
    while (start < end)
    {
        uint8_t tmp = *start;
        *start = *end;
        *end   = tmp;
        start++;
        end--;
    }
}

/* ------------------------------------------------------------------ */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
    uint8_t *p        = ptr;   /* writing cursor                  */
    uint8_t  negative = 0;
    uint32_t udata;            /* unsigned working copy of data   */
    uint8_t  len;

    /* Handle the special INT32_MIN case before negation to avoid UB */
    if (data == (int32_t)0x80000000)
    {
        /* Manually handle -2147483648 */
        int32_t tmp = data;
        negative = 1;
        udata = (uint32_t)(-(tmp + 1)) + 1u;
    }
    else if (data < 0)
    {
        negative = 1;
        udata = (uint32_t)(-data);
    }
    else
    {
        udata = (uint32_t)data;
    }

    /* Special case: value is zero */
    if (udata == 0)
    {
        *p = '0';
        p++;
        *p = '\0';
        p++;
        return 2; /* '0' + null terminator */
    }

    /* Build digits in reverse order */
    uint8_t *digit_start = p;

    while (udata > 0)
    {
        *p = *(DIGIT_MAP + (udata % base));
        p++;
        udata /= base;
    }

    /* Append negative sign (will be reversed into place) */
    if (negative)
    {
        *p = '-';
        p++;
    }

    /* Null-terminate first so we know the end position */
    uint8_t *null_pos = p;
    *p = '\0';
    p++;

    /* Reverse the digit (+ sign) characters — null stays at end */
    reverse_range(digit_start, null_pos);

    /* Return total length including the null terminator */
    len = (uint8_t)(p - ptr);
    return len;
}

/* ------------------------------------------------------------------ */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
    int32_t  result   = 0;
    uint8_t  negative = 0;
    uint8_t *p        = ptr;
    uint8_t  i;

    /* Check for a leading '-' sign */
    if (*p == '-')
    {
        negative = 1;
        p++;
        digits--;   /* one fewer digit to process */
    }

    /* Process each digit character */
    for (i = 0; i < digits; i++)
    {
        uint8_t c = *(p + i);
        uint8_t  digit_val;

        /* Convert character to numeric value */
        if (c >= '0' && c <= '9')
        {
            digit_val = c - '0';
        }
        else if (c >= 'A' && c <= 'F')
        {
            digit_val = c - 'A' + 10;
        }
        else if (c >= 'a' && c <= 'f')
        {
            digit_val = c - 'a' + 10;
        }
        else
        {
            /* Invalid character — stop processing */
            break;
        }

        result = (int32_t)((uint32_t)result * base + digit_val);
    }

    if (negative)
    {
        result = -result;
    }

    return result;
}
