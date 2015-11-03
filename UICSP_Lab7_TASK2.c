// Code by Alicia.20151030
// Recode by Alicia.20151102 Add Comments.
#include<stdio.h>
char* exchange(float a[], int n);//Function prototype...

int main(){
	int i = 0;
	float value[50]={};
    float returnValue[2];
	printf("Please input the values you want to do comparation(end with -1):\n");
	//Ge the input and store in array of value...
	do {
		scanf("%f",&value[i]);
		if (value[i] == -1){
			break;
		}
		i++;
	}while(1);
	//Do the bubble sorting.... 
	returnValue = exchange(value,i);
  
	//Printf the max&min by using array of value...    
	printf("The min is %f\n",value[0]);
    printf("The min from return value is %f\n",returnValue[0]);
	printf("The max is %f\n",value[i-1]);
    printf("The max from return value is %f\n",returnValue[i-1]);
    
    return 0;

}

//Try to return array to main funtion...
char* exchange(float a[], int n){
	float temp;
    float returnArray[2];
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
    returnArray[1] = a[1];
    
    return &returnArray;

}


