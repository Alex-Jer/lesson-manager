#include "funcoes_ucs.h"

UnidadeCurricular RegistarUc() {
  UnidadeCurricular novaUc;
  char obrigatoria;
  char diurno;

  novaUc.obrigatoria = true;
  novaUc.diurno = true;

  LerString("Nome: ", novaUc.designacao, MAX_STRING);

  printf("Obrigatoria? (S/N): ");
  scanf(" %c", &obrigatoria);  //? Função LerString não funciona para 1 char?
  if (obrigatoria == 'N') {
    novaUc.obrigatoria = false;
  }  // Fim da leitura do caracter

  novaUc.semestre = LerInteiro("Semestre", 1, 6);  //! Usar uma constante

  printf("Diurno ou noturno? (D/N): ");  // Ler Char
  scanf(" %c", &diurno);
  if (diurno == 'N') {
    novaUc.diurno = false;
  }  // Fim Ler Char

  // TODO: Estrutura (?) T, TP, PL
  novaUc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Duração de cada T, TP, PL
  // novaUc.duracao = LerInteiro("Duracao da aul");

  return novaUc;
}