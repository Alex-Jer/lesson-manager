#include "funcoes_ucs.h"

// Retorna a posição da UC no vetor ou -1 se não encontrar o id
int ProcuraUC(tipoUC vUCs[], int nUCs, int procuraId) {
  int i, pos = -1;
  for (i = 0; i < nUCs; i++) {
    if (vUCs[i].id == procuraId) {
      pos = i;
      i = nUCs;
    }
  }
  return pos;
}

tipoUC LeDadosUC() {
  tipoUC uc;
  char obrigatoria[MAX_STRING];
  char diurno[MAX_STRING];

  uc.obrigatoria = 1;  // 0 - Não // 1 - Sim
  uc.diurno = 1;       // 0 - Não // 1 - Sim

  uc.id = LerInteiro("Codigo: ", MIN_UCS, MAX_UCS);
  LerString("Nome: ", uc.designacao, MAX_STRING);
  // LerString("Obrigatoria? (S/N): ", obrigatoria, MAX_CHAR);
  LerChar("Obrigatoria? (S/N): ", obrigatoria, MAX_STRING);
  uc.semestre = LerInteiro("Semestre", MIN_SEMESTRE, MAX_SEMESTRE);
  // LerString("Diurno ou Pos-Laboral? (D/P): ", diurno, MAX_CHAR);
  LerChar("Diurno ou Pos-Laboral? (D/P): ", diurno, MAX_STRING);
  uc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
  // TODO: Estrutura (?) T, TP, PL
  // TODO: Duração de cada T, TP, PL
  // uc.duracao = LerInteiro("Duracao da aul");

  if (toupper(obrigatoria) == 'N') {
    uc.obrigatoria = 0;
  }

  if (toupper(diurno) == 'P') {
    uc.diurno = 0;
  }

  return uc;
}

tipoUC *AcrescentaUC(tipoUC vUCs[], int *nUCs) {
  tipoUC dadosUC, *pUCs;
  int pos;

  if (*nUCs >= 40) {
    printf("ERRO: Numero maximo de UCs atingido!\n");
  } else {
    pUCs = vUCs;
    dadosUC = LeDadosUC();
    pos = ProcuraUC(vUCs, *nUCs, dadosUC.id);

    if (pos != -1) {
      printf("ERRO: UC ja existe!\n");
    } else {
      vUCs = realloc(vUCs, (*nUCs + 1) * sizeof(tipoUC));
      if (vUCs == NULL) {
        printf("ERRO: Impossível inserir UC!\n");
        vUCs = pUCs;
      } else {
        vUCs[*nUCs] = dadosUC;
        (*nUCs)++;
        printf("SUCESSO: UC inserida!\n");
      }
    }
  }
  return vUCs;
}

void ListaUC(tipoUC vUCs[], int nUCs) {
  int i;

  if (nUCs == 0) {
    printf("ERRO: Nao existem UCs registadas!\n");
  } else {
    printf("\n\t\tID\t    Designacao\t  Obrigatoria\t  Diurno   Num. de aulas previstas\n");
    for (i = 0; i < nUCs; i++) {
      printf("%2d\t%30s\t%3d     %11d\t   %03d\t\t\n", vUCs[i].id, vUCs[i].designacao, vUCs[i].obrigatoria,
             vUCs[i].diurno, vUCs[i].num_tipo_aulas_previstas);
      // if (vUCs[i].diurno == 1) {
      //   printf("Diurno\n");
      // } else {
      //   printf("Pos-Laboral\n");
      // }
    }
  }
  printf("\nPressione ENTER para continuar . . .");
  getchar();
}

tipoUC *EliminaUC(tipoUC vUCs[], int *nUCs, int idUC) {
  tipoUC *pUCs;
  int i, pos;

  pUCs = vUCs;  // Backup do vetor

  if (*nUCs != 0) {
    pos = ProcuraUC(vUCs, *nUCs, idUC);
    if (pos == -1) {
      printf("ERRO: UC nao encontrada!\n");
    } else {
      for (i = pos; i < *nUCs - 1; i++) {
        vUCs[i] = vUCs[i + 1];
      }
      vUCs = realloc(vUCs, (*nUCs - 1) * sizeof(tipoUC));
      if (vUCs == NULL && (*nUCs - 1) != 0) {
        printf("ERRO: Falha na alocacao de memoria!");
        vUCs = pUCs;  // Restaura backup
      }
      (*nUCs)--;
      printf("SUCESSO: UC eliminada!\n");
    }
  }
  return vUCs;
}