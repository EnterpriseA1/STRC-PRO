#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int n;
    scanf("%d",&n);
    int nearest_fpair = 0,nearest_spair = 0;
    double distance = 0;
    double pair_coor[n][2];
    int i,j,k;
    for (i = 0; i < n; i++){
        for (j = 0 ; j < 2;j++){
            scanf("%lf",&pair_coor[i][j]);
        }
    }
    for (j = 0 ; j < n;j++){
        for (k = j + 1 ; k < n;k++){
            double cal;
            cal = sqrt(pow(pair_coor[j][0] - pair_coor[k][0],2) + pow(pair_coor[j][1] - pair_coor[k][1],2));
            if (j == 0){
                distance = cal;
                nearest_fpair = j + 1;
                nearest_spair = k + 1;
            }
            else{
                if (cal < distance){
                    distance = cal;
                    nearest_fpair = j + 1;
                    nearest_spair = k + 1;
                }
            }
        }
    }
    printf("%d %d %.2lf",nearest_fpair,nearest_spair,distance);
}
