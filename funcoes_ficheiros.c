#include "funcoes_ficheiros.h"

#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menu.h"
#include "funcoes_ucs.h"

void gravaFicheiroBinarioUCs(tipoUC novaUC, tipoUC vetor[MAX_UCS], int quantUCs) {
  FILE *ficheiro;
  int quantEscrito;

  ficheiro = fopen("dados.dat", "wb");

  if (ficheiro == NULL) {
    printf("Erro ao abrir o ficheiro\n");
  } else {  // conseguiu abrir o ficheiro
    quantEscrito = fwrite(&novaUC, sizeof(int), 1, ficheiro);
    if (quantEscrito != 1) {
      printf("Erro ao escrever a quantidade de estudantes no ficheiro\n");
    } else {
      quantEscrito = fwrite(vetor, sizeof(tipoUC), quantUCs, ficheiro);
    }
    fclose(ficheiro);
  }
}

void lerFicheiroBinario(tipoUC novaUC, tipoUC vetor[MAX_UCS], int quantUCs) {
  FILE *ficheiro;
  int quantLido;

  ficheiro = fopen("dados.dat", "rb");

  if (ficheiro == NULL) {
    printf("Erro ao abrir o ficheiro\n");
  } else {  // conseguiu abrir o ficheiro
    quantLido = fread(vetor, sizeof(tipoUC), quantUCs, ficheiro);
    // ou quantLido = fread(&*quantEstudantes, sizeof(int), 1, ficheiro);
    // if (quantLido != 1) {
    //   printf("Erro ao ler a quantidade de estudantes a partir do ficheiro\n");
    // } else {
    //   quantLido = fread(vEstudantes, sizeof(tipoEstudante), *novaUC, ficheiro);
    // }
    fclose(ficheiro);
  }
}

void gravaFicheiroTextoUCs(int quantUCs, tipoUC vUCs[]) {
  FILE *ficheiro;
  int i;

  ficheiro = fopen("dados.txt", "w");

  if (ficheiro == NULL) {
    printf("Erro ao abrir o ficheiro\n");
  } else {  // conseguiu abrir o ficheiro
    fprintf(ficheiro, "\tQuantidade estudantes: %d\n\n", quantUCs);
    for (i = 0; i < quantUCs; i++) {
      fprintf(ficheiro, "\t\tNome: %s\t Duracao: %d\n", vUCs[i].designacao, vUCs[i].duracao);
    }
    fclose(ficheiro);
  }
}
