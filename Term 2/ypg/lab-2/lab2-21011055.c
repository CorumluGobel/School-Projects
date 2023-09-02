#include <stdio.h>
#define N 20
#define M 20

int main(){
	
	int n, m, i ,j, matrix[N][M] = {0}, rota[20] = {0}, rotaBitti = 0, a, b;
	
	do{
		printf("Matris Buyuklugu: ");
		scanf("%d %d", &n, &m);
	}while(n>N && m>M);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < m; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	i = 0, a = 0, b = 0;
	while(rotaBitti == 0){
		if(matrix[a+1][b] == 1){
			rota[i] = 2;
			a++;
			i++;
		}
		else if(matrix[a][b+1] == 1){
			rota[i] = 1;
			b++;
			i++;
		}
		else{
			rotaBitti = 1;
		}
	}
	if(rota[0] == 0){
		printf("Rota Yok");
	}
	else{
		j = 0;
		while(j < i){
			printf("%d ", rota[j]);
			j++;
		}
	}
	
	
	return 0;
}
