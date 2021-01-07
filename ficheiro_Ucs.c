
#include <stdio.h>
#include <stdlib.h>

#include "constantes.h"
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_menu.h"
#include "funcoes_ucs.h"

void listarUcs(UnidadeCurricular vetor[MAX_UCS], int elem)
{
    FILE *fichUcs;
    int i;
    fichUcs = fopen("dados.txt","w");
    if (fichUcs == NULL)
    {
        printf ("Erro abrir ficheiro");
    }
    else
    {
        fprintf(fichUcs,"%d\n", elem);
        for (i=0; i<elem; i++)
        {
            fprintf(fichUcs,"%s\n",vetor[i].designacao);
            fprintf(fichUcs,"%s\n",vetor[i].obrigatoria);
            fprintf(fichUcs,"%d\n",vetor[i].semestre);
            fprintf(fichUcs,"%d\n",vetor[i].num_tipo_aulas_previstas);
            fprintf(fichUcs,"%s\n",vetor[i].tipoDes);
            fprintf(fichUcs,"%d\n",vetor[i].duracao);
        }
        fclose(fichUcs);
    }
}
int leListarUcs(UnidadeCurricular vetor[MAX_UCS])
{
    FILE *fichUcs;
    int i, elem;
    fichUcs = fopen("dados.txt","r");
    if (fichUcs == NULL)
    {
        printf ("Erro abrir ficheiro");
    }
    else
    {
        fscanf(fichUcs,"%d", &elem);
        for (i=0; i<elem; i++)
        {
            fgets(fichUcs,"%s\n",vetor[i].designacao);
            fscanf(fichUcs,"%s\n",vetor[i].obrigatoria);
            fscanf(fichUcs,"%d\n",vetor[i].semestre);
            fscanf(fichUcs,"%d\n",vetor[i].num_tipo_aulas_previstas);
            fgets(fichUcs,"%s\n",vetor[i].tipoDes);
            fgets(fichUcs,"%d\n",vetor[i].duracao);

        }
        fclose(fichUcs);
    }
    return elem;
}
