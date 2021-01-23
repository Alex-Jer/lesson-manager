#include "funcoes_aulas.h"

// Retorna a posição da Aula no vetor ou -1 se não encontrar o id
int ProcuraAula(tipoAula vAulas[], int nAulas, char procuraDesignacao[]) {
  int i, pos = -1;
  for (i = 0; i < nAulas; i++) {
    if (strcmp(vAulas[i].designacao, procuraDesignacao) == 0) {
      pos = i;
      i = nAulas;
    }
  }
  return pos;
}

// Pede ao utilizador dados de uma Aula
tipoAula LeDadosAula(tipoUC vUCs[], int nUCs, int modoEdicao) {
  tipoAula aula;
  int pos;
  char tipoAula[MAX_STRING];

  aula.nAcessos.online = 0;
  aula.nAcessos.offline = 0;

  if (modoEdicao == 0) {  // Valida se o utilizador não está a editar a UC, ou seja, se está a criar uma nova UC
    aula.estado = 'A';    // pois o nome da aula é único e não pode ser editado
    LerString("Nome: ", aula.designacao, MAX_STRING);
  }

  do {
    aula.idUC = LerInteiro("Codigo da UC: ", MIN_UCS, MAX_UCS);

    pos = ProcuraUC(vUCs, nUCs, aula.idUC);
    if (pos == -1) {
      printf("\nERRO: UC nao encontrada!\n\n");
    } else {
      do {
        LerString("Tipo de Aula: (T/TP/PL): ", tipoAula, MAX_STRING);
        strcpy(tipoAula, strupr(tipoAula));
        if ((strcmp(tipoAula, "T") != 0) && (strcmp(tipoAula, "TP") != 0) && (strcmp(tipoAula, "PL") != 0)) {
          printf("ERRO: Opcao invalida!\n");
        } else if ((strcmp(tipoAula, "T") == 0) && vUCs[pos].teorica.nPrevistas <= 0) {
          printf("ERRO: Esta UC nao tem aulas teoricas!\n");
        } else if ((strcmp(tipoAula, "TP") == 0) && vUCs[pos].teoricopratica.nPrevistas <= 0) {
          printf("ERRO: Esta UC nao tem aulas teoricopraticas!\n");
        } else if ((strcmp(tipoAula, "PL") == 0) && vUCs[pos].praticolab.nPrevistas <= 0) {
          printf("ERRO: Esta UC nao tem aulas praticolaboratoriais!\n");
        }
      } while (((strcmp(tipoAula, "T") != 0) && (strcmp(tipoAula, "TP") != 0) && (strcmp(tipoAula, "PL") != 0)) ||
               ((strcmp(tipoAula, "T") == 0) && vUCs[pos].teorica.nPrevistas <= 0) ||
               ((strcmp(tipoAula, "TP") == 0) && vUCs[pos].teoricopratica.nPrevistas <= 0) ||
               ((strcmp(tipoAula, "PL") == 0) && vUCs[pos].praticolab.nPrevistas <= 0));

      strcpy(aula.tipoAula, tipoAula);

      if (strcmp(aula.tipoAula, "T") == 0) {
        vUCs[aula.idUC - 1].teorica.nAgendadas++;
      } else if (strcmp(aula.tipoAula, "TP") == 0) {
        vUCs[aula.idUC - 1].teoricopratica.nAgendadas++;
      } else {
        vUCs[aula.idUC - 1].praticolab.nAgendadas++;
      }

      LerString("Docente: ", aula.docente, MAX_STRING);

      aula.data.dia = LerInteiro("Dia: ", MIN_DIA, MAX_DIA);
      aula.data.mes = LerInteiro("Mes: ", MIN_MES, MAX_MES);
      aula.data.ano = LerInteiro("Ano: ", MIN_ANO, MAX_ANO);

      //! Melhorar validação das horas
      do {
        printf("\n-> Hora de Inicio <-\n");
        if (vUCs[aula.idUC - 1].diurno == 1) {
          aula.inicio.horas = LerInteiro("Hora (8 as 17): ", MIN_HORA_INICIO_DIURNO, MAX_HORA_INICIO_DIURNO);
          aula.inicio.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
        } else {
          aula.inicio.horas = LerInteiro("Hora (18 as 23): ", MIN_HORA_INICIO_PL, MAX_HORA_INICIO_PL);
          aula.inicio.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
        }

        printf("\n-> Hora de Fim <-\n");
        if (vUCs[aula.idUC - 1].diurno == 1) {
          aula.fim.horas = LerInteiro("Hora (9 as 18): ", MIN_HORA_FIM_DIURNO, MAX_HORA_FIM_DIURNO);
          aula.fim.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
        } else {
          aula.fim.horas = LerInteiro("Hora (19 as 24): ", MIN_HORA_FIM_PL, MAX_HORA_FIM_PL);
          aula.fim.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
        }

        if (aula.inicio.horas > aula.fim.horas) {
          printf("\nERRO: Hora invalida!\n");
        } else if (aula.inicio.horas == aula.fim.horas) {
          printf("\nERRO: Aula deve ter pelo menos 1 hora!\n");
        }
      } while (aula.inicio.horas >= aula.fim.horas);
    }
  } while (pos == -1);

  return aula;
}

