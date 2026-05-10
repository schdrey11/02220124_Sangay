/**
 * @file    platform.h
 * @brief   Platform-specific abstraction layer macros
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * Provides the PRINTF macro that routes output appropriately
 * depending on whether we are building for the host (Linux/Mac)
 * or the embedded target (MSP432).
 */

#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifdef HOST
  #include <stdio.h>
  #define PRINTF(f, ...) printf(f, ##__VA_ARGS__)
#elif defined(MSP432)
  /* On the MSP432 target, redirect or suppress output as needed */
  #define PRINTF(f, ...) /* no-op on target unless UART is wired */
#else
  #include <stdio.h>
  #define PRINTF(f, ...) printf(f, ##__VA_ARGS__)
#endif

#endif /* __PLATFORM_H__ */
