#include <stdio.h>
#include <stdlib.h>

int function(int N);

int main(){
	
	
	int* array;
	int N, i = 0, size = 2;
	array = (int*)malloc(size*sizeof(int));
	
	printf("Enter starting number: ");
	scanf("%d", &N);
	array[0] = N;
	while(array[i] != 1){
		if(size-1 == i){
			size = size*2;
			array = (int*)realloc(array,size*sizeof(int));
		}
		
		array[i+1] = function(array[i]);
		
		i++;
	}
	i = 0;
	while(array[i] != 1){
		printf("%d ", array[i]);
		i++;
	}
	printf("%d", array[i]);
	printf("\nNumber of Elements: %d\n", i+1);
	printf("Array Size: %d", size);
	free(array);
	
	return 0;
}

int function(int N){
	if(N % 2 == 0){
		N = N/2;
	}
	else{
		N = 3*N+1;
	}
	return N;
}
