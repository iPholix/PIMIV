#include <stdio.h>

int main() {
    
    int numero;
    printf("Entre cmo um número: \n");
    scanf("%d", &numero);
    
    if( numero < 0 ) {
        printf(" negativo\n ");
    }
    
    if( numero >= 0 ) {
        printf(" positivo\n ");
    }
    
    system("pause");
   
    return 0;
}