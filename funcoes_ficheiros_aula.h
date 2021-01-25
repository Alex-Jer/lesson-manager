#ifndef FUNCOES_FICHEIROS_AULA_H_INCLUDED
#define FUNCOES_FICHEIROS_AULA_H_INCLUDED

#include <string.h>

#include "estruturas.h"

void EscreveFicheiroBinarioAulas(tipoAula vAulas[], int nAulas);
tipoAula *LeFicheiroBinarioAulas(tipoAula vAulas[], int *nAulas);
void EscreveFicheiroTextoLog(tipoAula aula, char tipoAcesso[], int numeroEstudante);
void EscreveFicheiroBinLog(tipoAula aula, char tipoAcesso[], int numeroEstudante);

#endif /* FUNCOES_FICHEIROS_AULA_H_INCLUDED */
