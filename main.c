#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menu.h"

int main() {
  MenuPrincipal();
  return 0;
}

void MenuPrincipal() {
  int opcao;
  do {
    printf("GESTOR DE AULAS ONLINE\n\n");
    printf("1. Gerir UCs\n");
    printf("2. Gerir Aulas\n");
    printf("3. Estatistica\n");
    opcao = lerInteiro("Opcao", 1, 3);
  } while (opcao < 1 || opcao > 3);

  switch (opcao) {
    case 1:
      MenuUcs();
      break;
    case 2:
      break;
    case 3:
      break;

    default:
      printf("0");
      break;
  }
}

void MenuUcs() {
  int opcao;
  printf("\nGESTOR DE UCs\n");
  printf("1. Registar UC\n");
  printf("2. Editar UC\n");
  printf("3. Listar UCs\n");
  opcao = lerInteiro("Opcao", 1, 3);
}
