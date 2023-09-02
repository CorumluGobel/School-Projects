#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sub{
	int id;
	char* name;
	char* type;
}SUB;
typedef struct database{
	SUB** data;
}DATABASE;

SUB* addnew(int id, char* name, char* type){
	SUB* newSub = (SUB*)malloc(1*sizeof(SUB));
	newSub->name = (char*)malloc((strlen(name)+1)*sizeof(char));
	strcpy(newSub->name,name);
	newSub->type = (char*)malloc((strlen(type)+1)*sizeof(char));
	strcpy(newSub->type,type);
	newSub->id = id;
	return newSub;
}
SUB* getPerson(SUB* newSub){
	int id;
	char name[16], type[2];
	printf("ID: ");
	scanf("%d", &id);
	printf("Name: ");
	scanf("%s", name);
	printf("Type: ");
	scanf("%s", type);
	newSub = addnew(id, name, type);
	return newSub;
}
void sort(int n, DATABASE database){
	int i;
	int j;
	SUB* tmp;
	int counter;
	int min;
	for(i = 0; i < n; i++){
		if(database.data[i]->type[0] == 'A'){
			tmp = database.data[i];
			for(j = i; j > 0; j--){
				database.data[j] = database.data[j-1];
			}
			database.data[0] = tmp;
			counter++;
		}
	}
	for(i = 0; i < counter; i++){
		min = 9999;
		for(j = i; j < counter; j++){
			if(min >= database.data[j]->id){
				min = database.data[j]->id;
				tmp = database.data[j];
			}
		}
		for(j = counter-1; j > 0; j--){
			database.data[j] = database.data[j-1];
		}
		database.data[0] = tmp;
	}
	for(i = counter; i < n; i++){
		min = 9999;
		for(j = i; j < n; j++){
			if(min >= database.data[j]->id){
				min = database.data[j]->id;
				tmp = database.data[j];
			}
		}
		for(j = n-1; j > counter; j--){
			database.data[j] = database.data[j-1];
		}
		database.data[counter] = tmp;
	}
}

int main(){
	SUB* newSub;
	int n, i;
	char name[10];
	DATABASE database;
	database.data = (SUB**)malloc(n*sizeof(SUB*));
	
	
	printf("Enter subscriber count: ");
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		newSub = getPerson(newSub);
		database.data[i] = newSub;
	}
	sort(n, database);
	for(i = 0; i < n; i++){
		printf("\nId: %d, Name: %s, Type: %s", database.data[i]->id, database.data[i]->name, database.data[i]->type);
	}
	
	return 0;
}
