#include "funcoes_ucs.h"

#include "funcoes_ficheiros.h"

// Retorna a posição da UC no vetor ou -1 se não encontrar nada
int ProcuraUC(tipoUC vUCs[], int nUCs, char procuraNome[]) {
  int i, pos = -1;
  for (i = 0; i < nUCs; i++) {
    if (strcmp(vUCs[i].designacao, procuraNome) == 0) {
      pos = i;
      i = nUCs;
    }
  }
  return pos;
}

tipoUC LeDadosUC() {
  tipoUC uc;
  char obrigatoria;
  char diurno;

  uc.obrigatoria = 1;  // 0 - Não // 1 - Sim
  uc.diurno = 1;       // 0 - Não // 1 - Sim

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
  tipoUC dadosUC, *pUCs;
  int pos;

  pUCs = vUCs;
  dadosUC = LeDadosUC();
  pos = ProcuraUC(vUCs, *nUCs, dadosUC.designacao);

  if (pos != -1) {
    printf("ERRO: UC já existe!\n");
  } else {
    vUCs = realloc(vUCs, (*nUCs + 1) * sizeof(tipoUC));
    if (vUCs == NULL) {
      printf("ERRO: Impossível inserir UC!\n");
      vUCs = pUCs;
    } else {
      vUCs[*nUCs] = dadosUC;
      (*nUCs)++;
    }
  }

  return vUCs;
}