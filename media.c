#include <stdio.h>

void main() {
    
    double nota1, nota2, media;
    
    printf("Digita a nota 1: ");
    scanf("%lf", &nota1);
    
    printf("Digita a nota 2: ");
    scanf("%lf", &nota2);
    
    media = (nota1 + nota2) / 2;
    
    printf("A média de %lg + %lg é: %lg", nota1, nota2, media);
}