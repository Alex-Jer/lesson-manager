#include "funcoes_menus.h"

#include <stdio.h>
#include <stdlib.h>

#include "funcoes_auxiliares.h"

int MenuPrincipal() {
  int opcao;

  printf("\n\nGESTOR DE AULAS ONLINE\n\n");
  printf("1. Gerir UCs\n");
  printf("2. Gerir Aulas\n");
  printf("3. Estatistica\n");
  printf("0. Voltar\n");
  opcao = LerInteiro("\nOpcao", 0, 3);

  return opcao;
}

int MenuUCs() {
  int opcao;

  printf("\n\nGESTOR DE UCs\n\n");
  printf("1. Registar UC\n");
  printf("2. Editar UC\n");
  printf("3. Listar UCs\n");
  printf("4. Guardar Alteracoes\n");
  printf("5. Ler Ficheiro\n");
  printf("0. Fechar\n");
  opcao = LerInteiro("\nOpcao", 0, 5);

  return opcao;
}