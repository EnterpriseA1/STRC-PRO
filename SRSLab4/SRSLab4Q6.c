#include <stdio.h>

int main(){
    char ISBN[11] = {'\0'};
    scanf("%s",ISBN);
    int result = 0;
    for (int i = 0 ; i < 11 ; i++){
        result += (ISBN[i] - '0') *  (11 - (i + 1));
    }
    int valid = (result % 11) == 0;
    printf("%s",(valid) ? "valid":"invalid");

}