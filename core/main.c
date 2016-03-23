#include <stdio.h>
#include <stdint.h>

//#include <pl01x.h>
#include <drivers/serial_sh.h>
#include <../drivers/gic-v2.h>
#include <libc_init.h>
#include <asm/asm.h>
#include <arch/armv7.h>
#include <arch/irq.h>
#include <platform.h>



#define irq_enable() asm volatile("cpsie i" : : : "memory")
void main(void)
{
	console_init();
    libc_init();
	irq_init();
    irq_enable();

    printf("BMGuest is Done\n");
    while(1)
	{
		get_periphbase();
	}
}
