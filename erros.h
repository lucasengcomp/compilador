void mensagemErro(int codigoErro, int numeroDaLinha)
{
    if(numeroDaLinha != 0)
    {
        printf("LINHA: %i\n ", numeroDaLinha);
    }
    switch (codigoErro) {
        
        case 0: 
            printf("|===================== Erro no MAIN ==========================|");
            printf(" Erro! MSG0 - Houve algum problema com a declaração do Main\n");
            printf("|=============================================================|");
        break;
                default:
            printf("Sem mensagem de erro");
    }
    system("pause");
    exit(0);
}
