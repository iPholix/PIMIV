#include <stdio.h>

int main() {
    int idade;
    printf("digite a sua idade: \n");
    scanf("%d", &idade);
    
    if( idade < 18 ) {
        printf(" Sem acesso \n");
    }
    else {
        printf(" Acesso permitido \n");
    }
    
    system("pause");
    
    return 0;
}