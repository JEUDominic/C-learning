//
//  TASK1
//  LAB8
//
//  Created by JEU on 20151106



#include <stdio.h>
int stringCompare(char compare[2][21]);


int main() {
    // Declare 2dimensions arrays and initialing...
    char input[2][21] = {};
    int returnValue;
    // Get the two strings and estimate each length...
    printf("Please input the first string:");
    gets(input[0]);
    printf("Please input the second string:");
    gets(input[1]);
    
	//Give strings to the compare function...
    returnValue = stringCompare(input);

	//Print...
    if (returnValue < 0)
        printf("%s is smaller than %s.\n",input[0],input[1]);
    else if (returnValue == 0)
        printf("%s is equal to %s.\n",input[0],input[1]);
    else
        printf("%s is larger than %s.\n",input[0],input[1]);
    
}

int stringCompare(char compare[2][21]){
    int c;//The c th character in each string...
    int difference;
    for(c = 0;compare[0][c] != '\0' || compare[1][c] != '\0';c++){
        difference = compare[0][c] - compare[1][c];
		if(difference == 0)
			continue;
		if(difference != 0)
			break;
    }
	printf("%d\n",difference);
	return difference;
}