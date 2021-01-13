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
  uc.teorica.quantidade = 0;
  uc.teoricopratica.quantidade = 0;
  uc.praticolab.quantidade = 0;

  uc.id = LerInteiro("Codigo: ", MIN_UCS, MAX_UCS);
  LerString("Nome: ", uc.designacao, MAX_STRING);

  do {
    LerChar("Obrigatoria? (S/N): ", obrigatoria, MAX_STRING);
    obrigatoria[0] = toupper(obrigatoria[0]);

    if (obrigatoria[0] != 'S' && obrigatoria[0] != 'N') {
      printf("ERRO: Opcao invalida!\n");
    }
  } while (obrigatoria[0] != 'S' && obrigatoria[0] != 'N');

  uc.semestre = LerInteiro("Semestre (1 a 6): ", MIN_SEMESTRE, MAX_SEMESTRE);
  do {
    LerChar("Diurno ou Pos-Laboral? (D/P): ", diurno, MAX_STRING);
    diurno[0] = toupper(diurno[0]);

    if (diurno[0] != 'D' && diurno[0] != 'P') {
      printf("ERRO: Opcao invalida!\n");
    }
  } while (diurno[0] != 'D' && diurno[0] != 'P');

  printf("\n-> Aulas Teoricas <-\n");
  uc.teorica.quantidade = LerInteiro("Numero de aulas previstas (0 a 20): ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
  if (uc.teorica.quantidade != 0) {
    uc.teorica.duracao = LerInteiro("Duracao de cada aula (30 a 240min): ", MIN_DURACAO_AULA, MAX_DURACAO_AULA);
  }

  printf("\n-> Aulas Teoricopraticas <-\n");
  uc.teoricopratica.quantidade = LerInteiro("Numero de aulas previstas (0 a 20): ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
  if (uc.teoricopratica.quantidade != 0) {
    uc.teoricopratica.duracao = LerInteiro("Duracao de cada aula (30 a 240min): ", MIN_DURACAO_AULA, MAX_DURACAO_AULA);
  }

  printf("\n-> Aulas Praticolaboratoriais <-\n");
  uc.praticolab.quantidade = LerInteiro("Numero de aulas previstas (0 a 20): ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
  if (uc.praticolab.quantidade != 0) {
    uc.praticolab.duracao = LerInteiro("Duracao de cada aula (30 a 240min): ", MIN_DURACAO_AULA, MAX_DURACAO_AULA);
  }

  uc.totalAulasPrevistas = uc.teorica.quantidade + uc.teoricopratica.quantidade + uc.praticolab.quantidade;

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

void ListaUCs(tipoUC vUCs[], int nUCs) {
  int i;

  if (nUCs == 0) {
    printf("\nERRO: Nao existem UCs registadas!\n");
  } else {
    printf("\n   ID\t\t\t    Designacao\t  Obrigatoria\t Regime\t\tT\t        TP               PL\n");
    for (i = 0; i < nUCs; i++) {
      printf("   %2d\t%30s\t  ", vUCs[i].id, vUCs[i].designacao);
      if (vUCs[i].obrigatoria == 1) {
        printf("Sim\t\t ");
      } else {
        printf("Nao\t\t ");
      }
      if (vUCs[i].diurno == 1) {
        printf("Diurno\t\t");
      } else {
        printf("Pos-Laboral\t");
      }
      printf("%2d (%03dmin)    %2d (%03dmin)     %2d (%03dmin)\n", vUCs[i].teorica.quantidade, vUCs[i].teorica.duracao,
             vUCs[i].teoricopratica.quantidade, vUCs[i].teoricopratica.duracao, vUCs[i].praticolab.quantidade,
             vUCs[i].praticolab.duracao);
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