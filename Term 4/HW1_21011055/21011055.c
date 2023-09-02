#include <stdio.h>
#include <stdlib.h>
#include <time.h>



typedef struct gear{
    int value;
    struct gear* next;
    struct gear* prev;
}GEAR;

void addValue(GEAR** head, int inputValue);
GEAR* createHead(int inputValue);
void printGear(GEAR* head);
void findLocations(GEAR* gear1, GEAR* gear2, GEAR* gear3, int *loc1, int *loc2, int *loc3, int M);
void turnGear(GEAR** head, int loc1, int loc2, int M);
void placeNumbers(GEAR** head, int N, int M, int **numbers, int commonNumber, int *locs);

int main(){
    int N, M, go = 0, loc1 = 1, loc2 = 1, loc3 = 1;
    int i, commonNumber;
    GEAR* gear1, *gear2, *gear3;
    srand(time(NULL));
    
    do{
        printf("N: ");
        scanf("%d", &N);
        printf("M: ");
        scanf("%d", &M);
        if((3*M/2) <= N && M >= 3)
            go = 1;
        else
            printf("Enter Again:\n");
    }while(go == 0);
    
    int **numbers = (int**)calloc(2, sizeof(int*));
    for(i = 0; i < 2; i++){
        numbers[i] = (int*)calloc(N, sizeof(int));
    }
    int *locs = (int*)calloc(2, sizeof(int));
    commonNumber = rand() % N + 1;							// ortak sayinin elde edilmesi
    // random sayýlarý ve ortak sayiyi linkli listelere atanmasý
    printf("%d\n", commonNumber);
    placeNumbers(&gear1, N, M, numbers, commonNumber, locs);
    placeNumbers(&gear2, N, M, numbers, commonNumber, locs);
    placeNumbers(&gear3, N, M, numbers, commonNumber, locs);
    //çarklarýn ilk hallerinin çýktý olarak verilmesi
    printf("1. Cark: ");
    printGear(gear1);
    printf("2. Cark: ");
    printGear(gear2);
    printf("3. Cark: ");
    printGear(gear3);
    
    // ortak sayýnýn lokasyonlarýnýn bulunmasý
    findLocations(gear1, gear2, gear3, &loc1, &loc2, &loc3, M);
    printf("\n1. Carktaki Konumu: %d\n2. Carktaki Konumu: %d\n3. Carktaki Konumu: %d\n", loc1, loc2, loc3);
    // turn gear fonksiyonu ile en kýsa yolu kullanarak çarklar döndürülür
    printf("\n2. Cark ");
    turnGear(&gear2, loc1, loc2, M);
    printf("3. Cark ");
    turnGear(&gear3, loc1, loc3, M);
    //çarklarýn son hallerinin çýktý olarak verilmesi
    printf("Carklarin Son Durumu\n");
    printf("1. Cark: ");
    printGear(gear1);
    printf("2. Cark: ");
    printGear(gear2);
    printf("3. Cark: ");
    printGear(gear3);
    
    for(i = 0; i < 2; i++){
    	free(numbers[i]);
	}
	free(numbers);
	free(locs);
    return 0;
}

void addValue(GEAR** head, int inputValue){
    GEAR* tmp = *head;
    GEAR* newValue = (GEAR*)malloc(sizeof(GEAR)*1);
    newValue->value = inputValue;
    
    while(tmp->next != (*head)){
        tmp = tmp->next;
    }
    tmp->next = newValue;
    newValue->next = (*head);
    newValue->prev = tmp;
    (*head)->prev = newValue;
}

GEAR* createHead(int inputValue){
    GEAR* newHead = (GEAR*)malloc(sizeof(GEAR)*1);
    newHead->value = inputValue;
    newHead->next = newHead;
    newHead->prev = newHead;
    
    return newHead;
}

