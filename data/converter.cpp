#include "../utilities/command_line.h"
#include "../utilities/graph.hpp"
#include "../utilities/builder.hpp"
#include "../utilities/writer.hpp"
#include "../include/PerfSparseBLAS_func.h"
#include "../include/PerfSparseBLAS_type.h"

int main(int argc, char *argv[])
{
    CLConvert cli(argc, argv, "converter : This tool can convert .mtx format to .sg format, which can be loaded at a much higher speed than .mtx");

    if (!cli.ParseArgs())
        return -1;

    if (cli.needs_weights())
    {
        typedef struct NodeWeight<perfSpB_index, int32_t> DestID_T;

        Builder<perfSpB_index, DestID_T, int32_t> builder(&cli, true);

        CSRGraph<perfSpB_index, DestID_T> g = builder.MakeGraph();

        Writer<perfSpB_index, DestID_T> w(g);

        w.WriteGraph(cli.out_filename());
    }
    else
    {
        Builder<perfSpB_index, perfSpB_index, perfSpB_index> builder(&cli, false);

        CSRGraph<perfSpB_index, perfSpB_index> g = builder.MakeGraph();

        Writer<perfSpB_index, perfSpB_index> w(g);

        w.WriteGraph(cli.out_filename());
    }

    return 0;
}