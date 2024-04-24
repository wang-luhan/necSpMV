#include <stdio.h>
#include <stdlib.h>
#include "PerfSpB_Global.h"

void PerfSpB_Warning(char *warningMsg, char *filename, int line)
{
    if (PerfSpB_Warning_switch_get())
    {
        fprintf(stderr, "\033[33m[  WARNING ] \033[0m%s at %s:%d\n", warningMsg, filename, line);
    }
}