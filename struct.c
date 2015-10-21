#include<stdio.h>

struct row{
	int x;
	int y;
};

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
		{{1,0},{0,1}},
		{{2,0},{0,2}},
	};
	for (i=0;i < 2;i++){
		printRect(I[i]);
	};

	return 0;
} 
