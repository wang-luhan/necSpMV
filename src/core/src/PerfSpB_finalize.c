#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "PerfSpB_Global.h"

void PerfSpB_finalize(){
    PerfSpB_NNZ_Counting_Mes_free();
    PerfSpB_LinkedList_free();
    return;
}