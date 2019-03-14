#include "A_Star.h"
Visual A_Star::Init(int ts){
    timeSet *= ts;
    if(timeSet<10000) timeSet = 10000000;
    Visual vv;
    vv.read_map();
    for(int i = 0;i<vv.N;i++){
        for(int j = 0;j<vv.M;j++){
            dist[i][j] = INF;
            if(vv.map[i][j] == 2){
                sx = i;
                sy = j;
            }
            else if(vv.map[i][j] == 3){
                ex = i;
                ey = j;
            }
        }
    }
    return vv;
}
int A_Star::A_Star_Run(){
    Visual vv = Init(2000);
    priority_queue<tuple<int,int,int,int> >pq;
    dist[sx][sy] = 0;
    vv.state[sx][sy] = 2;
    pq.push(make_tuple(0,sx,sy,-1));
    int x,y,dir,nx,ny;
    while(!pq.empty()){
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        dir = get<3>(pq.top());
        pq.pop();
        vv.state[x][y] = 2;
        if(vv.map[x][y] == 3) return dist[x][y];
        for(int i = 0;i<4;i++){
            if(i == dir) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=vv.N||ny>=vv.M) continue;
            if(vv.map[nx][ny] != 1 && dist[nx][ny] > dist[x][y] + 1){
                dist[nx][ny] = dist[x][y] + 1;
                pq.push(make_tuple(-(dist[nx][ny] + (abs(ex - nx) + abs(ey - ny))*3),nx,ny,(i+2)%4));
            }
        }
        vv.draw();
        usleep(50000); // 1000000microsecond = 1second
    }
}

