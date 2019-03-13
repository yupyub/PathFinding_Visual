#include "visual.h"
int arr[10][10];
int a = 0,b = 0;
void test_draw(){
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}
void test_update(int i,int j){
    arr[i][j] = (arr[i][j]+1)%10;
}
int visual(){
    init_keyboard();
    while(1){
        if(_kbhit()){
            char kc = _getch();
            _putch(kc);
            if(kc == 'q') break;
        }
        system("clear");
        test_draw();
        test_update((a++)%10,(b++)%10);
        usleep(200000); // 1000000microsecond = 1second
    }
    close_keyboard();
}

