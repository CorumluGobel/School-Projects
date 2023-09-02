#include <stdio.h>
#define N 100
#define M 100

void matrisYap(int m, int n, int i);
int main(){
	int m, n, i;
	
	matrisYap(m, n, i);
	
	return 0;
	
}
void matrisYap(int m, int n, int i){
	do{
		printf("Matris Buyuklugu: ");
		scanf("%d %d", &m, &n);
	}while(n>N && m>M);
}
