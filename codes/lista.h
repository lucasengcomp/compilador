//biblioteca de entrada padrão
#include <string.h> // para permitir a manipulação de strings. +info em http://www.cplusplus.com/reference/cstring/strcpy/

typedef struct VerificaArquivo {
    char linha[1000];
    int posicao;

    struct VerificaArquivo *proximaLinha;   
} verificaArquivo;

verificaArquivo *novaLista(char *linha, int posicao) {
    //aloca o espaço na memória para o arquivo
    verificaArquivo *ponteiroArquivo = malloc(sizeof(verificaArquivo)); 

    //verifica o tamanho da memória
    somaMemoria(sizeof(verificaArquivo)); 
    
    if (ponteiroArquivo == NULL) {
        printf("Erro na execução do arquivo! Sem memória no momento!");
        exit(0);
    } else {
        strcpy (ponteiroArquivo -> linha, linha);
        ponteiroArquivo -> posicao = posicao;
        ponteiroArquivo -> proximaLinha = NULL;
        return ponteiroArquivo;
    }

}


