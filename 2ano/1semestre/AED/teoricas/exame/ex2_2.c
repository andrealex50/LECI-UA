#include <stdlib.h>
#include <stdio.h>

// Definindo a estrutura Node
typedef struct Node {
    struct Node* next;
    int data;
} Node;

// Definindo a estrutura header_pointer
typedef struct {
    Node* next;
    int numEle;
} header_pointer;

header_pointer* Merge(header_pointer seq_1, header_pointer seq_2) {
    header_pointer* final = (header_pointer*)malloc(sizeof(header_pointer));
    final->numEle = 0;
    final->next = NULL;
    Node* current1 = seq_1.next;
    Node* current2 = seq_2.next;
    Node* currentFinal = final->next; // currentFinal para percorrer a lista final

    while (current1 != NULL && current2 != NULL) {
        if (current1->data <= current2->data) {
            // Inserimos o menor elemento do seq_1 no final
            currentFinal->next = current1;
            current1 = current1->next; // Avançamos para o próximo elemento de seq_1
        } else {
            // Inserimos o menor elemento do seq_2 no final
            currentFinal->next = current2;
            current2 = current2->next; // Avançamos para o próximo elemento de seq_2
        }
        currentFinal = currentFinal->next; // Avançamos para o próximo elemento na lista final
    }

    // Verificar se há elementos restantes em seq_1 e adicionar à lista final
    while (current1 != NULL) {
        currentFinal->next = current1;
        current1 = current1->next;
        currentFinal = currentFinal->next;
    }

    // Verificar se há elementos restantes em seq_2 e adicionar à lista final
    while (current2 != NULL) {
        currentFinal->next = current2;
        current2 = current2->next;
        currentFinal = currentFinal->next;
    }

    // Atualizar o número de elementos na lista final
    final->numEle = seq_1.numEle + seq_2.numEle;

    return final;
}


