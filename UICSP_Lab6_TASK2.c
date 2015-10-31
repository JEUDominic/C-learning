// Code by Alicia.20151030

#include<stdio.h>
void exchange(float a[], int n);//Function prototype...

int main(){
	int i = 0;
	float value[50]={};
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
	exchange(value,i);
	
	//Printf the max&min by using array of value...    
	printf("The min is %f\n",value[0]);
	printf("The max is %f\n",value[i-1]);

}

void exchange(float a[], int n){
	float temp;
	int i, j;
	//....................Bubble Sorting................
    for (j = 0; j < n - 1; j++){
        for (i = 0; i < n - 1 - j; i++){
            if(a[i] > a[i + 1]){
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
	}

}


