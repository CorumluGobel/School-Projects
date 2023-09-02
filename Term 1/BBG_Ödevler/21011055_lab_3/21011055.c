#include <stdio.h>

int main(){
	
	int N, M, i, j, toplam, bosSatir[100];
	
	printf("Matris Buyuklugunu Girin: ");
	scanf("%d %d", &N, &M);
	
	int matris[N][M];
	
	printf("Matris Elemanlarini Giriniz: \n");
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			scanf("%d", &matris[i][j]);
		}
	}
	
	for(i = 0; i < N; i++){
		for(j = 0; j < M; j++){
			printf("%2d", matris[i][j]);
		}
		printf("\n");
	}
	
	printf("Bos Satir: ");
	
	for(i = 0; i < N; i++){
		toplam = 0;
		for(j = 0; j < M; j++){
			toplam = toplam + matris[i][j];
		}
		if(toplam == 0){
			bosSatir[i] = i + 1;
			printf("%d ", bosSatir[i]);
		}
	}
	return 0;
}
