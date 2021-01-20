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
  int opcao, opcaoSubMenu, idUC, nUCs = 0, nAulas = 0;
  char designacaoAula[MAX_STRING];
  tipoUC *vUCs = NULL;      // Inicializar vetor dinâmico de UCs
  tipoAula *vAulas = NULL;  // Inicializar vetor dinâmico de Aulas

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
              if (nUCs <= 0) {
                printf("\nERRO: Nao ha UCs registadas!\n");
              } else {
                idUC = LerInteiro("ID da UC a editar: ", MIN_UCS, MAX_UCS);
                EditaUC(vUCs, &nUCs, idUC);
              }
              break;
            case 3:  // Eliminar
              if (nUCs <= 0) {
                printf("\nERRO: Nao ha UCs registadas!\n");
              } else {
                idUC = LerInteiro("ID da UC a eliminar: ", MIN_UCS, MAX_UCS);
                vUCs = EliminaUC(vUCs, &nUCs, idUC);
              }
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
              vAulas = AgendaAula(vAulas, &nAulas, vUCs, &nUCs);
              break;
            case 2:  // Editar
              if (nAulas <= 0) {
                printf("\nERRO: Nao existem aulas registadas!\n");
              } else {
                LerString("\nDesignacao da aula a editar: ", designacaoAula, MAX_STRING);
                EditaAula(vAulas, nAulas, designacaoAula, vUCs, nUCs);
              }
              break;

            case 3:  // Eliminar
              if (nAulas <= 0) {
                printf("\nERRO: Nao existem aulas registadas!\n");
              } else {
                LerString("\nDesignacao da aula a eliminar: ", designacaoAula, MAX_STRING);
                vAulas = EliminaAula(vAulas, &nAulas, designacaoAula);
              }
              break;
            case 4:  // Listar
              ListaTodasAulas(vAulas, nAulas, vUCs);
              break;
            case 5:
              ListaAlteraEstadoAulas(vAulas, nAulas);
              break;
            case 6:  // Gravar em ficheiro
              EscreveFicheiroBinarioAulas(vAulas, nAulas);
              // EscreveFicheiroTextoAulas(vAulas, nAulas);
              break;
            case 7:  // Ler ficheiro
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
