#include<stdio.h>

typedef struct{
	int *array;
	int size;
}Array;

Array array_create(int init_size){
	Array a;
	a.size = init_size;
	a.array = (int*)malloc(sizeof(int)*a.size);
	return a;
}

void array_free(Array *a){
	free(a->array);
	a->array = null;
	a->size = 0;
}

int main(int argc, char const *argv[]){
	Array a = array_create(100);
	array_free(&a);
	
	return 0;
}