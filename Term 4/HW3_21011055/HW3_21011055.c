#include <stdio.h>
#include <stdlib.h>

typedef struct class{
    int classNo;
    struct class* next;
}Class;
typedef struct adjList{
    int inDegree;
    struct class* head;
}adjList;
void print(int** adjMatrix, int N){
    int i, j;
    printf("\n\nAdjacency Matrix: \n");
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}
Class* createNode(int j){
    Class* newNode = (Class*)malloc(sizeof(Class));
    newNode->classNo = j+1;
    newNode->next = NULL;
    return newNode;
}
int main(){
    int N, i, j, donem = 1, isDone = 0, exit;
    printf("N: ");
    scanf("%d", &N);
    adjList* list = (adjList*)malloc(sizeof(adjList)*N);
    Class* tmp;
    int** adjMatrix = (int**)malloc(sizeof(int*)*N);
    for(i = 0; i < N; i++)
    {
        adjMatrix[i] = (int*)malloc(sizeof(int));
    }
    //matris input
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    system("cls");
    print(adjMatrix, N);
    //liste oluşturma
    for(i = 0; i < N; i++){
        list[i].head = NULL;
        list[i].inDegree = 0;
        for(j = 0; j < N; j++){
            if(adjMatrix[i][j] == 1){
                tmp = createNode(j);
                tmp->next = list[i].head;
                list[i].head = tmp;
            }
        }
    }
    //indegree yerleştirme;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(adjMatrix[j][i] == 1){
                list[i].inDegree += 1;
            }
        }
    }
    //liste print
    printf("\nAdjacency List: ");
    for(i = 0; i < N; i++){
        tmp = list[i].head;
        printf("\nClass %d: ", i+1);
        while(tmp != NULL){
            printf("%d ", tmp->classNo);
            tmp = tmp->next;
        }
    }
    //dönem paylaştırılması
    printf("\n");
    while(isDone == 0){
        printf("\nDonem %d: ", donem);
        for(i = 0; i < N; i++){
            if(list[i].inDegree == 0){
                printf("Course-%d ", i+1);
                list[i].inDegree = -1;
            }
        }
        for(i = 0; i < N; i++){
            if(list[i].inDegree == -1){
                list[i].inDegree--;
                tmp = list[i].head;
                while(tmp != NULL){
                    list[tmp->classNo-1].inDegree--;
                    tmp = tmp->next;
                }
            }
        
        }
        exit = 0;
        j = 0;
        while(j < N && exit == 0){
            if(list[j].inDegree > -1)
                exit = 1;
            j++;
        }
        if(exit == 0)
            isDone = 1;
        donem++;
    }
    printf("\n\nOgrenci bolumu %d donemde bitirir.", donem-1);
    return 0;
}
