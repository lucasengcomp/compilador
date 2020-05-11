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

char modulo[500];

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

  /* Criei uma variavel temporaria para armazenar  o proximo elemento da lista */
	noLista *tmp = lista -> proximo;

  /* Percorrer a linha da listaEncadeada */
  while (tmp != NULL) {
    int indentificadorDeCaracter = 0, indentificadorDaPalavra = 0;
    strcpy(linhaArquivo, tmp->linhaArquivo);
    memset(palavra, '\0', sizeof(palavra));

        /* Enquanto o caracter da linha for diferente de NULL */
        while ((int)linhaArquivo[indentificadorDeCaracter] != 0) {
            asciiLetter = (int)linhaArquivo[indentificadorDeCaracter];

            /* Se o caracter não for um delimitador, irá adicionar o caracter a palavra,
                caso seja um delimitador irá concluir a montagem da palavra */            
            if ( (asciiLetter != espaco)        && (asciiLetter != virgula) &&
                 (asciiLetter != pontoEvirgula) && (asciiLetter != igual) &&
                 (asciiLetter != abreParentese) && (asciiLetter != fechaParentese) &&
                 (asciiLetter != abreChave)     && (asciiLetter != fechaChave) &&
                 (asciiLetter != abreColchete)  && (asciiLetter != fechaColchete) ) 
            {
                palavra[indentificadorDaPalavra] = linhaArquivo[indentificadorDeCaracter];
                indentificadorDaPalavra++;
            } else {
                switch (palavra[0]) {
                    case 'm' | 'M' : /* main 0 */
                        if (strcmp(palavra, palavraReservada[0] ) == 0) {
                            strcpy(modulo, palavraReservada[0]);
                            verificaMain++;
                        } else {
                            mensagemDeErro(0, numeroDaLinhaNoArquivoComErro);
                        }
                    break;
                    
                    case 'p' | 'P' : /* puts 1 */
                    /* puts(“ A é maior”, #a); */
                        if ( strcmp(palavra, palavraReservada[1]) == 0 ) {
                            strcpy(modulo, palavraReservada[1]);
                        } else {

                        }
                    break;

                    case 'g' | 'G' : /* gets 2 */
                        if ( strcmp(palavra, palavraReservada[2]) == 0 ) {
                            strcpy(modulo, palavraReservada[2]);
                        } else {

                        }
                    break;

                    case 'i' | 'I' : /* if 3 | integer 6 */
                    	if (palavra[1] == 'f') {
                            if ( strcmp(palavra, palavraReservada[3]) == 0 ) {
                                strcpy(modulo, palavraReservada[3]);
                            } else {

                            }
                        } else {
                            if ( strcmp(palavra, palavraReservada[6]) == 0 ) {
                                strcpy(modulo, palavraReservada[6]);
                            } else {
                                
                            }
                        }
                    break;

                    case 'e' | 'E' : /* else 4 */
                        if (strcmp(palavra, palavraReservada[4]) == 0) {
                            strcpy(modulo, palavraReservada[4]);
                        } else {

                        }
                    break;

                    case 'f' | 'F' : /* for 5 */
                        if (strcmp(palavra, palavraReservada[5]) == 0) {
                            strcpy(modulo, palavraReservada[5]);
                        } else {
                            mensagemDeErro(5, numeroDaLinhaNoArquivoComErro);
                        }
                    break;

                    case 's' | 'S' : /* string 7*/
                        if (strcmp(palavra, palavraReservada[7]) == 0) {
                            strcpy(modulo, palavraReservada[7]);
                        } else {
                            mensagemDeErro(1, numeroDaLinhaNoArquivoComErro);
                        }
                    break;

                    case 'd' | 'D' : /* decimal 8*/
                        if (strcmp(palavra, palavraReservada[8]) == 0)
                        {
                            strcpy(modulo, palavraReservada[8]);
                        } else {

                        }
                    break;
                }

                indentificadorDaPalavra = 0;
				memset(palavra, '\0', sizeof(palavra));
            }
            indentificadorDeCaracter++;

        }
        numeroDaLinhaNoArquivoComErro++;
		tmp = tmp -> proximo;
  }

    if (verificaMain > 1) {
        mensagemDeErro(3, 0);
    }
    if (verificaMain == 0) {
        mensagemDeErro(1, 0);
    }
    

}
