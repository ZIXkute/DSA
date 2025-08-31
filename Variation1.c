#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
}List;

List initialize();
    void insertPos(List *L, int data, int possition);
    void deletePos(List *L, int possition);
    int locate(List L, int data);
    void insertSorted(List *L, int data);
    void display(List L);

List initialize(){
    List L;
    L.count = 0;
    return L;
}

void insertPos(List *L, int data, int possition){
    if(L->count == MAX){
        printf("Full\n");
        return;
    }
    if(possition < 0 || possition > L-> count){
        printf("Invalid\n");
        return;
    }

    for(int i = L ->count; i > possition; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[possition] = data;
    L->count++;
}

void deletePos(List *L, int possition){
    if(possition < 0 || possition >= L->count){
        printf("Invalid\n");
        return;
    }
    for(int i = possition; i < L->count - 1; i++){
        L->elem[i] = L->elem[i + 1];
    }
    L->count --;
}

int locate(List L, int data){
    for(int i = 0; i < L.count; i++){
        if(L.elem[i] == data)
        return i;
    }
    return -1;
}

void insertSorted(List *L, int data){
    if(L->count == MAX){
        printf("Full\n");
        return;
    }
    int i = L->count - 1;
    while(i >= 0 && L->elem[i] > data){
        L->elem[i+1] = L->elem[i];
        i--;
    }
    L->elem[i+1] = data;
    L->count++;
}

void display(List L){
    if(L.count == 0){
        printf("Empty\n");
        return;
    }
    printf("List elements: ");
    for(int i = 0; i < L.count; i++){
        printf("%d ", L.elem[i]);
    }
    printf("\n");
}

int main() {
    List L = initialize();

    insertPos(&L, 10, 0);
    insertPos(&L, 20, 1);
    insertPos(&L, 30, 2);
    display(L);

    printf("\nDeleting element at position 1\n");
    deletePos(&L, 1);
    display(L);

    printf("\nLocating element 30: Position %d\n", locate(L, 30));

    printf("Insert sort elemens:\n");
    insertSorted(&L, 15);
    insertSorted(&L, 5);
    insertSorted(&L, 25);
    display(L);

    return 0;
    
}