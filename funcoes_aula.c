#include "estruturas.h"
#include "funcoes_auxiliares.h"
UnidadeCurricular RegistarAula() {
  UnidadeCurricular novaAula;
  char obrigatoria;
  char diurno;

  //LerString("Nome: ",.designacao, MAX_STRING);
  LerString("Nome do Docente",novaAula.docente[MAX_STRING]);

  // TODO: Estrutura (?) T, TP, PL
  novaUc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Duração de cada T, TP, PL
  // novaUc.duracao = LerInteiro("Duracao da aul");

  return novaAula;
}
int uc_id;
  Data data;
  Hora inicio;
  Hora fim;
  char estado;  // A - Agendada // D - A Decorrer // R - Realizada
  bool gravacao;
