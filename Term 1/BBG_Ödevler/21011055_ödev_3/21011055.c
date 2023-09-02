#include <stdio.h>
#define N 5000
int main(void){
	FILE *fp;
	char text[N];
/********* deðiþken tanýmlarý ************/
	int word, j, i = 0, k = 0, counter = 0;
		
	
	
/********* deðiþken tanýmlarý sonu ************/
 
// Dosyayý açma
	if ((fp = fopen ("soru.txt", "r")) == NULL) {
		printf("Dosya açma hatasý!");
		return 1;
	}
// Dosyadan okuma
	fgets(text, N-1, fp);
	//printf("%s\n", text);
 
/* 
* text karakter dizisi deðiþkeninde dosyadan okunan metin yer almaktadýr.
* toplam kelime sayýsýnýn hesabý ve boþluk temizleme iþlemleri -TERCÝHEN-
* bu dizi üzerinde yapýlmalýdýr. Harici dizi kullanýmý önerilmemektedir. 
*/
/********* kod bloðu ************/	
	//boþluk silme
	while(text[i] != '\0'){
		while(text[i] == ' ' && text[i+1] == ' '){
			j = i;
			while(text[j] != '\0'){
				text[j] = text[j+1];
				j++;
			}
		}
		i++;
	}
	//sondaki tek boþluðu kaldýrma
	if(text[i-1] == ' '){
		text[i-1] = text[i];
	}
	
	
	//kelime sayýsý bulma
	while(text[k] != '\0'){
		if(text[k] == ' '){
			counter++;
		}
		k++;
	}
	
	counter++;
	
	printf("Kelime Sayisi: %d \n", counter);
	printf("%s",text);
	
	
		
/********* kod bloðu sonu ************/
// Dosyayý kapama
	fclose(fp);
	return 0;
}
