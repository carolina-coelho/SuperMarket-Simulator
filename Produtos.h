#ifndef PRODUTOS_H_INCLUDED
#define PRODUTOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "ListaGenerica.h"

typedef struct
{
    int CODIGO;
    char *NOME;
    float PRECO;
    float TCAIXA;
    float TCOMPRA;

    int NEL;
}Produtos;

Produtos *CriarProdutos(int _codigo, char *_nome, float _preco, float _tcompra, float _tcaixa);
void MostrarProdutos(void *X);
void DestruirProdutos(void *X);
void LerProdutos(ListaGenerica *LP, char *ficheiro);

#endif // PRODUTOS_H_INCLUDED
