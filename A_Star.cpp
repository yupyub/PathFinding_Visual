#include "A_Star.h"
void Init(int ts){
    timeSet *= ts;
    if(timeSet<10000) timeSet = 1000000;
    read_map();
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(map[i][j] == 2){
                sx = i;
                sy = j;
            }
            else if(map[i][j] == 3){
                ex = i;
                ey = j;
            }
        }
    }
}
int A_Star(){
    priority_queue<tuple<int,int,int,int> >pq;
    dist[sx][sy] = 0;
    state[sx][ey] = 2;
    pq.push(make_tuple(0,sx,sy,-1));
    int x,y,dir,nx,ny;
    while(!pq.empty()){
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        dir = get<3>(pq.top());
        pq.pop();
        state[x][y] = 2;
        if(x == ex && y == ey) return dist[x][y];
        for(int i = 0;i<4;i++){
            if(i == dir) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                pq.push(make_tuple(-(dist[nx][ny] + abs(ex - nx) + abs(ex - ny)),nx,ny,(i+2)%4));
            }
        }
        draw();
    }
}

