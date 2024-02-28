#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 

int Indexof(int [][2],char);

int main ()
{
    char str1[100], str2[100], str_rem[100];
    int str_fequen[100][2];
    int i = 0, j = 0, k = 0,count = 0;
    printf ("Enter the First string:\n");
    fflush (stdin);
    gets(str1);
    printf ("Enter the Second string:\n");
    gets(str2);
    for(i = 0 ; i < 100;i++){
        str_fequen[i][0] = -1;
        str_fequen[i][1] = 0;
    }
    for (i = 0; str1[i]!= '\0'; i++)
    {
        int index = Indexof(str_fequen,str1[i]);
        if (index == -1 && str1[i] != ' '){
            str_fequen[count][0] = str1[i];
            count++;
        }
        for (j = 0; str2[j] != '\0'; j++)
        {
            if (str1[i] == str2[j] && str1[i] != ' ' && str2[j] != ' ')
            {
                int index_s = Indexof(str_fequen,str2[j]);
                str_fequen[index_s][1]++;
                continue;
            }
            else
            {
                str_rem[k] = str2[j];
                k++;
            }
        }
        str_rem[k] = '\0';
        strcpy(str2, str_rem);
        k = 0;
    }
    for (i = 0 ; str_fequen[i][0] != -1 ; i++){
        if (str_fequen[i][1]){
            printf("Delete character : [%c , %d times]\n",str_fequen[i][0],str_fequen[i][1]);
        }
    }
    printf("Character(s) not found : [");
    int length_notfound = 0;
    for (i = 0; str_fequen[i][0] != -1; i++){
        length_notfound++;
    }
    char CHANOMKAIMOOK[++length_notfound];
    CHANOMKAIMOOK[length_notfound - 1] = '\0';
    int temp = 0;
    for (i = 0 ; str_fequen[i][0] != -1 ; i++){
        if (!str_fequen[i][1]){
            CHANOMKAIMOOK[temp] = str_fequen[i][0];
            temp++;
        }
    }
    if (temp == 0){
        printf("None");
    }
    else{
        for (i = 0 ; i < temp ; i++){
            if (i == temp - 1){
                printf("%c",CHANOMKAIMOOK[i]);
            }
            else{
                printf("%c, ",CHANOMKAIMOOK[i]);
            }
        }
    }
    printf("]");
    printf ("\nOn removing characters from second string we get: %s\n", str_rem);
    return 0;
}

int Indexof(int str_fequen[][2],char y){
    int i;
    for (i = 0 ; str_fequen[i][0] != -1 ;i++){
        if (str_fequen[i][0] == y){
            return i;
        }
    }
    return -1;
}