// Acrescenta uma Aula ao vetor dinâmico de Aulas
tipoAula *AgendaAula(tipoAula vAulas[], int *nAulas, tipoUC vUCs[], int *nUCs) {
  tipoAula dadosAula, *pAulas;
  int pos;

  pAulas = vAulas;

  if (*nUCs <= 0) {
    printf("\nERRO: Nao ha UCs registadas!\n");
  } else {
    dadosAula = LeDadosAula(vUCs, *nUCs, 0);
    pos = ProcuraAula(vAulas, *nAulas, dadosAula.designacao);

    if (pos != -1) {
      printf("\nERRO: Aula com o mesmo ID ja existe!\n");
    } else {
      vAulas = realloc(vAulas, (*nAulas + 1) * sizeof(tipoAula));
      if (vAulas == NULL) {
        printf("\nERRO: Impossível inserir Aula!\n");
        vAulas = pAulas;
      } else {
        vAulas[*nAulas] = dadosAula;
        (*nAulas)++;
        printf("\nSUCESSO: Aula inserida!");
      }
    }
  }
  return vAulas;
}

// Mostra no ecrã todas as Aulas no vetor
void ListaTodasAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[]) {
  int i;

  if (nAulas == 0) {
    printf("\nERRO: Nao existem aulas registadas!\n");
  } else {
    for (i = 0; i < nAulas; i++) {
      printf("\n************\n");
      printf("\nDesignacao: %s\n", vAulas[i].designacao);
      printf("UC: %s\n", vUCs[vAulas[i].idUC - 1].designacao);
      printf("Tipo: %s\n", vAulas[i].tipoAula);
      printf("Docente: %s\n", vAulas[i].docente);
      printf("Data: %02d-%02d-%04d\n", vAulas[i].data.dia, vAulas[i].data.mes, vAulas[i].data.ano);
      printf("Hora: %02d:%02d - %02d:%02d\n", vAulas[i].inicio.horas, vAulas[i].inicio.minutos, vAulas[i].fim.horas,
             vAulas[i].fim.minutos);

      if (vAulas[i].estado == 'A') {
        printf("Estado: Agendada\n");
      } else if (vAulas[i].estado == 'D') {
        printf("Estado: A decorrer\n");
      } else {
        printf("Estado: Realizada\n");
      }

      if (vAulas[i].gravacao == 'G') {
        printf("Gravacao: Sim\n");
      } else {
        printf("Gravacao: Nao\n");
      }
    }
  }
  printf("\nPressione ENTER para continuar . . . ");
  getchar();
}

