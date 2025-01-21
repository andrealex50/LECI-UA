#include <stdio.h>
#include <math.h>

int power(int x, int n) { 
    if (n == 0) 
        return 1; 
    else 
        return x * power(x, n-1); 
}

int main() {
    for (int i = 0; i <= 6; i++) {
        int t = pow(2, i);
        printf("%d\t%d\n", t, power(2, t));
    }

    return 0;
}
