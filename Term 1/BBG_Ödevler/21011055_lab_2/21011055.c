#include <stdio.h>
#define N 5000


int main(void){
	
	FILE *fp;
	char text[N];
	
	int i=0, j;
	
	
	if((fp = fopen ("soru3.txt", "r")) == NULL){
		printf("pipi");
		return 1;
	}
	fgets(text, N-1, fp);
	
	
	while(text[i] != '\0'){
		if('a'<=text[0]<='z'){
			text[0] = text[0] - 32;
		}
		if(text[i] == '.' && 'a'<=text[i+1]<='z'){
			text[i+1] = text[i+1] - 32;
		}
		i++;
	}
	
	printf("%s",text);
	return 0;
	
	
}
