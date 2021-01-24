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

// Pede ao utilizador dados de uma UC
tipoUC LeDadosUC(tipoUC vUCs[], int nUCs, int modoEdicao) {
  tipoUC uc;
  char obrigatoria[MAX_STRING];
  char diurno[MAX_STRING];

  uc.obrigatoria = 1;  // 0 - Não // 1 - Sim
  uc.diurno = 1;       // 0 - Não // 1 - Sim
  uc.teorica.nAgendadas = 0;
  uc.teoricopratica.nAgendadas = 0;
  uc.praticolab.nAgendadas = 0;

  if (modoEdicao == 0) {
    do {
      uc.id = LerInteiro("Codigo: ", MIN_UCS, MAX_UCS);
      if (ProcuraUC(vUCs, nUCs, uc.id) != -1) {
        printf("\nERRO: Ja existe uma UC com esse ID!\n\n");
      }
    } while (ProcuraUC(vUCs, nUCs, uc.id) != -1);
  }

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

  do {
    printf("\n-> Aulas Teoricas <-\n");
    uc.teorica.nPrevistas = LerInteiro("Numero de aulas previstas (0 a 20): ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
    if (uc.teorica.nPrevistas != 0) {
      uc.teorica.duracao = LerInteiro("Duracao de cada aula (60 a 240min): ", MIN_DURACAO_AULA, MAX_DURACAO_AULA);
    } else {
      uc.teorica.duracao = 0;
    }

    printf("\n-> Aulas Teoricopraticas <-\n");
    uc.teoricopratica.nPrevistas = LerInteiro("Numero de aulas previstas (0 a 20): ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
    if (uc.teoricopratica.nPrevistas != 0) {
      uc.teoricopratica.duracao = LerInteiro("Duracao de cada aula (60 a 240min): ", MIN_DURACAO_AULA, MAX_DURACAO_AULA);
    } else {
      uc.teoricopratica.duracao = 0;
    }

    printf("\n-> Aulas Praticolaboratoriais <-\n");
    uc.praticolab.nPrevistas = LerInteiro("Numero de aulas previstas (0 a 20): ", MIN_AULAS_PREVISTAS, MAX_AULAS_PREVISTAS);
    if (uc.praticolab.nPrevistas != 0) {
      uc.praticolab.duracao = LerInteiro("Duracao de cada aula (60 a 240min): ", MIN_DURACAO_AULA, MAX_DURACAO_AULA);
    } else {
      uc.praticolab.duracao = 0;
    }

    uc.totalAulasPrevistas = uc.teorica.nPrevistas + uc.teoricopratica.nPrevistas + uc.praticolab.nPrevistas;

    if (uc.totalAulasPrevistas <= 0) {
      printf("\nERRO: Tem de inserir pelo menos 1 aula!\n");
    }

  } while (uc.totalAulasPrevistas <= 0);

  if (obrigatoria[0] == 'N') {
    uc.obrigatoria = 0;
  }

  if (diurno[0] == 'P') {
    uc.diurno = 0;
  }

  return uc;
}

// Acrescenta uma UC ao vetor dinâmico de UCs
tipoUC *AcrescentaUC(tipoUC vUCs[], int *nUCs) {
  tipoUC dadosUC, *pUCs;
  int pos;

  if (*nUCs >= 40) {
    printf("\nERRO: Numero maximo de UCs atingido!\n");
  } else {
    pUCs = vUCs;
    dadosUC = LeDadosUC(vUCs, *nUCs, 0);
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

// Mostra no ecrã uma tabela de todas as UCs no vetor
void ListaUCs(tipoUC vUCs[], int nUCs) {
  int i;

  if (nUCs == 0) {
    printf("\nERRO: Nao existem UCs registadas!\n");
  } else {
    printf("\n   ID\t\t\t    ");
    printf("Designacao\t  ");
    printf("Obrigatoria\t ");
    printf("Regime            ");
    printf("Semestre    ");
    printf("T              TP              PL             \n");
    for (i = 0; i < nUCs; i++) {
      printf("   %02d\t%30s\t  ", vUCs[i].id, vUCs[i].designacao);
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
      printf("   #%d\t        %02d (%03dmin)    %02d (%03dmin)     %02d (%03dmin)\n", vUCs[i].semestre,
             vUCs[i].teorica.nPrevistas, vUCs[i].teorica.duracao, vUCs[i].teoricopratica.nPrevistas,
             vUCs[i].teoricopratica.duracao, vUCs[i].praticolab.nPrevistas, vUCs[i].praticolab.duracao);
    }
  }
  printf("\nPressione ENTER para continuar . . . ");
  getchar();
}

// Pede dados ao utilizador através da função LeDadosUC e altera a UC recebida como parâmetro
void EditaUC(tipoUC vUCs[], int *nUCs, int idUC) {
  tipoUC editadaUC;
  int pos;

  if (*nUCs != 0) {
    pos = ProcuraUC(vUCs, *nUCs, idUC);
    if (pos == -1) {
      printf("\nERRO: UC nao encontrada!\n");
    } else {
      editadaUC = LeDadosUC(vUCs, *nUCs, 1);
      strcpy(vUCs[pos].designacao, editadaUC.designacao);
      vUCs[pos].obrigatoria = editadaUC.obrigatoria;
      vUCs[pos].semestre = editadaUC.semestre;
      vUCs[pos].diurno = editadaUC.diurno;
      vUCs[pos].teorica.nPrevistas = editadaUC.teorica.nPrevistas;
      vUCs[pos].teorica.duracao = editadaUC.teorica.duracao;
      vUCs[pos].teoricopratica.nPrevistas = editadaUC.teoricopratica.nPrevistas;
      vUCs[pos].teoricopratica.duracao = editadaUC.teoricopratica.duracao;
      vUCs[pos].praticolab.nPrevistas = editadaUC.praticolab.nPrevistas;
      vUCs[pos].praticolab.duracao = editadaUC.praticolab.duracao;
      vUCs[pos].totalAulasPrevistas =
          editadaUC.teorica.nPrevistas + editadaUC.teoricopratica.nPrevistas + editadaUC.praticolab.nPrevistas;
      printf("SUCESSO: UC modificada!\n");
    }
  }
}

// Elimina a UC recebida como parâmetro
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