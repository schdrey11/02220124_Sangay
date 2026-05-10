/**
 * @file    main.c
 * @brief   Application entry point
 *
 * @author  Choden
 * @date    May 10, 2026
 *
 * The main function is intentionally minimal. The COURSE1 compile-time
 * switch selects which course deliverable is invoked. Build with
 *   make COURSE1=1
 * to enable the Course 1 final assessment path.
 */

#include "platform.h"

#ifdef COURSE1
#include "course1.h"
#endif

/**
 * @brief  Program entry point
 * @return 0 on success
 */
int main(void)
{
#ifdef COURSE1
    course1();
#endif
    return 0;
}
