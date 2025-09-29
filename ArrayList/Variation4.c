#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10
typedef int studtype;

typedef struct {
    studtype *elemPtr;
    int count;
    int max;
} List;

void initialize(List *L) {
    L->elemPtr = (studtype*) malloc(LENGTH * sizeof(studtype));
    if (L->elemPtr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    L->count = 0;
    L->max = LENGTH;
}

void resize(List *L) {
    int newSize = L->max * 2;
    studtype *newPtr = (studtype*) realloc(L->elemPtr, newSize * sizeof(studtype));
    if (newPtr == NULL) {
        printf("Resize failed!\n");
        exit(1);
    }
    L->elemPtr = newPtr;
    L->max = newSize;
}

void insertPos(List *L, studtype elem, int pos) {
    if (L->count == L->max) resize(L);

    if (pos < 0 || pos > L->count) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = L->count; i > pos; i--) {
        L->elemPtr[i] = L->elemPtr[i - 1];
    }

    L->elemPtr[pos] = elem;
    L->count++;
}

void deletePos(List *L, int pos) {
    if (pos < 0 || pos >= L->count) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < L->count - 1; i++) {
        L->elemPtr[i] = L->elemPtr[i + 1];
    }

    L->count--;
}

int locate(List L, int ID) {
    for (int i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == ID) return i;
    }
    return -1;
}

studtype retrieve(List L, int pos) {
    if (pos < 0 || pos >= L.count) {
        printf("Invalid position!\n");
        return -1;
    }
    return L.elemPtr[pos];
}

void insertSorted(List *L, studtype elem) {
    if (L->count == L->max) resize(L);

    int i = L->count - 1;
    while (i >= 0 && L->elemPtr[i] > elem) {
        L->elemPtr[i + 1] = L->elemPtr[i];
        i--;
    }

    L->elemPtr[i + 1] = elem;
    L->count++;
}

void makeNULL(List *L) {
    L->count = 0;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

int main() {
    List L;
    initialize(&L);

    insertPos(&L, 10, 0);
    insertPos(&L, 20, 1);
    insertPos(&L, 15, 1);
    display(L);

    deletePos(&L, 1);
    printf("Position 1 deleted: ");
    display(L);

    printf("Location of 20: %d\n", locate(L, 20));
    printf("Element at pos 1: %d\n", retrieve(L, 1));

    insertSorted(&L, 12);
    insertSorted(&L, 5);
    display(L);

    makeNULL(&L);
    display(L);

    free(L.elemPtr);
    return 0;
}
