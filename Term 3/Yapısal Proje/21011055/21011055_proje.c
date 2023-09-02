#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ogrenci{
	char ogrID[9];
	char ad[30];
	char soyad[30];
	int puan;
	struct Ogrenci* next;
	struct Ogrenci* prev;
}OGRENCI;
typedef struct Yazar{
	int yazarID;
	char yazarAd[30];
	char yazarSoyad[30];
	struct Yazar* next;
}YAZAR;
typedef struct KitapOrnek{
	char etiketNo[20];
	char durum[9];
	struct KitapOrnek* next;
}ORNEK;
typedef struct Kitap{
	char kitapAdi[30];
	char ISBN[14];
	int adet;
	struct Kitap* next;
	struct KitapOrnek* head;
}KITAP;
typedef struct KitapYazar{
	char ISBN[14];
	int yazarID;
}KITAPYAZAR;
typedef struct Tarih{
	unsigned int gun:5;
	unsigned int ay:4;
	unsigned int yil:12;
}TARIH;
typedef struct KitapOdunc{
	char etiketNo[20];
	char ogrID[9];
	unsigned int islemTipi:1;
	struct Tarih islemTarihi;
}ODUNC;

int addKitap(KITAP**);
int addOgrenci(OGRENCI**, int (*findOgrenci)(OGRENCI*, char*));
int addYazar(YAZAR**, int*);
int deleteKitap(KITAP**);
int deleteOgrenci(OGRENCI**, int (*findOgrenci)(OGRENCI*, char*));
int deleteYazar(YAZAR**, KITAPYAZAR*, int*);
OGRENCI* fileReadOgrenci(char*, char*);
void fileWriteOgrenci(OGRENCI*, char*);
void printListOgrenci(OGRENCI*);
void printListOgrenciOne(OGRENCI*, int (*findOgrenci)(OGRENCI*, char*), ODUNC*, int);
void printListCezaliOgrenci(OGRENCI* head);
void splitDataOgrenci(OGRENCI*, char*, char*);
void updateYazar(YAZAR**);
void updateOgrenci(OGRENCI**, int (*findOgrenci)(OGRENCI*, char*));
void updateKitap(KITAP**);
int findOgrenci(OGRENCI*, char*);
int findOgrenciID(OGRENCI*, char*);
YAZAR* fileReadYazar(char*, char*, int*);
void splitDataYazar(YAZAR*, char*, char*);
void printListYazar(YAZAR*, KITAPYAZAR*, int*, KITAP*);
void fileWriteYazar(YAZAR*, char*);
int findYazar(YAZAR*, char*);
KITAP* fileReadKitap(char*, char*, ODUNC*, int);
void splitDataKitap(KITAP*, char*, char*);
void kitapISBN(KITAP**, ODUNC*, int);
KITAPYAZAR* fileReadKitapYazar(char*, char*, int*);
void fileWriteKitap(KITAP*, char*);
int findKitap(KITAP* head, char* findName);
void fileWriteKitapYazar(KITAPYAZAR* array, int* elementCount, char* fileName);
int updateKitapYazar(KITAPYAZAR*, int*);
void printListKitap(KITAP* head, KITAPYAZAR*, int*, YAZAR*);
void fileWriteKitapOdunc(ODUNC*, char*, int*);
void printListRafta(KITAP*);
void printListTeslimEtmeyen(OGRENCI*, ODUNC*, int*);
int kitapYazarEslestir(KITAP*, KITAPYAZAR*, int*);
ODUNC* KitapOduncAl(OGRENCI*, KITAP*, ODUNC**, int*);
int gunHesap(int, int, int, int, int, int);
ODUNC* kitapTeslimEt(ODUNC**, int*, KITAP*, OGRENCI**);
ODUNC* fileReadOdunc(char*, char*, int*);
void printListGecKitaplar(ODUNC*, int, KITAP*);

