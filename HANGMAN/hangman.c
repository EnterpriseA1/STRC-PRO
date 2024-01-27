#include <stdio.h>
#include <stdlib.h>


void in_array(char *arr,char y,int arr_length,int *inx){
    int i;
    for(i = 0 ; i < arr_length ; i++){
        if (arr[i] == y){
            arr[i] = '-';
        }
    }
}  

int main()
{
    int length = 0;
    int con = 1;
    int i;
    char *x = malloc(sizeof(char) * 1);
    char current_read;
    while (con){
        scanf("%c", &current_read);
        if (current_read == '\n'){
            con = 0;
        }
        else{
            if (current_read != ' '){
                char *temp = realloc(x, (length + 1) * sizeof(char));
                if (temp != NULL){
                    x = temp;
                    x[length] = current_read;
                    length++;
                }
            }
        }
    }
    x[length] = '\0';
    char *copy_x = malloc(sizeof(char) * length);
    for (int i = 0 ; i < length ; i++){
        copy_x[i] = x[i];
    }
    copy_x[length] = '\0';
    char input_;
    for (scanf("%c", &input_); input_ != '0'; scanf("%c", &input_)){
        int inx = -1;
        in_array(copy_x,input_,length,&inx);
    }
    for (i = 0 ; i < length ;i++){
        if (copy_x[i] != '-'){
            x[i] = '-';
        }
    }
    
    printf("%s",x);
}

