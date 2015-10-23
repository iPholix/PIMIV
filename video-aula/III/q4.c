#include <stdio.h>

int main() {
    float num1, num2;
    char op;
    
    printf("Digite número op número \n");
    scanf("%f %c %f", &num1, &op, &num2);
    
    switch(op) {
        case '*':
            printf("= %f\n", num1 * num2);
        break;
        case '/':
            if( num2 > 0 ) {
                printf("= 10.5%f \n", num1 / num2);
            }
            else {
                printf("Divisão por zero\n");
            }
        break;
        default: 
            printf("operador inválido\n");
        break;
        
    }
    
    system("pause");
    return 0;
}