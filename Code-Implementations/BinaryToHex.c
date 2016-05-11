#include<stdio.h>
int main(){

    long int binaryNumber,hexadecimalNumber=0,j=1,remainder;

    printf("Enter any number any binary number: ");
    scanf("%ld",&binaryNumber);

    while(binaryNumber!=0){
    remainder=binaryNumber%10;
    hexadecimalNumber=hexadecimalNumber+remainder*j;
        j=j*2;
        binaryNumber=binaryNumber/10;
      }

    printf("Equivalent hexadecimal value: %lX",hexadecimalNumber);
}

