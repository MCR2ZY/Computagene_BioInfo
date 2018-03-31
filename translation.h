//
// Created by M on 28/03/2018.
//
#include <stdio.h>
#include <stdlib.h>

#ifndef CONPUTAGENE_TRANSLATION_H
#define CONPUTAGENE_TRANSLATION_H

char * readRNAFull(FILE *); /*Ler arquivo completo, ou seja, toda a fita de RNA */
char * readRNAPart(FILE *, int, int); /*Ler arquivo parcialmente, ou seja, dentro de um limite especificado do nucleotideo inicial ao final da cadeia.  */
void invertRNA(FILE *); /*Inverte a sequência de nucleotideos do RNA*/
void complementRNA(FILE *); /*Gera a fita complementar da fita de RNA existente*/

#endif //CONPUTAGENE_TRANSLATION_H
