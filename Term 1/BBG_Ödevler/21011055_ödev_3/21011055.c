#include <stdio.h>
#define N 5000
int main(void){
	FILE *fp;
	char text[N];
/********* de�i�ken tan�mlar� ************/
	int word, j, i = 0, k = 0, counter = 0;
		
	
	
/********* de�i�ken tan�mlar� sonu ************/
 
// Dosyay� a�ma
	if ((fp = fopen ("soru.txt", "r")) == NULL) {
		printf("Dosya a�ma hatas�!");
		return 1;
	}
// Dosyadan okuma
	fgets(text, N-1, fp);
	//printf("%s\n", text);
 
/* 
* text karakter dizisi de�i�keninde dosyadan okunan metin yer almaktad�r.
* toplam kelime say�s�n�n hesab� ve bo�luk temizleme i�lemleri -TERC�HEN-
* bu dizi �zerinde yap�lmal�d�r. Harici dizi kullan�m� �nerilmemektedir. 
*/
/********* kod blo�u ************/	
	//bo�luk silme
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
	//sondaki tek bo�lu�u kald�rma
	if(text[i-1] == ' '){
		text[i-1] = text[i];
	}
	
	
	//kelime say�s� bulma
	while(text[k] != '\0'){
		if(text[k] == ' '){
			counter++;
		}
		k++;
	}
	
	counter++;
	
	printf("Kelime Sayisi: %d \n", counter);
	printf("%s",text);
	
	
		
/********* kod blo�u sonu ************/
// Dosyay� kapama
	fclose(fp);
	return 0;
}
