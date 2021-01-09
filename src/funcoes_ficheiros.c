#include "funcoes_ficheiros.h"

void EscreveFicheiroBinario(tipoUC vUCs[], int nUCs) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados.dat", "wb");
  if (ficheiro == NULL) {
    printf("ERRO: Falha na abertura do ficheiro!\n");
  } else {
    quantEscrito = fwrite(&nUCs, sizeof(int), 1, ficheiro);
    if (quantEscrito != 1) {
      printf("ERRO: Falha na escrita da quantidade de UCs no ficheiro.\n");
    } else {
      quantEscrito = fwrite(vUCs, sizeof(tipoUC), nUCs, ficheiro);
      if (quantEscrito != nUCs) {
        printf("ERRO: Falha na escrita de informacao no vetor!\n");
      } else {
        printf("\nGravado com sucesso no ficheiro binario!\n");
      }
    }
    fclose(ficheiro);
  }
}

tipoUC *LeFicheiroBinario(tipoUC vUCs[], int *nUCs) {
  FILE *ficheiro;
  tipoUC *pUCs;

  ficheiro = fopen("dados.dat", "rb");
  if (ficheiro == NULL) {
    printf("ERRO: Falha na abertura do ficheiro!\n");
  } else {
    fread(&(*nUCs), sizeof(int), 1, ficheiro);
    pUCs = vUCs;
    vUCs = realloc(vUCs, (*nUCs) * sizeof(tipoUC));

    if (vUCs == NULL && *nUCs != 0) {
      printf("ERRO: Erro ao reservar memoria.");
      vUCs = pUCs;
    } else {
      fread(vUCs, sizeof(tipoUC), *nUCs, ficheiro);
      printf("\nFicheiro lido com sucesso!");
    }
    fclose(ficheiro);
  }
  return vUCs;
}

// void EscreveFicheiroTexto(tipoUC vUCs[], int nUCs) {
//   int i;
//   FILE *ficheiro;

//   ficheiro = fopen("dados.txt", "w");
//   if (ficheiro == NULL) {
//     printf("Erro ao abrir ficheiro!\n");
//   } else {
//     for (i = 0; i < nUCs; i++) {
//       fprintf(ficheiro, "%s\n", vUCs[i].designacao);
//       fprintf(ficheiro, "%d\n", vUCs[i].diurno);
//       fprintf(ficheiro, "%d\n", vUCs[i].duracao);
//       fprintf(ficheiro, "%d\n", vUCs[i].num_tipo_aulas_previstas);
//     }
//     fclose(ficheiro);
//   }
// }

// int LeFicheiroTexto(tipoUC vUCs[], int *nUCs) {
//   FILE *ficheiro;
//   int i;

//   ficheiro = fopen("dados.txt", "r");
//   if (ficheiro == NULL) {
//     printf("ERRO: Falha na abertura do ficheiro!");
//   } else {
//     fscanf(ficheiro, "%d", &nUCs);
//     for (i = 0; i < *nUCs; i++) {
//       fgets(vUCs[i].designacao, MAX_STRING, ficheiro);
//       fscanf(ficheiro, "%d", &vUCs[i].diurno);
//       fscanf(ficheiro, "%d", &vUCs[i].duracao);
//       fscanf(ficheiro, "%d", &vUCs[i].num_tipo_aulas_previstas);
//     }
//     fclose(ficheiro);
//   }

//   return *nUCs;
// }