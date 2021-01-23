#include "funcoes_ficheiros_uc.h"

// Cria ou substitui um ficheiro dados_uc.dat com os dados do vetor de UCs
void EscreveFicheiroBinarioUCs(tipoUC vUCs[], int nUCs) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados_ucs.dat", "wb");
  if (ficheiro == NULL) {
    printf("\nERRO: Falha na abertura do ficheiro!\n");
  } else {
    quantEscrito = fwrite(&nUCs, sizeof(int), 1, ficheiro);
    if (quantEscrito != 1) {
      printf("\nERRO: Falha na escrita da quantidade de UCs no ficheiro.\n");
    } else {
      quantEscrito = fwrite(vUCs, sizeof(tipoUC), nUCs, ficheiro);
      if (quantEscrito != nUCs) {
        printf("\nERRO: Falha na escrita de informacao no vetor!\n");
      } else {
        printf("\nGravado com sucesso no ficheiro binario!\n");
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
    printf("\nERRO: Falha na abertura do ficheiro!\n");
  } else {
    fread(&(*nUCs), sizeof(int), 1, ficheiro);
    pUCs = vUCs;
    vUCs = realloc(vUCs, (*nUCs) * sizeof(tipoUC));

    if (vUCs == NULL && *nUCs != 0) {
      printf("\nERRO: Erro ao reservar memoria.");
      vUCs = pUCs;
    } else {
      fread(vUCs, sizeof(tipoUC), *nUCs, ficheiro);
      printf("\nFicheiro lido com sucesso!\n");
      //! Temporário
      printf("\n   ID\t\t\t    ");
      printf("Designacao\t  ");
      printf("Obrigatoria\t ");
      printf("Regime            ");
      printf("Semestre    ");
      printf("T              TP             PL\n");
      for (int i = 0; i < *nUCs; i++) {
        printf("   %02d\t%30s\t  ", vUCs[i].id, vUCs[i].designacao);
        if (vUCs[i].obrigatoria == 1) {
          printf("Sim\t\t ");
        } else {
          printf("Nao\t\t ");
        }
        if (vUCs[i].diurno == 1) {
          printf("Diurno\t\t");
        } else {
          printf("Pos-Laboral\t");
        }
        printf("   %d.\t        %02d (%03dmin)    %02d (%03dmin)    %02d (%03dmin)\n", vUCs[i].semestre,
               vUCs[i].teorica.nPrevistas, vUCs[i].teorica.duracao, vUCs[i].teoricopratica.nPrevistas,
               vUCs[i].teoricopratica.duracao, vUCs[i].praticolab.nPrevistas, vUCs[i].praticolab.duracao);
      }
      //!
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
    printf("Erro ao abrir ficheiro!\n");
  } else {
    fprintf(ficheiro, "\n   ID\t\t\t\t\t\t\t\t\t\t\t");
    fprintf(ficheiro, "Designacao\t  ");
    fprintf(ficheiro, "Obrigatoria\t\t");
    fprintf(ficheiro, "Regime\t\t\t\t ");
    fprintf(ficheiro, "Semestre\t\t");
    fprintf(ficheiro, "T              TP             PL\n");
    for (i = 0; i < nUCs; i++) {
      fprintf(ficheiro, "   %02d\t%30s\t  ", vUCs[i].id, vUCs[i].designacao);
      if (vUCs[i].obrigatoria == 1) {
        fprintf(ficheiro, "Sim\t\t\t\t\t\t");
      } else {
        fprintf(ficheiro, "Nao\t\t\t\t\t\t");
      }
      if (vUCs[i].diurno == 1) {
        fprintf(ficheiro, "Diurno\t\t\t\t ");
      } else {
        fprintf(ficheiro, "Pos-Laboral\t\t ");
      }
      fprintf(ficheiro, "%d.\t        %02d (%03dmin)    %02d (%03dmin)    %02d (%03dmin)\n", vUCs[i].semestre,
              vUCs[i].teorica.nPrevistas, vUCs[i].teorica.duracao, vUCs[i].teoricopratica.nPrevistas,
              vUCs[i].teoricopratica.duracao, vUCs[i].praticolab.nPrevistas, vUCs[i].praticolab.duracao);
    }
    fclose(ficheiro);
  }
}

// int LeFicheiroTextoUC(tipoUC vUCs[], int *nUCs) {
//   FILE *ficheiro;
//   int i;

//   ficheiro = fopen("dados_ucs.txt", "r");
//   if (ficheiro == NULL) {
//     printf("\nERRO: Falha na abertura do ficheiro!");
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