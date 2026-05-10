/**
 * @file    course1.c
 * @brief   Course 1 final assessment test suite
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * Implements the course1() top-level runner and every sub-test
 * function.  Each test returns 0 on success or a negative error
 * code on failure.  Diagnostic output is routed through PRINTF so
 * it can be silenced on an embedded target if needed.
 */

#include "course1.h"
#include "data.h"
#include "memory.h"
#include "platform.h"
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ */
/*  Top-level runner                                                    */
/* ------------------------------------------------------------------ */

int8_t course1(void)
{
    int8_t result = 0;

    PRINTF("\n========== Course 1 Final Assessment — Choki ==========\n");
    PRINTF("Date: May 1, 2026\n\n");

    result |= test_data1();
    result |= test_data2();
    result |= test_memmove1();
    result |= test_memmove2();
    result |= test_memmove3();
    result |= test_memcopy();
    result |= test_memset();
    result |= test_reverse();

    if (result == 0)
    {
        PRINTF("\n[PASS] All Course 1 tests passed.\n");
    }
    else
    {
        PRINTF("\n[FAIL] One or more tests failed (code %d).\n", result);
    }

    PRINTF("=========================================================\n\n");
    return result;
}

/* ------------------------------------------------------------------ */
/*  Data conversion tests                                               */
/* ------------------------------------------------------------------ */

int8_t test_data1(void)
{
    PRINTF("----- test_data1: itoa/atoi round-trip (decimal) -----\n");

    int32_t original = 1234;
    uint8_t buf[34]  = {0};
    uint8_t len;
    int32_t recovered;

    /* Convert integer → string */
    len = my_itoa(original, buf, 10);
    PRINTF("  my_itoa(%d, buf, 10) -> \"%s\", len=%u\n", original, buf, len);

    /* Verify length includes null terminator */
    if (len != 5)   /* "1234\0" => 5 chars */
    {
        PRINTF("  [FAIL] Expected length 5, got %u\n", len);
        return -1;
    }

    /* Convert string → integer */
    recovered = my_atoi(buf, (uint8_t)(len - 1), 10);
    PRINTF("  my_atoi(\"%s\", %u, 10) -> %d\n", buf, (uint8_t)(len - 1), recovered);

    if (recovered != original)
    {
        PRINTF("  [FAIL] Round-trip mismatch: got %d\n", recovered);
        return -1;
    }

    PRINTF("  [PASS] test_data1\n\n");
    return 0;
}

/* ------------------------------------------------------------------ */

int8_t test_data2(void)
{
    PRINTF("----- test_data2: itoa/atoi with negatives & base 16 -----\n");

    int8_t  rc       = 0;
    uint8_t buf[34]  = {0};
    uint8_t len;
    int32_t recovered;

    /* --- negative decimal --- */
    int32_t neg_val = -5678;
    len = my_itoa(neg_val, buf, 10);
    PRINTF("  my_itoa(%d, buf, 10) -> \"%s\", len=%u\n", neg_val, buf, len);
    recovered = my_atoi(buf, (uint8_t)(len - 1), 10);
    PRINTF("  my_atoi -> %d\n", recovered);
    if (recovered != neg_val)
    {
        PRINTF("  [FAIL] Negative decimal round-trip failed\n");
        rc = -1;
    }

    /* --- hex positive --- */
    int32_t hex_val = 0xFF;
    len = my_itoa(hex_val, buf, 16);
    PRINTF("  my_itoa(%d, buf, 16) -> \"%s\", len=%u\n", hex_val, buf, len);
    recovered = my_atoi(buf, (uint8_t)(len - 1), 16);
    PRINTF("  my_atoi -> %d\n", recovered);
    if (recovered != hex_val)
    {
        PRINTF("  [FAIL] Hex round-trip failed\n");
        rc = -1;
    }

    /* --- binary --- */
    int32_t bin_val = 0b1010;   /* 10 decimal */
    len = my_itoa(bin_val, buf, 2);
    PRINTF("  my_itoa(%d, buf, 2) -> \"%s\", len=%u\n", bin_val, buf, len);
    recovered = my_atoi(buf, (uint8_t)(len - 1), 2);
    PRINTF("  my_atoi -> %d\n", recovered);
    if (recovered != bin_val)
    {
        PRINTF("  [FAIL] Binary round-trip failed\n");
        rc = -1;
    }

    if (rc == 0) { PRINTF("  [PASS] test_data2\n\n"); }
    else         { PRINTF("  [FAIL] test_data2\n\n"); }
    return rc;
}

/* ------------------------------------------------------------------ */
/*  Memory move tests                                                   */
/* ------------------------------------------------------------------ */

