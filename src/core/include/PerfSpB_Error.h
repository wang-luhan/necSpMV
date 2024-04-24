#ifdef __cplusplus
extern "C"
{
#endif
    void PerfSpB_Error(char *errorMsg, char *filename, const int line);

    void PerfSpB_Warning(char *warningMsg_, char *filename, int line);
#ifdef __cplusplus
}
#endif

#define CHECK_ERROR(condition, msg)             \
    if (condition)                              \
    {                                           \
        PerfSpB_Error(msg, __FILE__, __LINE__); \
    }
