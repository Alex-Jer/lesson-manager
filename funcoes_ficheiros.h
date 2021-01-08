#ifndef FUNCOES_FICHEIROS_H_H_INCLUDED
#define FUNCOES_FICHEIROS_H_H_INCLUDED

#include "estruturas.h"
void gravaFicheiroBinarioUCs(tipoUC novaUC, tipoUC vetor[MAX_UCS], int quantUCs);
void lerFicheiroBinario(tipoUC novaUC, tipoUC vetor[MAX_UCS], int quantUCs);
void gravaFicheiroTextoUCs(int quantUCs, tipoUC vUCs[]);

#endif /* FUNCOES_FICHEIROS_H_H_INCLUDED */
