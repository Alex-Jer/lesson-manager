// #include "funcoes_ucs.h"

#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "ficheiro_Ucs.h"
UnidadeCurricular RegistarUc() {
  UnidadeCurricular novaUc;
  char obrigatoria;
  char diurno;
  char tipoDes[2];
    int duracao=0;
  novaUc.obrigatoria = true;
  novaUc.diurno = true;

  LerString("Nome: ", novaUc.designacao, MAX_STRING);

  printf("Obrigatoria? (S/N): ");
  scanf(" %c", &obrigatoria);  //? Função LerString não funciona para 1 char?
  if (obrigatoria == 'N') {
    novaUc.obrigatoria = false;
  }  // Fim da leitura do caracter

  novaUc.semestre = LerInteiro("Semestre", 1, 6);  //! Usar uma constante

  printf("Diurno ou noturno? (D/N): ");  // Ler Char
  scanf(" %c", &diurno);
  if (diurno == 'N') {
    novaUc.diurno = false;
  }  // Fim Ler Char

  novaUc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
  // TODO: Estrutura (?) T, TP, PL
  printf("Qual o tipo de aula?(T/TP/PL): ");  // Ler Char
  scanf(" %s",&tipoDes);

printf("Digite a opção refere há pergunta aterior(1-T/2-TP/3-PL): ");
scanf("%d",&duracao);
  switch (duracao)
  {
      case 1:
      {
          printf("A duração da aula será de 0 min ");
      }
      break;
      case 2:
      {
          printf("A duração da aula será de 120 min ");
      }
      break;
      case 3:
      {
          printf("A duração da aula será de 180 min ");
      }
        break;
  }
  // TODO: Duração de cada T, TP, PL

  // Confirmar se escreve tudo
  //printf(
   //   "Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario %c \nAulas previstas: %d \nTipo de aula:%s/n %s",novaUc.designacao, obrigatoria, novaUc.semestre, diurno, novaUc.num_tipo_aulas_previstas, tipoDes,duracao);

  return novaUc;
}
void mostrarUcs(int quantUcs,UnidadeCurricular vUcs[MAX_UCS])
{
    int i;

    // caso em que quant == 0
    if (quantUcs==0)
    {
        printf("\nNao ha informacao para mostrar(nao ha Ucs inscritas)\n");
    }
    else
    {
        for(i=0; i<quantUcs; i++)
        {
            printf("Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario %c \nAulas previstas: %d \nTipo de aula:%s/n %s");
                   //,vUcs.designacao, obrigatoria, vUcs.semestre, diurno, vUcs.num_tipo_aulas_previstas, tipoDes,duracao

        }

    }
}
