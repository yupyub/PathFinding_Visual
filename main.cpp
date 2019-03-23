#include "A_Star.h"
#include "Dijkstra.h"
#include "DFS.h"
int main(){
    Dijkstra D;
    A_Star A;
    DFS F;

    int a,t,m,h,g;
    system("clear");
    printf("Choose the Algorithm\n");
    printf("1. Dijkstra\n2. A Star\n3. DFS\n");
    printf("Write the number : ");
    scanf("%d",&a);
    system("clear");
    printf("Set the ShowSpeed(Microsecond = 1/10^6second)\n");
    printf("<Recommand 10000 ~ 50000 / minimum = 10000>   : ");
    scanf("%d",&t);
    system("clear");
    printf("< Map Size >\n1. 10 x 20\n2. 20 x 50\n3. 40 x 70\n");
    printf("You can add your own map (ex) name : map4.txt)\n"); 
    printf("Choose the map number : ");
    scanf("%d",&m);
    system("clear");
    switch(a){
        case 1:
            D.Dijkstra_Run(t,m);
            break;
        case 2:
            printf("< A Star Algorithm Huristic Function>\n");
            printf("1. Manhattan_Distance * g\n");
            printf("2. Real_Distance * g\n");
            printf("Choose the Huristic Function : ");
            scanf("%d",&h);
            printf("Choose the Weight : ");
            scanf("%d",&g);
            A.A_Star_Run(t,m,h,g);
            break;
        case 3:
            F.DFS_Run(t,m);  
            break;
    }
}

