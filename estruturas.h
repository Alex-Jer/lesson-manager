#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"

typedef struct {
  int dia, mes, ano;
} Data;

typedef struct {
  int horas, minutos;
} Hora;

typedef struct {
  char designacao[MAX_STRING];
  bool obrigatoria;
  int semestre;
  bool diurno;
  int num_tipo_aulas_previstas;
  int duracao;
} UnidadeCurricular;

typedef struct {
  int uc_id;
  char tipo_aula[MAX_TIPO_AULA];  // T, TP, PL
  char docente[MAX_STRING];
  Data data;
  Hora inicio;
  Hora fim;
  char estado;  // A - Agendada // D - A Decorrer // R - Realizada
  bool gravacao;
} Aula;

#endif /* ESTRUTURAS_H_INCLUDED */
