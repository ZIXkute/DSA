#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L) {
    L.elemPtr = (int*) malloc(LENGTH * sizeof(int));
    if (L.elemPtr == NULL) {
        printf("failed!\n");
        exit(1);
    }
    L.count = 0;
    L.max = LENGTH;
    return L;
}

List resize(List L) {
    int newSize = L.max * 2;
    int *newPtr = (int*) realloc(L.elemPtr, newSize * sizeof(int));
    if (newPtr == NULL) {
        printf("Resize failed!\n");
        exit(1);
    }
    L.elemPtr = newPtr;
    L.max = newSize;
    return L;
}

List insertPos(List L, int data, int pos) {
    if (L.count == L.max) {
        L = resize(L);
    }
    if (pos < 0 || pos > L.count) {
        printf("Invalid\n");
        return L;
    }
    for (int i = L.count; i > pos; i--) {
        L.elemPtr[i] = L.elemPtr[i - 1];
    }
    L.elemPtr[pos] = data;
    L.count++;
    return L;
}

List deletePos(List L, int pos) {
    if (pos < 0 || pos >= L.count) {
        printf("Invalid!\n");
        return L;
    }
    for (int i = pos; i < L.count - 1; i++) {
        L.elemPtr[i] = L.elemPtr[i + 1];
    }
    L.count--;
    return L;
}

int locate(List L, int data) {
    for (int i = 0; i < L.count; i++) {
        if (L.elemPtr[i] == data) return i;
    }
    return -1;
}

List insertSorted(List L, int data) {
    if (L.count == L.max) {
        L = resize(L);
    }
    int i = L.count - 1;
    while (i >= 0 && L.elemPtr[i] > data) {
        L.elemPtr[i + 1] = L.elemPtr[i];
        i--;
    }
    L.elemPtr[i + 1] = data;
    L.count++;
    return L;
}

void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d ", L.elemPtr[i]);
    }
    printf("\n");
}

int main() {
    List L;
    L = initialize(L);

    L = insertPos(L, 10, 0);
    L = insertPos(L, 20, 1);
    L = insertPos(L, 15, 1);
    display(L);

    L = deletePos(L, 1);
    printf("Position 1 deleted: ");
    display(L);

    printf("Location of 20: %d\n", locate(L, 20));

    L = insertSorted(L, 12);
    L = insertSorted(L, 5);
    display(L);

    free(L.elemPtr);

    return 0;
}