// Mostra no ecrã uma aula escolhida pelo utilizador
void ListaUmaAula(tipoAula vAulas[], int nAulas, char designacaoAula[], tipoUC vUCs[]) {
  int pos, porAgendarT, porAgendarTP, porAgendarPL;

  if (nAulas >= 0) {
    pos = ProcuraAula(vAulas, nAulas, designacaoAula);
    if (pos == -1) {
      printf("\nERRO: Aula nao encontrada!\n");
    } else {
      printf("\nDesignacao: %s\n", vAulas[pos].designacao);
      printf("UC: %s\n", vUCs[vAulas[pos].idUC - 1].designacao);
      printf("Tipo: %s\n", vAulas[pos].tipoAula);
      printf("Docente: %s\n", vAulas[pos].docente);
      printf("Data: %02d-%02d-%04d\n", vAulas[pos].data.dia, vAulas[pos].data.mes, vAulas[pos].data.ano);
      printf("Hora: %02d:%02d - %02d:%02d\n", vAulas[pos].inicio.horas, vAulas[pos].inicio.minutos, vAulas[pos].fim.horas,
             vAulas[pos].fim.minutos);

      if (vAulas[pos].estado == 'A') {
        printf("Estado: Agendada\n");
      } else if (vAulas[pos].estado == 'D') {
        printf("Estado: A decorrer\n");
      } else {
        printf("Estado: Realizada\n");
      }

      if (vAulas[pos].gravacao == 'G') {
        printf("Gravacao: Sim\n");
      } else {
        printf("Gravacao: Nao\n");
      }

      porAgendarT = vUCs[vAulas[pos].idUC - 1].teorica.nPrevistas - vUCs[vAulas[pos].idUC - 1].teorica.nAgendadas;
      // printf("\nnome: %s\n", vUCs[vAulas[pos].idUC - 1].designacao);
      // printf("nPrevistasT: %d\n", vUCs[vAulas[pos].idUC - 1].teorica.nPrevistas);
      // printf("nAgendadasT: %d\n", vUCs[vAulas[pos].idUC - 1].teorica.nAgendadas);
      porAgendarTP = vUCs[vAulas[pos].idUC - 1].teoricopratica.nPrevistas - vUCs[vAulas[pos].idUC - 1].teoricopratica.nAgendadas;
      porAgendarPL = vUCs[vAulas[pos].idUC - 1].praticolab.nPrevistas - vUCs[vAulas[pos].idUC - 1].praticolab.nAgendadas;
      // printf("\nnome: %s\n", vUCs[vAulas[pos].idUC - 1].designacao);
      // printf("nPrevistasPL: %d\n", vUCs[vAulas[pos].idUC - 1].praticolab.nPrevistas);
      // printf("nAgendadasPL: %d\n\n", vUCs[vAulas[pos].idUC - 1].praticolab.nAgendadas);

      if (strcmp(vAulas[pos].tipoAula, "T") == 0) {
        printf("Aulas por agendar: %d\n", porAgendarT);
      } else if (strcmp(vAulas[pos].tipoAula, "TP") == 0) {
        printf("Aulas por agendar: %d\n", porAgendarTP);
      } else {
        printf("Aulas por agendar: %d\n", porAgendarPL);
      }
    }
  }

  printf("\nPressione ENTER para continuar . . . ");
  getchar();
}

