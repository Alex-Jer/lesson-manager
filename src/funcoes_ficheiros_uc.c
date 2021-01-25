#include "funcoes_ficheiros_uc.h"

// Cria ou substitui um ficheiro dados_uc.dat com os dados do vetor de UCs
void EscreveFicheiroBinarioUCs(tipoUC vUCs[], int nUCs) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados_ucs.dat", "wb");
  if (ficheiro == NULL) {
    printf("\n ERRO: Falha na abertura do ficheiro!\n");
  } else {
    quantEscrito = fwrite(&nUCs, sizeof(int), 1, ficheiro);
    if (quantEscrito != 1) {
      printf("\n ERRO: Falha na escrita da quantidade de UCs no ficheiro.\n");
    } else {
      quantEscrito = fwrite(vUCs, sizeof(tipoUC), nUCs, ficheiro);
      if (quantEscrito != nUCs) {
        printf("\n ERRO: Falha na escrita de informacao no vetor!\n");
      } else {
        printf("\n SUCESSO: Ficheiro gravado!\n");
      }
    }
    fclose(ficheiro);
  }
}

// Lê o ficheiro dados_ucs.dat e preenche o vetor com os dados do ficheiro
tipoUC *LeFicheiroBinarioUCs(tipoUC vUCs[], int *nUCs) {
  FILE *ficheiro;
  tipoUC *pUCs;

  ficheiro = fopen("dados_ucs.dat", "rb");
  if (ficheiro == NULL) {
    printf("\n ERRO: Falha na abertura do ficheiro!\n");
  } else {
    fread(&(*nUCs), sizeof(int), 1, ficheiro);
    pUCs = vUCs;
    vUCs = NULL;
    vUCs = realloc(vUCs, (*nUCs) * sizeof(tipoUC));

    if (vUCs == NULL && *nUCs != 0) {
      printf("\n ERRO: Falha na reserva de memoria.");
      vUCs = pUCs;
    } else {
      fread(vUCs, sizeof(tipoUC), *nUCs, ficheiro);
    }
    fclose(ficheiro);
  }
  return vUCs;
}
