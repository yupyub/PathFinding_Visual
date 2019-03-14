#ifndef __Visual_F__
#define __Visual_F__
#include "linuxfunc.h"
#define Max_N 2000
#define Max_M 2000
int map[Max_N][Max_M];
int state[Max_N][Max_M];
int N,M;
int visual();
int read_map();
void draw();
#endif
