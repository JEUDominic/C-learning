#include<stdio.h>

// The inner struct...
struct row{
	int x;
	int y;
};
// The outside struct...
struct matrix{
	struct row r1;
	struct row r2;
};
void printRect(struct matrix r){
	printf("<%d,%d>\n<%d,%d>\n\n",r.r1.x,r.r1.y,r.r2.x,r.r2.y);
}

int main(){
	int i;
	struct matrix I[]={
	//This brace is for array...
		{{1,0},{0,1}},
	//The row r1...The outside brace is for struct matrix...
		{{2,0},{0,2}},
	//The row r2...The insiade brace is for struct row...
	};
	for (i=0;i < 2;i++){
		printRect(I[i]);//Send the struct to funtion...
	};

	return 0;
} 
