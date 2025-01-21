#include <stdio.h>

// Selection Sort
void SelectionSort(int* a, int n) {
    int indexmax;
    for (int i=(n-1); i>0; i--) {
        indexmax = i;
        for (int j=0; j<=i; j++) {
            if (a[j] >= a[indexmax]) {
                indexmax = j;
            }
        }
        if (indexmax != i) {
            int temp = a[i];
            a[i] = a[indexmax];
            a[indexmax] = temp;
        }
    }
}

// Bubble Sort
void BubbleSort(int* a, int n) {
    for (int i=(n-1); i>0; i--) {
        for (int j=0; j<=i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Insertion Sort
void InsertionSort(int* a, int n) {
    for (int i=1; i<n;i++) {
        int key = a[i];
        int j = i - 1;
        while (j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}