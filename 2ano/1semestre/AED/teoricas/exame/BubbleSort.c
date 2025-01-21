#include <stdio.h>

void BubbleSort(int* a,int n) {
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

int main() {
    int b[] = {7, 2, 6, 4, 3};
    BubbleSort(b, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b[i]);
    }
    return 0;
}