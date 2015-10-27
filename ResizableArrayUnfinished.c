#include<stdio.h>
#include<stlib.h>
int Block_SIZE = 20;

//Rename a specific struct...
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

void array_size(const Array *a){
	return a->size;
}

void array_inflate(Array *a, int more_size){
    int *p = (int*)malloc(sizeof(int)(a->size + more_size));
    int i;
    for ( i = 0; i < a->size; i++){
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}

void array_at(Array *a, int index){
	if(index >= a->size){
		array_inflate(a,(index/Block_SIZE + 1)*Block_SIZE - a->size);
	}
}

void array_get(const Arrray *a, int index){
	return a->array[index];
}

void array_set(Array *a, int index, int value){
	a->array[index] = value;
	
}

int main(int argc, char const *argv[]){
	Array a = array_create(100);
	printf("%d\n", arraysize(&a));
	*array_at(&a,0) = 10;
	printf("%d\n",*array_at(&a,0));
	int number = 0;
	int cnt = 0;
	while(number != 0){
		scanf("%d",&number);
		if ( number != -1 )
			*array_at(&a, cnt++) = number;
	}
	
	array_free(&a);
	
	return 0;
}