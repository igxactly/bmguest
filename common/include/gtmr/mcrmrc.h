/* Copyright (c) 2010, Code Aurora Forum. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Code Aurora nor
 *       the names of its contributors may be used to endorse or promote
 *       products derived from this software without specific prior written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NON-INFRINGEMENT ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
mrcmcr.h

DESCRIPTION: Convenience macros for access the cp registers in the arm.

REV/DATE: Fri Mar 18 16:34:44 EST 2005
*/

/*
 * modified by wonseok ko(magicyaba@gmail.com)
 */

#ifndef __mrcmcr__h_
#define __mrcmcr__h_

#include <gtmr/asm.h>

/*
* Define some convenience macros to acccess the cp registers from c code
* Lots of macro trickery here.
*
* Takes the same format as the asm instructions and unfortunatly you cannot
* use variables to select the crn, crn or op fields...
*
* For those unfamiliar with the # and string stuff.
* # creates a string from the value and any two strings that are beside
*   are concatenated...thus these create one big asm string for the
*   inline asm code.
*
* When compiled these compile to single asm instructions (fast) but
* without all the hassel of __asm__ __volatile__ (...) =r
*
* Format is:
*
*    unsigned long reg;   // destination variable
*    MRC(reg, p15, 0, c1, c0, 0 );
*
*   MRC read control register
*   MCR control register write
*/

/*
* Some assembly macros so we can use the same macros as in the C version.
* Turns the ASM code a little C-ish but keeps the code consistent and in
* one location...
*/

#define COPROC(x)           p##x
#define CR(x)           c##x

#define __COPROC32(rt, cp, n, opc1, m, opc2)    COPROC(cp), opc1, rt, CR(n), CR(m), opc2
#define COPROC32(rt, args...)                   __COPROC32(rt, args)

#define __COPROC64(rt, rt2, cp, opc1, m)        COPROC(cp), opc1, rt, rt2, CR(m)
#define COPROC64(rt, rt2, args...)              __COPROC64(rt, rt2, args)


#ifdef __ASSEMBLY__

#define read_cp32(rt, args...)        	mrc     COPROC32(rt, args)
#define write_cp32(rt, args...)       	mcr     COPROC32(rt, args)

#define read_cp64(rt, rt2, args...)     mrrc    COPROC64(rt, rt2, args)
#define write_cp64(rt, rt2, args...)    mcrr    COPROC64(rt, rt2, args)

/* * C version of the macros.
*/
#else

/* For stringification */
#define xstr(s...) str(s)
#define str(s...) #s

#define read_cp32(args) ({                                  \
    unsigned int reg;                                       \
    asm volatile(                                           \
    "mrc\t" xstr(COPROC32(%0, args)) : "=r" (reg));         \
    reg; })

#define write_cp32(rt, args) 					            \
    asm volatile ( 								            \
    "mcr\t"  xstr(COPROC32(%0, args)) : : "r" (rt))

#define read_cp64(args) ({                                  \
    unsigned long long reg;                                 \
    asm volatile(                                           \
    "mrrc\t" xstr(COPROC64(%0, %H0, args)) : "=r" (reg));   \
    reg; })

#define write_cp64(rt, args) 				                \
    asm volatile ( 									        \
    "mcrr\t"  xstr(COPROC64(%0, %H0, args)) : : "r" (rt))

#endif

#endif