void printGear(GEAR* head){
    GEAR* tmp = head;
    do{
        printf("%d ",tmp->value);
        tmp = tmp->next;
    }
    while(tmp != head);
    printf("\n");
}
void findLocations(GEAR* gear1, GEAR* gear2, GEAR* gear3, int *loc1, int *loc2, int *loc3, int M){
    int found = 0;
    GEAR* tmp1, *tmp2, *tmp3;
    tmp1 = gear1;
    tmp2 = gear2;
    tmp3 = gear3;

    do{
        tmp2 = gear2;
        (*loc2) = 1;
        do{
        	(*loc3) = 1;
            if(tmp1->value == tmp2->value && *loc3 != M + 1){
                tmp3 = gear3;
                do{
                    if(tmp1->value == tmp3->value){
                        found = 1;
                    }
                    else{
                        tmp3 = tmp3->next;
                        (*loc3)++;
                    }
                }while(tmp3 != gear3 && found == 0);
            }
            if(!(tmp1->value == tmp2->value && *loc3 != M + 1)){
                tmp2 = tmp2->next;
                (*loc2)++;
            }
        }while(tmp2 != gear2 && found == 0);
        if(found == 0){
            tmp1 = tmp1->next;
            (*loc1)++;
        }
    }while(tmp1 != gear1 && found == 0);
    printf("Ortak Sayi: %d\n", tmp1->value);
}
void turnGear(GEAR** head, int loc1, int loc2, int M){
    int i, turn;
    GEAR* tmp = *head;
    turn = loc1-loc2;
    //anti-clockwise
    if(abs(turn) > M - abs(turn) && turn > 0){
        
        for(i = 0; i < M - abs(turn); i++){
            tmp = tmp->next;
        }
        *head = tmp;
        printf("Saat Yonunun Tersine %d Kere Cevrilmelidir\n", M - abs(turn));
    }
    else if(abs(turn) < M - abs(turn) && turn < 0){
    	for(i = 0; i < abs(turn); i++){
            tmp = tmp->next;
        }
        *head = tmp;
        printf("Saat Yonunun Tersine %d Kere Cevrilmelidir\n", abs(turn));
	}
    //clockwise
    else if(abs(turn) > M - abs(turn) && turn < 0){
    	for(i = 0; i < M - abs(turn); i++){
            tmp = tmp->prev;
        }
        *head = tmp;
        printf("Saat Yonunde %d Kere Cevrilmelidir\n", M - abs(turn));
	}
    else if(abs(turn) < M - abs(turn) && turn > 0){
        for(i = 0; i < abs(turn); i++){
            tmp = tmp->prev;
        }
        *head = tmp;
        printf("Saat Yonunde %d Kere Cevrilmelidir\n", abs(turn));
    }
    else{
    	for(i = 0; i < abs(turn); i++){
            tmp = tmp->prev;
        }
        *head = tmp;
        printf("Saat Yonunde %d Kere Cevrilmelidir\n", abs(turn));
	}
}
void placeNumbers(GEAR** head, int N, int M, int **numbers, int commonNumber, int *locs){
    int i, x, created = 0, noMatch;
	GEAR* tmp;
    for(i = 0; i < N; i++){
        numbers[1][i] = 0;
    }
    for(i = 0; i < M; i++){
        do{
            x = rand() % N + 1;
        }while(numbers[1][x-1] == 1 || numbers[0][x-1] == 2 || x == commonNumber);
        if(created == 0){
        	*head = createHead(x);
        	created = 1;
		}
        else
            addValue(head, x);
        (numbers[0][x-1])++;
        (numbers[1][x-1])++;
    }
    tmp = *head;
    do{
    	noMatch = 0;
    	x = rand() % M + 1;
    	for(i = 0; i < 2; i++){
    		if(x == locs[i])
    			noMatch = 1;
		}
	}while(noMatch == 1);
	locs[1] = locs[0];
	locs[0] = x;
	for(i = 0; i < x-1; i++){
		tmp = tmp->next;
	}
	tmp->value = commonNumber;
}
