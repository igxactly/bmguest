#ifndef __CONFIG_H__
#define __CONFIG_H__

#define MAHINE_TYPE             2272
#define CFG_CNTFRQ              100000000

#define NR_CPUS                 2

/*
 *  SOC param
 */
#define CFG_GIC_BASE_PA     0xF1000000
#define CFG_GICD_BASE_PA    0xF1001000
#define CFG_GICC_BASE_PA    0xF1002000

#define USEC 1000000

#define COUNT_PER_USEC (CFG_CNTFRQ/USEC)
#define TICKTIME_1MS 1000
#define TICK_PERIOD_US 250
#define MAX_IRQS 1024

#define CFG_MEMMAP_PHYS_START      0x40000000

#endif  /* RTSM_CONFIG_H */
