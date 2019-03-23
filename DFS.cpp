#include "DFS.h"
void DFS::Init(int ts,int mnum){
    if(ts<10000) timeSet = 10000;
    timeSet = ts;
    scnt = 0;
    itr = 0;
    dx[0] = dx[2] = dy[1] = dy[3] = 0;
    dx[1] = dy[0] = 1;
    dx[3] = dy[2] = -1;
    vv.read_map(mnum);
    for(int i = 0;i<vv.N;i++){
        for(int j = 0;j<vv.M;j++){
            dist[i][j] = INF;
            vv.state[i][j] = 0;
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
}
void DFS::sol_path(int x,int y){
    if(dist[x][y] == 0) return;
    vv.state[x][y] = 1;
    vector<tuple<int,int,int> > v;
    for(int i = 0;i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0||ny<0||nx>=vv.N||ny>=vv.M) continue;
        v.push_back(make_tuple(dist[nx][ny],nx,ny));
    }
    sort(v.begin(),v.end());
    sol_path(get<1>(v[0]),get<2>(v[0]));
}
int DFS::DFS_H(int x,int y,int dir){ // DFS + Heuristic
    vv.state[x][y] = 3;
    vv.draw();
    itr++;
    printf("Total Iteration : %d\n",itr);
    printf("DFS Stack Count : %d\n",scnt);
    usleep(timeSet);
    vv.state[x][y] = 2;
    if(x == ex && y == ey) return 1;
    int si = 0;
    if(dir%2){
        if(ey>=y) si = 0;
        else si = 2;
    }
    else{
        if(ex>=x) si = 1;
        else si =3;
    }
    for(int i = 0;i<4;i++){
        int ni = (si+i)%4;
        int nx = x+dx[ni];
        int ny = y+dy[ni];
        if(nx<0||ny<0||nx>=vv.N||ny>=vv.M) continue;
        if(vv.map[nx][ny] != 1 && dist[nx][ny] > dist[x][y] + 1){
            if(dist[nx][ny] == INF){
                dist[nx][ny] = dist[x][y] + 1;
                scnt++;
                int ret = DFS_H(nx,ny,ni);
                scnt--;
                if(ret == 1)return 1;
            }
            else dist[nx][ny] = dist[x][y] + 1;
        }
    }
    return 0;
}
int DFS::DFS_Run(int tset, int mnum){
    Init(tset,mnum);
    dist[sx][sy] = 0;
    if(DFS_H(sx,sy,-1)){
        sol_path(ex,ey);
        vv.draw();
        printf("Total Iteration : %d / Path Distance : %d\n",itr,dist[ex][ey]);
    }
}

