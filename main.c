#include "translation.h"

int main() {
    FILE *fp = NULL;
    int opc = 0, inicio = 0, final = 0, frame = 0; // Sequencia da equipe 4680854 - 4681408 OUTRA: 3478493 - 3479299 Negativa
    char nomeFile[50];
    float peso;
    char *rna = NULL, *rnaPart = NULL, *polipeptideo = NULL;

    printf("\tCOMPUTAGENE\n");

    do {
        printf("\n\tEscolha sua opcao: \n");

        printf("1: Ler rna completo.\n");
        printf("2: Ler rna parcial.\n");
        printf("3: Gerar fita complementar.\n");
        printf("4: Imprimir polipeptideo.\n");
        printf("5: Imprimir a massa do polipeptideo.\n");
        printf("6: Frame de Leitura.\n");
        printf("7: Encerrar.\n");


        scanf("%i", &opc);

        switch (opc) {
            case 1:
                printf("Insira o nome do arquivo(nomeArquivo.extensao):\n");
                scanf(" %s", nomeFile);
                fp = fopen(nomeFile, "r");
                rna = readRNAFull(fp);
            break;

            case 2:
                printf("\nDigite a posicao do nucleotideo inicial\n");
                scanf("%i", &inicio);
                printf("\nDigite a posicao do nucleotideo final\n");
                scanf("%i", &final);
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
                printf("\nPeso molecular: %fg/mol\n", peso);
                break;

            case 6:
                frame = calcFrame(inicio);
                printf("\nFrame de leitura: %i\n", frame);
                break;

            case 7:
                exit(EXIT_SUCCESS);

            default:
                printf("\nOpcao Invalida.\n");
                break;
        }
    }
    while(opc != 0);




    fclose(fp);
    return 0;
}