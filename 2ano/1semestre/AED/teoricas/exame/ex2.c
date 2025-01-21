#include <stdio.h>
#include <stdlib.h>

struct header_pointer {
    int* elements;
    int numElements;
    int current;
};

typedef struct header_pointer* header_pointer;

header_pointer Merge(header_pointer seq_1, header_pointer seq_2) {
    header_pointer mergedHeader = (header_pointer)malloc(sizeof(struct header_pointer));
    mergedHeader->numElements = seq_1->numElements + seq_2->numElements;
    mergedHeader->elements = (int*)malloc(mergedHeader->numElements * sizeof(int));

    int left1 = seq_1->current;
    int left2 = seq_2->current;
    int mergedIndex = 0;

    while (left1 < seq_1->numElements && left2 < seq_2->numElements) {
        if (seq_1->elements[left1] <= seq_2->elements[left2]) {
            mergedHeader->elements[mergedIndex++] = seq_1->elements[left1++];
        } else {
            mergedHeader->elements[mergedIndex++] = seq_2->elements[left2++];
        }
    }

    // Set the mergedHeader properties
    mergedHeader->current = 0;

    return mergedHeader;
}

void PrintSequence(header_pointer mergedSeq) {
    for (int i = 0; i < mergedSeq->numElements; i++) {
        printf("%d ", mergedSeq->elements[i]);
    }
    printf("\n");
}

int main() {
    // Example usage
    struct header_pointer seq1 = {(int[]){1, 4, 5, 6}, 4, 0};
    struct header_pointer seq2 = {(int[]){2, 4, 5, 8}, 4, 0};

    header_pointer mergedSeq = Merge(&seq1, &seq2);

    // Print the merged sequence
    PrintSequence(mergedSeq);

    // Don't forget to free the allocated memory
    free(mergedSeq->elements);
    free(mergedSeq);

    return 0;
}
