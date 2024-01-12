#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int i;
    float distance = 0;
    for (i = 0 ; i < n;i++){
        int speed;
        float time;
        scanf("%d %f",&speed,&time);
        distance += (speed * (time / 60));
    }
    printf("%.1f",distance);
}