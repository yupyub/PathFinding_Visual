#ifndef __A_Ster_F__
#define __A_Ster_F__
#include "visual.h"
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define INF 987654321
#define Max_N 2000
#define Max_M 2000
using namespace std;
int dist[Max_N][Max_M];
vector<tuple<int,int,int,int,int> >rec;
int sx,sy,ex,ey;
int timeSet = 1000;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void Init_A(int ts);
int A_Star();
#endif
