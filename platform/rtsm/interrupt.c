#include <irq-chip.h>
#include "../../drivers/gic-v2.h"

struct irq_chip gic_v2 = {
    .init = gic_init,
    .enable = gic_enable_irq,
    .disable = gic_disable_irq,
    .ack = gic_get_irq_number,
    .eoi = gic_completion_irq,
    .dir = gic_deactivate_irq,
    .set_irq_type = gic_configure_irq,
};

void set_irqchip_type(void)
{
    irq_hw = &gic_v2;

    irq_hw->init();
}
