#ifndef __Visual_F__
#define __Visual_F__
#include "linuxfunc.h"
#define Max_N 200
#define Max_M 200
class Visual{
    public:
        int map[Max_N][Max_M];
        int state[Max_N][Max_M];
        int N,M;
        int visual();
        int read_map();
        void draw();
};
#endif
