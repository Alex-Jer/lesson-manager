#include "funcoes_ficheiros.h"

void EscreveFicheiroTexto(tipoUC vUCs[], int nUCs) {
  int i;
  FILE *ficheiro;

  ficheiro = fopen("dados.txt", "w");
  if (ficheiro == NULL) {
    printf("Erro ao abrir ficheiro!\n");
  } else {
    fprintf(ficheiro, "\tQuantidade de UCs: %d\n\n", nUCs);
    for (i = 0; i < nUCs; i++) {
      fprintf(ficheiro, "\t\tDesignacao: %s\t Diurno: %d\tDuracao: %d\tNumero de aulas previstas: %d\n",
              vUCs[i].designacao, vUCs[i].diurno, vUCs[i].duracao, vUCs->num_tipo_aulas_previstas);
    }
    fclose(ficheiro);
  }
}

int LeFicheiroTexto(tipoUC vUCs[]) {
  FILE *ficheiro;
  int i, nUCs;

  ficheiro = fopen("dados.txt", "r");
  if (ficheiro == NULL) {
    printf("Erro ao abrir ficheiro!");
  } else {
    fscanf(ficheiro, "%d", &nUCs);
    for (i = 0; i < nUCs; i++) {
      fscanf(ficheiro, "%s", &vUCs[i].designacao);
      fscanf(ficheiro, "%d", &vUCs[i].diurno);
      fscanf(ficheiro, "%d", &vUCs[i].duracao);
      fscanf(ficheiro, "%d", &vUCs[i].num_tipo_aulas_previstas);
    }
    fclose(ficheiro);
  }

  return nUCs;
}