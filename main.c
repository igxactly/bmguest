//#include <asm-arm_inline.h>
//#include <log/uart_print.h>
//#include <gic.h>
//#include <test/tests.h>
#include <trap.h>
#include <drivers/sp804_timer.h>

int main()
{
    int val;
    uart_print(GUEST_LABEL);
    uart_print("\n\r=== Starting platform main\n\r");
#ifdef TESTS_ENABLE_SP804_TIMER
    /* Test the SP804 timer */
    uart_print("%s[%d]\n", __func__, __LINE__);
    hvmm_tests_sp804_timer();
    uart_print("%s[%d]\n", __func__, __LINE__);
#endif
#ifdef TESTS_TRAP_WFI
    uart_print("%s[%d]\n", __func__, __LINE__);
    WFI();
    uart_print("%s[%d]\n", __func__, __LINE__);
#endif
#ifdef TESTS_TRAP_SMC
    uart_print("%s[%d]\n", __func__, __LINE__);
    SVC();
    uart_print("%s[%d]\n", __func__, __LINE__);
/*    SMC(); */
#endif
#ifdef TESTS_TRAP_SCTLR
    uart_print("%s[%d]\n", __func__, __LINE__);
    READ_SCTLR(val);
    uart_print("%s[%d]\n", __func__, __LINE__);
    WRITE_SCTLR(val);
    uart_print("%s[%d]\n", __func__, __LINE__);
#endif
#ifdef TESTS_TRAP_DDCISW
    uart_print("%s[%d]\n", __func__, __LINE__);
    WRITE_DCCISW(val);
    uart_print("%s[%d]\n", __func__, __LINE__);
#endif
#ifdef TESTS_TRAP_ACTLR
    uart_print("%s[%d]\n", __func__, __LINE__);
    READ_ACTLR(val);
    uart_print("%s[%d]\n", __func__, __LINE__);
    WRITE_ACTLR(val);
    uart_print("%s[%d]\n", __func__, __LINE__);
#endif
    uart_print("\n\r=== Ending platform main\n\r");

    int i = 0;
    while (1)
        uart_print("1");

    return 0;
}
