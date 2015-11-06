//
//  TASK4
//  Lab7
//
//  Created by JEU.20151030
//  Recode by JEU.20151102 Add Comments.

#include<stdio.h>
float* exchange(float a[], int n);//Function prototype...

int main(){
	int i = 0;
	float value[50]={};
    float *returnValue;
	printf("Please input the values you want to do comparation(end with -1):\n");
	//Ge the input and store in array of value...
	do {
		scanf("%f",&value[i]);
		if (value[i] == -1){
			break;
		}
		i++;
	}while(1);
	// Do the bubble sorting.... 
	returnValue = exchange(value,i);
	free(returnArray);
	printf("The returnArray is %f\n",returnArray[0]);
  
	//Printf the max&min by using array of value...    
	printf("The min is %f\n",value[0]);
    printf("The min from return value is %f\n",returnValue[0]);
	printf("The max is %f\n",value[i-1]);
    printf("The max from return value is %f\n",returnValue[1]);
    
    return 0;

}

//Try to return array to main funtion...
float* exchange(float a[], int n){
	float temp;
    static float returnArray[2];// How to free this memory..
	int i, j;
	//....................Bubble Sorting................
    for (j = 0; j < n - 1; j++){//For n numbers, do this comparation n-1 times...
        for (i = 0; i < n - 1 - j; i++){
            if(a[i] > a[i + 1]){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
	}
    returnArray[0] = a[0];
    returnArray[1] = a[n-1];
    
    return returnArray;
}