int main(){
	int cho = 0;
	int cho_2 = 0;
	int cho_3 = 0;
	int yazarID_count = 0;
	int elementCount;
	int numElements = 0;
	OGRENCI* headOgrenci;
	headOgrenci = fileReadOgrenci("Ogrenciler.csv", ",\0");
	ODUNC* arrayOdunc = fileReadOdunc("KitapOdunc.csv", ",\0", &numElements);
	if(arrayOdunc == NULL){
		arrayOdunc = (ODUNC*)malloc(sizeof(ODUNC*)*0);
	}
	YAZAR* headYazar;
	headYazar = fileReadYazar("Yazarlar.csv", ",\0", &yazarID_count);
	KITAP* headKitap;
	headKitap = fileReadKitap("Kitaplar.csv", ",\0", arrayOdunc, numElements);
	KITAPYAZAR* arrayKitapYazar = fileReadKitapYazar("KitapYazar.csv", ",\0", &elementCount);

	
	//MENU
	while(cho != 4){
		printf("1-Ogrenci Islemleri\n2-Kitap Islemleri\n3-Yazar Islemleri\n4-Cikis\n");
		scanf("%d", &cho);
		system("cls");
		cho_2 = 0;
		switch(cho){
			case 1:
				while(cho_2 != 7){
					printf("1-Ogrenci Ekle/Sil/Guncelle\n2-Ogrenci Bilgisi Goruntuleme\n3-Kitap Teslim Etmemis Ogrencileri Listele\n4-Cezali Ogrencileri Listele\n5-Tum Ogrencileri Listele\n6-Kitap Odunc Al/Teslim Et\n7-Geri Don\n");
					scanf("%d", &cho_2);
					system("cls");
					cho_3 = 0;
					switch(cho_2){
						case 1://ogrenci ekle sil guncelle
							while(cho_3 != 4){
								printf("1-Ogrenci Ekle\n2-Ogrenci Sil\n3-Ogrenci Guncelle\n4-Geri Don\n");
								scanf("%d", &cho_3);
								system("cls");
								switch(cho_3){
									case 1://ekle
										addOgrenci(&headOgrenci, findOgrenciID);
										fileWriteOgrenci(headOgrenci, "Ogrenciler.csv");
										break;
									case 2://sil
										deleteOgrenci(&headOgrenci, findOgrenci);
										fileWriteOgrenci(headOgrenci, "Ogrenciler.csv");
										break;
									case 3://guncelle
										updateOgrenci(&headOgrenci, findOgrenci);
										fileWriteOgrenci(headOgrenci, "Ogrenciler.csv");
										break;
								}
							}
							break;
						case 2://ogrenci bilgisi goruntuleme
							printListOgrenciOne(headOgrenci, findOgrenci, arrayOdunc, numElements);
							break;
						case 3://kitap teslim etmemis ogrencileri listele
							printListTeslimEtmeyen(headOgrenci, arrayOdunc, &numElements);
							break;
						case 4://cezali ogrencileri listele
							printListCezaliOgrenci(headOgrenci);
							break;
						case 5://tum ogrencileri listele
							printListOgrenci(headOgrenci);
							break;
						case 6://kitap odunc al teslim et
							while(cho_3 != 3){
								printf("1-Odunc Al\n2-Teslim Et\n3-Geri Don\n");
								scanf("%d", &cho_3);
								system("cls");
								switch(cho_3){
									case 1://odunc
										arrayOdunc = KitapOduncAl(headOgrenci, headKitap, &arrayOdunc, &numElements);
										fileWriteKitapOdunc(arrayOdunc, "KitapOdunc.csv", &numElements);
										break;
									case 2://teslim
										arrayOdunc = kitapTeslimEt(&arrayOdunc, &numElements, headKitap, &headOgrenci);
										fileWriteOgrenci(headOgrenci, "Ogrenciler.csv");
										fileWriteKitapOdunc(arrayOdunc, "KitapOdunc.csv", &numElements);
										break;
								}
							}
							break;
					}
				}
				break;
			case 2:
				while(cho_2 != 7){
					printf("1-Kitap Ekle/Sil/Guncelle\n2-Kitap Bilgisi Goruntuleme\n3-Raftaki Kitaplari Listele\n4-Zamaninda Teslim Edilmeyen Kitaplari Listele\n5-Kitap-Yazar Eslestir\n6-Kitabin Yazarini Guncelle\n7-Geri Don\n");
					scanf("%d", &cho_2);
					system("cls");
					cho_3 = 0;
					switch(cho_2){
						case 1://kitap ekle sil guncelle
							while(cho_3 != 4){
								printf("1-Kitap Ekle\n2-Kitap Sil\n3-Kitap Guncelle\n4-Geri Don\n");
								scanf("%d", &cho_3);
								system("cls");
								switch(cho_3){
									case 1://ekle
										addKitap(&headKitap);
										fileWriteKitap(headKitap, "Kitaplar.csv");
										break;
									case 2://sil
										deleteKitap(&headKitap);
										fileWriteKitap(headKitap, "Kitaplar.csv");
										break;
									case 3://guncelle
										updateKitap(&headKitap);
										fileWriteKitap(headKitap, "Kitaplar.csv");
										break;
								}
							}
							break;
						case 2://kitap bilgisi goruntuleme
							printListKitap(headKitap, arrayKitapYazar, &elementCount, headYazar);
							break;
						case 3://raftaki kitapları listele
							printListRafta(headKitap);
							break;
						case 4://zamanında teslim edilmeyen kitapları listele
							printListGecKitaplar(arrayOdunc, numElements, headKitap);
							break;
						case 5://kitap yazar eşleştir
							kitapYazarEslestir(headKitap, arrayKitapYazar, &elementCount);
							fileWriteKitapYazar(arrayKitapYazar, &elementCount, "KitapYazar.csv");
							break;
						case 6://kitabın yazarını güncelle
							updateKitapYazar(arrayKitapYazar, &elementCount);
							fileWriteKitapYazar(arrayKitapYazar, &elementCount, "KitapYazar.csv");
							break;
					}
				}
				break;
			case 3:
				while(cho_2 != 3){
					printf("1-Yazar Ekle/Sil/Guncelle\n2-Yazar Bilgisi Goruntuleme\n3-Geri Don\n");
					scanf("%d", &cho_2);
					system("cls");
					cho_3 = 0;
					switch(cho_2){
						case 1://yazar ekle sil guncelle
							while(cho_3 != 4){
								printf("1-Yazar Ekle\n2-Yazar Sil\n3-Yazar Guncelle\n4-Geri Don\n");
								scanf("%d", &cho_3);
								system("cls");
								switch(cho_3){
									case 1://ekle
										addYazar(&headYazar, &yazarID_count);
										fileWriteYazar(headYazar, "Yazarlar.csv");
										break;
									case 2://sil
										deleteYazar(&headYazar, arrayKitapYazar, &elementCount);
										fileWriteYazar(headYazar, "Yazarlar.csv");
										fileWriteKitapYazar(arrayKitapYazar, &elementCount, "KitapYazar.csv");
										break;
									case 3://guncelle
										updateYazar(&headYazar);
										fileWriteYazar(headYazar, "Yazarlar.csv");
										break;
								}
							}
							break;
						case 2://yazar bilgisi goruntuleme
							printListYazar(headYazar, arrayKitapYazar, &elementCount, headKitap);
							break;
					}
				}
				break;
		}
	}
	return 0;
}
int addYazar(YAZAR** head, int* ID_count){
	YAZAR* newYazar;
	newYazar = (YAZAR*)malloc(sizeof(YAZAR));
	YAZAR* temp = *head;
	(*ID_count)++;
	if(newYazar == NULL){
		return -1;
	}
	newYazar->yazarID = *ID_count;
	printf("Ad: ");
	scanf("%s", newYazar->yazarAd);
	printf("Soyad: ");
	scanf("%s", newYazar->yazarSoyad);
	newYazar->next = NULL;
	if(temp == NULL){
		*head = newYazar;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newYazar;
	}
	
	
	return 0;
}
int deleteYazar(YAZAR** head, KITAPYAZAR* array, int* elementCount){
	char* findName = (char*)malloc(30*sizeof(char));
	int found, i;
	YAZAR* current = *head;
	YAZAR* prev = NULL;

	printf("Silmek istediginiz yazarin adini veya soyadini giriniz: ");
	scanf("%s", findName);
	found = findYazar(current, findName);
	if(found != -1){
		for(i = 0; i < found; i++){
			prev = current;
			current = current->next;
		}
		if(prev != NULL){
			prev->next = current->next;
		}
		else{
			*head = current->next;
		}
		for(i = 0; i < *elementCount; i++){
			if(array[i].yazarID == current->yazarID){
				array[i].yazarID = -1;
			}
		}
		free(current);
		return 1;
	}
	else{
		printf("Girdiginiz yazar sistemde bulunmamaktadir.\n");
		return -1;
	}

	free(findName);
	
}
void updateYazar(YAZAR** head){
	char* name = (char*)malloc(sizeof(char)*30);
	int found, i, cho = 0;
	YAZAR* tmp = *head;
	printf("Bilgilerini degistirmek istediginiz yazarin adini veya soyadini girin: ");
	scanf("%s", name);
	found = findYazar(*head, name);
	
	if(found != -1){
		for(i = 0; i < found; i++){
			tmp = tmp->next;
		}
		printf("1-Ad\n2-Soyad\nDegistirmek istediginiz bilgiyi seciniz: ");
		scanf("%d", &cho);
		switch(cho){
			case 1:
				printf("Yeni ad: ");
				scanf("%s", name);
				strcpy(tmp->yazarAd, name);
				break;
			case 2:
				printf("Yeni soyad: ");
				scanf("%s", name);
				strcpy(tmp->yazarSoyad, name);
				break;
		}
	}
	else{
		printf("Girdiginiz yazar sistemde bulunmamaktadir.\n");
	}
	free(name);
}
int addOgrenci(OGRENCI** head, int (*findOgrenci)(OGRENCI*, char*)){
	OGRENCI* newOgrenci;
	newOgrenci = (OGRENCI*)malloc(sizeof(OGRENCI));
	if(newOgrenci == NULL){
		return -1;
	}
	do{
		printf("ID: ");
		scanf("%s", newOgrenci->ogrID);
	}while(findOgrenci(*head, newOgrenci->ogrID));
	printf("Ad: ");
	scanf("%s", newOgrenci->ad);
	printf("Soyad: ");
	scanf("%s", newOgrenci->soyad);
	newOgrenci->puan = 100;
	
	(*head)->prev = newOgrenci;
	newOgrenci->next = *head;
	*head = newOgrenci;
	newOgrenci->prev = NULL;
	
	return 0;
}
int deleteOgrenci(OGRENCI** head, int (*findOgrenci)(OGRENCI*, char*)){
	char* name = (char*)malloc(sizeof(char)*30);
	int found, i;
	OGRENCI* current = *head;
	OGRENCI* previous = current->prev;
	printf("Silmek istediginiz ogrencinin numarasini veya adini veya soyadini giriniz: ");
	scanf("%s", name);
	found = findOgrenci(*head, name);
	if(found != -1){
		for(i = 0; i < found; i++){
			previous = current;
			current = current->next;
		}
		if(previous != NULL){
			previous->next = current->next;
			current->next->prev = previous;
		}
		else{
			*head = current->next;
			current->next->prev = NULL;
		}
		free(current);
		return 1;
	}
	else{
		printf("Girdiginiz ogrenci sistemde bulunmamaktadir.\n");
		return -1;
	}
}
void updateOgrenci(OGRENCI** head, int (*findOgrenci)(OGRENCI*, char*)){
	char* name = (char*)malloc(sizeof(char)*30);
	int found, i, cho = 0, puan;
	OGRENCI* tmp = *head;
	printf("Bilgilerini degistirmek istediginiz ogrencinin numarasini veya adini veya soyadini girin: ");
	scanf("%s", name);
	found = findOgrenci(*head, name);
	
	if(found != -1){
		for(i = 0; i < found; i++){
			tmp = tmp->next;
		}
		printf("1-Numara\n2-Ad\n3-Soyad\n4-Puan\nDegistirmek istediginiz bilgiyi seciniz: ");
		scanf("%d", &cho);
		switch(cho){
			case 1:
				printf("Yeni numara: ");
				scanf("%s", name);
				strcpy(tmp->ogrID, name);
				break;
			case 2:
				printf("Yeni ad: ");
				scanf("%s", name);
				strcpy(tmp->ad, name);
				break;
			case 3:
				printf("Yeni soyad: ");
				scanf("%s", name);
				strcpy(tmp->soyad, name);
				break;
			case 4:
				printf("Yeni puan: ");
				scanf("%d", &puan);
				tmp->puan = puan;
		}
	}
	else{
		printf("Girdiginiz ogrenci sistemde bulunmamaktadir.\n");
	}
	free(name);
}
int addKitap(KITAP** head){
	char c;
	int i= 0;
	KITAP* newKitap;
	newKitap = (KITAP*)malloc(sizeof(KITAP));
	if(newKitap == NULL){
		return -1;
	}
	printf("ISBN: ");
	scanf("%s", newKitap->ISBN);
	scanf("%c",&c);
	printf("Kitap Adi: ");
	fgets(newKitap->kitapAdi, 30, stdin);
	newKitap->kitapAdi[strlen(newKitap->kitapAdi)-1]='\0';
	printf("Adet: ");
	scanf("%d", &newKitap->adet);

	newKitap->next = *head;
	*head = newKitap;
	
	return 0;
}
int deleteKitap(KITAP** head){
	char* findName = (char*)malloc(30*sizeof(char));
	char* tmp = malloc(sizeof(char)*2);
	int found, i;
	KITAP* current = *head;
	KITAP* prev = NULL;
	printf("Silmek istediginiz kitabin adini veya isbn numarasini giriniz: ");
	scanf("%c", &tmp);
	fgets(findName, 30, stdin);
	findName[strlen(findName)-1]='\0';
	found = findKitap(current, findName);

	if(found != -1){
		for(i = 0; i < found; i++){
			prev = current;
			current = current->next;
		}
		if(prev != NULL){
			prev->next = current->next;
		}
		else{
			*head = current->next;
		}
		free(current->head);
		free(current);
		return 1;
	}
	else{
		printf("Girdiginiz kitap sistemde bulunmamaktadir.\n");
		return -1;
	}

	free(findName);
}
void updateKitap(KITAP** head){
	char* name = (char*)malloc(sizeof(char)*30);
	char* tmpc = malloc(sizeof(char)*2);
	int found, i, cho = 0, adet;
	KITAP* tmp = *head;
	printf("Bilgilerini degistirmek istediginiz kitabin adini veya ISBN girin: ");
	scanf("%c", &tmpc);
	fgets(name, 30, stdin);
	name[strlen(name)-1]='\0';
	found = findKitap(*head, name);

	if(found != -1){
		for(i = 0; i < found; i++){
			tmp = tmp->next;
		}
		printf("1-Ad\n2-ISBN\n3-Adet\nDegistirmek istediginiz bilgiyi seciniz: ");
		scanf("%d", &cho);
		switch(cho){
			case 1:
				printf("Yeni ad: ");
				scanf("%s", name);
				strcpy(tmp->kitapAdi, name);
				break;
			case 2:
				printf("Yeni ISBN: ");
				scanf("%s", name);
				strcpy(tmp->ISBN, name);
				break;
			case 3:
				printf("Yeni adet: ");
				scanf("%d", &adet);
				tmp->adet = adet; 
				break;
		}
	}
	else{
		printf("Girdiginiz ogrenci sistemde bulunmamaktadir.\n");
	}
	free(name);
}
void splitDataOgrenci(OGRENCI* head, char* buffer, char* delimiter){
	char* token;
	token = strtok(buffer, delimiter);
	strcpy(head->ogrID, token);
	token = strtok(NULL, delimiter);
	strcpy(head->ad, token);
	token = strtok(NULL, delimiter);
	strcpy(head->soyad, token);
	token = strtok(NULL, delimiter);
	head->puan = atoi(token);
}
OGRENCI* fileReadOgrenci(char* fileName, char* delimiter){
	FILE* fptr = fopen(fileName, "r");
	char* buffer = (char*)malloc(255*sizeof(char));
	
	OGRENCI* head = (OGRENCI*)malloc(sizeof(OGRENCI));
	OGRENCI* prevNode;
	OGRENCI* currentNode;
	
	if(fgets(buffer,255,fptr) != NULL){
		splitDataOgrenci(head,buffer,delimiter);
	}
	else{
		return NULL;
	}
	prevNode = head;
	head->prev = NULL;
	while(fgets(buffer,255,fptr) != NULL){
		currentNode = (OGRENCI*)malloc(sizeof(OGRENCI));
		prevNode->next = currentNode;
		currentNode->prev = prevNode;
		splitDataOgrenci(currentNode,buffer,delimiter);
		prevNode = currentNode;
	}
	prevNode->next = NULL;
	fclose(fptr);
	free(buffer);
	return head;
}
void fileWriteOgrenci(OGRENCI* head, char* fileName){
	FILE* fptr = fopen(fileName, "w");
	
	while(head != NULL){
		fprintf(fptr, "%s,%s,%s,%d\n", head->ogrID, head->ad, head->soyad, head->puan);
		head = head->next;
	}
	fclose(fptr);
}
void printListOgrenci(OGRENCI* head){
	char c;
	while(head != NULL){
		printf("ID: %s, Name: %s, Surname: %s, Point: %d\n", head->ogrID, head->ad, head->soyad, head->puan);
		head=head->next;
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
}
void printListOgrenciOne(OGRENCI* head, int (*findOgrenci)(OGRENCI*, char*), ODUNC* array, int numElement){
	int found, i;
	char c;
	char* name = (char*)malloc(sizeof(char)*30);
	printf("Bilgilerini gormek istediginiz ogrencinin ismini veya numarasini giriniz: ");
	scanf("%s", name);
	found = findOgrenci(head, name);
	if(found != -1){
		for(i = 0; i < found; i++){
			head = head->next;
		}
		printf("ID: %s, Name: %s, Surname: %s, Puan: %d\n", head->ogrID, head->ad, head->soyad, head->puan);
		printf("Kitap Hareketleri:\n");
		for(i = 0; i < numElement; i++){
			if(strcmp(head->ogrID, array[i].ogrID) == 0){
				printf("%s,%s,%d,%d.%d.%d\n", array[i].etiketNo, array[i].ogrID, array[i].islemTipi, array[i].islemTarihi.gun, array[i].islemTarihi.ay, array[i].islemTarihi.yil);
			}
		}
	}
	else{
		printf("Girdiginiz ogrenci sistemde bulunmamaktadir.\n");
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
	free(name);
}
void printListCezaliOgrenci(OGRENCI* head){
	char c;
	while(head != NULL){
		if(head->puan < 0){
			printf("ID: %s, Name: %s, Surname: %s, Point: %d\n", head->ogrID, head->ad, head->soyad, head->puan);
		}
		head = head->next;
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
}
int findOgrenci(OGRENCI* head, char* name){
	OGRENCI* tmp = head;
	int found = 0, count = 0;
	while(found == 0 && head != NULL){
		if(strcmp(head->ad, name) == 0 || strcmp(head->soyad, name) == 0 || strcmp(head->ogrID, name) == 0){
			found = 1;
		}
		else{
			head = head->next;
			count++;
		}
	}
	if(head == NULL){
		return -1;
	}
	return count;
}
int findOgrenciID(OGRENCI* head, char* ID){
	OGRENCI* tmp = head;
	while(tmp != NULL){
		if(!strcmp(tmp->ogrID, ID)){
			return 1;
		}
		tmp = tmp->next;
	}
	return 0;
}
YAZAR* fileReadYazar(char* fileName, char* delimiter, int* ID_count){
	FILE* fptr = fopen(fileName, "r");
	char* buffer = (char*)malloc(255*sizeof(char));

	YAZAR* head = (YAZAR*)malloc(sizeof(YAZAR));
	YAZAR* prevNode;
	YAZAR* currentNode;

	if(fgets(buffer,255,fptr) != NULL){
		splitDataYazar(head, buffer, delimiter);
	}
	else{
		return NULL;
	}
	prevNode = head;
	while(fgets(buffer, 255, fptr) != NULL){
		currentNode = (YAZAR*)malloc(sizeof(YAZAR));
		prevNode->next = currentNode;
		splitDataYazar(currentNode, buffer, delimiter);
		prevNode = currentNode;
	}
	prevNode->next = NULL;
	*ID_count = prevNode->yazarID;
	fclose(fptr);
	free(buffer);
	return head;
}
void splitDataYazar(YAZAR* head, char* buffer, char* delimiter){
	char* token;
	token = strtok(buffer, delimiter);
	head->yazarID = atoi(token);
	token = strtok(NULL, delimiter);
	strcpy(head->yazarAd, token);
	token = strtok(NULL, delimiter);
	token[strlen(token)-1]='\0';
	strcpy(head->yazarSoyad, token);
}
void fileWriteYazar(YAZAR* head, char* fileName){
	FILE* fptr = fopen(fileName, "w");

	while(head != NULL){
		fprintf(fptr, "%d,%s,%s\n", head->yazarID, head->yazarAd, head->yazarSoyad);
		head = head->next;
	}
	fclose(fptr);
}
void printListYazar(YAZAR* head, KITAPYAZAR* array, int* elementCount, KITAP* headKitap){
	int found, i;
	char c;
	char* name = (char*)malloc(sizeof(char)*30);
	KITAP* tmp = headKitap;
	printf("Bilgilerini gormek istediginiz yazarin ismini giriniz: ");
	scanf("%s", name);
	found = findYazar(head, name);
	if(found != -1){
		for(i = 0; i < found; i++){
			head = head->next;
		}
		printf("ID: %d, Name: %s, Surname: %s\n", head->yazarID, head->yazarAd, head->yazarSoyad);
		printf("Kitaplari:\n");
		for(i = 0; i < *elementCount; i++){
			while(tmp != NULL){
				if(head->yazarID == array[i].yazarID && strcmp(tmp->ISBN, array[i].ISBN) == 0){
					printf("%s, %s\n", array[i].ISBN, tmp->kitapAdi);
				}
				tmp = tmp->next;
			}
			tmp = headKitap;
		}
	}
	else{
		printf("Girdiginiz yazar sistemde bulunmamaktadir.\n");
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
}
int findYazar(YAZAR* head, char* findName){
	int count = 0, found = 0;

	while(found == 0 && head != NULL){
		if(strcmp(head->yazarAd, findName) == 0 || strcmp(head->yazarSoyad, findName) == 0){
			found = 1;
		}
		else{
			head = head->next;
			count++;
		}
	}
	if(head == NULL){
		return -1;
	}
	return count;
}
KITAP* fileReadKitap(char* fileName, char* delimiter, ODUNC* array, int numElements){
	FILE* fptr = fopen(fileName, "r");
	char* buffer = (char*)malloc(255*sizeof(char));

	KITAP* head = (KITAP*)malloc(sizeof(KITAP));
	KITAP* prevNode;
	KITAP* currentNode;

	if(fgets(buffer,255,fptr) != NULL){
		splitDataKitap(head, buffer, delimiter);
		head->head = NULL;
	}
	else{
		return NULL;
	}
	prevNode = head;
	while(fgets(buffer, 255, fptr) != NULL){
		currentNode = (KITAP*)malloc(sizeof(KITAP));
		prevNode->next = currentNode;
		splitDataKitap(currentNode, buffer, delimiter);
		currentNode->head = NULL;
		prevNode = currentNode;
	}
	prevNode->next = NULL;
	kitapISBN(&head, array, numElements);
	fclose(fptr);
	free(buffer);
	return head;
}
void splitDataKitap(KITAP* head, char* buffer, char* delimiter){
	char* token;
	token = strtok(buffer, delimiter);
	strcpy(head->kitapAdi, token);
	token = strtok(NULL, delimiter);
	strcpy(head->ISBN, token);
	token = strtok(NULL, delimiter);
	head->adet = atoi(token);
}
void kitapISBN(KITAP** headKitap, ODUNC* array, int numElements){
	int i, N, j, k;
	char* tmp = (char*)malloc(sizeof(char)*20);
	char* N_string = (char*)malloc(sizeof(char)*5);
	KITAP* current = *headKitap;
	ORNEK* newOrnek;
	ORNEK* headOrnek;
	
	while(current != NULL){
		headOrnek = current->head;
		for(i = 1; i <= current->adet; i++){
			newOrnek = (ORNEK*)malloc(sizeof(ORNEK));
			strcpy(tmp, current->ISBN);
			strcat(tmp, "_");
			N = i;
			itoa(N, N_string, 10);
			strcat(tmp, N_string);
			strcpy(newOrnek->etiketNo, tmp);
			strcpy(tmp,"");
			strcpy(newOrnek->durum, "Rafta");
			for(j = 0; j < numElements; j++){
				for(k = j+1; k < numElements; k++){
					if(strcmp(array[j].etiketNo, newOrnek->etiketNo) == 0 && array[j].islemTipi == 0){
						strcpy(newOrnek->durum, array[i-1].ogrID);
					}
					else if(array[j].islemTipi == 1){
						strcpy(newOrnek->durum, "Rafta");
					}
				}
			}
			if(numElements == 1 && strcmp(array[0].etiketNo, newOrnek->etiketNo) == 0){
				strcpy(newOrnek->durum, array[0].ogrID);
			}
			newOrnek->next = NULL;
			if(headOrnek == NULL){
				headOrnek = newOrnek;
				current->head = newOrnek;
			}
			else{
				headOrnek->next = newOrnek;
				headOrnek = headOrnek->next;
			}
			
		}
		current = current->next;
	}
	free(tmp);
	free(N_string);
}
KITAPYAZAR* fileReadKitapYazar(char* fileName, char* delimiter, int* elementCount){
	int i = 0;
	FILE* fptr = fopen(fileName, "r");
	char* buffer = (char*)malloc(sizeof(char)*255);
	char* token;
	KITAPYAZAR* array = (KITAPYAZAR*)malloc(sizeof(KITAPYAZAR));

	if(fptr == NULL){
		return NULL;
	}
	while(fgets(buffer, 255, fptr) != NULL) {
		token = strtok(buffer, delimiter);
        strcpy(array[i].ISBN, token);
        token = strtok(NULL, delimiter);
        array[i].yazarID = atoi(token);
        i++;
        array = realloc(array, (i + 1) * sizeof(KITAPYAZAR));
    }
    *elementCount = i;
	fclose(fptr);
	free(buffer);
	return array;
}
void fileWriteKitapYazar(KITAPYAZAR* array, int* elementCount, char* fileName){
	FILE* fptr = fopen(fileName, "w");
	int i;
	for(i = 0; i < *elementCount; i++){
		fprintf(fptr, "%s,%d\n", array[i].ISBN, array[i].yazarID);
	}
	fclose(fptr);
}
void fileWriteKitap(KITAP* head, char* fileName){
	FILE* fptr = fopen(fileName, "w");

	while(head != NULL){
		fprintf(fptr, "%s,%s,%d\n", head->kitapAdi, head->ISBN, head->adet);
		head = head->next;
	}
	fclose(fptr);
}
int findKitap(KITAP* head, char* findName){
	int count = 0, found = 0;

	while(found == 0 && head != NULL){
		if(strcmp(head->kitapAdi, findName) == 0 || strcmp(head->ISBN, findName) == 0){
			found = 1;
		}
		else{
			head = head->next;
			count++;
		}
	}
	if(head == NULL){
		return -1;
	}
	return count;
}
int updateKitapYazar(KITAPYAZAR* array, int* elementCount){
	char* ISBN = malloc(sizeof(char)*15);
	int i = 0, found = 0;
	printf("Yazarini guncellemek istediginiz kitabin ISBN'sini giriniz: ");
	scanf("%s", ISBN);
	while(i < *elementCount){
		if(strcmp(ISBN, array[i].ISBN) == 0){
			printf("ISBN: %s, Yazar ID: %d\nYeni ID: ", array[i].ISBN, array[i].yazarID);
			scanf("%d", &array[i].yazarID);
			found = 1;
		}
		i++;
	}
	if(found == 0){
		printf("Aradiginiz kitap sistemde yok");
		return -1;
	}
}
void printListKitap(KITAP* head, KITAPYAZAR* array, int* elementCount, YAZAR* headYazar){
	int found, i;
	char* name = (char*)malloc(sizeof(char)*30);
	char c;
	YAZAR* tmp = headYazar;
	ORNEK* tmpOrnek;
	printf("Bilgilerini gormek istediginiz kitabin ismini veya ISBN giriniz: ");
	scanf("%c", &c);
	fgets(name, 30, stdin);
	name[strlen(name)-1]='\0';
	system("cls");
	found = findKitap(head, name);

	if(found != -1){
		for(i = 0; i < found; i++){
			head = head->next;
		}
		tmpOrnek = head->head;
		printf("Ad: %s, ISBN: %s, Adet: %d\nYazarlari:\n", head->kitapAdi, head->ISBN, head->adet);
		for(i = 0; i < *elementCount; i++){
			while(tmp != NULL){
				if(tmp->yazarID == array[i].yazarID && strcmp(head->ISBN, array[i].ISBN) == 0 ){
					printf("%d, %s, %s\n", tmp->yazarID, tmp->yazarAd, tmp->yazarSoyad);
				}
				tmp = tmp->next;
			}
			tmp = headYazar;
		}
		printf("Kitap Durumlari:\n");
		for(i = 0; i < head->adet; i++){
			printf("%s,%s\n", tmpOrnek->etiketNo, tmpOrnek->durum);
			tmpOrnek = tmpOrnek->next;
		}
	}
	else{
		printf("Girdiginiz kitap sistemde bulunmamaktadir.\n");
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
}
void fileWriteKitapOdunc(ODUNC* array, char* fileName, int* numElements){
	FILE* fptr = fopen(fileName, "w");
	int i, gun, ay, yil;
	for(i = 0; i < *numElements; i++){
		gun = array[i].islemTarihi.gun;
		ay = array[i].islemTarihi.ay;
		yil = array[i].islemTarihi.yil;
		fprintf(fptr, "%s,%s,%d,%d.%d.%d\n", array[i].etiketNo, array[i].ogrID, array[i].islemTipi, gun, ay, yil);
	}
	fclose(fptr);
}
void printListRafta(KITAP* head){
	KITAP* current = head;
	int i;
	char c;
	ORNEK* curr;
	while(current != NULL){
		curr = current->head;
		printf("Kitap Adi: %s\n", current->kitapAdi);
		for(i = 0; i < current->adet; i++){
			if(strcmp(curr->durum, "Rafta") == 0){
				printf("%s\n", curr->etiketNo);
			}
			curr = curr->next;
		}
		current = current->next;
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
}
void printListTeslimEtmeyen(OGRENCI* head, ODUNC* arrayOdunc, int* numElements){
	char c;
	int i, j, teslimEdildi;
	if(*numElements == 0){
		printf("Kitap odunc alinmamis.\n");
		return;
	}
	while(head != NULL){
		teslimEdildi = 0;
		for(i = 0; i < *numElements; i++){
			for(j = i+1; j < *numElements; j++){
				if(arrayOdunc[i].islemTipi != arrayOdunc[j].islemTipi && strcmp(arrayOdunc[i].etiketNo, arrayOdunc[j].etiketNo) == 0 && strcmp(arrayOdunc[i].ogrID, arrayOdunc[j].ogrID)){
					teslimEdildi = 1;
				}
			}
			if(teslimEdildi != 1 && strcmp(head->ogrID, arrayOdunc[i].ogrID) == 0){
				printf("ID: %s, Name: %s, Surname: %s, Point: %d\n", head->ogrID, head->ad, head->soyad, head->puan);
			}
		}
		head = head->next;
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");
}
ODUNC* KitapOduncAl(OGRENCI* headOgrenci, KITAP* headKitap, ODUNC** array, int* numElements){
	int i, foundKitap, foundOgrenci, gun, ay, yil;
	char* name = malloc(sizeof(char)*30);
	char* ID = malloc(sizeof(char)*10);
	char c;
	KITAP* tmp = headKitap;
	ORNEK* tmpHead;
	ODUNC* tmpOdunc = *array;
	OGRENCI* tmpOgrenci = headOgrenci;
	printf("Odunc almak istediginiz kitabin ismini veya ISBN giriniz: ");
	scanf("%c", &c);
	fgets(name, 30, stdin);
	name[strlen(name)-1]='\0';
	printf("Ogrenci ID'nizi giriniz: ");
	scanf("%s", ID);
	foundKitap = findKitap(headKitap, name);
	foundOgrenci = findOgrenciID(headOgrenci, ID);

	while(strcmp(tmpOgrenci->ogrID, ID) != 0){
		tmpOgrenci = tmpOgrenci->next;
	}
	if(foundKitap != -1 && foundOgrenci && tmpOgrenci->puan > 0){
		for(i = 0; i < foundKitap; i++){
			tmp = tmp->next;
		}
		tmpHead = tmp->head;
		for(i = 0; i < tmp->adet; i++){
			if(strcmp(tmpHead->durum, "Rafta") == 0){
				strcpy(tmpHead->durum, ID);
				tmpOdunc = (ODUNC*)realloc(tmpOdunc, sizeof(ODUNC)*(*numElements+1));
				tmpOdunc[*numElements].islemTipi = 0;
				strcpy(tmpOdunc[*numElements].etiketNo, tmpHead->etiketNo);
				strcpy(tmpOdunc[*numElements].ogrID, ID);
				printf("Islem tarihini giriniz dd.mm.yyyy: \n");
				scanf("%d.%d.%d", &gun, &ay, &yil);
				tmpOdunc[*numElements].islemTarihi.gun = gun;
				tmpOdunc[*numElements].islemTarihi.ay = ay;
				tmpOdunc[*numElements].islemTarihi.yil = yil;
				(*numElements)++;
				i = tmp->adet;
			}
			else{
				tmpHead = tmpHead->next;
			}
		}
		
	}
	else{
		if(foundKitap == -1){
			printf("Girdiginiz kitap sistemde bulunmamaktadir.\n");
		}
		if(foundOgrenci == 0){
			printf("Girdiginiz ID sistemde bulunmamaktadir.\n");
		}
		if(tmpOgrenci->puan < 0){
			printf("Puaniniz 0'dan dusuk oldugu icin kitap alamazsiniz.\n");
		}
		
	}
	return (tmpOdunc);
}
void printListGecKitaplar(ODUNC* array, int numElements, KITAP* headKitap){
	//tarihten 15 gun gectiyse listele
	int i, j, fark, gecTeslim;
	char c;
	ORNEK* headOrnek;
	KITAP* tmpKitap = headKitap;

	for(i = 0; i < numElements; i++){
		gecTeslim = 0;
		for(j = i+1; j < numElements; j++){
			if(array[i].islemTipi != array[j].islemTipi && strcmp(array[i].etiketNo, array[j].etiketNo) == 0 && strcmp(array[i].ogrID, array[j].ogrID) == 0){
				if(array[i].islemTipi > array[j].islemTipi){
					fark = gunHesap(array[i].islemTarihi.gun, array[i].islemTarihi.ay, array[i].islemTarihi.yil, array[j].islemTarihi.gun, array[j].islemTarihi.ay, array[j].islemTarihi.yil);
				}
				else{
					fark = gunHesap(array[j].islemTarihi.gun, array[j].islemTarihi.ay, array[j].islemTarihi.yil, array[i].islemTarihi.gun, array[i].islemTarihi.ay, array[i].islemTarihi.yil);
				}
				if(fark > 15){
					gecTeslim = 1;
				}
			}
		}
		if(gecTeslim == 1){
			printf("Kitabin Adi:\n");
			printf("%s\n", array[i].etiketNo);
		}
	
	}
	printf("Devam etmek icin entera basin...");
	scanf("%c", &c);
	scanf("%c", &c);
	system("cls");

}
int kitapYazarEslestir(KITAP* headKitap, KITAPYAZAR* array, int* elementCount){
	char* name = (char*)malloc(sizeof(char)*30);
	int found, i, ID;
	char c;
	KITAP* tmp = headKitap;

	printf("Yazarla eslestirmek istediginiz kitabin ismini veya ISBN giriniz: ");
	scanf("%c", &c);
	fgets(name, 30, stdin);
	name[strlen(name)-1]='\0';
	found = findKitap(headKitap, name);

	if(found != -1){
		for(i = 0; i < found; i++){
			tmp = tmp->next;
		}
		printf("Eslestirmek istediginiz yazarin ID'sini giriniz: ");
		scanf("%d", &ID);
		array = (KITAPYAZAR*)realloc(array, sizeof(KITAPYAZAR)*(*elementCount+1));
		array[*elementCount].yazarID = ID;
		strcpy(array[*elementCount].ISBN, tmp->ISBN);
		(*elementCount)++;
	}
	else{
		printf("Girdiginiz kitap sistemde bulunmamaktadir.\n");
	}
	free(name);
}
ODUNC* kitapTeslimEt(ODUNC** array, int* numElements, KITAP* headKitap, OGRENCI** headOgrenci){
	char* name = (char*)malloc(sizeof(char)*30);
	char* ID = malloc(sizeof(char)*10);
	char c;
	ODUNC* tmpOdunc = *array;
	int foundKitap, foundOgrenci, i, gun, ay, yil, j, gunOdunc, ayOdunc, yilOdunc, fark;
	KITAP* tmp = headKitap;
	ORNEK* headOrnek;
	OGRENCI* tmpOgrenci = *headOgrenci;
	printf("Teslim etmek istediginiz kitabin ismini veya ISBN giriniz: ");
	scanf("%c", &c);
	fgets(name, 30, stdin);
	name[strlen(name)-1]='\0';
	printf("Ogrenci ID'nizi giriniz: ");
	scanf("%s", ID);

	foundKitap = findKitap(headKitap, name);
	foundOgrenci = findOgrenciID(*headOgrenci, ID);

	while(strcmp(tmpOgrenci->ogrID, ID) != 0){
		tmpOgrenci = tmpOgrenci->next;
	}

	if(foundKitap != -1 && foundOgrenci){
		for(i = 0; i < foundKitap; i++){
			tmp = tmp->next;
		}
		headOrnek = tmp->head;
		for(i = 0; i < tmp->adet; i++){
			j = 0;
			if(strcmp(headOrnek->durum, ID) == 0){
				while(strcmp(tmpOdunc[j].ogrID, ID) != 0){
					j++;
				}
				gunOdunc = tmpOdunc[j].islemTarihi.gun;
				ayOdunc = tmpOdunc[j].islemTarihi.ay;
				yilOdunc = tmpOdunc[j].islemTarihi.yil;
				tmpOdunc = (ODUNC*)realloc(tmpOdunc, sizeof(ODUNC)*(*numElements+1));
				printf("Islemin yapildigi tarihi giriniz dd.mm.yyyy: ");
				scanf("%d.%d.%d", &gun, &ay, &yil);
				tmpOdunc[*numElements].islemTarihi.gun = gun;
				tmpOdunc[*numElements].islemTarihi.ay = ay;
				tmpOdunc[*numElements].islemTarihi.yil = yil;
				tmpOdunc[*numElements].islemTipi = 1;
				strcpy(tmpOdunc[*numElements].etiketNo, headOrnek->etiketNo);
				strcpy(tmpOdunc[*numElements].ogrID, ID);
				(*numElements)++;
				fark = gunHesap(gun, ay, yil, gunOdunc, ayOdunc, yilOdunc);
				if(fark > 15){
					printf("-10 puan ceza aldiniz.\n");
					tmpOgrenci->puan = tmpOgrenci->puan - 10;
				}
				i = tmp->adet;
			}
			else{
				headOrnek = headOrnek->next;
			}
		}
		
	}
	else{
		if(foundKitap == -1){
			printf("Girdiginiz kitap sistemde bulunmamaktadir.\n");
		}
		if(foundOgrenci == 0){
			printf("Girdiginiz ID sistemde bulunmamaktadir.\n");
		}
		
	}
	return (tmpOdunc);
}
int gunHesap(int gun, int ay, int yil, int gunOdunc, int ayOdunc, int yilOdunc){
	ay = ay + yil*12;
	gun = gun + ay*30;
	ayOdunc = ayOdunc + yilOdunc*12;
	gunOdunc = gunOdunc + ayOdunc*30;

	return gun - gunOdunc;
}
ODUNC* fileReadOdunc(char* fileName, char* delimiter, int* numElements){
	int i = 0, gun, ay, yil;
	FILE* fptr = fopen(fileName, "r");
	char* buffer = (char*)malloc(sizeof(char)*255);
	char* token;
	ODUNC* array = malloc(sizeof(ODUNC));

	if(fptr == NULL){
		return NULL;
	}
	while(fgets(buffer, 255, fptr) != NULL) {
		token = strtok(buffer, delimiter);
        strcpy(array[i].etiketNo, token);
        token = strtok(NULL, delimiter);
		strcpy(array[i].ogrID, token);
		token = strtok(NULL, delimiter);
        array[i].islemTipi = atoi(token);
        
		token = strtok(NULL, ".\0");
		gun = atoi(token);
		token = strtok(NULL, ".\0");
		ay = atoi(token);
		token = strtok(NULL, ".\0");
		yil = atoi(token);
		array[i].islemTarihi.gun = gun;
		array[i].islemTarihi.ay = ay;
		array[i].islemTarihi.yil = yil;
        i++;
        array = realloc(array, (i + 1) * sizeof(ODUNC));
        
    }
    *numElements = i;
	fclose(fptr);
	free(buffer);
	return array;
}
