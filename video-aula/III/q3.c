#include <stdio.h>

int main() {
    int n1, n2, n3;
    
    printf("entre com 3 números separados por espaço: \n");
    scanf("%d %d %d", &n1, &n2, &n3);
    
    if( n1 < n2 ) {
        if( n1 < n3 ) {
            printf("O menor número %d \n", n1);
        }
        else {
            printf("O menor número %d \n", n3);
        }
    }
    else {
        if( n2 < n3 ) {
            printf("O menor número %d \n", n2);
        }
        else {
            printf("O menor número %d \n", n3);
        }
    }
}