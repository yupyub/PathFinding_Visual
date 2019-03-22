#include "DFS.h"
Visual DFS::Init(int ts,int mnum){
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
void DFS::sol_path(int x,int y){
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
int DFS_F(int x,int y){ // 

}
int DFS::DFS_Run(int tset, int mnum){
    int g;
    vv = Init(tset,mnum);
    dist[sx][sy] = 0;
    vv.state[sx][sy] = 2;
    DFS_F(sx,sy);    
    if(dist[ex][ey] != INF){
        sol_path(ex,ey);
        vv.draw();
        printf("Total Iteration : %d / Path Distance : %d\n",itr,dist[ex][ey]);
    }
}

