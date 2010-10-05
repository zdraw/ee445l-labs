#include "music.h"

#if PROCEDURE == 32
const unsigned short SinWave[32] = {
683,
816,
944,
1062,
1165,
1250,
1313,
1352,
1365,
1352,
1313,
1250,
1165,
1062,
944,
816,
683,
550,
422,
304,
201,
116,
53,
14,
1,
14,
53,
116,
201,
304,
422,
550
};
#endif

#if PROCEDURE == 64
const unsigned short SinWave[64] = {
2048,
2249,
2447,
2642,
2831,
3013,
3185,
3347,
3495,
3630,
3750,
3853,
3939,
4007,
4056,
4085,
4095,
4085,
4056,
4007,
3939,
3853,
3750,
3630,
3495,
3347,
3185,
3013,
2831,
2642,
2447,
2249,
2048,
1847,
1649,
1454,
1265,
1083,
911,
749,
601,
466,
346,
243,
157,
89,
40,
11,
1,
11,
40,
89,
157,
243,
346,
466,
601,
749,
911,
1083,
1265,
1454,
1649,
1847
};
#endif

const NoteType melody[618] = {
{FREQUENCY/659, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/466, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/466, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/740, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/740, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/1047, EIGHTH},
{0, EIGHTH},
{FREQUENCY/1047, EIGHTH},
{FREQUENCY/1047, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/740, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/740, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/740, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/1047, EIGHTH},
{0, EIGHTH},
{FREQUENCY/1047, EIGHTH},
{FREQUENCY/1047, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/740, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/622, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/466, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/466, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/659, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/880, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/784, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH}
};             

const NoteType harmony[618] = {
{FREQUENCY/370, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{FREQUENCY/277, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{FREQUENCY/277, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/622, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/622, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/622, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/622, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/622, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{FREQUENCY/784, EIGHTH},
{FREQUENCY/784, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/659, EIGHTH},
{FREQUENCY/622, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/466, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/466, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/466, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{FREQUENCY/277, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{FREQUENCY/277, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/440, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/294, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/466, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/466, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{0, EIGHTH},
{FREQUENCY/415, EIGHTH},
{FREQUENCY/466, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/370, EIGHTH},
{FREQUENCY/370, EIGHTH},
{0, EIGHTH},
{FREQUENCY/494, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/698, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/659, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/440, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/349, EIGHTH},
{FREQUENCY/523, EIGHTH},
{0, EIGHTH},
{FREQUENCY/523, EIGHTH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{FREQUENCY/587, EIGHTH},
{0, EIGHTH},
{FREQUENCY/587, EIGHTH},
{FREQUENCY/587, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/523, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/494, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH}
};

const NoteType bass[606] = {
{FREQUENCY/147, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/330, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/220, EIGHTH},
{FREQUENCY/247, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/330, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/220, EIGHTH},
{FREQUENCY/247, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/233, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/698, EIGHTH},
{FREQUENCY/698, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/233, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{FREQUENCY/104, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/156, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/98, EIGHTH},
{0, EIGHTH},
{FREQUENCY/104, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/156, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/98, EIGHTH},
{0, EIGHTH},
{FREQUENCY/104, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/156, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/98, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/330, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/220, EIGHTH},
{FREQUENCY/247, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/165, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/330, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/349, EIGHTH},
{0, EIGHTH},
{FREQUENCY/294, EIGHTH},
{FREQUENCY/330, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/220, EIGHTH},
{FREQUENCY/247, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/247, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/196, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/220, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/247, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/247, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/196, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/220, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/247, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/104, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/156, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/98, EIGHTH},
{0, EIGHTH},
{FREQUENCY/104, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/156, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/98, EIGHTH},
{0, EIGHTH},
{FREQUENCY/104, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/156, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/208, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/98, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{FREQUENCY/392, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/147, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/247, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/185, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/262, EIGHTH},
{FREQUENCY/175, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{FREQUENCY/196, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/220, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/247, TRIP8TH},
{0, TRIP8TH},
{FREQUENCY/262, EIGHTH},
{0, EIGHTH},
{FREQUENCY/196, EIGHTH},
{0, EIGHTH},
{FREQUENCY/131, EIGHTH},
{0, EIGHTH},
{0, EIGHTH},
{0, EIGHTH}
};