//
// Created by M on 28/03/2018.
//

#include "translation.h"

char * readRNAFull(FILE *fp) {
    char cabecalho[TAMCABECALHO];
    char *mRNA, c;
    int qntLetras = 0;

    fgets(cabecalho, sizeof(cabecalho), fp); // Consome a primeira linha

    while(fgetc(fp) != EOF) { // Conta a quantidade de letras total do arquivo
        qntLetras++;
    }
    printf("O numero toral de caracteres eh: %d \n", qntLetras);

    rewind(fp); // Retorna ao inicio do arquivo

    fgets(cabecalho, sizeof(cabecalho), fp); // Consome a primeira linha

    mRNA = (char *) malloc(sizeof(char) * qntLetras); //Aloca memoria para todas as letras

    for (int i = 0; i < qntLetras; ++i) { // Salva as letras na memoria
        mRNA[i] = fgetc(fp);
    }
    mRNA[qntLetras+1] = '\0'; // Adiciona o caracter /0 ao final da cadeia de letras
    printf("%s", cabecalho); // Imprime o cabecalho
    printf("%s", mRNA); // Imprime as letras

    return mRNA; // Retorna ponteiro com a sequencia
}

char *readRNAPart(FILE *fp, int inicio, int fim) {
    return NULL;
}

char *polipeptideoGerado(char *mRNA) {
    return NULL;
}

void invertRNA(char *mRNA) {

}

void complementRNA(char * mRNA) {

}
