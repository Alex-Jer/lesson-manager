#ifndef FUNCOES_UCS_H_INCLUDED
#define FUNCOES_UCS_H_INCLUDED

#include "estruturas.h"
#include "funcoes_auxiliares.h"

int ProcuraUC(tipoUC vUCs[], int n, char procuraNome[]);
tipoUC LeDadosUC();
tipoUC *AcrescentaUC(tipoUC vUCs[], int *nUCs);
void ListaUC(tipoUC vUCs[], int nUCs);

#endif /* FUNCOES_UCS_H_INCLUDED */
