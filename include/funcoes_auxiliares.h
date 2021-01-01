#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes.h"

int LerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float LerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void LerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void LimpaBufferStdin(void);

#endif  // FUNCOES_AUXILIARES_H_INCLUDED
