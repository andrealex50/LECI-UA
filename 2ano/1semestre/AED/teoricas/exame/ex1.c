#include <stdio.h>

void SelectionSort(int* a, unsigned int n) {
    int indexMax;
    for (int i=(n-1); i>0; i--) {
        indexMax = i;
        for (int j=0; j<i;j++) {
            if (a[j] >= a[indexMax]) {
                indexMax = j;
            }
        }
        if (indexMax != i) {
            int temp = a[i];
            a[i] = a[indexMax];
            a[indexMax] = temp;
        }
    }
}

int main() {
    int b[] = {7, 2, 6, 4, 3};
    SelectionSort(b, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b[i]);
    }
    return 0;
}