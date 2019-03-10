
#include <termios.h> // usleep
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int arr[10][10];
void draw(){
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++){
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}
void update(int i,int j){
    arr[i][j]++;
}
int main(){
    int a = 0,b = 0;
    while(1){
        if(kbhit()){
            char kc = getchar();
            if(kc == 'q') break;
        }
        system("clear");
        draw();
        update((a++)%10,(b++)%10);
        usleep(100); // 1ms = 1sec
    }
}
