#include "translation.h"

int main() {
    FILE *fp;
    int opc, inicio, final; // Sequencia da equipe 4680854 - 4681408 OUTRA: 3478493 - 3479299 Negativa
    char nomeFile[50];
    float peso;
    char *rna, *rnaPart, *polipeptideo = NULL;

    if(fp==NULL) {
        printf("\n\tERRO AO ABRIR ARQUIVO");
        printf("\n\tPressione <ENTER> para finalizar...\n\t");
        exit(1);
    }

    printf("\tCOMPUTAGENE\n");

    do {
        printf("\n\tEscolha sua opcao: \n");

        printf("\n1: Ler rna completo.\n");
        printf("\n2: Ler rna parcial.\n");
        printf("\n3: Gerar fita complementar.\n");
        printf("\n4: Imprimir polipeptideo.\n");
        printf("\n5: Imprimir a massa do polipeptideo.\n");

        scanf("%d", &opc);

        switch (opc) {
            case 1:
                printf("Insira o nome do arquivo(nomeArquivo.extensao):\n");
                scanf(" %s", nomeFile);
                fp = fopen(nomeFile, "r");
                rna = readRNAFull(fp);
            break;

            case 2:
                printf("\nDigite a posicao do nucleotideo inicial\n");
                scanf("%d", &inicio);
                printf("\nDigite a posicao do nucleotideo final\n");
                scanf("%d", &final);
                rnaPart = readRNAPart(rna, inicio, final);
            break;

            case 3:
                rnaPart = invertRNA(rnaPart);
                complementRNA(rnaPart);
                printf("Complementar Gerado com Sucesso");
            break;

            case 4:
                printf("\nCadeia de aminoacidos gerada:\n");
                polipeptideo = polipeptideoGerado(rnaPart);
                printf("\nCadeia: %s\n", polipeptideo);
                break;

            case 5:
                peso = calcMassa(polipeptideo);
                printf("Peso molecular: %fg/mol", peso);

            default:
                break;
        }
    }
    while(opc != 0);




    fclose(fp);
    return 0;
}