#include <stdio.h>
#include <string.h>

#include "./libs/multiply.h"
#include "./libs/animal.h"


void teste( Animal *caozinho ) {
    
    printf("2 Nome: %s \nIdade: %d\n", caozinho->nome, caozinho->idade);
    
    caozinho->nome = "ma oe";
    
    printf("3 Nome: %s \nIdade: %d\n", caozinho->nome, caozinho->idade);

}


void main() {
    Animal meuAnimal;
    
    meuAnimal.nome = "Teste";
    meuAnimal.idade = 10;
    
    printf("1 Nome: %s \nIdade: %d\n", meuAnimal.nome, meuAnimal.idade);
    
    teste( &meuAnimal );
}
