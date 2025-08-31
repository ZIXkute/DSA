#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *Eptr;

void initialitze(Eptr L){
    L->count = 0;
}

void insertPos(Eptr L, int data, int position){
    if(L->count == MAX){
        printf("Full");
        return;
    }
    if(position < 0 || position > L->count){
        printf("Invalid");
        return;
    }
    for(int i = L->count; i > position; i--){
        L->elem[i] = L->elem[i-1];
    }
    L->elem[position] = data;
    L->count++;
}

void deletePos(Eptr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid");
        return;
    }
    for(int i = position; i < L->count - 1; i++){
        L->elem[i] = L->elem[i+1];
    }
    L->count--;
}

int locate(Eptr L, int data){
    for(int i = 0; i < L->count; i++){
        if(L->elem[i] == data)return i;
    }
    return -1;

}

int retrive(Eptr L, int position){
    if(position < 0 || position >= L->count){
        printf("Invalid");
        return -1;
    }
    return L->elem[position];

}

void insertSorted(Eptr L, int data){
    if(L->count == MAX){
        printf("Full");
        return;
    }
    int i = L->count - 1;
    while(i >= 0 && L->elem[i] > data){
        L->elem[i+1] = L->elem[i];
        i--;
    }
    L->elem[i + 1] = data;
    L->count++;

}

void makeNULL(Eptr L){
    L->count = 0;
}

void display(Eptr L){
    for(int i = 0; i < L->count; i++){
        printf("%d ", L->elem[i]);
    }
    printf("\n");
}


int main(){
    Etype myList;
    Eptr L = &myList;

    initialitze(L);

    insertPos(L, 10, 0);
    insertPos(L, 20, 1);
    insertPos(L, 15, 1);
    display(L);

    deletePos(L, 1);
    printf("Position 1 deleted: ");
    display(L);

    printf("Location of 20 is %d\n", locate(L, 20));
    printf("Element of pos 1 is %d\n", retrive(L, 1));

    insertSorted(L, 12);
    insertSorted(L, 5);
    display(L);

    makeNULL(L);
    display(L);

    return 0;
}