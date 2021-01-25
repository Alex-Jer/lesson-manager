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

void EscreveFicheiroTextoUCs(tipoUC vUCs[], int nUCs) {
  int i;
  FILE *ficheiro;

  ficheiro = fopen("dados_ucs.txt", "w");
  if (ficheiro == NULL) {
    printf(" Erro ao abrir ficheiro!\n");
  } else {
    for (i = 0; i < nUCs; i++) {
      fprintf(ficheiro, "ID: %d\n", vUCs[i].id);
      fprintf(ficheiro, "Designacao: %s\n", vUCs[i].designacao);

      fprintf(ficheiro, "Obrigatoria: ");
      if (vUCs[i].obrigatoria == 1) {
        fprintf(ficheiro, "Sim\n");
      } else {
        fprintf(ficheiro, "Nao\n");
      }

      fprintf(ficheiro, "Regime");
      if (vUCs[i].diurno == 1) {
        fprintf(ficheiro, "Diurno\n");
      } else {
        fprintf(ficheiro, "Pos-Laboral\n");
      }

      fprintf(ficheiro, "Semestre: %2d\n", vUCs[i].semestre);
      fprintf(ficheiro, "Teoricas Previstas: %d (%dmin)\n", vUCs[i].teorica.nPrevistas, vUCs[i].teorica.duracao);
      fprintf(ficheiro, "Teoricopraticas Previstas: %d (%dmin)\n", vUCs[i].teoricopratica.nPrevistas,
              vUCs[i].teoricopratica.duracao);
      fprintf(ficheiro, "Praticolaboratoriais Previstas: %d (%dmin)\n", vUCs[i].praticolab.nPrevistas,
              vUCs[i].praticolab.duracao);
      fprintf(ficheiro, "\n********************************\n\n");
    }
    fclose(ficheiro);
  }
}

// int LeFicheiroTextoUC(tipoUC vUCs[], int *nUCs) {
//   FILE *ficheiro;
//   int i;

//   ficheiro = fopen("dados_ucs.txt", "r");
//   if (ficheiro == NULL) {
//     printf("\n ERRO: Falha na abertura do ficheiro!");
//   } else {
//     fscanf(ficheiro, "%d", &nUCs);
//     for (i = 0; i < *nUCs; i++) {
//       fgets(vUCs[i].designacao, MAX_STRING, ficheiro);
//       fscanf(ficheiro, "%d", &vUCs[i].diurno);
//       fscanf(ficheiro, "%d", &vUCs[i].duracao);
//       fscanf(ficheiro, "%d", &vUCs[i].totalAulasPrevistas);
//     }
//     fclose(ficheiro);
//   }

//   return *nUCs;
// }