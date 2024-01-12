#include <stdio.h>
#include <stdlib.h>

void find_bit(char *bit, int length, int base10);
void reset_ (char *modified,char *default_,int length);
void set1_3toZero(char *modified,char *default_,int length);
void set4_6toOne(char *modified,char *default_,int length);
void reverseBit2(char *modified,char *default_,int length);
void binary(char *modified,char *default_,int length);
int base10_convert(char *bit, int length);

int main(){

    int bit_length = 8;
    int base_tenint = 0;
    scanf("%d",&base_tenint);
    int i;
    int temp_assign = 0;
    char bit_[bit_length + 1];
    char temp_char[bit_length + 1];
    for (i = 0 ; i < bit_length ; i++){
        bit_[i] = '0';
        temp_char[i] = '0';
    }
    bit_[bit_length] = '\0';
    temp_char[bit_length] = '\0';
    find_bit(bit_,bit_length,base_tenint);
    for (i = 0 ; i < bit_length ; i++){
        temp_char[i] = bit_[i];
    }
    bit_[bit_length] = '\0';
    temp_char[bit_length] = '\0';
    set1_3toZero(temp_char,bit_,bit_length);
    set4_6toOne(temp_char,bit_,bit_length);
    reverseBit2(temp_char,bit_,bit_length);
    binary(temp_char,bit_,bit_length);
    return 0;
}

void reset_ (char *modified,char *default_,int length){
    int i;
    for (i=0;i<length;i++){
        modified[i] = default_[i];
    }
    modified[length] = '\0';
}
int base10_convert(char *bit, int length) {
    int result = 0;
    int i;
    for (i = length - 1; i >= 0; i--) {
        int current = bit[i] - '0';
        int current_digit_power = 1 << (length - 1 - i);
        int sub_result = current_digit_power * current;
        result += sub_result;
    }
    return result;
}
void find_bit(char *bit, int length, int base10) {
    int divider = 2;
    while (base10 > 0 && length > 0) {
        int result = base10 % divider;
        bit[length - 1] = result + '0';
        base10 /= divider;
        length--;
    }
    while (length > 0) {
        bit[length - 1] = '0';
        length--;
    }
}
void set1_3toZero(char *modified,char *default_,int length){
    modified[length - 1] = '0';
    modified[length - 3] = '0';
    modified[length] = '\0';
    int decimal = 0;
    decimal = base10_convert(modified,length);
    printf("%d 0b%s\n",decimal,modified);
    reset_(modified,default_,length);
}
void set4_6toOne(char *modified,char *default_,int length){
    modified[length - 4] = '1';
    modified[length - 6] = '1';
    modified[length] = '\0';
    int decimal = 0;
    decimal = base10_convert(modified,length);
    printf("%d 0b%s\n",decimal,modified);
    reset_(modified,default_,length);
}
void reverseBit2(char *modified,char *default_,int length){
    int bit2 = modified[length - 2];
    if (bit2 == '0'){
        modified[length - 2] = '1';
    }
    else{
        modified[length - 2] = '0';
    }
    modified[length] = '\0';
    int decimal = 0;
    decimal = base10_convert(modified,length);
    printf("%d 0b%s\n",decimal,modified);
    reset_(modified,default_,length);
}
void binary(char *modified,char *default_,int length){
    int decimal = 0;
    decimal = base10_convert(modified,length);
    printf("%d 0b%s",decimal,modified);
    reset_(modified,default_,length);
}

