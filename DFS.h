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
        //
        int t0 = 0,t1 = 0;
        //
        Visual vv;
        int dist[Max_N][Max_M];
        int sx,sy,ex,ey;
        int itr = 0;
        int timeSet = 0;
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        Visual Init(int ts,int mnum);
        void DFS_H(int x,int y,int dir); // DFS + Heuristic
        int DFS_Run(int tset,int mnum);
        void sol_path(int x,int y);
};
#endif
