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
tipoAula LeDadosAula(tipoUC vUCs[], int *nUCs) {
  tipoAula aula;
  int pos;
  char tipoAula[MAX_STRING], estado[MAX_STRING], gravacao[MAX_STRING];

  aula.gravacao = 1;  // 0 - Não // 1 - Sim

  LerString("Nome: ", aula.designacao, MAX_STRING);

  do {
    aula.idUC = LerInteiro("Codigo da UC: ", MIN_UCS, MAX_UCS);
    pos = ProcuraUC(vUCs, *nUCs, aula.idUC);
    if (pos == -1) {
      printf("\nERRO: UC nao encontrada!\n\n");
    } else {
      do {
        LerString("Tipo de Aula: (T/TP/PL): ", tipoAula, MAX_STRING);
        strcpy(tipoAula, strupr(tipoAula));
        if ((strcmp(tipoAula, "T") != 0) && (strcmp(tipoAula, "TP") != 0) && (strcmp(tipoAula, "PL") != 0)) {
          printf("ERRO: Opcao invalida!\n");
        }
      } while ((strcmp(tipoAula, "T") != 0) && (strcmp(tipoAula, "TP") != 0) && (strcmp(tipoAula, "PL") != 0));

      strcpy(aula.tipoAula, tipoAula);

      LerString("Docente: ", aula.docente, MAX_STRING);

      aula.data.dia = LerInteiro("Dia: ", MIN_DIA, MAX_DIA);
      aula.data.mes = LerInteiro("Mes: ", MIN_MES, MAX_MES);
      aula.data.ano = LerInteiro("Ano: ", MIN_ANO, MAX_ANO);

      printf("\n-> Hora de Inicio <-\n");
      aula.inicio.horas = LerInteiro("Hora: ", MIN_HORA, MAX_HORA);
      aula.inicio.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);
      printf("\n-> Hora de Fim <-\n");
      aula.fim.horas = LerInteiro("Hora: ", MIN_HORA, MAX_HORA);
      aula.fim.minutos = LerInteiro("Minutos: ", MIN_MINUTOS, MAX_MINUTOS);

      do {
        LerChar("Aula [A]gendada, a [D]ecorrer ou ja [R]ealizada? (A/D/R): ", estado, MAX_STRING);
        estado[0] = toupper(estado[0]);

        if (estado[0] != 'A' && estado[0] != 'D' && estado[0] != 'R') {
          printf("ERRO: Opcao invalida!\n");
        }
      } while (estado[0] != 'A' && estado[0] != 'D' && estado[0] != 'R');

      aula.estado = estado[0];

      do {
        LerChar("Gravacao disponivel? (S/N): ", gravacao, MAX_STRING);
        gravacao[0] = toupper(gravacao[0]);

        if (gravacao[0] != 'S' && gravacao[0] != 'N') {
          printf("ERRO: Opcao invalida!\n");
        }
      } while (gravacao[0] != 'S' && gravacao[0] != 'N');

      if (gravacao[0] == 'N') {
        aula.gravacao = 0;
      }
    }
  } while (pos == -1);

  return aula;
}

// Acrescenta uma Aula ao vetor dinâmico de Aulas
tipoAula *AcrescentaAula(tipoAula vAulas[], int *nAulas, tipoUC vUCs[], int *nUCs) {
  tipoAula dadosAula, *pAulas;
  int pos;

  pAulas = vAulas;

  if (*nUCs <= 0) {
    printf("\nERRO: Nao ha UCs registadas!\n");
  } else {
    dadosAula = LeDadosAula(vUCs, nUCs);
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
        printf("\nSUCESSO: Aula inserida!\n");
      }
    }
  }
  return vAulas;
}

// Mostra no ecrã uma tabela de todas as Aulas no vetor
void ListaAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[] /* nUCs */) {
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

      if (vAulas[i].gravacao == 1) {
        printf("Gravacao: Sim\n");
      } else {
        printf("Gravacao: Nao\n");
      }
    }
  }
  printf("\nPressione ENTER para continuar . . . ");
  getchar();
}

// Pede dados ao utilizador através da função LeDadosAula e altera a Aula recebida como parâmetro
void EditaAula(tipoAula vAulas[], int *nAulas, char designacaoAula[], tipoUC vUCs[], int *nUCs) {
  tipoAula editadaAula;
  int pos;

  if (*nAulas != 0) {
    pos = ProcuraAula(vAulas, *nAulas, designacaoAula);
    if (pos == -1) {
      printf("\nERRO: Aula nao encontrada!\n");
    } else {
      editadaAula = LeDadosAula(vUCs, nUCs);
      strcpy(vAulas[pos].designacao, editadaAula.designacao);
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
      vAulas[pos].estado = editadaAula.estado;
      vAulas[pos].gravacao = editadaAula.gravacao;
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