#include<stdio.h>


void vender_passagem(o)
{
    printf("Venda de Passagem\n");

}

void historico_caixa()
{
    printf("Histórico de Caixa\n");
}

void sair()
{
    printf("Ja vai??? Nao! Nao! Espere! Naa...\n");
}



//Estruturas aninhadas
//estrutura da passagem de onibus
struct Passagem 
{
    int acento;
    int ocupado;
    float valor;
    int idoso;
    int estudante;
};
struct onibus 
{
    char *destino;
    char data_hora[50];
    int lugares;
    int numero;
    struct Passagem pass[36]; 
};



main()
{
    int continuar=1;
    
   //Definir passagem em branco
    struct onibus o[5];
    
    //Definir ônibus 1
    o[0].lugares = 36;
    o[0].numero = 3214;
    
    o[0].pass[1].acento = 1;
    
    

    do
    {
        printf("\n\tSistema de ônibus PIM IV\n\n");
        printf("1. Vender Passagem\n");
        printf("2. Verificar histórico do caixa\n");
        printf("0. Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch(continuar)
        {
            case 1:
                vender_passagem(o);
                 break;
                 
            case 2:
                historico_caixa();
                break;

            case 0:
                sair();
                break;

            default:
                printf("Digite uma opcao valida\n");
        }
    } while(continuar);
}