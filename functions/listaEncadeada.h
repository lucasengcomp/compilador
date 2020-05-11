typedef struct NoLista {
	char linhaArquivo[500];
	int numeroDaLinhaNoArquivo;
	struct NoLista *proximo;
} noLista;

/* Inicializa o noLista */
noLista *nova ( char *linhaArquivo, int numeroDaLinhaNoArquivo ) {
	noLista *ponteiro = malloc(sizeof(noLista)); /*aloca espaço na memoria*/
	strcpy(ponteiro -> linhaArquivo, linhaArquivo); /*copia linhaArquivo para p->linhaArquivo*/
	ponteiro -> numeroDaLinhaNoArquivo = numeroDaLinhaNoArquivo;
	ponteiro -> proximo = NULL;
	return ponteiro;
}

void insere(noLista *LISTA, char *linhaArquivo, int numeroDaLinhaNoArquivo) {
	noLista *novo = (noLista*) malloc(sizeof(noLista));

	/* Atribui nulo em todos os bits na linha do arquivo */
	memset(novo -> linhaArquivo, '\0', sizeof(novo -> linhaArquivo));

	strcpy(novo -> linhaArquivo, linhaArquivo);
	novo -> numeroDaLinhaNoArquivo = numeroDaLinhaNoArquivo;
	novo -> proximo = NULL;

	/* Verifica se o proximo nó da lista é igual a null, se for recebe o novo que entrou,
		caso não seja irá apontar para o proximo nó*/
	if ( LISTA -> proximo == NULL ) {
		LISTA -> proximo = novo;
	} else {
		noLista *variavelTemporaria = LISTA -> proximo;
		while(variavelTemporaria -> proximo != NULL ) {
			variavelTemporaria = variavelTemporaria -> proximo;
		}
		variavelTemporaria -> proximo = novo;
	}

}
