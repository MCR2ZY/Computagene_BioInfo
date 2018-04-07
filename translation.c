//
// Created by M on 28/03/2018.
//

#include "translation.h"

char * readRNAFull(FILE *fp) {
    char cabecalho[TAMCABECALHO];
    char *rna;
    char aux;
    int qntLetras = 0;

    fgets(cabecalho, sizeof(cabecalho), fp); // Consome a primeira linha

    aux = fgetc(fp);
    while(aux != EOF) { // Conta a quantidade de letras total do arquivo
        if(aux != '\n' && aux != '\t' && aux != ' ') {
            qntLetras++;
            aux = fgetc(fp);
        }
        else
            aux = fgetc(fp);
    }
    printf("O numero total de caratfcteres eh: %d \n", qntLetras);

    rewind(fp); // Retorna ao inicio do arquivo

    fgets(cabecalho, sizeof(cabecalho), fp); // Consome a primeira linha

    rna = (char *) malloc(sizeof(char) * (qntLetras+1)); //Aloca memoria para todas as letras

    for (int i = 0; i < qntLetras; i++) { // Salva as letras na memoria
        aux = fgetc(fp);
        if(aux != '\n' && aux != '\t' && aux != ' ') {
            rna[i] = aux;
        }
        else {
            i--;
        }
    }
    rna[qntLetras] = '\0'; // Adiciona o caracter /0 ao final da cadeia de letras

    return rna; // Retorna ponteiro com a sequencia
}

char *readRNAPart(char *rna, int inicio, int fim) {
    char *rnaPart;
    int qntLetras;

    inicio -= 1;
    fim -= 1;
    qntLetras = (fim - inicio) + 1;

    printf("O numero parcial de caratfcteres eh: %d \n", qntLetras);
    if(qntLetras%3){
        printf("Quantidade de nucleotideos nao eh multiplo de tres.");
        exit(EXIT_FAILURE);
    }

    rnaPart = (char *) malloc(sizeof(char) * (qntLetras+1)); //Aloca memoria para as letras necessarias

    for (int i = 0; i < qntLetras; i++) { // Salva as letras na memoria
        rnaPart[i] = rna[inicio+i];
    }

    rnaPart[qntLetras] = '\0'; // Adiciona o caracter /0 ao final da cadeia de letras

    printf("\n%s\n", rnaPart);

    return rnaPart;
}

char *polipeptideoGerado(char *rna) {
    char *polipeptideo, codon[3];
    int cont = 0;

    for (int i = 0; rna[i] != '\0' ; i++) {
        cont++;
    }

    polipeptideo = (char *) malloc(sizeof(char) * (cont/3) );

    for (int i = 0; rna[i+3] != '\0'; i + 3) {

    }

    return NULL;
}

char * invertRNA(char *rna) {
    char *rnaAux;
    int  cont = 0;
    int i,j;

    for (i = 0; rna[i] != '\0' ; i++) {
        cont++;
    }

    rnaAux = (char *) malloc(sizeof(char)*cont);

    rnaAux[cont] = '\0';
    cont -= 1;

    i = 0;
    while (cont >= 0) {
        rnaAux[i] = rna[cont];
        i++;
        cont--;
    }


    printf("\nInvertido rnaAux: %s\n", rnaAux);
    return rnaAux;
}

void complementRNA(char * rna) {
    for (int i = 0; rna[i] != '\0' ; i++) {
        if (rna[i] == 'A') {
            rna[i] = 'T';
        } else if (rna[i] == 'T') {
            rna[i] = 'A';
        } else rna[i] = rna[i] == 'C' ? 'G' : 'C';
    }

    printf("\nrna complementar: %s\n", rna);
}
