#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int value;
    int valueLeft;
    struct node *left;
    struct node *right;
}node;

struct kova{
	int value;
	struct kova *next;
}*top, *temp, *top1;

node *newNode(int value);
void printTree(node *root);
node *generateTree(int N, int M);
int isNode(node *root, int k);
node *hitFruit(node **root, int p, int k);
int isEmpty();
void create();
void push(int value);
int pop();
void printKova();
node *findMin(node *root);

int main(){
    int N, M, isDone = 0, k, p;
    srand(time(NULL));
    do{
        printf("Meyve Adedini Giriniz: ");
        scanf("%d", &M);
        printf("Maksimum Meyve Agirligini Giriniz: ");
        scanf("%d", &N);
    }while(N < M);
    //stack
    create();
    
    node* root = generateTree(N, M);
    printTree(root);
    printf("\n");
    while(isDone == 0){
    	do{
    		printf("Vurmak Istediginiz Meyvenin Degerini Giriniz: ");
    		scanf("%d", &k);
		}while(!(isNode(root, k)));
		printf("Vurus Gucunu Giriniz: ");
		scanf("%d", &p);
		
		root = hitFruit(&root, p, k);
    	printTree(root);
    	printf("\n");
    	
    	if(root == NULL)
    		isDone = 1;
	}
	printKova();
    return 0;
}

node *newNode(int value){
    node *newNode = (node*)malloc(sizeof(node)*1);
    
    newNode->value = value;
    newNode->valueLeft = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void printTree(node *root){
	
	if(root == NULL)
		return;
	
	printTree(root->left);
	if(root->value != root->valueLeft)
		printf("%d(%d) ", root->value, root->valueLeft);
	else
		printf("%d ", root->value);
	printTree(root->right);
	
}

node *generateTree(int N, int M){
	int i, valuePlaced, x;
	int* numbers = (int*)calloc(N, sizeof(int));
	node *root = NULL;
	node *tmp;
	for(i = 0; i < M; i++){
		do{
			x = rand() % N + 1;
		}while(numbers[x-1] == 1);
		numbers[x-1]++;
		
		if(root == NULL)
			root = newNode(x);
		else{
			valuePlaced = 0;
			tmp = root;
			while(valuePlaced == 0){
				if(x > tmp->value){
					if(tmp->right != NULL)
						tmp = tmp->right;
					else{
						tmp->right = newNode(x);
						valuePlaced = 1;
					}
				}
				else{
					if(tmp->left != NULL)
						tmp = tmp->left;
					else{
						tmp->left = newNode(x);
						valuePlaced = 1;
					}
				}
			}
		}
	}
	free(numbers);
	return root;
}
int isNode(node *root, int k){
	int found = 0;
	if(root == NULL)
		return 0;
	
	if(root->value == k)
		found = 1;
	if(found == 0){
		found = isNode(root->left, k);
		if(found == 0)
			found = isNode(root->right, k);
	}
	
	
	return found;
}
node *hitFruit(node **root, int p, int k){
	if (root == NULL) {
        return NULL;
    }

    if(k < (*root)->value){
        (*root)->left = hitFruit(&(*root)->left, p, k);
    }
	else if(k > (*root)->value){
        (*root)->right = hitFruit(&(*root)->right, p, k);
    }
    else{
    	(*root)->valueLeft -= p;
    	if((*root)->valueLeft <= 0){
    		push((*root)->value);
    		if((*root)->left != NULL && (*root)->right != NULL){
				(*root)->value = findMin((*root)->right)->value;
				(*root)->right = hitFruit(&(*root)->right, p, k);
   			}
    		else
    			(*root) = ((*root)->left != NULL) ? (*root)->left : (*root)->right;
		}
    	
	}
	

    return *root;
}
int isEmpty(){
	if(top == NULL)
		return 1;
	else
		return 0;
}
void create(){
	top = NULL;
}
void push(int value){
	if(top == NULL){
		top = (struct kova*)malloc(1*sizeof(struct kova));
		top->next = NULL;
		top->value = value;
	}
	else{
		temp = (struct kova*)malloc(1*sizeof(struct kova));
		temp->next = top;
		temp->value = value;
		top = temp;
	}
}
int pop(){
	int ret;
	top1 = top;
	
	if(top1 == NULL)
		return -1;
	else
		top1 = top1->next;
	ret = top->value;
	free(top);
	top = top1;
	return ret;
}
void printKova(){
	int value;
	if(isEmpty())
		return;
	value = pop();
	printKova();
	printf("%d ", value);
}
node *findMin(node *root){
	node *tmp = root;
	while(tmp->left != NULL){
		tmp = tmp->left;
	}
	return tmp;
}
















