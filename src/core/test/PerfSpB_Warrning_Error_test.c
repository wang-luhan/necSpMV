#include "PerfSpB_Error.h"
#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"

void run_PerfSpB_Warning()
{
    PerfSpB_Warning("This is a PerfSpB_Warning test\n", __FILE__, __LINE__);
}
void run_no_PerfSpB_Warning()
{
    PerfSpB_Warning_switch_set_ext(false);
    PerfSpB_Warning("This is a no PerfSpB_Warning test\n", __FILE__, __LINE__);
}

void run_PerfSpB_Error()
{
    PerfSpB_Error("This is a PerfSpB_Error test!\n", __FILE__, __LINE__);
}