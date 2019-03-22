#ifndef __DFS_F__
#define __DFS_F__
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
class DFS{
    public:
        Visual vv;
        int dist[Max_N][Max_M];
        int sx,sy,ex,ey;
        int timeSet = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        Visual Init(int ts,int mnum);
        int DFS_F(int x,int y);
        int DFS_Run(int tset,int mnum);
        void sol_path(int x,int y);
};
#endif
