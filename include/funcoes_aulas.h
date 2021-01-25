#ifndef FUNCOES_AULAS_H_INCLUDED
#define FUNCOES_AULAS_H_INCLUDED

#include <ctype.h>
#include <string.h>

#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros_aula.h"
#include "funcoes_ucs.h"

int ProcuraAula(tipoAula vAulas[], int nAulas, char procuraDesignacao[]);
tipoAula LeDadosAula(tipoUC vUCs[], int nUCs, tipoAula vAulas[], int nAulas);
tipoAula *AgendaAula(tipoAula vAulas[], int *nAulas, tipoUC vUCs[], int *nUCs);
void ListaTodasAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[], int nUCs);
void ListaUmaAula(tipoAula vAulas[], int nAulas, char designacaoAula[], tipoUC vUCs[], int nUCs);
void ListaAlteraEstadoAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[]);
void EditaAula(tipoAula vAulas[], int nAulas, char designacaoAula[], tipoUC vUCs[], int nUCs);
void EditaAgendamento(tipoAula vAulas[], int nAulas, char designacaoAula[], tipoUC vUCs[]);
tipoAula *EliminaAula(tipoAula vAulas[], int *nAulas, char designacaoAula[]);
void AssisteAula(tipoAula vAulas[], int nAulas, tipoUC vUCs[], char designacaoAula[], int numeroEstudante);

#endif /* FUNCOES_AULAS_H_INCLUDED */
