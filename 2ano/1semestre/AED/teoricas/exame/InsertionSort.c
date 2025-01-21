#include <stdio.h>

void InsertionSort(int* a, int n) {
    for (int i=1; i<n; i++) {
        int key = a[i];
        int j = i-1;
        while (j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

int main() {
    int b[] = {7, 2, 6, 4, 3};
    InsertionSort(b, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b[i]);
    }
    return 0;
}