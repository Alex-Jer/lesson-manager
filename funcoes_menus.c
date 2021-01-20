#include "funcoes_menus.h"

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_auxiliares.h"

// Mostra no ecrã o Menu Principal e pede uma opção ao utilizador
int MenuPrincipal() {
  int opcao;

  printf("\n\n===== MENU PRINCIPAL =====\n\n");
  printf("1 - Gerir UCs\n");
  printf("2 - Gerir Aulas\n");
  printf("3 - Estatistica\n");
  printf("0 - Terminar\n");
  opcao = LerInteiro("\nOpcao--> ", 0, 3);

  return opcao;
}

// Mostra no ecrã o Menu de UCs e pede uma opção ao utilizador
int MenuUCs() {
  int opcao;

  printf("\n\n===== GESTOR DE UCS =====\n\n");
  printf("1 - Registar UC\n");
  printf("2 - Editar UC\n");
  printf("3 - Eliminar UC\n");
  printf("4 - Listar UCs\n");
  printf("5 - Guardar Alteracoes\n");
  printf("6 - Ler Ficheiro\n");
  printf("0 - Voltar\n");
  opcao = LerInteiro("\nOpcao--> ", 0, 6);

  return opcao;
}

// Mostra no ecrã o Menu de Aulas e pede uma opção ao utilizador
int MenuAulas() {
  int opcao;

  printf("\n\n===== GESTOR DE AULAS =====\n\n");
  printf("1 - Inserir Aula\n");
  printf("2 - Editar Aula\n");
  printf("3 - Eliminar Aula\n");
  printf("4 - Listar Aulas\n");
  printf("5 - Guardar Alteracoes\n");
  printf("6 - Ler Ficheiro\n");
  printf("0 - Voltar\n");
  opcao = LerInteiro("\nOpcao--> ", 0, 6);

  return opcao;
}