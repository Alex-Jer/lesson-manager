#include "funcoes_ficheiros_aula.h"

// Cria ou substitui um ficheiro dados_aula.dat com os dados do vetor de Aulas
void EscreveFicheiroBinarioAulas(tipoAula vAulas[], int nAulas) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados_aulas.dat", "wb");
  if (ficheiro == NULL) {
    printf("\n ERRO: Falha na abertura do ficheiro!\n");
  } else {
    quantEscrito = fwrite(&nAulas, sizeof(int), 1, ficheiro);
    if (quantEscrito != 1) {
      printf("\n ERRO: Falha na escrita da quantidade de Aulas no ficheiro.\n");
    } else {
      quantEscrito = fwrite(vAulas, sizeof(tipoAula), nAulas, ficheiro);
      if (quantEscrito != nAulas) {
        printf("\n ERRO: Falha na escrita de informacao no vetor!\n");
      } else {
        printf("\n SUCESSO: Ficheiro gravado!\n");
        printf("\n Pressione ENTER para continuar . . . ");
        getchar();
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
    printf("\n ERRO: Falha na abertura do ficheiro!\n");
  } else {
    fread(&(*nAulas), sizeof(int), 1, ficheiro);
    pAulas = vAulas;
    vAulas = realloc(vAulas, (*nAulas) * sizeof(tipoAula));

    if (vAulas == NULL && *nAulas != 0) {
      printf("\n ERRO: Erro ao reservar memoria.");
      vAulas = pAulas;
    } else {
      fread(vAulas, sizeof(tipoAula), *nAulas, ficheiro);
    }
    fclose(ficheiro);
  }
  return vAulas;
}

void EscreveFicheiroTextoLog(tipoAula aula, char tipoAcesso[], int numeroEstudante) {
  FILE *ficheiro;

  ficheiro = fopen("log.txt", "a");

  if (ficheiro == NULL) {
    printf(" Erro ao abrir o ficheiro!\n");
  } else {
    fprintf(ficheiro, "ACESSO %s - Aula: %s Num. Estudante: %d\n", tipoAcesso, aula.designacao, numeroEstudante);
    fclose(ficheiro);
  }
}

void EscreveFicheiroBinLog(tipoAula aula, char tipoAcesso[], int numeroEstudante) {
  FILE *ficheiro;
  int compTipoAcesso, compDesignacao;

  ficheiro = fopen("log.dat", "ab");

  if (ficheiro == NULL) {
    printf(" Erro ao abrir o ficheiro!\n");
  } else {
    compTipoAcesso = strlen(tipoAcesso);
    compDesignacao = strlen(aula.designacao);
    fwrite(tipoAcesso, sizeof(char), compTipoAcesso, ficheiro);
    fwrite(aula.designacao, sizeof(char), compDesignacao, ficheiro);
    fwrite(&numeroEstudante, sizeof(int), 1, ficheiro);
    fclose(ficheiro);
  }
}
