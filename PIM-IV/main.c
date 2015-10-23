#include <stdio.h>

//Varáveis Globais

// O primeiro nível é a poltrona
// O segundo nível é o Tipo
// 0 = Vazio
// 1 = Ocupada - Normal
// 2 = Ocupado - Estudante
// 3 = Ocupado - Idoso

int _onibus[36];
int _poltrona_atual;
int _tipo_atual;
int _idosos = 0;
float _onibusPassagem = 100.00;
char *tiposPassagem[4] = { "Vazio", "Inteira", "Estudante", "Idoso" };

void clear() {
	system("clear");
}

void pausa() {
	 printf("Press enter to continue...\n");
	 getchar(); getchar();
}

void menuCaixa() {
	clear();
	printf("Gestao de Caixa.\n");
	printf("Passagens vendidas:\n\n");
	float valorTotal = 0;
	float valorParcial = 0;
	int inteiras=0;
	int estudantes=0;
	int idosos=0;
	int i;

	for (i = 0; i < 36; i++) {
		valorParcial = 0;
		//Se inteira
		if (_onibus[i] == 1){
			valorParcial = _onibusPassagem;
			inteiras++;
		}
		
		//Se estudante
		if (_onibus[i] == 2){
			valorParcial = _onibusPassagem/2;
			estudantes++;
		}
		
		//Se Idoso
		if (_onibus[i] == 3){
			valorParcial = 0;
			idosos++;
		}
		valorTotal=valorTotal+valorParcial;
	}

	printf("Passagens Inteiras: %d.   - Total: R$%.2f.\n", inteiras, inteiras*_onibusPassagem );
	printf("Passagens Idodos: %d. 	  - Total: R$ 0.00.\n", idosos );
	printf("Passagens Estudantes: %d. - Total: R$%.2f.\n", estudantes, estudantes*_onibusPassagem/2 );
	printf("Total Vendido: %f. \n", valorTotal);
    pausa();
}

void finalizaPassagem(){
	clear();
	_onibus[_poltrona_atual]=_tipo_atual;
	printf("======================================================\n");
	printf("------------------ Passagem Vendida ------------------\n");
	printf("======================================================\n");
	printf("Onibus... Destino... Data... Hora...\n");	
	printf("Onibus 001 \n");	
	printf("Poltrona %d\n",_poltrona_atual);
	printf("Pressione uma tecla para retornar ao menu principal.\n");		
	pausa();
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
	_tipo_atual = escolhaCompra;	
	
	clear();
	switch (escolhaCompra) {
	case 1:
		printf("Passagem Inteira.\n");
		break;
	case 2:
		printf("Passagem para Estudantes.\n");
		break;
	case 3:
		printf("Passagem para Idosos.\n");
		if (_idosos >= 2){
			printf("Já foram vendidas todas as passagens disponíveis para idoso neste ônibus.\n");
			goto comecoCompra;
		}
		_idosos++;
		break;
	case 4:
	break;
	default:
		printf("Opcao invalida! Escolha novamente.\n----------------------------------\n");
		goto comecoCompra;
		break;
	}
		finalizaPassagem();
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
        
	if (_onibus[escolhaPoltrona] != 0)
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