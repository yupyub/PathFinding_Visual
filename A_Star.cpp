#include "A_Star.h"
void Init(int ts){
    timeSet *= ts;
    if(timeSet<10000) timeSet = 1000000;
    read_map();
}
int A_Star(){
    priority_queue<tuple<ll,int,int,char> >pq;
    dist[sx][sy] = 0;
    pq.push(make_tuple(0,sx,sy,-1));
    int x,y,dir,nx,ny;
    ll len;
    while(!pq.empty()){
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        dir = get<3>(pq.top());
        pq.pop();
        if(x == ex && y == ey) return dist[x][y];
        for(int i = 0;i<4;i++){
            if(i == dir) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=X.size()||ny>=Y.size()) continue;
            len = abs(X[nx]-X[x]) + abs(Y[ny] - Y[y]);
            if(dist[nx][ny] > dist[x][y] + cost[x][y][i] *len){
                dist[nx][ny] = dist[x][y] + cost[x][y][i] * len;
                pq.push(make_tuple(-(dist[nx][ny] + 10*(abs(X[ex] - X[nx]) + abs(Y[ex] - Y[ny]))),nx,ny,(i+2)%4));
            }
        }
    }
}

