#include "headers.h"

int memoriaTotal = 256000; //definido em bytes. Memoria 256 kbytes
int memoriaUtilizada = 0;
int memoriaDisponivel = 0;
int alertaMemoriaExcedida = 0;

void somaMemoria(int memoriaAlocada) {
    memoriaUtilizada += memoriaAlocada;
    memoriaDisponivel = memoriaTotal - memoriaUtilizada;
}

void verificaMemoriaDisponivel(memoriaUtilizada) {
    
    if (memoriaUtilizada >= memoriaTotal) {
        printf("Não existe memória disponível no momento!");
        exit(0);
    }
    //verifica a quantidade de memória sendo usada ultrapassa 90%
    // alertaMemoriaExcedida = memoriaTotal * 90 / 100;
    alertaMemoriaExcedida = memoriaTotal * 0.9;

    if (memoriaUtilizada  = alertaMemoriaExcedida) {
        printf("| ########################################################################## |\n");
        printf("| Vish, no momento a memória que está sendo usada está 90 por cento ou mais! |\n");
        printf("| ########################################################################## |\n");
    } else {
        printf("| ====================================================== |\n");
        printf("| Tudo com ok com o uso da memória! |\n");
        printf("| ====================================================== |\n");
    }

}
