#include "funcoes_ficheiros_uc.h"

void EscreveFicheiroBinarioUC(tipoUC vUCs[], int nUCs) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados.dat", "wb");
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
        //! Temporário
        printf("\n   ID\t\t\t    ");
        printf("Designacao\t  ");
        printf("Obrigatoria\t ");
        printf("Regime            ");
        printf("Semestre    ");
        printf("T              TP             PL\n");
        for (int i = 0; i < nUCs; i++) {
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
                 vUCs[i].teorica.quantidade, vUCs[i].teorica.duracao, vUCs[i].teoricopratica.quantidade,
                 vUCs[i].teoricopratica.duracao, vUCs[i].praticolab.quantidade, vUCs[i].praticolab.duracao);
        }
        //!
      }
    }
    fclose(ficheiro);
  }
}

tipoUC *LeFicheiroBinarioUC(tipoUC vUCs[], int *nUCs) {
  FILE *ficheiro;
  tipoUC *pUCs;

  ficheiro = fopen("dados.dat", "rb");
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
               vUCs[i].teorica.quantidade, vUCs[i].teorica.duracao, vUCs[i].teoricopratica.quantidade,
               vUCs[i].teoricopratica.duracao, vUCs[i].praticolab.quantidade, vUCs[i].praticolab.duracao);
      }
      //!
    }
    fclose(ficheiro);
  }
  return vUCs;
}

// void EscreveFicheiroTextoUC(tipoUC vUCs[], int nUCs) {
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
//       fprintf(ficheiro, "%d\n", vUCs[i].totalAulasPrevistas);
//     }
//     fclose(ficheiro);
//   }
// }

// int LeFicheiroTextoUC(tipoUC vUCs[], int *nUCs) {
//   FILE *ficheiro;
//   int i;

//   ficheiro = fopen("dados.txt", "r");
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