
/*
Mathoian        https://github.com/mathoian
MCR2ZY          https://github.com/MCR2ZY
programa:       Search for protein in mRNA sequence
Linguagem:      C/C++
Informacoes:    README.md

*/


#include <stdlib.h>
#include <stdio.h>
#include "translation.h"

int main() {

    FILE *fp;
    fp = fopen("genome.txt", "r");
    if (fp == NULL) {

        perror("Error FILE");
        return (-1);

    }else{

        fclose(fp);

    }


    return 0;
}
