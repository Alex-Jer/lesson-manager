#include "funcoes_menus.h"

#include "funcoes_auxiliares.h"

// Mostra no ecrã o Menu Principal e pede uma opção ao utilizador
int MenuPrincipal(int nUCs, tipoAula vAulas[], int nAulas) {
  int opcao, i, nAgendadas = 0, nRealizadas = 0, nGravadas = 0;

  for (i = 0; i < nAulas; i++) {
    if (vAulas[i].estado == 'A') {
      nAgendadas++;
    } else if (vAulas[i].estado == 'R') {
      nRealizadas++;
    }

    if (vAulas[i].gravacao == 'G') {
      nGravadas++;
    }
  }

  printf("\n\n =================== MENU PRINCIPAL ===================\n\n");

  if (nUCs > 0 && nAgendadas > 0) {
    printf(" Num de UCs: %d\t\t\tNum Aulas Agendadas: %d\n", nUCs, nAgendadas);
  } else if (nUCs > 0 && nAgendadas <= 0) {
    printf(" Num de UCs: %d\t\t\tNum Aulas Agendadas: **\n", nUCs);
  } else {
    printf(" Num de UCs: **\t\t\tNum Aulas Agendadas: **\n");
  }

  if (nRealizadas > 0 && nGravadas > 0) {
    printf(" Num Aulas Realizadas: %d\tNum Aulas Gravadas: %d\n\n", nRealizadas, nGravadas);
  } else if (nRealizadas > 0 && nGravadas <= 0) {
    printf(" Num Aulas Realizadas: %d\tNum Aulas Gravadas: **\n\n", nRealizadas);
  } else {
    printf(" Num Aulas Realizadas: **\tNum Aulas Gravadas: **\n\n");
  }

  printf(" 1 - Gerir UCs\n");
  printf(" 2 - Gerir Aulas\n");
  printf(" 3 - Estatistica\n");
  printf(" 4 - Guardar Alteracoes\n");
  printf(" 5 - Carregar Dados Guardados\n");
  printf(" 0 - Terminar\n");
  opcao = LerInteiro(" \n Opcao--> ", 0, 5);

  return opcao;
}

// Mostra no ecrã o Menu de UCs e pede uma opção ao utilizador
int MenuUCs() {
  int opcao;

  printf("\n\n ===== GERIR UCS =====\n\n");
  printf(" 1 - Registar UC\n");
  printf(" 2 - Editar UC\n");
  printf(" 3 - Eliminar UC\n");
  printf(" 4 - Listar UCs\n");
  printf(" 5 - Ranking de UCs\n");
  printf(" 0 - Voltar\n");
  opcao = LerInteiro(" \n Opcao--> ", 0, 5);

  return opcao;
}

// Mostra no ecrã o Menu de Aulas e pede uma opção ao utilizador
int MenuAulas() {
  int opcao;

  printf("\n\n ===== GERIR AULAS =====\n\n");
  printf(" 1 - Agendar Aula\n");
  printf(" 2 - Alterar Agendamento\n");
  printf(" 3 - Eliminar Aula\n");
  printf(" 4 - Listar Todas as Aulas\n");
  printf(" 5 - Consultar Info e Presencas Aula\n");
  printf(" 6 - Alterar Estado Aula\n");
  printf(" 7 - Assistir Aula\n");
  printf(" 0 - Voltar\n");
  opcao = LerInteiro(" \n Opcao--> ", 0, 7);

  return opcao;
}

// Mostra no ecrã um conjunto de dados estatísticos
int DadosEstatisticos(tipoUC vUCs[], int nUCs, tipoAula vAulas[], int nAulas) {
  int opcao, i, soma1, soma2;
  int nDecorrerRealizadas = 0, nPresencas = 0, nGravadas = 0, nAcessosGravT = 0, nAcessosGravTP = 0, nAcessosGravPL = 0;
  float mediaPresencas, mediaGravadas, nGravadasPerc;

  for (i = 0; i < nUCs; i++) {
    nAcessosGravT += vUCs[i].teorica.nAcessosGrav;
    nAcessosGravTP += vUCs[i].teoricopratica.nAcessosGrav;
    nAcessosGravPL += vUCs[i].praticolab.nAcessosGrav;
  }

  for (i = 0; i < nAulas; i++) {
    if (vAulas[i].estado == 'D' || vAulas[i].estado == 'R') {
      nDecorrerRealizadas++;
    }

    if (vAulas[i].gravacao == 'G') {
      nGravadas++;
    }

    if (vAulas[i].estado == 'D' || vAulas[i].estado == 'R') {
      nPresencas += vAulas[i].nAcessos.online;
    }
  }

  mediaPresencas = (float)nPresencas / nDecorrerRealizadas;
  mediaGravadas = (float)nGravadas / nUCs;
  nGravadasPerc = mediaGravadas * 100;

  printf("\n\n ===== DADOS ESTATISTICOS =====\n\n");
  if (nPresencas > 0) {
    printf(" Media de presencas em aulas realizadas: %.2f\n", mediaPresencas);
  } else {
    printf(" Media de presencas em aulas realizadas: **\n");
  }

  if (nAulas > 0 && nGravadas > 0) {
    printf(" UCs com aulas gravadas: %.2f%%\n", nGravadasPerc);
  } else {
    printf(" UCs com aulas gravadas: **%%\n");
  }

  printf(" UC(s) com menor quantidade de aulas realizadas:\n");
  if (nAulas > 0) {
    qsort(vUCs, nUCs, sizeof(tipoUC), ComparaQuantAulasUC);
    soma1 = vUCs[0].teorica.nRealizadas + vUCs[0].teoricopratica.nRealizadas + vUCs[0].praticolab.nRealizadas;
    printf(" - %s\n", vUCs[0].designacao);

    for (i = 1; i < nUCs; i++) {
      soma2 = vUCs[i].teorica.nRealizadas + vUCs[i].teoricopratica.nRealizadas + vUCs[i].praticolab.nRealizadas;
      if (soma2 == soma1) {
        printf(" - %s\n", vUCs[i].designacao);
      }
    }
  } else {
    printf(" Nao ha UCs com aulas registadas.\n");
  }

  printf(" Tipo(s) de aula com maior quantidade de acessos as gravacoes:\n");
  if (nAcessosGravT == nAcessosGravTP && nAcessosGravTP == nAcessosGravPL) {
    printf(" - Teorica\n");
    printf(" - Teoricopratica\n");
    printf(" - Praticolaboratorial\n");
  } else if (nAcessosGravT > nAcessosGravTP && nAcessosGravT > nAcessosGravPL) {
    printf(" - Teorica\n");
  } else if (nAcessosGravTP > nAcessosGravT && nAcessosGravTP > nAcessosGravPL) {
    printf(" - Teoricopratica\n");
  } else if (nAcessosGravPL > nAcessosGravT && nAcessosGravPL > nAcessosGravTP) {
    printf(" - Praticolaboratorial\n");
  } else if (nAcessosGravT + nAcessosGravTP + nAcessosGravPL == 0) {
    printf(" Ainda nao foi visualizada nenhuma gravacao\n");
  }

  printf(" Aula(s) online realizadas a mais tempo: **\n");
  qsort(vAulas, nAulas, sizeof(tipoAula), ComparaDataAulas);
  for (i = 0; i < nAulas; i++) {
    if (vAulas[i].estado == 'R') {
      printf(" #%d - %s", i + 1, vAulas[i].designacao);
    }
  }

  opcao = LerInteiro(" \n Insira 0 para voltar--> ", 0, 0);

  return opcao;
}