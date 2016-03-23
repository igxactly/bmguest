DRIVER_SRCS+= generic_timer.c
DRIVER_SRCS+= gic-v2.c

ifeq (${TARGET}, rtsm)
DRIVER_SRCS+= serial_pl01x.c
else ifeq (${TARGET}, lager)
DRIVER_SRCS+= serial_sh.c
endif