// Mostra no ecrã as Aulas Agendadas
void ListaAlteraEstadoAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[]) {
  int i, pos, quantA = 0, quantD = 0, quantR = 0;
  char designacaoAula[MAX_STRING], confirmacao[MAX_CHAR], temGravacao[MAX_CHAR];

  strcpy(temGravacao, "S");

  if (nAulas == 0) {
    printf("\nERRO: Nao existem aulas registadas!");
  } else {
    printf("\n***** Aulas Agendadas *****\n");
    for (i = 0; i < nAulas; i++) {
      if (vAulas[i].estado == 'A') {
        printf("\n%s", vAulas[i].designacao);
        quantA++;
      }
    }

    if (quantA == 0) {
      printf("\n(Nenhuma aula agendada.)");
    }

    printf("\n\n***** Aulas A Decorrer ****\n");
    for (i = 0; i < nAulas; i++) {
      if (vAulas[i].estado == 'D') {
        printf("\n%s", vAulas[i].designacao);
        quantD++;
      }
    }

    if (quantD == 0) {
      printf("\n(Nenhuma aula a decorrer.)\n");
    }

    printf("\n\n***** Aulas Realizadas *****\n");
    for (i = 0; i < nAulas; i++) {
      if (vAulas[i].estado == 'R') {
        printf("\n%s", vAulas[i].designacao);
        quantR++;
      }
    }

    if (quantR == 0) {
      printf("\n(Nenhuma aula realizada.)");
    }
  }

  LerString("\n\nDesignacao da aula a alterar: ", designacaoAula, MAX_STRING);
  if (nAulas >= 0) {
    pos = ProcuraAula(vAulas, nAulas, designacaoAula);
    if (pos == -1) {
      printf("\nERRO: Aula nao encontrada!\n");
    } else {
      if (vAulas[pos].estado == 'A') {  // Altera estado de Agendada para A Decorrer
        do {
          printf("\nDeseja alterar o estado da aula %s de \"Agendada\" para \"A Decorrer\"? ", designacaoAula);
          LerChar("(S/N): ", confirmacao, MAX_CHAR);

          confirmacao[0] = toupper(confirmacao[0]);
          if (confirmacao[0] != 'S' && confirmacao[0] != 'N') {
            printf("ERRO: Opcao invalida!\n");
          }
        } while (confirmacao[0] != 'S' && confirmacao[0] != 'N');

        if (confirmacao[0] == 'S') {                     // Se o utilizador confirmar
          if (vUCs[vAulas[pos].idUC - 1].diurno == 1) {  // Se a aula for de regime diurno
            vAulas[pos].inicio.horas =
                LerInteiro("Hora de inicio da aula (8 as 17): ", MIN_HORA_INICIO_DIURNO, MAX_HORA_INICIO_DIURNO);
            vAulas[pos].inicio.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
          } else {  // Se a aula for de regime pós-laboral
            vAulas[pos].inicio.horas = LerInteiro("Hora inicio da aula (18 as 23): ", MIN_HORA_INICIO_PL, MAX_HORA_INICIO_PL);
            vAulas[pos].inicio.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
          }
          vAulas[pos].estado = 'D';  // Muda o estado da aula para "A Decorrer"

          do {
            LerChar("A aula sera gravada? (S/N): ", temGravacao, MAX_STRING);
            temGravacao[0] = toupper(temGravacao[0]);

            if (temGravacao[0] != 'S' && temGravacao[0] != 'N') {
              printf("ERRO: Opcao invalida!\n");
            }
          } while (temGravacao[0] != 'S' && temGravacao[0] != 'N');

          if (temGravacao[0] == 'N') {  // Se o utilizador não desejar que a aula seja gravada
            vAulas[pos].gravacao = 'N';
          } else {
            vAulas[pos].gravacao = 'A';
          }
        }
        printf("\nSUCESSO: Estado Alterado!\n");
      } else if (vAulas[pos].estado == 'D') {  // Altera estado de A Decorrer para Realizada
        do {
          printf("\nDeseja alterar o estado da aula %s de \"A Decorrer\" para \"Realizada\"? ", designacaoAula);
          LerChar("(S/N): ", confirmacao, MAX_CHAR);

          confirmacao[0] = toupper(confirmacao[0]);
          if (confirmacao[0] != 'S' && confirmacao[0] != 'N') {
            printf("ERRO: Opcao invalida!\n");
          }
        } while (confirmacao[0] != 'S' && confirmacao[0] != 'N');

        do {
          if (confirmacao[0] == 'S') {                     // Se o utilizador confirmar
            if (vUCs[vAulas[pos].idUC - 1].diurno == 1) {  // Se a aula for de regime diurno
              vAulas[pos].fim.horas = LerInteiro("Hora de fim da aula (9 as 18): ", MIN_HORA_FIM_DIURNO, MAX_HORA_FIM_DIURNO);
              vAulas[pos].fim.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
            } else {  // Se a aula for de regime pós-laboral
              vAulas[pos].fim.horas = LerInteiro("Hora de fim da aula (19 as 24): ", MIN_HORA_FIM_PL, MAX_HORA_FIM_PL);
              vAulas[pos].fim.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
            }
            vAulas[pos].estado = 'R';  // Muda o estado da aula para "Realizada"
          }

          if (vAulas[pos].inicio.horas > vAulas[pos].fim.horas) {  // A hora de início não pode ser maior do que a hora de fim
            printf("\nERRO: Hora invalida!\n");
          } else if (vAulas[pos].inicio.horas == vAulas[pos].fim.horas) {
            printf("\nERRO: Aula deve ter pelo menos 1 hora!\n");
          }
        } while (vAulas[pos].inicio.horas >= vAulas[pos].fim.horas);

        if (vAulas[pos].gravacao == 'A') {
          vAulas[pos].gravacao = 'G';
          printf("\nINFO: Gravacao disponibilizada.\n");
        }

        printf("\nSUCESSO: Estado Alterado!\n");
      } else if (vAulas[pos].estado == 'R') {
        printf("\nERRO: A aula %s ja terminou!", designacaoAula);
      }
    }
  }
}

