#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

#include "constantes.h"

typedef struct {
  int dia;
  int mes;
  int ano;
} tipoData;  // Armazena uma data

typedef struct {
  int horas;
  int minutos;
} tipoHora;  // Armazena uma hora

typedef struct {
  int nPrevistas;
  int nAgendadas;
  int nRealizadas;
  int duracao;
} tipoTipoDeAula;  // Armazena para cada tipo de aula (T, TP, PL) o número de aulas previstas e agendadas e a respetiva duração

typedef struct {
  int online;
  int offline;
} tipoAcesso;  // Armazena o acesso de um estudante a uma aula. Online é um acesso presencial e offline é um acesso a uma gravação

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
  tipoAcesso nAcessos;
} tipoUC;  // Estrutura que armazena todos os dados de uma UC. O campo 'id' é único

typedef struct {
  char designacao[MAX_STRING];
  int idUC;
  char tipoAula[MAX_TIPO_AULA];  // T, TP, PL
  char docente[MAX_STRING];
  char estado;    // A - Agendada // D - A Decorrer // R - Realizada
  char gravacao;  // N - Não // A - A Gravar // G - Gravada
  int presencas[MAX_QUANT_ESTUDANTES];
  tipoData data;
  tipoHora inicio;
  tipoHora fim;
  tipoAcesso nAcessos;
} tipoAula;  // Estrutura que armazena todos os dados de uma Aula. O campo 'designacao' é único

#endif /* ESTRUTURAS_H_INCLUDED */
