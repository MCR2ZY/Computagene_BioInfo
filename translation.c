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
        return NULL;
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
    int cont = 0, j = 0;

    for (int i = 0; rna[i] != '\0' ; i++) {
        cont++;
    }

    polipeptideo = (char *) malloc(sizeof(char) * ((cont/3)+1) );
    printf("\ncontador no polipeptideo: %d\n", ((cont/3)+1) );

    for (int i = 0; rna[i] != '\0'; i += 3) {
        codon[0] = rna[i];
        codon[1] = rna[i+1];
        codon[2] = rna[i+2];

        polipeptideo[j] = codigoGenetico(codon);
        j++;
    }
    polipeptideo[cont/3] = '\0';

    return polipeptideo;
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

char codigoGenetico(char codon[]) {
    if( (!strncmp(codon, "GCT", 3)) || (!strncmp(codon, "GCC", 3)) || (!strncmp(codon, "GCA", 3)) || (!strncmp(codon, "GCG", 3))) {
        return 'A';
    } else if ( (!strncmp(codon, "CGT", 3)) || (!strncmp(codon, "CGC", 3)) || (!strncmp(codon, "CGA", 3)) || (!strncmp(codon, "CGG", 3)) || (!strncmp(codon, "AGA", 3)) || (!strncmp(codon, "AGG", 3))) {
        return 'R';
    } else if ( (!strncmp(codon, "AAT", 3)) || (!strncmp(codon, "AAC", 3))) {
        return 'N';
    } else if ( (!strncmp(codon, "GAT", 3)) || (!strncmp(codon, "GAC", 3))) {
        return 'D';
    } else if ( (!strncmp(codon, "TGT", 3)) || (!strncmp(codon, "TGC", 3))) {
        return 'C';
    } else if ( (!strncmp(codon, "CAA", 3)) || (!strncmp(codon, "CAG", 3))) {
        return 'Q';
    } else if ( (!strncmp(codon, "GAA", 3)) || (!strncmp(codon, "GAG", 3))) {
        return 'E';
    } else if ( (!strncmp(codon, "GGT", 3)) || (!strncmp(codon, "GGC", 3)) || (!strncmp(codon, "GGA", 3)) || (!strncmp(codon, "GGG", 3))) {
        return 'G';
    } else if ( (!strncmp(codon, "CAT", 3)) || (!strncmp(codon, "CAC", 3))) {
        return 'H';
    } else if ( (!strncmp(codon, "ATT", 3)) || (!strncmp(codon, "ATC", 3)) || (!strncmp(codon, "ATA", 3))) {
        return 'I';
    } else if ( (!strncmp(codon, "TTA", 3)) || (!strncmp(codon, "TTG", 3)) || (!strncmp(codon, "CTT", 3)) || (!strncmp(codon, "CTC", 3)) || (!strncmp(codon, "CTA", 3)) || (!strncmp(codon, "CTG", 3))) {
        return 'L';
    } else if ( (!strncmp(codon, "AAA", 3)) || (!strncmp(codon, "AAG", 3))) {
        return 'K';
    } else if ( (!strncmp(codon, "ATG", 3))) {
        return 'M';
    } else if ( (!strncmp(codon, "TTT", 3)) || (!strncmp(codon, "TTC", 3))) {
        return 'F';
    } else if( (!strncmp(codon, "CCT", 3)) || (!strncmp(codon, "CCC", 3)) || (!strncmp(codon, "CCA", 3)) || (!strncmp(codon, "CCG", 3))) {
        return 'P';
    } else if ( (!strncmp(codon, "TCT", 3)) || (!strncmp(codon, "TCC", 3)) || (!strncmp(codon, "TCA", 3)) || (!strncmp(codon, "TCG", 3)) || (!strncmp(codon, "AGT", 3)) || (!strncmp(codon, "AGC", 3))) {
        return 'S';
    } else if( (!strncmp(codon, "ACT", 3)) || (!strncmp(codon, "ACC", 3)) || (!strncmp(codon, "ACA", 3)) || (!strncmp(codon, "ACG", 3))) {
        return 'T';
    } else if( (!strncmp(codon, "TGG", 3))) {
        return 'W';
    } else if( (!strncmp(codon, "TAT", 3)) || (!strncmp(codon, "TAC", 3))) {
        return 'Y';
    } else if( (!strncmp(codon, "GTT", 3)) || (!strncmp(codon, "GTC", 3)) || (!strncmp(codon, "GTA", 3)) || (!strncmp(codon, "GTG", 3))) {
        return 'V';
    } else if( (!strncmp(codon, "TAA", 3)) || (!strncmp(codon, "TAG", 3)) || (!strncmp(codon, "TGA", 3))) {
        return '\0';
    }
}

float calcMassa(char *polipept) {
    float peso;
    peso = 0;
    for (int i = 0; polipept[i] != '\0'; i++) {
        if(polipept[i] == 'A') {
            peso += 89.0935;
        } else if(polipept[i] == 'C') {
            peso += 121.159;
        } else if(polipept[i] == 'D') {
            peso += 133.1032;
        } else if(polipept[i] == 'E') {
            peso += 174.1299;
        } else if(polipept[i] == 'F') {
            peso += 165.19;
        } else if(polipept[i] == 'G') {
            peso += 75.0669;
        } else if(polipept[i] == 'H') {
            peso += 155.1502;
        } else if(polipept[i] == 'I') {
            peso += 131.1736;
        } else if(polipept[i] == 'K') {
            peso += 146.1882;
        } else if(polipept[i] == 'L') {
            peso += 131.1736;
        } else if(polipept[i] == 'M') {
            peso += 149.2124;
        } else if(polipept[i] == 'N') {
            peso += 132.1184;
        } else if(polipept[i] == 'P') {
            peso += 115.131;
        } else if(polipept[i] == 'R') {
            peso += 174.2017;
        } else if(polipept[i] == 'S') {
            peso += 105.093;
        } else if(polipept[i] == 'T') {
            peso += 119.1197;
        } else if(polipept[i] == 'V') {
            peso += 117.1469;
        } else if(polipept[i] == 'W') {
            peso += 204.2262;
        } else if(polipept[i] == 'Y') {
            peso += 181.1894;
        }
    }
    return peso;
}

