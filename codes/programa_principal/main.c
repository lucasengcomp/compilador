//biblioteca de entrada padrão
#include <stdio.h>
#include <stdlib.h>

//biblioteca personalizada
#include "lista.h"
#include "memoria.h"

int main(void) {

    FILE *arquivo;

    verificaArquivo *novaLista = (verificaArquivo *)malloc(sizeof(verificaArquivo));

    somaMemoria(sizeof(verificaArquivo)); //pega a quantidade de memória que o arquivo está consumindo
    

}
