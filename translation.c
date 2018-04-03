//
// Created by M on 28/03/2018.
//

#include "translation.h"

char * readRNAFull(FILE *fp) {
    char cabecalho[TAMCABECALHO];
    char *RNA;
    char aux;
    int qntLetras = 0;

    fgets(cabecalho, sizeof(cabecalho), fp); // Consome a primeira linha

    aux = fgetc(fp);
    while(aux != EOF) { // Conta a quantidade de letras total do arquivo
        if(aux != '\n' || aux != '\t' || aux != ' ') {
            qntLetras++;
            aux = fgetc(fp);
        }
        else
            aux = fgetc(fp);
    }
    printf("O numero toral de caratfcteres eh: %d \n", qntLetras);

    rewind(fp); // Retorna ao inicio do arquivo

    fgets(cabecalho, sizeof(cabecalho), fp); // Consome a primeira linha

    RNA = (char *) malloc(sizeof(char) * (qntLetras+1)); //Aloca memoria para todas as letras

    for (int i = 0; i <= qntLetras; i++) { // Salva as letras na memoria
        aux = fgetc(fp);
        if(aux != '\n' || aux != '\t' || aux != ' ') {
            RNA[i] = aux;
        }
    }
    RNA[qntLetras+1] = '\0'; // Adiciona o caracter /0 ao final da cadeia de letras
    printf("%s", cabecalho); // Imprime o cabecalho
    for (int j = 0; j < qntLetras; j++) {
        printf("%c", RNA[j]); // Imprime as letras
    }

    return RNA; // Retorna ponteiro com a sequencia
}

char *readRNAPart(FILE *rma, int inicio, int fim) {
    char cabecalho[TAMCABECALHO];\
    char *RNA;
    int qntLetras;

    qntLetras = (fim - inicio) + 1;
    printf("O numero toral de caratfcteres eh: %d \n", qntLetras);
    if(qntLetras%3){
        printf("Quantidade de nucleotideos nao eh multiplo de tres.");
        exit(EXIT_FAILURE);
    }

    fgets(cabecalho, sizeof(cabecalho), rma); // Consome a primeira linha

    RNA = (char *) malloc(sizeof(char) * (qntLetras+1)); //Aloca memoria para as letras necessarias


    if(fseek(rma, inicio, SEEK_CUR)){ //Posiciona ponteiro do arquivo na posição inicial
        printf("Erro ao reposicionar ponteiro no arquivo");
        exit(EXIT_FAILURE);
    }

    char teste = fgetc(rma);
    printf("%c\n", teste);

    for (int i = 0; i <= qntLetras; i++) { // Salva as letras na memoria
        RNA[i] = fgetc(rma);
    }

    RNA[qntLetras+1] = '\0'; // Adiciona o caracter /0 ao final da cadeia de letras
    printf("%s", RNA); // Imprime as letras

    return RNA;
}

char *polipeptideoGerado(char *RNA) {
    return NULL;
}

void invertRNA(char *RNA) {

}

void complementRNA(char * RNA) {

}
