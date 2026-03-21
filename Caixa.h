#ifndef CAIXA_H_INCLUDED
#define CAIXA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Funcionarios.h"
#include "Cliente.h"
#include "ListaGenerica.h"

typedef struct
{
    int ID;
    Funcionarios *Func;
    FilaGenerica *FCli;

    float TempoTotal;
}Caixa;

Caixa  *CriarCaixa(int _ID, Funcionarios *_Func, FilaGenerica *_Fcli);
void MostrarCaixa(Caixa *C);

#endif // CAIXA_H_INCLUDED
