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
        printf("\nSUCESSO: Ficheiro gravado!\n");
        printf("\nPressione ENTER para continuar . . . ");
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
    }
    fclose(ficheiro);
  }
  return vAulas;
}

void EscreveFicheiroTextoLog(tipoAula aula, char tipoAcesso[], int numeroEstudante) {
  FILE *ficheiro;

  ficheiro = fopen("log.txt", "a");

  if (ficheiro == NULL) {
    printf("Erro ao abrir o ficheiro!\n");
  } else {
    fprintf(ficheiro, "ACESSO %s - Aula: %s Num. Estudante: %d\n", tipoAcesso, aula.designacao, numeroEstudante);
    fclose(ficheiro);
  }
}

void EscreveFicheiroBinLog(tipoAula aula, char tipoAcesso[], int numeroEstudante) {
  FILE *ficheiro;
  int quantEscrito;
  int compTipoAcesso, compDesignacao;

  ficheiro = fopen("log.dat", "ab");

  if (ficheiro == NULL) {
    printf("Erro ao abrir o ficheiro!\n");
  } else {
    compTipoAcesso = strlen(tipoAcesso);
    compDesignacao = strlen(aula.designacao);
    quantEscrito = fwrite(tipoAcesso, sizeof(char), compTipoAcesso, ficheiro);
    // TODO:
    // if (quantEscrito != compTipoAcesso) {
    //   printf("\nErro ao escrever o tipo de acesso\n");
    // } else {
    //   printf("\nGravado com sucesso no ficheiro binario\n");
    // }

    quantEscrito = fwrite(aula.designacao, sizeof(char), compDesignacao, ficheiro);
    // if (quantEscrito != compDesignacao) {
    //   printf("\nErro ao escrever a designacao da aula\n");
    // } else {
    //   printf("\nGravado com sucesso no ficheiro binario\n");
    // }

    quantEscrito = fwrite(&numeroEstudante, sizeof(int), 1, ficheiro);
    // if (quantEscrito != 1) {
    //   printf("\nErro ao escrever o numero de estudante\n");
    // } else {
    //   printf("\nGravado com sucesso no ficheiro binario\n");
    // }
    fclose(ficheiro);
  }
}

void EscreveFicheiroTextoAulas(tipoAula vAulas[], int nAulas, tipoUC vUCs[]) {
  int i;
  FILE *ficheiro;

  ficheiro = fopen("dados_aulas.txt", "w");
  if (ficheiro == NULL) {
    printf("Erro ao abrir ficheiro!\n");
  } else {
    for (i = 0; i < nAulas; i++) {
      fprintf(ficheiro, "Designacao: %s\n", vAulas[i].designacao);
      fprintf(ficheiro, "UC: %s\n", vUCs[vAulas[i].idUC - 1].designacao);
      fprintf(ficheiro, "Tipo: %s\n", vAulas[i].tipoAula);
      fprintf(ficheiro, "Docente: %s\n", vAulas[i].docente);
      fprintf(ficheiro, "Data: %02d-%02d-%04d\n", vAulas[i].data.dia, vAulas[i].data.mes, vAulas[i].data.ano);
      fprintf(ficheiro, "Hora: %02d:%02d - %02d:%02d\n", vAulas[i].inicio.horas, vAulas[i].inicio.minutos, vAulas[i].fim.horas,
              vAulas[i].fim.minutos);

      if (vAulas[i].gravacao == 'G') {
        fprintf(ficheiro, "Gravacao: Disponivel\n");
      } else if (vAulas[i].gravacao == 'A') {
        fprintf(ficheiro, "Gravacao: A gravar...\n");
      } else {
        fprintf(ficheiro, "Gravacao: Indisponivel\n");
      }

      if (vAulas[i].estado == 'A') {
        fprintf(ficheiro, "Estado: Agendada\n");
      } else if (vAulas[i].estado == 'D') {
        fprintf(ficheiro, "Estado: A decorrer\n");
        fprintf(ficheiro, "Num presencas: %d\n", vAulas[i].nAcessos.online);
      } else {
        fprintf(ficheiro, "Estado: Realizada\n");
        fprintf(ficheiro, "Num alunos que participaram: %d\n", vAulas[i].nAcessos.online);
        fprintf(ficheiro, "Acessos a gravacao: %d\n", vAulas[i].nAcessos.offline);
      }
      fprintf(ficheiro, "\n//\n\n");
    }
    fclose(ficheiro);
  }
}