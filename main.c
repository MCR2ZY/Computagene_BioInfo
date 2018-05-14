#include "translation.h"

int main() {
    FILE *fp = NULL;
    int opc = 0, inicio = 0, final = 0, frame = 0, utr = 0, tamEnzimaRestricao = 0; // Sequencia da equipe 4680854 - 4681408 OUTRA: 3478493 - 3479299 Negativa
    float peso;
    char *rna = NULL, *rnaPart = NULL, *polipeptideo = NULL, *enzimaRestricao = NULL, **fragmentos = NULL;

    printf("\tCOMPUTAGENE\n");

    do {
        printf("\nEscolha sua opcao: \n");

        printf("1: Ler rna completo.\n");
        printf("2: Ler rna parcial.\n");
        printf("3: Gerar fita complementar do rna completo.\n");
        printf("4: Gerar fita complementar do rna parcial.\n");
        printf("5: Imprimir polipeptideo.\n");
        printf("6: Imprimir a massa do polipeptideo.\n");
        printf("7: Frame de leitura.\n");
        printf("8: Procurar regiao promotora.\n");
        printf("9: Gerar Fragmentos do rna.\n");
        printf("10: Encerrar.\n");


        scanf("%i", &opc);

        switch (opc) {
            case 1:
                fp = fopen("genome.txt", "r");
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
                rnaPart = rna;
                rnaPart = invertRNA(rnaPart);
                complementRNA(rnaPart);
                printf("\nComplementar Gerado com Sucesso");

            case 4:
                rnaPart = invertRNA(rnaPart);
                complementRNA(rnaPart);
                printf("\nComplementar Gerado com Sucesso");
            break;

            case 5:
                printf("\nCadeia de aminoacidos gerada:\n");
                polipeptideo = polipeptideoGerado(rnaPart);
                printf("\nCadeia: %s\n", polipeptideo);
                break;

            case 6:
                peso = calcMassa(polipeptideo);
                printf("\nPeso molecular: %fg/mol\n", peso);
                break;

            case 7:
                frame = calcFrame(inicio);
                printf("\nFrame de leitura: %i\n", frame);
                break;

            case 8:
                printf("\nDigite o tamanho do 5'UTR:\n");
                scanf("%d", &utr);
                buscaPromotor(rna,inicio,utr);
                break;

            case 9:
                printf("\nDigite a quantidade de letras da enzima de restrição: \n");
                scanf("%d", &tamEnzimaRestricao);
                enzimaRestricao = (char *) malloc(sizeof(char) * (tamEnzimaRestricao + 1));
                printf("\nDigite a enzima de restrição: \n");
                scanf("%s", enzimaRestricao);
                calcFragmentos(fragmentos, rna, enzimaRestricao);
                printf("\n\n\n%s", fragmentos[0]);
                break;

            case 10:
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