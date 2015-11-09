//
//  TASK3
//  Assignment3
//
//  Created by JEU.20151106
//  Recode by JEU.20151110

#include<stdio.h>

int prime(unsigned int integer);
int biggestDivisor(unsigned int integer);
int main(){
    unsigned int p;// Positive number...
    int checkValue;// Stored the return value from prime funtion...
    int divisor;
    printf("Please input a positive number:");
    scanf("%d",&p);
    
    // Getting the value that could check its prime...
    checkValue = prime(p);
    
    
    if(checkValue == 0)
        printf("%d is a prime number.\n",p);
    else{
        divisor = biggestDivisor(p);
        printf("%d is not prime number, and its biggest divisor is %d.\n",p,divisor);
    }
}

int prime(unsigned int integer){
    int i;
    
    // Looking through
    for(i = integer - 1;i >= integer/2;i--){
        if(integer % i == 0)
            return 1;
    }
    
    return 0;
}

int biggestDivisor(unsigned int integer){
    int i;
    int divisor;
    for(i = 2;i < integer; i++){
        if(integer % i == 0)
            return integer / i;
        
    }
}