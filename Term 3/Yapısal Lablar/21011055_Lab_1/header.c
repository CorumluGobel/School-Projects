#include <stdio.h>
#include "header.h"

void findNumber(int *s1, int *s2, int *b1, int *b2, int array[]){
	
	int i;
	for(i = 0; i < 7; i++){
		if(array[i]>*b1){
			*b2 = *b1;
			*b1 = array[i];
		}
		else if(array[i]>*b2){
			*b2 = array[i];
		}
		if(array[i]<*s1){
			*s2 = *s1;
			*s1 = array[i];
		}
		else if(array[i]<*s2){
			*s2 = array[i];
		}
	}
}
