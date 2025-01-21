void heapify(int arr[], int N, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) { 
        // TROCAR
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) {
    // Build MAX-Heap
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // HeapSort
    for (int i = N - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}