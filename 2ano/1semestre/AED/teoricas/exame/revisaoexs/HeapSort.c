#include <stdio.h>

// HeapSort
void heapify(int* a, int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && a[left] > a[largest]) {
        largest = left;
    } 
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    if (largest != i) {
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        heapify(a,largest,n);
    }
}
void HeapSort(int* a, int n) {
    // build MAX heap
    for (int i= (n/2 - 1); i>=0; i--) {
        heapify(a,i,n);
    }
    for (int i = (n-1); i>=0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a,0,i);
    }

}