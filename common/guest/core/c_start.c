/*
 * Copyright (c) 2012 Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of Linaro Limited nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 */

/* This file just contains a small glue function which fishes the
 * location of kernel etc out of linker script defined symbols, and
 * calls semi_loader functions to do the actual work of loading
 * and booting the kernel.
 */

#include <asm-arm_inline.h>
#include <log/uart_print.h>
#include <gic.h>
#include <test/tests.h>
#include <test/test_vtimer.h>
#ifdef _SMP_
#include <smp.h>
#endif

/* #define TESTS_ENABLE_VDEV_SAMPLE */

#ifdef __MONITOR_CALL_HVC__
#define hsvc_ping()     asm("hvc #0xFFFE")
#define hsvc_yield()    asm("hvc #0xFFFD")
#else
#define SWITCH_MANUAL() asm("smc #0")
#endif

#ifndef GUEST_LABEL
#define GUEST_LABEL "[guest] :"
#endif

#ifndef NUM_ITERATIONS
#define NUM_ITERATIONS 10
#endif

inline void nrm_delay(void)
{
    volatile int i = 0;
    for (i = 0; i < 0x0000FFFF; i++)
        ;
}

void nrm_loop(void)
{
    int i = 0;
#if _SMP_
    uint32_t cpu = smp_processor_id();
#endif
    uart_init();
    gic_init();

    /* We are ready to accept irqs with GIC. Enable it now */
    irq_enable();
    /* start platform start up code */
    main();
}
