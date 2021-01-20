#ifndef FUNCOES_UCS_H_INCLUDED
#define FUNCOES_UCS_H_INCLUDED

#include <ctype.h>

#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros_uc.h"

int ProcuraUC(tipoUC vUCs[], int nUCs, int procuraId);
tipoUC LeDadosUC();
tipoUC *AcrescentaUC(tipoUC vUCs[], int *nUCs);
void ListaUCs(tipoUC vUCs[], int nUCs);
void EditaUC(tipoUC vUCs[], int *nUCs, int idUC);
tipoUC *EliminaUC(tipoUC vUCs[], int *nUCs, int idUC);
#endif /* FUNCOES_UCS_H_INCLUDED */
