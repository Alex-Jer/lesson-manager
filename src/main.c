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
  int opcao, opcaoSubMenu, idUC, numeroEstudante, nUCs = 0, nAulas = 0;
  char designacaoAula[MAX_STRING];
  tipoUC *vUCs = NULL;      // Inicializar vetor dinâmico de UCs
  tipoAula *vAulas = NULL;  // Inicializar vetor dinâmico de Aulas

  do {
    opcao = MenuPrincipal(nUCs, vAulas, nAulas);
    switch (opcao) {
      case 1:  // Menu UCs
        do {
          opcaoSubMenu = MenuUCs();
          switch (opcaoSubMenu) {
            case 1:  // Registar
              vUCs = AcrescentaUC(vUCs, &nUCs);
              break;
            case 2:  // Editar
              if (nUCs <= 0) {
                printf("\n ERRO: Nao ha UCs registadas!\n");
              } else {
                idUC = LerInteiro(" \n ID da UC a editar: ", MIN_UCS, MAX_UCS);
                EditaUC(vUCs, &nUCs, idUC);
              }
              break;
            case 3:  // Eliminar
              if (nUCs <= 0) {
                printf("\n ERRO: Nao ha UCs registadas!\n");
              } else {
                idUC = LerInteiro(" \n ID da UC a eliminar: ", MIN_UCS, MAX_UCS);
                vUCs = EliminaUC(vUCs, &nUCs, idUC);
              }
              break;
            case 4:  // Listar
              qsort(vUCs, nUCs, sizeof(tipoUC), ComparaIdUC);
              ListaUCs(vUCs, nUCs);
              break;
            case 5:  // Ranking UCs por gravação
              qsort(vUCs, nUCs, sizeof(tipoUC), ComparaQuantAcessosGravacao);
              ListaUCs(vUCs, nUCs);
              break;
          }
        } while (opcaoSubMenu != 0);
        break;
      case 2:  // Menu Aulas
        do {
          opcaoSubMenu = MenuAulas();
          switch (opcaoSubMenu) {
            case 1:  // Agendar Aula
              vAulas = AgendaAula(vAulas, &nAulas, vUCs, &nUCs);
              break;
            case 2:  // Alterar Agendamento
              if (nAulas <= 0) {
                printf("\n ERRO: Nao existem aulas registadas!\n");
              } else {
                LerString("\n Designacao da aula: ", designacaoAula, MAX_STRING);
                EditaAgendamento(vAulas, nAulas, designacaoAula, vUCs, nUCs);
              }
              break;

            case 3:  // Eliminar Aula
              if (nAulas <= 0) {
                printf("\n ERRO: Nao existem aulas registadas!\n");
              } else {
                LerString("\n Designacao da aula a eliminar: ", designacaoAula, MAX_STRING);
                vAulas = EliminaAula(vAulas, &nAulas, designacaoAula);
              }
              break;
            case 4:  // Listar Todas as Aulas
              ListaTodasAulas(vAulas, nAulas, vUCs, nUCs);
              break;
            case 5:  // Consultar uma Aula
              if (nAulas <= 0) {
                printf("\n ERRO: Nao existem aulas registadas!\n");
              } else {
                LerString("\n Designacao da aula a consultar: ", designacaoAula, MAX_STRING);
                ListaUmaAula(vAulas, nAulas, designacaoAula, vUCs, nUCs);
              }
              break;
            case 6:  // Alterar Estado das Aulas
              if (nAulas <= 0) {
                printf("\n ERRO: Nao existem aulas registadas!\n");
              } else {
                ListaAlteraEstadoAulas(vAulas, nAulas, vUCs, nUCs);
              }
              break;
            case 7:  // Assistir a uma Aula
              if (nAulas <= 0) {
                printf("\n ERRO: Nao existem aulas registadas!\n");
              } else {
                numeroEstudante = LerInteiro(" \n Insira o seu numero de estudante: ", MIN_NUM_ESTUDANTE, MAX_NUM_ESTUDANTE);
                LerString("\n Designacao da aula que deseja assistir: ", designacaoAula, MAX_STRING);
                AssisteAula(vAulas, nAulas, vUCs, nUCs, designacaoAula, numeroEstudante);
              }
              break;
          }
        } while (opcaoSubMenu != 0);
        break;
      case 3:  // Estatística
        do {
          opcaoSubMenu = DadosEstatisticos(vUCs, nUCs, vAulas, nAulas);
        } while (opcaoSubMenu != 0);
        break;
      case 4:  // Gravar em ficheiro
        EscreveFicheiroBinarioUCs(vUCs, nUCs);
        EscreveFicheiroTextoUCs(vUCs, nUCs);
        EscreveFicheiroBinarioAulas(vAulas, nAulas);
        EscreveFicheiroTextoAulas(vAulas, nAulas, vUCs);
        break;
      case 5:  // Ler Ficheiro
        vUCs = LeFicheiroBinarioUCs(vUCs, &nUCs);
        vAulas = LeFicheiroBinarioAulas(vAulas, &nAulas);
        printf("\n SUCESSO: Dados Restaurados!\n");
        printf("\n Pressione ENTER para continuar . . . ");
        getchar();
    }
  } while (opcao != 0);

  free(vUCs);

  return 0;
}
