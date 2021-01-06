#include "funcoes_ucs.h"

tipoUc LeDadosUc() {
  tipoUc uc;

  char obrigatoria;
  char diurno;

  uc.obrigatoria = true;
  uc.diurno = true;

  LerString("Nome: ", uc.designacao, MAX_STRING);

  printf("Obrigatoria? (S/N): ");
  scanf(" %c", &obrigatoria);  //? Função LerString não funciona para 1 char?
  if (obrigatoria == 'N') {
    uc.obrigatoria = false;
  }  // Fim da leitura do caracter

  uc.semestre = LerInteiro("Semestre", 1, 6);  //! Usar uma constante

  printf("Diurno ou noturno? (D/N): ");  // Ler Char
  scanf(" %c", &diurno);
  if (diurno == 'N') {
    uc.diurno = false;
  }  // Fim Ler Char

  // TODO: Estrutura (?) T, TP, PL
  uc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Duração de cada T, TP, PL
  // uc.duracao = LerInteiro("Duracao da aul");

  return uc;
}

tipoUc *RegistarUc(tipoUc vUcs[], int *nUcs) {
  tipoUc uc, *pUcs;

  pUcs = vUcs;

  // vUcs = realloc(p);

  (*nUcs)++;

  return vUcs;
}