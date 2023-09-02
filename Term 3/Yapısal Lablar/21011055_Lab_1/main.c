//tek döngüde sýrasýz diziyi karþýlaþtýr baþka c dosyasýnda en küçük 2 ve en büyük 2 sayýnýn topla

#include <stdio.h>
#include "header.h"

int main(){
	
	int array[7] = {8, 23, 56, 12, 9, 24, 87};
	int s1 = 100, s2 = 100, b1 = 0, b2 = 0;
	int sToplam = 0, bToplam = 0;
	int i = 0;
	
	findNumber(&s1, &s2, &b1, &b2, array);
	
	sToplam = s1 + s2;
	bToplam = b1 + b2;
	
	for(i = 0; i < 7; i++){
		printf("%d ", array[i]);
	}
	printf("\nSmallest Numbers: %d %d Sum: %d", s1, s2, sToplam);
	printf("\nBiggest Numbers: %d %d Sum: %d", b1, b2, bToplam);
	
	return 0;
}


