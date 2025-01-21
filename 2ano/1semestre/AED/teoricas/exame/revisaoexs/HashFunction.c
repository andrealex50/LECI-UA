#include <stdio.h>

int Hash(char* s, int n) {
    int hash = 0;
    for (int i=0; i<n; i++) {
        hash = s[i] + 31*hash;
    }
    return hash;
}

int main() {
    char input[] = "example";  // You can replace this string with the desired input
    int length = sizeof(input) - 1;  // Calculate the length of the string

    int result = Hash(input, length);
    
    printf("Hash value: %d\n", result);

    return 0;
}