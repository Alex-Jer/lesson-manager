#include "funcoes_menus.h"

#include "funcoes_auxiliares.h"

// Mostra no ecrã o Menu Principal e pede uma opção ao utilizador
int MenuPrincipal(int nUCs, tipoAula vAulas[], int nAulas) {
  int opcao, i, nAgendadas = 0, nRealizadas = 0, nGravadas = 0;

  for (i = 0; i < nAulas; i++) {
    if (vAulas[i].estado == 'A') {
      nAgendadas++;
    } else if (vAulas[i].estado == 'R') {
      nRealizadas++;
    }

    if (vAulas[i].gravacao == 'G') {
      nGravadas++;
    }
  }

  printf("\n\n =================== MENU PRINCIPAL ===================\n\n");

  if (nUCs > 0 && nAgendadas > 0) {
    printf(" Num de UCs: %d\t\t\tNum Aulas Agendadas: %d\n", nUCs, nAgendadas);
  } else if (nUCs > 0 && nAgendadas <= 0) {
    printf(" Num de UCs: %d\t\t\tNum Aulas Agendadas: **\n", nUCs);
  } else {
    printf(" Num de UCs: **\t\t\tNum Aulas Agendadas: **\n");
  }

  if (nRealizadas > 0 && nGravadas > 0) {
    printf(" Num Aulas Realizadas: %d\tNum Aulas Gravadas: %d\n\n", nRealizadas, nGravadas);
  } else if (nRealizadas > 0 && nGravadas <= 0) {
    printf(" Num Aulas Realizadas: %d\tNum Aulas Gravadas: **\n\n", nRealizadas);
  } else {
    printf(" Num Aulas Realizadas: **\tNum Aulas Gravadas: **\n\n");
  }

  printf(" 1 - Gerir UCs\n");
  printf(" 2 - Gerir Aulas\n");
  printf(" 3 - Estatistica\n");
  printf(" 0 - Terminar\n");
  opcao = LerInteiro("\n Opcao--> ", 0, 3);

  return opcao;
}

// Mostra no ecrã o Menu de UCs e pede uma opção ao utilizador
int MenuUCs() {
  int opcao;

  printf("\n\n ===== GERIR UCS =====\n\n");
  printf(" 1 - Registar UC\n");
  printf(" 2 - Editar UC\n");
  printf(" 3 - Eliminar UC\n");
  printf(" 4 - Listar UCs\n");
  printf(" 5 - Guardar Alteracoes\n");
  printf(" 6 - Ler Ficheiro\n");
  printf(" 0 - Voltar\n");
  opcao = LerInteiro("\n Opcao--> ", 0, 6);

  return opcao;
}

// Mostra no ecrã o Menu de Aulas e pede uma opção ao utilizador
int MenuAulas() {
  int opcao;

  printf("\n\n ===== GERIR AULAS =====\n\n");
  printf(" 1 - Agendar Aula\n");
  printf(" 2 - Alterar Agendamento\n");
  printf(" 3 - Eliminar Aula\n");
  printf(" 4 - Listar Todas as Aulas\n");
  printf(" 5 - Consultar Dados Aula\n");
  printf(" 6 - Alterar Estado Aula\n");
  printf(" 7 - Assistir Aula\n");
  printf(" 8 - Guardar Alteracoes\n");
  printf(" 9 - Ler Ficheiro\n");
  printf(" 0 - Voltar\n");
  opcao = LerInteiro("\n Opcao--> ", 0, 9);

  return opcao;
}

// Mostra no ecrã um conjunto de dados estatísticos
int DadosEstatisticos(tipoUC vUCs[], int nUCs, tipoAula vAulas[], int nAulas) {
  int opcao, iAulas, iUCs, nRealizadas = 0, nPresencas = 0, nGravadas = 0;
  float mediaPresencas, mediaGravadas, nGravadasPerc;

  for (iUCs = 0; iUCs < nUCs; iUCs++) {
    for (iAulas = 0; iAulas < nAulas; iAulas++) {
      // printf("\n%d", iAulas);
      // printf("\n%d - %s\n", vAulas[iAulas].idUC, vUCs[vAulas[iAulas].idUC - 1].designacao);
      if (vAulas[iAulas].idUC == iUCs + 1) {
        printf("\n%d - %s\n", vAulas[iAulas].idUC, vUCs[vAulas[iAulas].idUC - 1].designacao);
      }
    }
  }

  /*
    if (vAulas[]) {
      //
    }
  }

  for (iAulas = 0; iAulas < nAulas; iAulas++) {
    if (vAulas[iAulas].estado == 'R') {
      //
    }

    for (iUCs = vAulas[iAulas].idUC - 1; iUCs < nUCs; iUCs++) {
      // vUCs[i].
    }
  */

  if (vAulas[iAulas].estado == 'D') {
    nPresencas += vAulas[iAulas].nAcessos.online;
    nRealizadas++;
  }

  if (vAulas[iAulas].gravacao == 'G') {
    nGravadas++;
  }

  printf("\n%d\n", nGravadas);

  mediaPresencas = (float)nPresencas / nRealizadas;
  mediaGravadas = (float)nGravadas / nAulas;
  nGravadasPerc = mediaGravadas * 100;

  printf("\n\n ===== DADOS ESTATISTICOS =====\n\n");
  if (nPresencas > 0) {
    printf(" Media de presencas em aulas realizadas: %.2f\n", mediaPresencas);
  } else {
    printf(" Media de presencas em aulas realizadas: **\n");
  }

  if (nAulas > 0) {
    printf(" UCs com aulas gravadas: %.2f%%\n", nGravadasPerc);
  } else {
    printf(" UCs com aulas gravadas: **%%\n");
  }

  printf(" UC(s) com menor quantidade de acessos a gravacoes: **\n");
  printf(" Aula(s) online realizadas a mais tempo: **\n");

  opcao = LerInteiro("\n Insira 0 para voltar--> ", 0, 0);

  return opcao;
}