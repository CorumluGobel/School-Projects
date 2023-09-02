#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
	int id;
	int v1;
	int v2;
	struct Node* next;
}Node;
void printList(Node* n);
void insert(struct Node** head_ref, int id, int value1, int value2);
Node* intersection(Node* start1, Node* start2, int (*compare)(Node*, Node*));
int compare_by_value1(Node* Node1, Node* Node2);
int compare_by_value2(Node* Node1, Node* Node2);


int main(){
	
	Node* start = NULL;
	insert(&start, 1, 10, 15); insert(&start, 2,20,15);
	insert(&start, 4,20,15); insert(&start, 7,30,20);
	insert(&start, 10,30,40);
	
	Node* start2 = NULL;
	insert(&start2, 1, 10, 15); insert(&start2, 4,25,15);
	insert(&start2, 7,25,20); insert(&start2, 10,30,41);
	Node* node3 = intersection(start, start2, compare_by_value1);
	printList(node3);
	Node* node4 = intersection(start, start2, compare_by_value2);
	printList(node4);
	return 0;
}
void printList(Node* n){
	Node* tmp = n;
	while(tmp != NULL){
		printf("id: %d, v1: %d, v2: %d\n", tmp->id, tmp->v1, tmp->v2);
		tmp = tmp->next;
	}
}
void insert(struct Node** head_ref, int id, int value1, int value2){
	Node* newNode; 
	newNode = (Node*)malloc(sizeof(Node));
	Node* tmp = *head_ref;
	newNode->id = id;
	newNode->v1 = value1;
	newNode->v2 = value2;
	newNode->next = NULL;
	if(tmp == NULL){
		*head_ref = newNode;
	}
	else{
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}
Node* intersection(Node* start1, Node* start2, int (*compare)(Node*, Node*)){
	Node* returnNode = NULL;
	Node* tmp1 = start1;
	Node* tmp2 = start2;
	while(tmp1 != NULL){
		tmp2 = start2;
		while(tmp2 != NULL){
			if(compare(tmp1, tmp2) == 1){
				insert(&returnNode, tmp1->id, tmp1->v1, tmp1->v2);			
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return returnNode;
}
int compare_by_value1(Node* Node1, Node* Node2){
	if(Node1->id == Node2->id && Node1->v1 == Node2->v1 ){
		return 1;
	}
	else{
		return 0;
	}
}
int compare_by_value2(Node* Node1, Node* Node2){
	if(Node1->id == Node2->id && Node1->v2 == Node2->v2){
		return 1;
	}
	else{
		return 0;
	}
}
