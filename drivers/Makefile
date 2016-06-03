include ${SOURCE_PATH}/drivers/serial/Makefile

DRIVER_SRCS+= $(patsubst %, serial/%, ${SERIAL_SRCS})

DRIVER_SRCS+= generic_timer.c
DRIVER_SRCS+= gic-v2.c

SUBDIRECTORIES += drivers/serial
