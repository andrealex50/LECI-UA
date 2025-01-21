#include <stdio.h>

//Não ordenado
int LinearSearch(int* a, int size, int n) {
    for (int i=0; i<size; i++) {
        if (a[i] == n) {
            return i;
        }
    }
    return -1;
}

//Ordenado
int LinearSearchSorted(int* a, int size, int n) {
    int stop;
    int i;
    for (i=0; i<size; i++) {
        if (n <= a[i]) {
            stop = 1;
            break;
        }
    }
    if (stop == 1 && a[i]==n) {
        return i;
    }
    return -1;
}

// Binary Search Iterativo
int BinarySearch(int* a, int n, int x) {
    int first = 0;
    int last = n-1;
    int middle;
    while(first <= last) {
        middle = (first + last)/2;
        if (x == a[middle]) {
            return middle;
        } 
        if (x < a[middle]) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }       
    }
    return -1;
}

// Binary Search Recursivo
int BinarySearchRec(int* a, int esq, int dir, int n) {
    int middle;
    if (esq <= dir) {
        middle = (esq+dir)/2;
        if (n == a[middle]) {
            return middle;
        }
        if (n < a[middle]) {
            return BinarySearchRec(a,esq,middle-1,n);
        } 
        return BinarySearchRec(a,middle+1,dir,n);
    }
    return -1;
} 
