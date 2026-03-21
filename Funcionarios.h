#ifndef FUNCIONARIOS_H_INCLUDED
#define FUNCIONARIOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "ListaGenerica.h"

typedef struct
{
    int CODIGO;
    char *NOME;
}Funcionarios;

Funcionarios *CriarFuncionarios(int _codigo, char *_nome);
void MostrarFuncionarios(void *X);
void DestruirFuncionarios(void *X);
void LerFuncionarios(ListaGenerica *LP, char *ficheiro);

#endif // FUNCIONARIOS_H_INCLUDED
