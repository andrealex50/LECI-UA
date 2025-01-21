#include <stdio.h>

// SelectionSort
void SelectionSort(int* a, unsigned int n) {
    int indexMax;
    for (int i=(n-1); i>0; i--) {
        indexMax = i;
        for (int j=0; j<i; j++) {
            if (a[j] > a[indexMax]) {
                indexMax = j;
            }
        }
        if (indexMax != i) {
            int temp = a[indexMax];
            a[indexMax] = a[i];
            a[i] = temp;
        }
    }
}

// BubbleSort 
void BubbleSort(int* a, unsigned int n) {
    for (int i=(n-1); i>0; i--) {
        for (int j=0; j<i; j++) {
            if (a[j] > a[j+1]) {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// InsertionSort
void InsertionSort(int* a, unsigned int n) {
    for (int i=1; i<n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j>=0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

// TorresDeHanoi
void TorresDeHanoi(char origem, char auxiliar, char destino, int n) {
    if (n == 1) {
        printf("Movimento de %c para %c",origem,destino);
        return;
    }
    TorresDeHanoi(origem,destino,auxiliar,n-1);
    printf("Movimento de %c para %c",origem,destino);
    TorresDeHanoi(auxiliar,origem,destino,n-1);
}

// MergeSort
void MergeSort(int* a, int* tmpA, int left, int right) {
    if (left < right) {
        int center = (left + right)/2;
        MergeSort(a,tmpA,left,center);
        MergeSort(a,tmpA,center+1,right);

        int lPos = left;
        int rPos = center + 1;
        int rEnd = right;
        int lEnd = rPos - 1;
        int tmpPos = lPos;
        int nElements = rEnd - lPos + 1;

        while (lPos <= lEnd && rPos <= rEnd) {
            if (a[lPos] <= a[rPos]) {
                tmpA[tmpPos++] = a[lPos++];
            } else {
                tmpA[tmpPos++] = a[rPos++];
            }
        }
        while (lPos <= lEnd) {

        }
        while (rPos < rEnd) {

        }
    }
}

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


int main() {
    int b[] = {7, 2, 6, 4, 3};
    SelectionSort(b, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b[i]);
    }

    printf("\n");
    int b1[] = {7, 2, 6, 4, 3};
    BubbleSort(b1,5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b1[i]);
    }
     
    printf("\n");
    int b2[] = {7, 2, 6, 4, 3};
    InsertionSort(b2,5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b2[i]);
    }

    printf("\n");
    int b3[] = {7, 2, 6, 4, 3};
    HeapSort(b3,5);
    for (int i = 0; i < 5; i++) {
        printf("%d, ", b3[i]);
    }

    return 0;
}