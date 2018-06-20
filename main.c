#include "translation.h"

int main() {
    FILE *fp = NULL, *fileFragmentos = NULL, *fpReads = NULL;
    int opc = 0, inicio = 0, final = 0, frame = 0, utr = 0, tamEnzimaRestricao = 0; // Sequencia da equipe 4680854 - 4681408 OUTRA: 3478493 - 3479299 Negativa
    int qntFragmentos = 0;
    float peso;
    char *rna = NULL, *rnaPart = NULL, *polipeptideo = NULL, *enzimaRestricao = NULL, **fragmentos = NULL;
    structRead r[QNTREADS];

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
        printf("10: Gerar Arquivo com Tamanho dos Fragmentos.\n");
        printf("11: Ler arquivos com formato dos reads.\n");
        printf("12: Gerar as reads.\n");
        printf("13: Gerar as contigs.\n");
        printf("14: Encerrar.\n");


        scanf("%i", &opc);

        switch (opc) {
            case 1:
                fp = fopen("genome.txt", "r");
                if(fp == NULL) {
                    printf("\nErro ao abrir arquivo genome\n");
                    exit(EXIT_FAILURE);
                }

                rna = lerRNAFull(fp);
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
                polipeptideo = gerarPolipeptideo(rnaPart);
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
                printf("\nDigite a quantidade de letras da enzima de restricao: \n");
                scanf("%d", &tamEnzimaRestricao);
                enzimaRestricao = (char *) malloc(sizeof(char) * (tamEnzimaRestricao + 1));
                printf("\nDigite a enzima de restricao: \n");
                scanf("%s", enzimaRestricao);
                fragmentos = calcFragmentos(&qntFragmentos, rna, enzimaRestricao);
                printf("\nTotal de Fragmentos Gerados: %d", qntFragmentos);
                break;

            case 10:
                fileFragmentos = fopen("tamFragmentos.txt", "w");
                if(fileFragmentos == NULL) {
                    printf("\nErro ao Criar o Arquivo tamFragmentos\n");
                    exit(EXIT_FAILURE);
                }

                for (int i = 0; i < qntFragmentos; i++) {
                    fprintf(fileFragmentos, "%d %d \n", i+1, strlen(fragmentos[i]));
                }

                printf("\nArquivo Gerado com Sucesso!!!\n");
                fclose(fileFragmentos);
                break;

            case 11:
                fpReads = fopen("reads.txt", "r");
                if(fp == NULL) {
                    printf("\nErro ao abrir arquivo reads\n");
                    exit(EXIT_FAILURE);
                }

                leArqReads(r, fpReads);
                break;

            case 12:
                break;

            case 13:
                break;

            case 14:
                fclose(fp);
                fclose(fpReads);
                free(rna);
                free(rnaPart);
                free(polipeptideo);
                free(enzimaRestricao);
                free(fragmentos);
                printf("Memoria Liberada");
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