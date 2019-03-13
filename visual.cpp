#include "visual.h"
int arr[10][10];
int a = 0,b = 0;
int visual(){
    init_keyboard();
    while(1){
        if(_kbhit()){
            char kc = _getch();
            _putch(kc);
            if(kc == 'q') break;
        }
        system("clear");
        //test_draw();
        //test_update((a++)%10,(b++)%10);
        usleep(200000); // 1000000microsecond = 1second
    }
    close_keyboard();
}

int read_map(){
    FILE *fp;
    fopen(&fp,"map.txt","r");
    if(fp == null){
        printf("Map Open Error\n");
        return -1;
    }
    fscanf(fp,"%d %d",&N,&M);
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            fscanf(fp,"%1d",&map[i][j]);
        }
    }
    fclose(fp);
}
void draw(){
    system("clear");
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            printf("%d",state[i][j]); //upgrade later
        }
        printf("\n");
    }
}
