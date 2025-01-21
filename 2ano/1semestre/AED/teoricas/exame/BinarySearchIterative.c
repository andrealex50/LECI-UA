#include <stdio.h>

int BinarySearchIterative(int* array, int size, int n) {
    int found = 0;
    int right = size-1;
    int left = 0;
    while (left<=right) {
        int middle = (right + left)/2;
        if (array[middle] == n) {
            found = 1;
            break;
        } else if (n > array[middle]) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    } 
    return found;
}

int main() {
    int a[] = {1,4,7,9,12,13};
    printf("ENCONTROU? : %d\n",BinarySearchIterative(a,6,14));
    printf("ENCONTROU? : %d\n",BinarySearchIterative(a,6,1));
    return 0;
}