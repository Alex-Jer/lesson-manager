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

  do {
    LerChar("Obrigatoria? (S/N): ", obrigatoria, MAX_STRING);
    obrigatoria[0] = toupper(obrigatoria[0]);

    if (obrigatoria[0] != 'S' && obrigatoria[0] != 'N') {
      printf("ERRO: Opcao invalida!\n");
    }
  } while (obrigatoria[0] != 'S' && obrigatoria[0] != 'N');

  uc.semestre = LerInteiro("Semestre: ", MIN_SEMESTRE, MAX_SEMESTRE);
  do {
    LerChar("Diurno ou Pos-Laboral? (D/P): ", diurno, MAX_STRING);
    diurno[0] = toupper(diurno[0]);

    if (diurno[0] != 'D' && diurno[0] != 'P') {
      printf("ERRO: Opcao invalida!\n");
    }
  } while (diurno[0] != 'D' && diurno[0] != 'P');

  uc.totalAulasPrevistas = LerInteiro("Total de aulas previstas: ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
  // uc.teorica.quantidade = LerInteiro("Numero de aulas teoricas previstas: ", MIN_AULAS_PREVISTAS,
  // MAX_AULAS_PREVISTAS);
  // TODO: Estrutura (?) T, TP, PL
  // TODO: Duração de cada T, TP, PL
  // uc.duracao = LerInteiro("Duracao da aul");

  if (obrigatoria[0] == 'N') {
    uc.obrigatoria = 0;
  }

  if (diurno[0] == 'P') {
    uc.diurno = 0;
  }

  return uc;
}

tipoUC *AcrescentaUC(tipoUC vUCs[], int *nUCs) {
  tipoUC dadosUC, *pUCs;
  int pos;

  if (*nUCs >= 40) {
    printf("\nERRO: Numero maximo de UCs atingido!\n");
  } else {
    pUCs = vUCs;
    dadosUC = LeDadosUC();
    pos = ProcuraUC(vUCs, *nUCs, dadosUC.id);

    if (pos != -1) {
      printf("\nERRO: UC com o mesmo ID ja existe!\n");
    } else {
      vUCs = realloc(vUCs, (*nUCs + 1) * sizeof(tipoUC));
      if (vUCs == NULL) {
        printf("\nERRO: Impossível inserir UC!\n");
        vUCs = pUCs;
      } else {
        vUCs[*nUCs] = dadosUC;
        (*nUCs)++;
        printf("\nSUCESSO: UC inserida!\n");
      }
    }
  }
  return vUCs;
}

void ListaUC(tipoUC vUCs[], int nUCs) {
  int i;

  if (nUCs == 0) {
    printf("\nERRO: Nao existem UCs registadas!\n");
  } else {
    printf("\n   ID\t\t\t    Designacao\t  Obrigatoria\t  Diurno   Num. de aulas previstas\n");
    for (int i = 0; i < nUCs; i++) {
      printf("   %2d\t%30s\t\t  %3d%11d\t\t        %03d\n", vUCs[i].id, vUCs[i].designacao, vUCs[i].obrigatoria,
             vUCs[i].diurno, vUCs[i].totalAulasPrevistas);
    }
  }
  printf("\nPressione ENTER para continuar . . . ");
  getchar();
}

tipoUC *EditaUC(tipoUC vUCs[], int *nUCs, int idUC) {
  tipoUC editadaUC;
  int pos;

  if (*nUCs != 0) {
    pos = ProcuraUC(vUCs, *nUCs, idUC);
    if (pos == -1) {
      printf("\nERRO: UC nao encontrada!\n");
    } else {
      editadaUC = LeDadosUC();
      vUCs[pos].id = editadaUC.id;
      strcpy(vUCs[pos].designacao, editadaUC.designacao);
      vUCs[pos].obrigatoria = editadaUC.obrigatoria;
      vUCs[pos].semestre = editadaUC.semestre;
      vUCs[pos].diurno = editadaUC.diurno;
      vUCs[pos].totalAulasPrevistas = editadaUC.totalAulasPrevistas;
      printf("SUCESSO: UC modificada!\n");
    }
  }
  return vUCs;
}

tipoUC *EliminaUC(tipoUC vUCs[], int *nUCs, int idUC) {
  tipoUC *pUCs;
  int i, pos;

  pUCs = vUCs;  // Backup do vetor

  if (*nUCs != 0) {
    pos = ProcuraUC(vUCs, *nUCs, idUC);
    if (pos == -1) {
      printf("\nERRO: UC nao encontrada!\n");
    } else {
      for (i = pos; i < *nUCs - 1; i++) {
        vUCs[i] = vUCs[i + 1];
      }
      vUCs = realloc(vUCs, (*nUCs - 1) * sizeof(tipoUC));
      if (vUCs == NULL && (*nUCs - 1) != 0) {
        printf("\nERRO: Falha na alocacao de memoria!");
        vUCs = pUCs;  // Restaura backup
      }
      (*nUCs)--;
      printf("SUCESSO: UC eliminada!\n");
    }
  }
  return vUCs;
}