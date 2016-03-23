#ifndef __CONFIG_H__
#define __CONFIG_H__

#define MAHINE_TYPE             2272
#define CFG_CNTFRQ              100000000

#define HYP_STACK_SIZE          4096
#define NR_CPUS                 2
#define NUM_GUESTS_STATIC       3

/*
 *  SOC param
 */
#define CFG_GIC_BASE_PA     0xF1000000
#define CFG_GICD_BASE_PA    0xF1001000
#define CFG_GICC_BASE_PA    0xF1002000

#define USEC 1000000


#define NUM_GUESTS_CPU0_STATIC       2
#define NUM_GUESTS_CPU1_STATIC       2
#define COUNT_PER_USEC (CFG_CNTFRQ/USEC)
#define TICKTIME_1MS 1000
#define TICK_PERIOD_US 250
#define MAX_IRQS 1024
#define MAX_PPI_IRQS 32
#define MAX_SPI_IRQS (MAX_IRQS - 1024)

#define CFG_MEMMAP_PHYS_START      0x40000000
#define CFG_MEMMAP_PHYS_SIZE       0x3FFFFFFF
#define CFG_MEMMAP_PHYS_END        (CFG_MEMMAP_PHYS_START+CFG_MEMMAP_PHYS_SIZE)

#define CFG_MEMMAP_GUEST_SIZE      			0x10000000
#define CFG_MEMMAP_GUEST0_ATAGS_OFFSET      0x40000000
#define CFG_MEMMAP_GUEST0_OFFSET            0x40500000
#define CFG_MEMMAP_GUEST1_ATAGS_OFFSET      0x50000000
#define CFG_MEMMAP_GUEST1_OFFSET            0x50500000
#define CFG_MEMMAP_GUEST2_ATAGS_OFFSET      0x60000000
#define CFG_MEMMAP_GUEST2_OFFSET            0x60500000
#define CFG_GUEST_ATAGS_START_ADDRESS       0x40000000
#define CFG_GUEST_START_ADDRESS             0x40500000

#define CFG_HYP_START_ADDRESS      			0x70000000

#endif  /* RTSM_CONFIG_H */
