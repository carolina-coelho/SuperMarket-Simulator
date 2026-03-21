#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Produtos.h"
#include "ListaGenerica.h"

typedef struct
{
    int ID;
    char *nome;
    ListaGenerica *ListaProd;
}Cliente, vetor;

Cliente *CriarCliente(int cod, char *nome);
void DestruirCliente(void *X);
void MostrarCliente(void *X);
void LerClientes(ListaGenerica *LC, char *ficheiro);


#endif // CLIENTE_H_INCLUDED
