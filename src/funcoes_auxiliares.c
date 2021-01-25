#include "funcoes_auxiliares.h"

// Pede um número inteiro ao utilizador
int LerInteiro(char mensagem[MAX_STRING], int minimo, int maximo) {
  int numero, controlo;
  do {
    printf("%s", mensagem);
    controlo = scanf("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
    LimpaBufferStdin();               // limpa todos os caracteres do buffer stdin
                                      // (nomeadamente o \n)
    if (controlo == 0) {
      printf(" ERRO: Insira um numero inteiro!\n");
    } else {
      if (numero < minimo || numero > maximo) {
        printf(" ERRO: Numero invalido!\n");
      }
    }
  } while (numero < minimo || numero > maximo || controlo == 0);

  return numero;
}

// Pede um número float ao utilizador
float LerFloat(char mensagem[MAX_STRING], float minimo, float maximo) {
  float numero;
  int controlo;
  do {
    printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
    controlo = scanf("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
    LimpaBufferStdin();

    if (controlo == 0) {
      printf("Devera inserir um numero decimal (float) \n");
    } else {
      if (numero < minimo || numero > maximo) {
        printf("Numero invalido. Insira novamente:\n");
      }
    }
  } while (numero < minimo || numero > maximo || controlo == 0);

  return numero;
}

// Pede uma string ao utilizador
void LerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres) {
  int tamanhoString;

  do {  // Repete leitura caso sejam obtidas strings vazias
    printf("%s", mensagem);
    fgets(vetorCaracteres, maximoCaracteres, stdin);

    tamanhoString = strlen(vetorCaracteres);

    if (tamanhoString == 1) {
      printf("\n Nao foram introduzidos caracteres!!! Apenas carregou no ENTER\n\n");
      // apenas faz sentido limpar buffer se a ficarem caracteres
    } else if (tamanhoString > maximoCaracteres) {
      printf("\n ERRO: Dados invalidos!");
    }
  } while (tamanhoString == 1 || tamanhoString > maximoCaracteres);

  if (vetorCaracteres[tamanhoString - 1] != '\n') {  // ficaram caracteres no buffer....
    LimpaBufferStdin();                              // apenas faz sentido limpar buffer se a ficarem
                                                     // caracteres
  } else {
    vetorCaracteres[tamanhoString - 1] = '\0';  // Elimina o \n da string armazenada em vetor
  }
}

// Pede um caracter ao utilizador
void LerChar(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres) {
  int tamanhoString;

  do {  // Repete leitura caso sejam obtidas strings vazias
    printf("%s", mensagem);
    fgets(vetorCaracteres, maximoCaracteres, stdin);

    tamanhoString = strlen(vetorCaracteres);

    if (tamanhoString == 1) {
      printf("\n ERRO: Nao introduziu nenhum caracter! Apenas carregou no ENTER\n\n");
    } else if (tamanhoString > 2) {
      printf("\n ERRO: Introduziu mais do que um caracter!\n\n");
    }
  } while (tamanhoString == 1 || tamanhoString > 2);

  if (vetorCaracteres[tamanhoString - 1] != '\n') {
    LimpaBufferStdin();
  } else {
    vetorCaracteres[tamanhoString - 1] = '\0';
  }
}

// Limpa o buffer
void LimpaBufferStdin(void) {
  char chr;
  do {
    chr = getchar();
  } while (chr != '\n' && chr != EOF);
}
