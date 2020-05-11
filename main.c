#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions/listaEncadeada.h"
#include "functions/tabelaSimbolos.h"

char palavraReservada[8][7] = { 
    "main", //codigo [0]
    "puts", //codigo [1]
    "gets", //codigo [2]
    "if", //codigo [3]
    "else", //codigo [4]
    "for", //codigo [5]
    "integer", //codigo [6]
    "string", //codigo [7]
    "decimal" //codigo [8]
};

int main(void)
{
    //códigos atribuídos conforme a tabela ascii
    char url[] = "codigo.txt", linhaArquivo[500], *resultado;
    int linhaErro = 1, asciiLetter, verificaMain = 0;
	int numeroDaLinhaNoArquivo = 1;
    int numeroDaLinhaNoArquivoComErro = 1;
    char palavra[255];
    int espaco = 32, virgula = 44, pontoEvirgula = 59, igual = 61;
    int abreParentese = 40, fechaParentese = 41;
    int abreChave = 123, fechaChave = 125;
    int abreColchete = 91, fechaColchete = 93;

	/* Aloca espaço na memória RAM */
	noLista *lista = (noLista *)malloc(sizeof(noLista));
    nodeTabelaSimbolo *listaSimbolo = (nodeTabelaSimbolo *)malloc(sizeof(nodeTabelaSimbolo));
    
    /* Seta proximo da lista como NULL*/
	lista->proximo = NULL;

	FILE *arquivo = fopen(url, "r");
	if (arquivo != NULL) {

				/* Equanto não chegar no fim de arquivo */
				while (!feof(arquivo) ) {
						/* Lê do fluxo para a cadeia de caracteres string até a quantidade de caracteres 500
						ser lida ou até uma nova linha (\n) ou EOF ser encontrado */
			resultado = fgets(linhaArquivo, sizeof(linhaArquivo), arquivo);
			insere(lista, resultado, numeroDaLinhaNoArquivo);
			numeroDaLinhaNoArquivo++;
		} //fim while
	} else {
        printf("|**************************************************************************|\n");
		printf("|============== Erro, não foi possível abrir o arquivo selecionado ========|\n");
        printf("|__________________________________________________________________________|\n");
	}
	fclose(arquivo);
	memset(linhaArquivo, '\0', sizeof(linhaArquivo));

}
