#include "funcoes_ucs.h"

tipoUC LeDadosUC() {
  tipoUC uc;

  char obrigatoria;
  char diurno;

  uc.obrigatoria = 1;
  uc.diurno = 1;

  LerString("Nome: ", uc.designacao, MAX_STRING);

  printf("Obrigatoria? (S/N): ");
  scanf("%c", &obrigatoria);  //? Função LerString não funciona para 1 char?
  LimpaBufferStdin();
  if (obrigatoria == 'N') {
    uc.obrigatoria = 0;
  }  // Fim da leitura do caracter

  uc.semestre = LerInteiro("Semestre", 1, 6);  //! Usar uma constante

  printf("Diurno ou noturno? (D/N): ");  // Ler Char
  scanf("%c", &diurno);
  LimpaBufferStdin();
  if (diurno == 'N') {
    uc.diurno = 0;
  }  // Fim Ler Char

  // TODO: Estrutura (?) T, TP, PL
  uc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Duração de cada T, TP, PL
  // uc.duracao = LerInteiro("Duracao da aul");

  return uc;
}

tipoUC *AcrescentaUC(tipoUC vUCs[], int *nUCs) {
  // tipoUC dadosUC, *pUCs;
  tipoUC dadosUC;
  // int pos;

  // pUCs = vUCs;
  dadosUC = LeDadosUC();

  (*nUCs)++;
  printf("%s", dadosUC.designacao);

  return vUCs;
}