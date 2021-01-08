// #include "funcoes_ucs.h"

#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros.h"

tipoUC RegistarUC() {
  tipoUC novaUc;
  char obrigatoria;
  char diurno;
  char tipoDes[2];
  int duracao = 0;
  novaUc.obrigatoria = true;
  novaUc.diurno = true;

  LerString("Nome: ", novaUc.designacao, MAX_STRING);

  printf("Obrigatoria? (S/N): ");
  scanf("%c", &obrigatoria);  //? Função LerString não funciona para 1 char?
  LimpaBufferStdin();
  if (obrigatoria == 'N') {
    novaUc.obrigatoria = false;
  }  // Fim da leitura do caracter

  novaUc.semestre = LerInteiro("Semestre", 1, 6);  //! Usar uma constante

  printf("Diurno ou noturno? (D/N): ");  // Ler Char
  scanf("%c", &diurno);
  LimpaBufferStdin();
  if (diurno == 'N') {
    novaUc.diurno = false;
  }  // Fim Ler Char

  novaUc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Estrutura (?) T, TP, PL
  printf("Qual o tipo de aula?(T/TP/PL): ");  // Ler Char
  scanf("%s", &tipoDes);

  printf("Digite a opcao refere a pergunta anterior(1-T/2-TP/3-PL): ");
  scanf("%d", &duracao);
  switch (duracao) {
    case 1: {
      printf("A duracao da aula sera de 0 min ");
    } break;
    case 2: {
      printf("A duracao da aula sera de 120 min ");
    } break;
    case 3: {
      printf("A duracao da aula sera de 180 min ");
    } break;
  }
  // TODO: Duração de cada T, TP, PL

  // Confirmar se escreve tudo
  // printf(
  //   "Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario %c \nAulas previstas: %d \nTipo de
  //   aula:%s/n %s",novaUc.designacao, obrigatoria, novaUc.semestre, diurno, novaUc.num_tipo_aulas_previstas,
  //   tipoDes,duracao);

  return novaUc;
}

void mostrarUCs(int quantUCs, tipoUC vUCs[MAX_UCS]) {
  int i;

  // caso em que quant == 0
  if (quantUCs == 0) {
    printf("\nNao ha informacao para mostrar (Nao ha UCs registadas)\n");
  } else {
    for (i = 0; i < quantUCs; i++) {
      // printf(
      //     "Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario %c \nAulas previstas: %d \nTipo de "
      //     "aula:%s/n %s");
      //,vUCs.designacao, obrigatoria, vUCs.semestre, diurno, vUCs.num_tipo_aulas_previstas, tipoDes,duracao
    }
  }
}
