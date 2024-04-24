#include "PerfSpB_Global.h"

void PerfSpB_init()
{
    PerfSpB_Warning_switch_set_ext(true);
    PerfSpB_NNZ_Counting_Mes_malloc();
    // PerfSpB_LinkedList_malloc();
    return;
}