#include <stdio.h>

int BinarySearchRecursive(int n, int* array, int max, int min) {
    int middle = (min + max)/2;
    if (n == array[middle]) {
        return middle;
    }  
    if (n > array[middle]) {
        return BinarySearchRecursive(n,array,max,middle+1);
    } 
    return BinarySearchRecursive(n,array,middle-1,min);
}

int main() {
    int a[] = {1,4,7,9,12,13};
    printf("ENCONTROU? : %d\n",BinarySearchRecursive(7,a,5,0));
    printf("ENCONTROU? : %d\n",BinarySearchRecursive(1,a,5,0));
    return 0;
}