#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"

typedef struct {
  int dia, mes, ano;
} tipoData;

typedef struct {
  int horas, minutos;
} tipoHora;

typedef struct {
  char designacao[MAX_STRING];
  int obrigatoria;  // 0 - Não // 1 - Sim
  int semestre;
  int diurno;  // 0 - Não // 1 - Sim
  int num_tipo_aulas_previstas;
  int duracao;
} tipoUC;

typedef struct {
  int uc_id;
  char tipo_aula[MAX_TIPO_AULA];  // T, TP, PL
  char docente[MAX_STRING];
  tipoData data;
  tipoHora inicio;
  tipoHora fim;
  char estado;   // A - Agendada // D - A Decorrer // R - Realizada
  int gravacao;  // 0 - Não // 1 - Sim
} tipoAula;

#endif /* ESTRUTURAS_H_INCLUDED */
