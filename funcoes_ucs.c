// #include "funcoes_ucs.h"

#include "estruturas.h"
#include "funcoes_auxiliares.h"

UnidadeCurricular RegistarUc() {
  UnidadeCurricular novaUc;
  char obrigatoria;
  char diurno;
  char tipoDes[2];

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

  novaUc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Estrutura (?) T, TP, PL
  printf("Qual o tipo de aula?(T/TP/PL): ");  // Ler Char
  scanf("%s", tipoDes);
  // TODO: Duração de cada T, TP, PL
  // novaUc.duracao = LerInteiro("Duracao da aula");

  // confirmar se escreve tudo
  printf(
      "Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario %c \nAulas previstas: %d \nTipo de aula: "
      "%s",
      novaUc.designacao, obrigatoria, novaUc.semestre, diurno, novaUc.num_tipo_aulas_previstas, tipoDes);

  return novaUc;
}
