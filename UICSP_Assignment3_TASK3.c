//
//  TASK3
//  Assignment3
//
//  Created by Alicia.20151106


#include<stdio.h>

int whetherPrime(int integer);

int main(){
	unsigned int p;// Positive number...
	int divisor;
	printf("Please input a positive number:");
	scanf("%d",&p);

	// Getting the value that could check its prime...
	divisor = whetherPrime(p);

	if(divisor == 1)
		printf("%d is a prime number.\n",p);
	else
		printf("%d is not prime number, and its biggest divisor is %d.\n",p,divisor);
	
}

int whetherPrime(int integer){
	int i;
	int divisor;

	// Get the biggest divisor except itself...
	for(i = 1;i < integer/3;i++){
		if(integer%i == 0)
			divisor = i;
	}

	return divisor;
}