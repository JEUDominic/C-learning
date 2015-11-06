//
//  TASK4
//  Lab7
//
//  Created by JEU.20151030
//  Recode by JEU.20151031
//  Recode by JEU.20151105

#include<stdio.h>
#define NUM 50
#define LENGTH 20
void stringCompare(char compare[NUM][LENGTH],int r);//Function prototype...
void changeCases(char change[NUM][LENGTH],int r);//Function prototype...

int main(){
	char STRING[NUM][LENGTH] = {};
    char temp[1][LENGTH] = {};
	int r;// Row...
	int c;// Column...
    int j;// Doing the bubble sorting... The j th time...
    int i;// The i th row while looking through the whole string array..
    int t;// The t th character in array temp...
	printf("Please input names(end with 0):\n");
	// Get the strings and storing in 2-dimentions array...
	for(r = 0;r < NUM;r++){
		scanf("%s",STRING[r]);
		if (STRING[r][0] == '0'){
			break;
		} 
	}

	stringCompare(STRING,r);
	changeCases(STRING,r);
	
    // Using bubble sorting to represent in alphabetical order...
    for(j = 0;j < r ; j++){
        for (i = 0;i < r - j - 1 ; i++){
            for(c = 0;c < LENGTH; c++ ){//Checking from the first character...
                if(STRING[i][c] > STRING[i+1][c]){
					
                    // If string[i] is less than string[i+1], then do the exchange...
                    for(t = c;t < LENGTH; t++){
                        temp[0][t] = STRING[i][t];
                        STRING[i][t] = STRING[i+1][t];
                        STRING[i+1][t] = temp[0][t];
                    }
                    break;
                }
                else if(STRING[i][c] == STRING[i+1][c]){
                    // If the c th character in these two strings are same, then check the next character...
                    continue;
                }
                else if(STRING[i][c] < STRING[i+1][c]){
                    break;
				}
            }
        }
    }
    
    // Print out all the value in upper case and alphabetical...
	printf("Print out all the value in upper case and alphabetical:\n");
    for(i = 0; i < r; i++)
            printf("%s\n",STRING[i]);

}
//Comparing the strings...
void stringCompare(char compare[NUM][LENGTH],int row){
    int r;
	int c;
    int j;
	int sameNumber = 0;
	for(r = 0; r < row; r++){// For a string compare[r]...
		for(j = r+1 ; j <= row ;j++ ){// Colleting other strings compare[j]...
			for(c = 0; c <= LENGTH; c++){// Comparing them by characters...
				if( compare[r][c] == compare[j][c]  && compare[r][c] == '\0')
					break;
				if( compare[r][c] == compare[j][c])
                    continue;// Do comparint step by step...
                if ( compare[r][c] != compare[j][c] || compare[r][c] == '\0')
					goto L;// If there is a difference then goto L check another string compare[j+1]...
			}
            //If all the characters are the same...
            printf("%s and %s are the same.\n",compare[r],compare[j]);
            sameNumber++;
       
            L: continue;
		}
	}
	switch(sameNumber){
	case 0:
		printf("There is no one pair of same names. \n",sameNumber);
		break;
	case 1:
		printf("There is %d pair of same names. \n",sameNumber);
		break;
	default:
		printf("There are %d pairs of same names. \n",sameNumber);
		break;


	}
}

void changeCases(char change[NUM][LENGTH],int row){
    int r;
    int c;
    for(r = 0; r <= row; r++){// For a string change[r]...
        for(c = 0; c <= LENGTH; c++){
            if(change[r][c]>='a' && change[r][c]<='z'){
                change[r][c] = change[r][c] - 'a' + 'A';
			}
        }
    }
}
