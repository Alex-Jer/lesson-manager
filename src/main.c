#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menu.h"
#include "funcoes_ucs.h"

int main() {
  int opcao;
  opcao = MenuPrincipal();
  UnidadeCurricular *vetorUcs = NULL;  // Vetor dinâmico

  switch (opcao) {
    case 1:
      MenuUcs(&vetorUcs);
      break;
    case 2:
      break;
    case 3:
      break;

    default:
      printf("0");
      break;
  }
  free(vetorUcs);

  return 0;
}

int MenuPrincipal() {
  int opcao;

  printf("GESTOR DE AULAS ONLINE\n\n");
  printf("1. Gerir UCs\n");
  printf("2. Gerir Aulas\n");
  printf("3. Estatistica\n");
  opcao = LerInteiro("Opcao", 1, 3);

  return opcao;
}

void MenuUcs(UnidadeCurricular *vetorUcs) {
  int opcao;
  // TODO: Alocar espaço no vetor
  printf("\nGESTOR DE UCs\n");
  printf("1. Registar UC\n");
  printf("2. Editar UC\n");
  printf("3. Listar UCs\n");
  opcao = LerInteiro("Opcao", 1, 3);

  switch (opcao) {
    case 1:
      vetorUcs[0] = RegistarUc();
      break;
    case 2:
      break;
    case 3:
      break;
    default:
      break;
  }
}