int8_t test_memmove1(void)
{
    PRINTF("----- test_memmove1: non-overlapping regions -----\n");

    uint8_t src[8] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    uint8_t dst[8] = {0};
    uint8_t i;

    my_memmove(src, dst, 8);

    for (i = 0; i < 8; i++)
    {
        if (*(dst + i) != *(src + i))
        {
            PRINTF("  [FAIL] dst[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(dst + i), *(src + i));
            return -1;
        }
    }

    PRINTF("  [PASS] test_memmove1\n\n");
    return 0;
}

/* ------------------------------------------------------------------ */

int8_t test_memmove2(void)
{
    PRINTF("----- test_memmove2: overlap — end of dst / start of src -----\n");
    /*
     * Layout:  [0 1 2 3 4 5 6 7 8 9]
     *   src starts at index 0, length 8  ->  [0..7]
     *   dst starts at index 4, length 8  ->  [4..11]
     * dst[0] == buf[4] which is inside src region.
     */

    uint8_t buf[12] = {0x10, 0x20, 0x30, 0x40,
                        0x50, 0x60, 0x70, 0x80,
                        0x00, 0x00, 0x00, 0x00};
    uint8_t expected[8] = {0x10, 0x20, 0x30, 0x40,
                            0x50, 0x60, 0x70, 0x80};
    uint8_t *src = buf;
    uint8_t *dst = buf + 4;
    uint8_t  i;

    my_memmove(src, dst, 8);

    for (i = 0; i < 8; i++)
    {
        if (*(dst + i) != *(expected + i))
        {
            PRINTF("  [FAIL] dst[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(dst + i), *(expected + i));
            return -1;
        }
    }

    PRINTF("  [PASS] test_memmove2\n\n");
    return 0;
}

/* ------------------------------------------------------------------ */

int8_t test_memmove3(void)
{
    PRINTF("----- test_memmove3: overlap — start of dst / end of src -----\n");
    /*
     * Layout:  [0 1 2 3 4 5 6 7 8 9]
     *   src starts at index 4, length 8  ->  [4..11]
     *   dst starts at index 0, length 8  ->  [0..7]
     * dst+4 == src which overlaps inside src region.
     */

    uint8_t buf[12] = {0x00, 0x00, 0x00, 0x00,
                        0xAA, 0xBB, 0xCC, 0xDD,
                        0xEE, 0xFF, 0x11, 0x22};
    uint8_t expected[8] = {0xAA, 0xBB, 0xCC, 0xDD,
                            0xEE, 0xFF, 0x11, 0x22};
    uint8_t *src = buf + 4;
    uint8_t *dst = buf;
    uint8_t  i;

    my_memmove(src, dst, 8);

    for (i = 0; i < 8; i++)
    {
        if (*(dst + i) != *(expected + i))
        {
            PRINTF("  [FAIL] dst[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(dst + i), *(expected + i));
            return -1;
        }
    }

    PRINTF("  [PASS] test_memmove3\n\n");
    return 0;
}

/* ------------------------------------------------------------------ */

int8_t test_memcopy(void)
{
    PRINTF("----- test_memcopy: non-overlapping copy -----\n");

    uint8_t src[6] = {0xDE, 0xAD, 0xBE, 0xEF, 0xCA, 0xFE};
    uint8_t dst[6] = {0};
    uint8_t i;

    my_memcopy(src, dst, 6);

    for (i = 0; i < 6; i++)
    {
        if (*(dst + i) != *(src + i))
        {
            PRINTF("  [FAIL] dst[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(dst + i), *(src + i));
            return -1;
        }
    }

    PRINTF("  [PASS] test_memcopy\n\n");
    return 0;
}

/* ------------------------------------------------------------------ */

int8_t test_memset(void)
{
    PRINTF("----- test_memset: set and zero -----\n");

    uint8_t buf[8] = {0};
    uint8_t value  = 0xA5;
    uint8_t i;

    /* --- test my_memset --- */
    my_memset(buf, 8, value);
    for (i = 0; i < 8; i++)
    {
        if (*(buf + i) != value)
        {
            PRINTF("  [FAIL] memset: buf[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(buf + i), value);
            return -1;
        }
    }
    PRINTF("  my_memset: all bytes = 0x%02X  OK\n", value);

    /* --- test my_memzero --- */
    my_memzero(buf, 8);
    for (i = 0; i < 8; i++)
    {
        if (*(buf + i) != 0)
        {
            PRINTF("  [FAIL] memzero: buf[%u] = 0x%02X, expected 0x00\n",
                   i, *(buf + i));
            return -1;
        }
    }
    PRINTF("  my_memzero: all bytes = 0x00  OK\n");

    PRINTF("  [PASS] test_memset\n\n");
    return 0;
}

/* ------------------------------------------------------------------ */

int8_t test_reverse(void)
{
    PRINTF("----- test_reverse -----\n");

    uint8_t buf[]     = {0x01, 0x02, 0x03, 0x04, 0x05};
    uint8_t expected[] = {0x05, 0x04, 0x03, 0x02, 0x01};
    size_t  len        = 5;
    uint8_t i;

    my_reverse(buf, len);

    for (i = 0; i < (uint8_t)len; i++)
    {
        if (*(buf + i) != *(expected + i))
        {
            PRINTF("  [FAIL] buf[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(buf + i), *(expected + i));
            return -1;
        }
    }

    /* Even-length test */
    uint8_t even[]    = {0xAA, 0xBB, 0xCC, 0xDD};
    uint8_t exp_even[] = {0xDD, 0xCC, 0xBB, 0xAA};
    my_reverse(even, 4);
    for (i = 0; i < 4; i++)
    {
        if (*(even + i) != *(exp_even + i))
        {
            PRINTF("  [FAIL] even[%u] = 0x%02X, expected 0x%02X\n",
                   i, *(even + i), *(exp_even + i));
            return -1;
        }
    }

    PRINTF("  [PASS] test_reverse\n\n");
    return 0;
}
