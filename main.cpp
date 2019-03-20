#include "A_Star.h"
int main(){
    A_Star A;

int t,m,h,g;
    system("clear");
    printf("\nSet the ShowSpeed(Microsecond = 1/10^6second)\n");
    printf("<Recommand 10000 ~ 50000 / minimum = 10000>   : ");
    scanf("%d",&t);
    printf("Choose the map number : ");
    scanf("%d",&m);
    printf("Choose Huristic Function : ");
    scanf("%d",&h);
    printf("Choose the Weight : ");
    scanf("%d",&g);
    A.A_Star_Run(t,m,h,g);
}

