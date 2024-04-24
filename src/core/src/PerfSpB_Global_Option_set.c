#include "PerfSparseBLAS_func.h"
#include "PerfSparseBLAS_type.h"
#include "PerfSpB_Global.h"
#include "PerfSpB_Error.h"

perfSpB_info PerfSpB_Global_Option_set_ext // set a global default option
    (
        perfSpB_option_field_ext field,  // option to change
        perfSpB_object_format_ext format // value to change it to
    )
{
    switch (field)
    {
    case perfSpB_matrix_format:
    {
        if (!(format.matrix_format == perfSpB_csc ||
              format.matrix_format == perfSpB_csr))
        {
            return perfSpB_failure;
        }
        PerfSpB_Global_is_csc_set(format.matrix_format != perfSpB_csr);
        break;
    }
    case perfSpB_vector_format:
    {
        PerfSpB_Global_Vector_Format_set(format.vector_format);
        break;
    }
    default:
        PerfSpB_Error("Unknown global option!\n \
(Maybe it has not been implemented!)\n",
                  __FILE__, __LINE__);
        break;
    }

    return perfSpB_success;
}