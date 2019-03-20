#ifndef __A_Star_F__
#define __A_Star_F__
#include "visual.h"
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>
#define INF 987654321
#define Max_N 200
#define Max_M 200
using namespace std;
class A_Star{
    public:
        int dist[Max_N][Max_M];
        int sx,sy,ex,ey;
        int timeSet = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        Visual Init(int ts,int mnum);
        int A_Star_Run(int tset,int mnum,int hnum,int hg);
        int H_Func(int nx,int ny,int g,int h);
        int H1(int nx,int ny,int g); // Manhattan_Distance * g
        int H2(int nx,int ny,int g);
};
#endif
