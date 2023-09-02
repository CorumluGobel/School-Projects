#include <stdio.h>

#define MAX 7

void codeCheck(int n, char code[MAX]){
	int i;
	int isOkay;
	int counter;
	int j;
	for(i = 0; i < n; i++){
		isOkay = 0;
		while(isOkay == 0){
			printf("%d. isin harf kodu: ", i+1);
			scanf("%s", &code[i]);
			counter = 0;
			j = 0;
			while(code[j] != NULL){
				if(code[i] == code[j] && i!=j){
					counter++;
				}
				j++;
			}
			if(counter == 0)
				isOkay = 1;
			
		}
	}
}
void timeCheck(int n, int times[2][MAX]){
	int i;
	int isOkay;
	for(i = 0; i < n; i++){
		isOkay = 0;
		printf("%d. isin baslangic zamani: ", i+1);
		scanf("%d", &times[0][i]);
		while(isOkay == 0){	
			printf("%d. isin bitis zamani: ", i+1);
			scanf("%d", &times[1][i]);
			if(times[0][i] < times[1][i])
				isOkay = 1;	
		}
	}
	
}

void GanttDraw(char code[MAX], int times[2][MAX], int n){
	int i;
	int j;
	for(i = 0; i < n; i++){
		for(j = 1; j < times[0][i]; j++){
			printf("_");
		}
		for(j; j <= times[1][i]; j++){
			printf("%c", code[i]);
		}
		printf("\n");
	}
	
}

int main(){
	
	int n, i, times[2][MAX];
	char code[MAX];
	
	printf("Yapilacak isin sayisini giriniz: ");
	scanf("%d", &n);
	printf("\n\n");
	printf("Yapilacak isin kodunu giriniz: \n");
	codeCheck(n, code);
	printf("\n\n");
	timeCheck(n, times);
	
	printf("Gantt Diyagrami: \n\n");
	GanttDraw(code, times, n);
	
	return 0;
}
