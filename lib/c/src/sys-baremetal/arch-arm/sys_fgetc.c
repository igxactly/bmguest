#include <stdio.h>
#include <stdint.h>
#include <pl01x.h>

extern int __fgetc();
/* Put character for elf-loader */
int
__fgetc()
{
	return pl01x_getc();
}

