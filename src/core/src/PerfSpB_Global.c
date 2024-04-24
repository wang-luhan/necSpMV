#include "PerfSpB_Global.h"
#include "PerfSpB_Alloc.h"
#include <stdlib.h>

perfSpB_index perfSpB_all_object = 0;
perfSpB_index *perfSpB_all = &perfSpB_all_object;

typedef struct
{
    bool is_csc;
    perfSpB_vector_format_value_ext vector_format;
} PerfSpB_Global_struct;

extern PerfSpB_Global_struct PerfSpB_Global;

PerfSpB_Global_struct PerfSpB_Global = {
    .is_csc = true,
    .vector_format = perfSpB_dense};

void PerfSpB_Global_is_csc_set(bool is_csc)
{
    PerfSpB_Global.is_csc = is_csc;
}

extern bool PerfSpB_Global_is_csc_get()
{
    return (PerfSpB_Global.is_csc);
}

void PerfSpB_Global_Vector_Format_set(
    perfSpB_vector_format_value_ext format)
{
    PerfSpB_Global.vector_format = format;
}

extern perfSpB_vector_format_value_ext PerfSpB_Global_get_Vector_Format()
{
    return (PerfSpB_Global.vector_format);
}

LinkedListMes_t LinkedListMes = {
    .capacity_nnz = 512,
    .capacity_nnz_row = 64,
    .capacity_vector_nnz = 64};

void PerfSpB_LinkedList_malloc()
{
    unsigned int nnz = LinkedListMes.capacity_nnz;
    LinkedListMes.ListNodes = PerfSpB_aligned_malloc(sizeof(listNode) * nnz);

    unsigned int nnz_row = LinkedListMes.capacity_nnz_row;
    LinkedListMes.ListPtr = PerfSpB_aligned_malloc(sizeof(listNode) * nnz_row);
}

void PerfSpB_LinkedList_grow(unsigned int nnz, unsigned int nnz_row)
{
    unsigned int new_capacity = LinkedListMes.capacity_nnz;

    while (nnz > new_capacity)
    {
        new_capacity = ((new_capacity) ? ((new_capacity) << 4) : 1);
    }

    if (new_capacity > LinkedListMes.capacity_nnz)
    {
        LinkedListMes.capacity_nnz = new_capacity;
        LinkedListMes.ListNodes =
            PerfSpB_aligned_realloc(LinkedListMes.ListNodes, sizeof(listNode) * new_capacity);
    }

    new_capacity = LinkedListMes.capacity_nnz_row;
    while (nnz_row > new_capacity)
    {
        new_capacity = ((new_capacity) ? ((new_capacity) << 4) : 1);
    }

    if (new_capacity > LinkedListMes.capacity_nnz_row)
    {
        LinkedListMes.capacity_nnz_row = new_capacity;
        LinkedListMes.ListPtr =
            PerfSpB_aligned_realloc(LinkedListMes.ListPtr, sizeof(listNode *) * new_capacity);
    }
}

void PerfSpB_LinkedList_free()
{
    free(LinkedListMes.ListNodes);
    free(LinkedListMes.ListPtr);
}

void PerfSpB_NNZ_Counting_Mes_malloc()
{
    unsigned int vector_nnz = LinkedListMes.capacity_vector_nnz;
    LinkedListMes.Indices_NZRows = PerfSpB_aligned_malloc(sizeof(unsigned int) * vector_nnz);
    LinkedListMes.LL_Index_Ptr = PerfSpB_aligned_malloc(sizeof(unsigned int) * (vector_nnz + 1));
}

void PerfSpB_NNZ_Counting_Mes_grow(unsigned int nnz)
{
    unsigned int new_capacity = LinkedListMes.capacity_vector_nnz;

    while (nnz > new_capacity)
    {
        // 16 times increase.
        new_capacity = ((new_capacity) ? ((new_capacity) << 4) : 1);
    }

    if (new_capacity > LinkedListMes.capacity_vector_nnz)
    {
        LinkedListMes.capacity_vector_nnz = new_capacity;
        LinkedListMes.Indices_NZRows =
            PerfSpB_aligned_realloc(LinkedListMes.Indices_NZRows, sizeof(unsigned int) * new_capacity);
        LinkedListMes.LL_Index_Ptr =
            PerfSpB_aligned_realloc(LinkedListMes.LL_Index_Ptr, sizeof(unsigned int) * (new_capacity + 1));
    }
}

void PerfSpB_NNZ_Counting_Mes_free()
{
    free(LinkedListMes.Indices_NZRows);
    free(LinkedListMes.LL_Index_Ptr);
}

bool warrning_switch = true;

perfSpB_info PerfSpB_Warning_switch_set_ext(bool val)
{
    warrning_switch = val;
    return perfSpB_success;
}

bool PerfSpB_Warning_switch_get()
{
    return warrning_switch;
}