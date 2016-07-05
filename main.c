//#include <asm-arm_inline.h>
//#include <log/uart_print.h>
//#include <gic.h>
//#include <test/tests.h>
#include <trap.h>
#include <log/uart_print.h>
#include <drivers/sp804_timer.h>

#include <gtmr/limits.h>
#include <gtmr/asm.h>
#include <gtmr/mcrmrc.h>
#include <gtmr/cp15.h>
#include <gtmr/vmsa.h>
#include <gtmr/generic_timer.h>

int main()
{
    uart_print(GUEST_LABEL);
    uart_print("\n\r=== Starting platform main\n\r");

#if 0
    while (1) {
        uart_print("\n\rCNTP_TVAL: ");
        uart_print_hex32(read_cp32(CNTP_TVAL));
    }
#endif

    uart_print("\n\rCNTPCT before (low): ");
    uart_print_hex32((uint32_t) read_cp64(CNTPCT));
    write_cp32(0x400000, CNTP_TVAL); /* let's see if interrupt occurs */

    uint32_t p_ctl = read_cp32(CNTP_CTL);
    p_ctl = 1u; /* enable, unmask */
    write_cp32(p_ctl, CNTP_CTL);

    // uart_print("\n\r=== Ending platform main\n\r");

    while (1);

    return 0;
}
