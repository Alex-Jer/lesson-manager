#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menu.h"
#include "funcoes_ucs.h"

int main() {
  int opcao, opcaoSubMenu, *nUcs = 0;
  tipoUc *vUcs = NULL;  // Inicializar vetor dinâmico

  //* Consultar slide 7 adenda!!!
  do {
    opcao = MenuPrincipal();
    switch (opcao) {
      case 1:
        do {
          opcaoSubMenu = MenuUcs();
          switch (opcaoSubMenu) {
            case 1:  // Registar
              vUcs = RegistarUc(vUcs, &nUcs);
              break;
            case 2:  // Editar
              /* code */
              break;
            case 3:  // Listar
              /* code */
              break;
            default:
              printf("0");
              break;
          }
        } while (opcaoSubMenu != 0);
        break;
      case 2:
        break;
      case 3:
        break;
      default:
        printf("0");
        break;
    }
  } while (opcao != 0);
  free(vUcs);

  return 0;
}

int MenuPrincipal() {
  int opcao;

  printf("GESTOR DE AULAS ONLINE\n\n");
  printf("1. Gerir UCs\n");
  printf("2. Gerir Aulas\n");
  printf("3. Estatistica\n");
  printf("0. Voltar\n");
  opcao = LerInteiro("\nOpcao", 0, 3);

  return opcao;
}

int MenuUcs() {
  printf("\nGESTOR DE UCs\n");
  printf("1. Registar UC\n");
  printf("2. Editar UC\n");
  printf("3. Listar UCs\n");
  printf("0. Voltar\n");
}