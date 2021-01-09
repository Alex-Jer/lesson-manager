#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros.h"
#include "funcoes_menus.h"
#include "funcoes_ucs.h"

int main() {
  int opcao, opcaoSubMenu, *nUCs = 0;
  tipoUC *vUCs = NULL;  // Inicializar vetor dinâmico

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
            case 3:                 // Listar
              ListaUC(vUCs, nUCs);  //? Com ou sem &?
              break;
            case 4:  // Gravar em ficheiro
              EscreveFicheiroBinario(vUCs, nUCs);
              break;
            case 5:  // Ler ficheiro
              vUCs = LeFicheiroBinario(vUCs, &nUCs);
              break;
          }
        } while (opcaoSubMenu != 0);
        break;
      case 2:
        break;
      case 3:
        break;
    }
  } while (opcao != 0);
  free(vUCs);

  return 0;
}
