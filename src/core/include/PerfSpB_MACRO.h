#pragma once
#define PerfSpB_TOKEN_PASTING2(x, y) x##y
#define PerfSpB_TOKEN_PASTING3(x, y, z) x##y##z
#define PerfSpB_TOKEN_PASTING4(x, y, z, a) x##y##z##a
#define PerfSpB(x) PerfSpB_SPLICE2(PerfSpB_, x)
