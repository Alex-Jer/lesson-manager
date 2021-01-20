#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include <ctype.h>
#include <string.h>

#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ucs.h"

int ProcuraAula(tipoAula vAulas[], int nAulas, char procuraDesignacao[]);
tipoAula LeDadosAula(tipoUC vUCs[], int *nUCs);
tipoAula *AcrescentaAula(tipoAula vAulas[], int *nAulas, tipoUC vUCs[], int *nUCs);
void ListaAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[]);
tipoAula *EditaAula(tipoAula vAulas[], int *nAulas, int designacaoAula);
tipoAula *EliminaAula(tipoAula vAulas[], int *nAulas, int designacaoAula);
#endif /* FUNCOES_AULAS_H_INCLUDED */
