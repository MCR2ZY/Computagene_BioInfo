//
// Created by M on 28/03/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#ifndef CONPUTAGENE_TRANSLATION_H
#define CONPUTAGENE_TRANSLATION_H

#define TAMCABECALHO 45

char * readRNAFull(FILE *); /*Ler arquivo completo, ou seja, toda a fita de RNA */
char * readRNAPart(char*, int, int); /*Ler arquivo parcialmente, ou seja, dentro de um limite especificado do nucleotideo inicial ao final da cadeia.  */
char * polipeptideoGerado(char *); /*Ler rMNA e realiza o processo de tradução. Função imprime e retorna a cadeia com os aminoacidos correspondentes. */
char * invertRNA(char *); /*Inverte a sequência de nucleotideos do RNA*/
void complementRNA(char *); /*Gera a fita complementar da fita de RNA existente*/
char codigoGenetico(char[]);
float calcMassa(char *);
int calcFrame(int );
int buscaPromotor(char *, int, int);


#endif //CONPUTAGENE_TRANSLATION_H
