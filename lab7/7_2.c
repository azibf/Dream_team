#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char decimalToBinary(int decimalnum, int index)
{
    char binarynum[8]= "       \0";
    int i = 0;
    int temp = 0;
    while (decimalnum > 0){
        temp = decimalnum%2;
        if(temp == 1){
            if (i ==0 || i==3 || i==6) binarynum[6-i] = '-';
            else binarynum[6-i]= '|';
        }
        else{
            binarynum[6-i] = ' ';
        }
        i++;
        decimalnum = decimalnum/2;
    }
    return(binarynum[index]);
}

size_t my_strlen(const char *str)
{
    int n = 0;
    while (str[n] != '\0') ++n;
    return n;
}

int main(){
    char digits[11] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123, 8};
    char input[100];
    int *user_input;
    
    scanf("%[^\n]s", input);
    int len = my_strlen(input);

    for(int i = 0; i<len; i++){
        if(input[i] != ' ' && input[i] != '-') user_input[i] = input[i] - '0';
        else{
            if (input[i] == '-'){
                user_input[i] = 10;
            } 
            else user_input[i] = input[i];
        }
    }

    int j = 0;

    for(int j = 0; j<5;j++){
        for(int i=0; i < len;i++){
            if ((j%2) == 0) printf(" %c  ", decimalToBinary(digits[user_input[i]], j+j/2));
            else printf("%c %c ", decimalToBinary(digits[user_input[i]], j+j/2), decimalToBinary(digits[user_input[i]], j+j/2+1));
        }
        printf("\n");
    }
}