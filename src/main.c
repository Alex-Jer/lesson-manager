#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros_uc.h"
#include "funcoes_menus.h"
#include "funcoes_ucs.h"

int main() {
  int opcao, opcaoSubMenu, idUC, *nUCs = 0;
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
              idUC = LerInteiro("ID da UC a editar: ", MIN_UCS, MAX_UCS);
              vUCs = EditaUC(vUCs, &nUCs, idUC);
              break;
            case 3:  // Eliminar
              idUC = LerInteiro("ID da UC a eliminar: ", MIN_UCS, MAX_UCS);
              vUCs = EliminaUC(vUCs, &nUCs, idUC);
              break;
            case 4:                 // Listar
              ListaUC(vUCs, nUCs);  //? Com ou sem &?
              break;
            case 5:  // Gravar em ficheiro
              EscreveFicheiroBinarioUC(vUCs, nUCs);
              break;
            case 6:  // Ler ficheiro
              vUCs = LeFicheiroBinarioUC(vUCs, &nUCs);
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
