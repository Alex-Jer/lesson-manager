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
  int quantidade;
  int duracao;
} tipoTipoDeAula;  // Aulas T, TP, PL

typedef struct {
  // int numEstudante;  // Ex: 2201799
  // char online;       // 0 - Acesso Offline // 1 - Acesso Online
  int online;
  int offline;
} tipoAcesso;

typedef struct {
  int id;
  char designacao[MAX_STRING];
  int obrigatoria;  // 0 - Não // 1 - Sim
  int semestre;     // 1 a 6
  int diurno;       // 0 - Não // 1 - Sim
  int totalAulasPrevistas;
  tipoTipoDeAula teorica;
  tipoTipoDeAula teoricopratica;
  tipoTipoDeAula praticolab;
} tipoUC;

typedef struct {
  char designacao[MAX_STRING];
  int idUC;
  char tipoAula[MAX_TIPO_AULA];  // T, TP, PL
  char docente[MAX_STRING];
  tipoData data;
  tipoHora inicio;
  tipoHora fim;
  char estado;    // A - Agendada // D - A Decorrer // R - Realizada
  char gravacao;  // N - Não // A - A Gravar // G - Gravada
  int estudantesOnline[MAX_QUANT_ESTUDANTES];
  tipoAcesso nAcessos;
  // tipoAcesso nAcessos[MAX_QUANT_ESTUDANTES];
} tipoAula;

#endif /* ESTRUTURAS_H_INCLUDED */
