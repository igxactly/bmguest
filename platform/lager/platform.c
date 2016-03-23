#include "platform.h"
#include <stdint.h>
#include <serial.h>

#include <size.h>
#include <arch/gic_regs.h>

#include <arch/armv7.h>

#define CFG_HYP_START_ADDRESS      0x70000000

void platform_init()
{
#if 0
    uint32_t gic_base = (uint32_t)(get_periphbase() & 0x000000FFFFFFFFFFULL);
    if (gic_base == 0xF1000000) {
        gic_base = 0xF1000000;
    }

    paging_add_mapping(gic_base + GICD_OFFSET, gic_base + GICD_OFFSET, MT_DEVICE, SZ_4K);
    paging_add_mapping(gic_base + GICC_OFFSET, gic_base + GICC_OFFSET, MT_DEVICE, SZ_4K);
    paging_add_mapping(gic_base + GICH_OFFSET, gic_base + GICH_OFFSET, MT_DEVICE, SZ_8K);
    paging_add_mapping(gic_base + GICV_OFFSET, gic_base + GICV_OFFSET, MT_DEVICE, SZ_8K);

    // add mapping for serial devices
    paging_add_mapping(0xE6E60000, 0xE6E60000, MT_DEVICE, SZ_64K);

    paging_add_mapping(0x70000000, CFG_HYP_START_ADDRESS, MT_WRITEBACK_RW_ALLOC, SZ_128M);

//  paging_add_mapping(0x40000000, 0x40000000, MT_WRITEBACK_RW_ALLOC, SZ_256K);
//  paging_add_mapping(0x50000000, 0x40000000, MT_WRITEBACK_RW_ALLOC, SZ_256K);
//  paging_add_mapping(0x60000000, 0x40000000, MT_WRITEBACK_RW_ALLOC, SZ_256K);
#endif
}

void console_init()
{
    // TODO(wonseok): add general initialization for console devices.
    serial_init();
}

void dev_init()
{
    // init .text.dev section like vdev.
}
