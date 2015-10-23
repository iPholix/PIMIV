#include <stdio.h>

//Varáveis Globais

// O primeiro nível é a poltrona
// o segundo nível é o Tipo
// 0 = Vazio
// 1 = Ocupada - Normal
// 2 = Ocupado - Estudante
// 3 = Ocupado - Idoso
int _onibus[36];
int _poltrona_atual;
int _tipo_atual;
int _idoso;

_idoso = 0;

void clear() {
	system("clear");
}

void finalizaPassagem(){
	clear();
	_onibus[_poltrona_atual][1]=_tipo_atual;
	printf("=====================================================\n");	
	printf("Passagem Vendida:\n");	
	printf("=====================================================\n");		
	printf("Onibus... Destino... Data... Hora...\n");	
	printf("Onibus 001 \n");	
	printf("Poltrona %d\n",_poltrona_atual);
	printf("Pressione uma tecla para reiniciar...\n");		
	getchar();
	clear();
}

void menuCompra() {
	comecoCompra:
	
	printf("Comprar Passagem\n\n");
	printf("1. Passagem Inteira.\n");
	printf("2. Passagem para Estudantes.\n");
	printf("3. Passagem para Idosos.\n");	
	printf("4. Voltar ao Menu Principal.\n\n");
	printf("Digite o numero da sua escolha: ");
	
	int escolhaCompra;
	scanf("%d", &escolhaCompra);
	
	clear();
	switch (escolhaCompra) {
	case 1:
		_tipo_atual = escolhaCompra;
		printf("Passagem Inteira.\n");
		finalizaPassagem();
		break;
	case 2:
		_tipo_atual = escolhaCompra;	
		printf("Passagem para Estudantes.\n");
		finalizaPassagem();		
		break;
	case 3:
		_tipo_atual = escolhaCompra;
		printf("Passagem para Idosos.\n");
		if
		
		finalizaPassagem();	
		break;
	case 4:
	break;
	default:

		printf("Opcao invalida! Escolha novamente.\n----------------------------------\n");
		goto comecoCompra;
		break;
	}

}



void menuEscolhePoltrona() {
	comecoPoltrona:
	printf("Poltrona desejada:\n\n");
	printf("Digite o n. da poltrona: ");
	
	int escolhaPoltrona;
	scanf("%d", &escolhaPoltrona);
	
	if (escolhaPoltrona>36 || escolhaPoltrona<1)
        {
        	printf ("\n\nPoltrona inválida, escolha um valor entre 1 e 36!\n");
        	goto comecoPoltrona;
        }
        
	if (_onibus[escolhaPoltrona][1] != 0)
        {
        	printf ("\n\nA Poltrona %d já está ocupada, escolha outra!\n", escolhaPoltrona );
        	goto comecoPoltrona;
        }    
    
    _poltrona_atual = escolhaPoltrona;
    menuCompra();
    
}


void menuOnibus() {
    comecoOnibus:
    printf("Escolha o Onibus\n\n");
    printf("1. 101-010\n");
    printf("Digite o numero da sua escolha: ");
    
    int escolhaOnibus;
    scanf("%d", &escolhaOnibus);
    
    if (escolhaOnibus == 1) {
		clear();
		menuEscolhePoltrona();
    }
	else {
		clear();
		printf("Opcao invalida! Escolha novamente.\n----------------------------------\n");
		goto comecoOnibus;
  }
}



void menuCaixa() {
	printf("Gestao de Caixa.\n\n");
	printf("1. Compras Detalhadas.\n");
	printf("2. Saldo em Caixa.\n");
	printf("3. Voltar ao Menu Principal.\n\n");
	printf("Digite o numero da sua escolha: ");

	int escolhaCaixa;
	scanf("%d", &escolhaCaixa);

	switch (escolhaCaixa) {
	case 1:
		clear();
		printf("Compra Detalhada.\n");
		getchar();
		break;
	case 2:
		clear();
		printf("Saldo em Caixa.\n");
		getchar();
		break;
	case 3:
		clear();
		break;
	default:
		clear();
		printf("Opcao invalida! Escolha novamente.\n----------------------------------\n");
		menuCompra();
		break;
	}
}

void menuPrincipal() {
	comecoPrincipal:
	
	printf("Sistema de Venda de Passagens de Onibus\n\n");
	printf("1. Comprar Passagem.\n");
	printf("2. Gestao do Caixa.\n");
	printf("3. Sair.\n\n");
	printf("Digite o numero da sua escolha: ");

	int escolhaPrincipal;
	scanf("%d", &escolhaPrincipal);

	switch (escolhaPrincipal) {
	case 1:
		clear();
		menuOnibus();
		goto comecoPrincipal;
		break;
	case 2:
		clear();
		menuCaixa();
		goto comecoPrincipal;
		break;
	case 3:
		break;
	default:
		clear();
		printf("Opcao invalida! Escolha novamente.\n----------------------------------\n");
		goto comecoPrincipal;
		break;
	}
}

int main(int argc, char *argv[]) {
	clear();
	menuPrincipal();
	return 0;
}