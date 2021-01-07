#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menus.h"
#include "funcoes_ucs.h"

int main() {
  int opcao, opcaoSubMenu, *nUCs = 0;
  tipoUC *vUCs = NULL;  // Inicializar vetor dinâmico

  //* Consultar slide 7 adenda!!!
  do {
    opcao = MenuPrincipal();
    switch (opcao) {
      case 1:
        do {
          opcaoSubMenu = MenuUCs();
          switch (opcaoSubMenu) {
            case 1:  // Registar
              vUCs = AcrescentaUC(vUCs, &nUCs);
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
  free(vUCs);

  return 0;
}