// Pede dados ao utilizador através da função LeDadosAula e altera a Aula recebida como parâmetro
void EditaAula(tipoAula vAulas[], int nAulas, char designacaoAula[], tipoUC vUCs[], int nUCs) {
  tipoAula editadaAula;
  int pos;

  if (nAulas >= 0) {
    pos = ProcuraAula(vAulas, nAulas, designacaoAula);
    if (pos == -1) {
      printf("\nERRO: Aula nao encontrada!\n");
    } else {
      editadaAula = LeDadosAula(vUCs, nUCs, 1);
      if (strcmp(vAulas[pos].tipoAula, "T") == 0) {
        vUCs[vAulas[pos].idUC - 1].teorica.nAgendadas--;
        printf("\nnome: %s\n", vUCs[pos].designacao);
        printf("\nagendadasT: %d\n", vUCs[pos].teorica.nAgendadas);
      } else if ((strcmp(vAulas[pos].tipoAula, "TP") == 0)) {
        vUCs[vAulas[pos].idUC - 1].teoricopratica.nAgendadas--;
        printf("\nnome: %s\n", vUCs[pos].designacao);
        printf("\nagendadasTP: %d\n", vUCs[pos].teoricopratica.nAgendadas);
      } else {
        vUCs[vAulas[pos].idUC - 1].teorica.nAgendadas--;
        printf("\nnome: %s\n", vUCs[pos].designacao);
        printf("\nagendadasPL: %d\n\n", vUCs[pos].praticolab.nAgendadas);
      }

      vAulas[pos].idUC = editadaAula.idUC;
      strcpy(vAulas[pos].tipoAula, editadaAula.tipoAula);
      strcpy(vAulas[pos].docente, editadaAula.docente);
      vAulas[pos].data.dia = editadaAula.data.dia;
      vAulas[pos].data.mes = editadaAula.data.mes;
      vAulas[pos].data.ano = editadaAula.data.ano;
      vAulas[pos].inicio.horas = editadaAula.inicio.horas;
      vAulas[pos].inicio.minutos = editadaAula.inicio.minutos;
      vAulas[pos].fim.horas = editadaAula.fim.horas;
      vAulas[pos].fim.minutos = editadaAula.fim.minutos;
      printf("SUCESSO: Aula modificada!\n");
    }
  }
}

// Elimina a Aula recebida como parâmetro
tipoAula *EliminaAula(tipoAula vAulas[], int *nAulas, char designacaoAula[]) {
  tipoAula *pAulas;
  int i, pos;

  pAulas = vAulas;  // Backup do vetor

  if (*nAulas != 0) {
    pos = ProcuraAula(vAulas, *nAulas, designacaoAula);
    if (pos == -1) {
      printf("\nERRO: Aula nao encontrada!\n");
    } else {
      for (i = pos; i < *nAulas - 1; i++) {
        vAulas[i] = vAulas[i + 1];
      }
      vAulas = realloc(vAulas, (*nAulas - 1) * sizeof(tipoAula));
      if (vAulas == NULL && (*nAulas - 1) != 0) {
        printf("\nERRO: Falha na alocacao de memoria!");
        vAulas = pAulas;  // Restaura backup
      }
      (*nAulas)--;
      printf("SUCESSO: Aula eliminada!\n");
    }
  }
  return vAulas;
}

void AssisteAula(tipoAula vAulas[], int nAulas, char designacaoAula[], int numeroEstudante) {
  int pos;

  if (nAulas >= 0) {
    pos = ProcuraAula(vAulas, nAulas, designacaoAula);
    if (pos == -1) {
      printf("\nERRO: Aula nao encontrada!\n");
    } else {
      if (vAulas[pos].estado == 'A') {
        printf("\nERRO: Aula ainda nao realizada!\n");
        printf("Espere ate %02d-%02d-%04d as %02d:%02d\n", vAulas[pos].data.dia, vAulas[pos].data.mes, vAulas[pos].data.ano,
               vAulas[pos].inicio.horas, vAulas[pos].inicio.minutos);
      } else if (vAulas[pos].estado == 'D') {  // Acesso Online
        vAulas[pos].estudantesOnline[vAulas[pos].nAcessos.online] = numeroEstudante;
        printf("\ni 0: %d", vAulas[pos].estudantesOnline[0]);                                 //!
        printf("\nEstudante %d", vAulas[pos].estudantesOnline[vAulas[pos].nAcessos.online]);  //!
        printf("\nSUCESSO: A assistir a aula %s", vAulas[pos].designacao);
        printf("\nindice: %d", vAulas[pos].nAcessos.online);  //!
        EscreveFicheiroTextoLog(vAulas[pos], "ONLINE", numeroEstudante);
        vAulas[pos].nAcessos.online++;
        printf("\nacessos online: %d", vAulas[pos].nAcessos.online);  //!
      } else if (vAulas[pos].estado == 'R' && vAulas[pos].gravacao == 'N') {
        printf("\nERRO: Gravacao da aula %s nao disponivel!\n", vAulas[pos].designacao);
      } else {  // Acesso Offline
        printf("\nSUCESSO: A visualizar gravacao da aula %s", vAulas[pos].designacao);
        printf("\nindice: %d", vAulas[pos].nAcessos.offline);  //!
        EscreveFicheiroTextoLog(vAulas[pos], "OFFLINE", numeroEstudante);
        vAulas[pos].nAcessos.offline++;
        printf("\nacessos offline: %d", vAulas[pos].nAcessos.offline);  //!
      }
    }
  }
}