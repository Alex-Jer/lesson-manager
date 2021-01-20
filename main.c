#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_aulas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros_aula.h"
#include "funcoes_ficheiros_uc.h"
#include "funcoes_menus.h"
#include "funcoes_ucs.h"

int main() {
  int opcao, opcaoSubMenu, idUC, nUCs = 0, nAulas = 0,gravacao=0;
  char designacaoAula[MAX_STRING];
  tipoUC *vUCs = NULL;      // Inicializar vetor dinâmico de UCs
  tipoAula *vAulas = NULL;  // Inicializar vetor dinâmico de Aulas

  do {

    opcao = MenuPrincipal(nUCs,nAulas,gravacao);
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
              EditaUC(vUCs, &nUCs, idUC);
              break;
            case 3:  // Eliminar
              idUC = LerInteiro("ID da UC a eliminar: ", MIN_UCS, MAX_UCS);
              vUCs = EliminaUC(vUCs, &nUCs, idUC);
              break;
            case 4:  // Listar
              ListaUCs(vUCs, nUCs);
              break;
            case 5:  // Gravar em ficheiro
              EscreveFicheiroBinarioUCs(vUCs, nUCs);
              EscreveFicheiroTextoUCs(vUCs, nUCs);
              break;
            case 6:  // Ler ficheiro
              vUCs = LeFicheiroBinarioUCs(vUCs, &nUCs);
              break;
          }
        } while (opcaoSubMenu != 0);
        break;
      case 2:
        do {
          opcaoSubMenu = MenuAulas();
          switch (opcaoSubMenu) {
            case 1:  // Registar
              vAulas = AcrescentaAula(vAulas, &nAulas, vUCs, &nUCs);
              break;
            case 2:  // Editar
              LerString("Designacao da aula a editar: ", designacaoAula, MAX_UCS);
              // EditaAula(vAulas, &nAulas, designacaoAula);
              break;
            case 3:  // Eliminar
              LerString("Designacao da aula a editar: ", designacaoAula, MAX_UCS);
              // vAulas = EliminaAula(vAulas, &nAulas, designacaoAula);
              break;
            case 4:  // Listar
              ListaAulas(vAulas, nAulas, vUCs);
              break;
            case 5:  // Gravar em ficheiro
              EscreveFicheiroBinarioAulas(vAulas, nAulas);
              // EscreveFicheiroTextoAulas(vAulas, nAulas);
              break;
            case 6:  // Ler ficheiro
              vAulas = LeFicheiroBinarioAulas(vAulas, &nAulas);
              break;
          }
        } while (opcaoSubMenu != 0);
        break;
      case 3:
        break;
    }
  } while (opcao != 0);

  free(vUCs);

  return 0;
}
