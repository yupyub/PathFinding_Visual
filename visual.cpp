#include "visual.h"
/*
int Visual::visual(){
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
*/
int Visual::read_map(int mnum){
    FILE *fp;
    std::string name = "MAP/map";
    name += std::to_string(mnum);
    name += ".txt";
    fp = fopen(name.c_str(),"r");
    if(fp == NULL){
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
void Visual::draw(){
    system("clear");
    for(int i = 0;i<M+2;i++) printf("#");
    printf("\n");
    for(int i = 0;i<N;i++){
        printf("#");
        for(int j = 0;j<M;j++){
            if(map[i][j] == 1) printf("#");
            else if(map[i][j] == 2) printf("S");
            else if(map[i][j] == 3) printf("E");
            else if(state[i][j] == 1)printf("O");
            else if(state[i][j] == 3)printf("O");
            else if(state[i][j] == 2)printf(".");
            else if(state[i][j] == 0)printf(" ");
        }
        printf("#\n");
    }
    for(int i = 0;i<M+2;i++) printf("#");
    printf("\n");
}
