// #include "funcoes_ucs.h"

#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_ficheiros.h"

tipoUC RegistarUC()
{
    tipoUC novaUc;
    char obrigatoria;
    char diurno;
    char tipoDes[2];
    int duracao;
    novaUc.obrigatoria = true;
    novaUc.diurno = true;

    LerString("Nome: ", novaUc.designacao, MAX_STRING);
do
    {
    printf("Obrigatoria? (S/N): ");
    scanf(" %c", &obrigatoria);  //? Função LerString não funciona para 1 char?
    LimpaBufferStdin();

    if (obrigatoria!='S' &&  obrigatoria!='s' && obrigatoria!='N' && obrigatoria!='n')
    {
        printf(" \t\tOpcao invalida\n\t\t Insira uma nova opcao--> ");
    }
    else
    {
        if (obrigatoria == 'N'||obrigatoria == 'n')
        {
            novaUc.obrigatoria = false;
        }  // Fim da leitura do caracter
    }
    }while(obrigatoria!='S' &&  obrigatoria!='s' && obrigatoria!='N' && obrigatoria!='n');

    novaUc.semestre = LerInteiro("Semestre", 1, 6);  //! Usar uma constante

    do
    {
        printf("Diurno ou noturno? (D/N): ");  // Ler Char
        scanf(" %c", &diurno);
        LimpaBufferStdin();

        if (diurno!='D' &&  diurno!='d' && diurno!='N' && diurno!='n')
        {
            printf(" \t\tOpcao invalida\n\t\t Insira uma nova opcao--> ");
        }
        else
        {

            if (diurno == 'N'||obrigatoria == 'n')
            {
                novaUc.diurno = false;
            }
        }



    }while(diurno!='D' &&  diurno!='d' && diurno!='N' && diurno!='n');


    novaUc.num_tipo_aulas_previstas = LerInteiro("Numero de aulas previstas", 1, 40);  //! Usar uma constante
    // TODO: Estrutura (?) T, TP, PL
    printf("Qual o tipo de aula?(T/TP/PL): ");  // Ler Char
    scanf("%s", &tipoDes);

    /*  printf("Qual a duracao ?(1-T/2-TP/3-PL): ");  // Ler Char
      duracao = LerInteiro("Opcao", 1, 3);

      switch (duracao)
      {
      case 1:
      {
          printf("A duracao da aula sera de 0 min ");
      }
      break;
      case 2:
      {
          printf("A duracao da aula sera de 120 min ");
      }
      break;
      case 3:
      {
          printf("A duracao da aula sera de 180 min ");
      }
      break;
      }*/
    // TODO: Duração de cada T, TP, PL

    // Confirmar se escreve tudo

    //printf( "Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario: %s \nAulas previstas: %d \nTipo de aula:%s\ ",novaUc.designacao, obrigatoria, novaUc.semestre, diurno, novaUc.num_tipo_aulas_previstas,tipoDes);
printf("\nHorario:",diurno);
    return novaUc;
}
/*
void mostrarUCs(int quantUCs, tipoUC vUCs[MAX_UCS])
{
    int i;

    // caso em que quant == 0
    if (quantUCs == 0)
    {
        printf("\nNao ha informacao para mostrar (Nao ha UCs registadas)\n");
    }
    else
    {
        for (i = 0; i < quantUCs; i++)
        {
            // printf(
            //     "Os dados são:\nNome: %s \n Obrigatoria: %c \n Semestre: %d \nHorario %c \nAulas previstas: %d \nTipo de "
            //     "aula:%s/n %s");
            //,vUCs.designacao, obrigatoria, vUCs.semestre, diurno, vUCs.num_tipo_aulas_previstas, tipoDes,duracao
        }
    }
}
*/
