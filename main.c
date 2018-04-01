#include "translation.h"

int main() {
    FILE *fp;

    //char nomeFile[50];

    //printf("Insira o nome do arquivo(nomeArquivo.extensao):\n");
    //scanf(" %s", nomeFile);
    fp = fopen("Genome.txt", "r");

    if(fp==NULL) {
        printf("\n\tERRO AO ABRIR ARQUIVO");
        printf("\n\tPressione <ENTER> para finalizar...\n\t");
        exit(1);
    }
    readRNAFull(fp);
    return 0;
}