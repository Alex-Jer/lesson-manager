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

  printf("\n\n ===== MENU PRINCIPAL =====\n\n");

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
  printf(" 2 - Editar Dados Aula\n");
  printf(" 3 - Eliminar Aula\n");
  printf(" 4 - Listar Dados Aulas\n");
  printf(" 5 - Alterar Estado Aulas\n");
  printf(" 6 - Assistir Aula\n");
  printf(" 7 - Guardar Alteracoes\n");
  printf(" 8 - Ler Ficheiro\n");
  printf(" 0 - Voltar\n");
  opcao = LerInteiro("\n Opcao--> ", 0, 8);

  return opcao;
}