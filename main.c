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
    int val;
    uart_print(GUEST_LABEL);
    uart_print("\n\r=== Starting platform main\n\r");

    while (1) {
        uart_print("\n\rCNTP_TVAL: ");
        uart_print_hex32(read_cp32(CNTP_TVAL));
    }

    uart_print("\n\r=== Ending platform main\n\r");

    while (1);

    return 0;
}
