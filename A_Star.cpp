#include "A_Star.h"
Visual A_Star::Init(int ts,int mnum){
    if(ts<10000) timeSet = 10000;
    timeSet = ts;
    Visual vv;
    vv.read_map(mnum);
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
int A_Star::H_Func(int nx,int ny,int g,int h){
    if(h == 1) return H1(nx,ny,g);
    else if(h == 2) return H2(nx,ny,g);
}
int A_Star::H1(int nx,int ny,int g){ // Manhattan_Distance * g
    return g*(abs(ex - nx) + abs(ey - ny));
}
int A_Star::H2(int nx,int ny,int g){ // Distance * g
    return sqrt((ex-nx)*(ex-nx) + (ey-ny) * (ey-ny)) * g;
}
int A_Star::A_Star_Run(int tset, int mnum, int hnum,int hg){
    int g;
    Visual vv = Init(tset,mnum);
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
        if(vv.map[x][y] == 3) return dist[x][y];
        for(int i = 0;i<4;i++){
            if(i == dir) continue;
            nx = x+dx[i];
            ny = y+dy[i];
            if(nx<0||ny<0||nx>=vv.N||ny>=vv.M) continue;
            if(vv.map[nx][ny] != 1 && dist[nx][ny] > dist[x][y] + 1 && vv.state[nx][ny] < 2){
                dist[nx][ny] = dist[x][y] + 1;
                pq.push(make_tuple(-(dist[nx][ny] + H_Func(nx,ny,hg,hnum)),nx,ny,(i+2)%4));
            }
        }
        vv.draw();
        vv.state[x][y] = 2;
        printf("iteration : %d / inqueue : %d\n",itr,(int)pq.size());
        usleep(timeSet); // 1000000microsecond = 1second
    }
}

