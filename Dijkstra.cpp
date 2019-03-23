#include "Dijkstra.h"
Visual Dijkstra::Init(int ts,int mnum){
    if(ts<10000) timeSet = 10000;
    timeSet = ts;
    dx[0] = dx[2] = dy[1] = dy[3] = 0;
    dx[1] = dy[0] = 1;
    dx[3] = dy[2] = -1;
    Visual vv;
    vv.read_map(mnum);
    for(int i = 0;i<vv.N;i++){
        for(int j = 0;j<vv.M;j++){
            vv.state[i][j] = 0;
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
void Dijkstra::sol_path(int x,int y){
    if(dist[x][y] == 0) return;
    vv.state[x][y] = 1;
    for(int i = 0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=vv.N||ny>=vv.M) continue;
        if(dist[nx][ny] == dist[x][y] -1){
            sol_path(nx,ny);
            return;
        }
    }
}
int Dijkstra::Dijkstra_Run(int tset, int mnum){
    int g;
    vv = Init(tset,mnum);
    priority_queue<tuple<int,int,int,int> >pq;
    dist[sx][sy] = 0;
    vv.state[sx][sy] = 2;
    pq.push(make_tuple(0,sx,sy,-1));
    int x,y,dir,nx,ny,itr = 0;
    while(!pq.empty()){
        x = get<1>(pq.top());
        y = get<2>(pq.top());
        dir = get<3>(pq.top());
        pq.pop();
        itr++;
        vv.state[x][y] = 3;
        if(vv.map[x][y] == 3) break;
        for(int i = 0;i<4;i++){
            if(i == dir) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=vv.N||ny>=vv.M) continue;
            if(vv.map[nx][ny] != 1 && dist[nx][ny] > dist[x][y] + 1 && vv.state[nx][ny] < 2){
                dist[nx][ny] = dist[x][y] + 1;
                pq.push(make_tuple(-dist[nx][ny],nx,ny,(i+2)%4));
            }
        }
        vv.draw();
        vv.state[x][y] = 2;
        printf("Total Iteration : %d / inqueue : %d\n",itr,(int)pq.size());
        usleep(timeSet);
    }
    if(dist[ex][ey] != INF){
        sol_path(ex,ey);
        vv.draw();
        printf("Total Iteration : %d / Path Distance : %d\n",itr,dist[ex][ey]);
    }
}

