#define tamanhoPilha 100
char pilha[tamanhoPilha];
int itensNaPilha;

/* 
  Esta função devolve 1 se a string ASCII s 
  contém uma sequência bem-formada e devolve 0 se 
  a sequência é mal-formada. 
*/

int verificaDuploBalanceamento (char s[]) {
  
  criaPilha ();

  for (int i = 0; s[i] != '\0'; ++i) {
    char c;

    //pega o que vem como parâmetro para verificar o duplo balanceamento e verifica nos casos
    switch ( s[i] ) {

      //caso o caractere seja (, esvazia a pilha, retorna 0 e desempilha caso seja diferente de (
      case '(' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != '(') {
          return 0;
        }
      break;

      case ')' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != ')') {
          return 0;
        }
      break;

      case '{' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != '{') {
          return 0;
        } 
      break;

      case '}' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != '}') {
          return 0;
        } 
      break;

      case '[' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != '[') {
          return 0;
        } 
      break;

      case ']' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != ']') {
          return 0;
        } 
      break;

      case '"' :
        if (pilhaVazia ()) {
          return 0;
        }
        c = desempilha ();
        if (c != '"') {
          return 0;
        } 
      break;
      default:  empilha (s[i]);
    }

  }
  return pilhaVazia ();

}

void criaPilha (void) {
  itensNaPilha = 0;
}

void empilha (char y) {
  pilha[itensNaPilha++] = y;
}

char desempilha (void) {
  return pilha[--itensNaPilha];
} 

int pilhaVazia (void) {
  return itensNaPilha <= 0;
}
