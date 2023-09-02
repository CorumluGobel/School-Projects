#include <stdio.h>
#define SIZE 20

int main(){
	
	int array[SIZE], i, j, counter, n;
	
	//input
	do{
    	printf("Enter the size of array: ");
   		scanf("%d",&n);
	}
	while(n > SIZE);
	printf("\nEnter the elements:\n");
	for(i = 0; i < n; i++){
		scanf("%d", &array[i]);
	}
	//control
	i = 0;
	
	while(i < n){
		j = i + 1;
		counter = 0;
		while(counter < array[i] && j < n && array[i] > 0){
			if(array[j] == array[i]){
				counter++;
				}
			j++;
		}
		if(counter + 1 == array[i])
			printf("%d ", array[i]);
		i++;
	}
	return 0;
	
}
