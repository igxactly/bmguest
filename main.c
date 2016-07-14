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

/* 700000ns = 0.7ms */
#define THRESHOLD 70000

int main()
{
    int val;
    uart_print(GUEST_LABEL);
    uart_print("\n\r=== Starting platform main\n\r");

    uint64_t prev_pct = 0;
    uint64_t curr_pct = 0;
    uint64_t prev_1k = 0;
    uint32_t diff_1k = 0;
    uint32_t count = 0;

    prev_1k = prev_pct = read_cp64(CNTPCT);
    while (1) {
        curr_pct = read_cp64(CNTPCT);
        if ((curr_pct - prev_pct) > THRESHOLD) {
            count++;
            if (count == 100) {
                diff_1k = (uint32_t) (curr_pct - prev_1k);
                prev_1k = curr_pct;
                count = 0;

                uart_print("1k ");
                uart_print_hex32(diff_1k);
                uart_print("\n\r");
            }
        }
        prev_pct = curr_pct;
    }

    uart_print("\n\r=== Ending platform main\n\r");

    while (1);

    return 0;
}
