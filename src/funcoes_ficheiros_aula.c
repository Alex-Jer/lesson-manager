#include "funcoes_ficheiros_aula.h"

// Cria ou substitui um ficheiro dados_aula.dat com os dados do vetor de Aulas
void EscreveFicheiroBinarioAulas(tipoAula vAulas[], int nAulas) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados_aulas.dat", "wb");
  if (ficheiro == NULL) {
    printf("\nERRO: Falha na abertura do ficheiro!\n");
  } else {
    quantEscrito = fwrite(&nAulas, sizeof(int), 1, ficheiro);
    if (quantEscrito != 1) {
      printf("\nERRO: Falha na escrita da quantidade de Aulas no ficheiro.\n");
    } else {
      quantEscrito = fwrite(vAulas, sizeof(tipoAula), nAulas, ficheiro);
      if (quantEscrito != nAulas) {
        printf("\nERRO: Falha na escrita de informacao no vetor!\n");
      } else {
        printf("\nGravado com sucesso no ficheiro binario!\n");
        //! Temporário
        // printf("\n   ID\t\t\t    ");
        // printf("Designacao\t  ");
        // printf("Obrigatoria\t ");
        // printf("Regime            ");
        // printf("Semestre    ");
        // printf("T              TP             PL\n");
        // for (int i = 0; i < nAulas; i++) {
        //   printf("   %02d\t%30s\t  ", vAulas[i].id, vAulas[i].designacao);
        //   if (vAulas[i].obrigatoria == 1) {
        //     printf("Sim\t\t ");
        //   } else {
        //     printf("Nao\t\t ");
        //   }
        //   if (vAulas[i].diurno == 1) {
        //     printf("Diurno\t\t");
        //   } else {
        //     printf("Pos-Laboral\t");
        //   }
        //   printf("   %d.\t        %02d (%03dmin)    %02d (%03dmin)    %02d (%03dmin)\n", vAulas[i].semestre,
        //          vAulas[i].teorica.quantidade, vAulas[i].teorica.duracao, vAulas[i].teoricopratica.quantidade,
        //          vAulas[i].teoricopratica.duracao, vAulas[i].praticolab.quantidade, vAulas[i].praticolab.duracao);
        // }
        //!
      }
    }
    fclose(ficheiro);
  }
}

// Lê o ficheiro dados_aulas.dat e preenche o vetor com os dados do ficheiro
tipoAula *LeFicheiroBinarioAulas(tipoAula vAulas[], int *nAulas) {
  FILE *ficheiro;
  tipoAula *pAulas;

  ficheiro = fopen("dados_aulas.dat", "rb");
  if (ficheiro == NULL) {
    printf("\nERRO: Falha na abertura do ficheiro!\n");
  } else {
    fread(&(*nAulas), sizeof(int), 1, ficheiro);
    pAulas = vAulas;
    vAulas = realloc(vAulas, (*nAulas) * sizeof(tipoAula));

    if (vAulas == NULL && *nAulas != 0) {
      printf("\nERRO: Erro ao reservar memoria.");
      vAulas = pAulas;
    } else {
      fread(vAulas, sizeof(tipoAula), *nAulas, ficheiro);
      printf("\nFicheiro lido com sucesso!\n");
      //! Temporário
      // printf("\n   ID\t\t\t    ");
      // printf("Designacao\t  ");
      // printf("Obrigatoria\t ");
      // printf("Regime            ");
      // printf("Semestre    ");
      // printf("T              TP             PL\n");
      // for (int i = 0; i < *nAulas; i++) {
      //   printf("   %02d\t%30s\t  ", vAulas[i].id, vAulas[i].designacao);
      //   if (vAulas[i].obrigatoria == 1) {
      //     printf("Sim\t\t ");
      //   } else {
      //     printf("Nao\t\t ");
      //   }
      //   if (vAulas[i].diurno == 1) {
      //     printf("Diurno\t\t");
      //   } else {
      //     printf("Pos-Laboral\t");
      //   }
      //   printf("   %d.\t        %02d (%03dmin)    %02d (%03dmin)    %02d (%03dmin)\n", vAulas[i].semestre,
      //          vAulas[i].teorica.quantidade, vAulas[i].teorica.duracao, vAulas[i].teoricopratica.quantidade,
      //          vAulas[i].teoricopratica.duracao, vAulas[i].praticolab.quantidade, vAulas[i].praticolab.duracao);
      // }
      //!
    }
    fclose(ficheiro);
  }
  return vAulas;
}
/*
void EscreveFicheiroTextoAulas(tipoAula vAulas[], int nAulas) {
  int i;
  FILE *ficheiro;

  ficheiro = fopen("dados_aulas.txt", "w");
  if (ficheiro == NULL) {
    printf("Erro ao abrir ficheiro!\n");
  } else {
    fprintf(ficheiro, "\n   ID\t\t\t\t\t\t\t\t\t\t\t");
    fprintf(ficheiro, "Designacao\t  ");
    fprintf(ficheiro, "Obrigatoria\t\t");
    fprintf(ficheiro, "Regime\t\t\t\t ");
    fprintf(ficheiro, "Semestre\t\t");
    fprintf(ficheiro, "T              TP             PL\n");
    for (i = 0; i < nAulas; i++) {
      fprintf(ficheiro, "   %02d\t%30s\t  ", vAulas[i].id, vAulas[i].designacao);
      if (vAulas[i].obrigatoria == 1) {
        fprintf(ficheiro, "Sim\t\t\t\t\t\t");
      } else {
        fprintf(ficheiro, "Nao\t\t\t\t\t\t");
      }
      if (vAulas[i].diurno == 1) {
        fprintf(ficheiro, "Diurno\t\t\t\t ");
      } else {
        fprintf(ficheiro, "Pos-Laboral\t\t ");
      }
      fprintf(ficheiro, "%d.\t        %02d (%03dmin)    %02d (%03dmin)    %02d (%03dmin)\n", vAulas[i].semestre,
              vAulas[i].teorica.quantidade, vAulas[i].teorica.duracao, vAulas[i].teoricopratica.quantidade,
              vAulas[i].teoricopratica.duracao, vAulas[i].praticolab.quantidade, vAulas[i].praticolab.duracao);
    }
    fclose(ficheiro);
  }
}
*/