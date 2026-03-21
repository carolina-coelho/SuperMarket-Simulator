#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>


typedef struct NOG
{
    void *Info;
    struct NOG *Prox;
}NOG;

typedef struct
{
    int NEL;
    NOG *Inicio;
    NOG *Fim;
}ListaGenerica, FilaGenerica;


ListaGenerica *CriarLG();
void DestruirLG(ListaGenerica *lg, void (*fdest)(void *));
void ShowLG(ListaGenerica *lg, void (*f)(void *));
void AddLG(ListaGenerica *lg, void *X);
int PertenceLG(ListaGenerica *lg, void *X, int (*fcomp)(void *, void *));
size_t MemoriaOcupada(ListaGenerica *lg, size_t (*fmem)(void *X));
void *GetElementoPosicao(ListaGenerica *lg, int pos);

void AddFG(FilaGenerica *Fg, void *X);
void *RemoverFila(FilaGenerica *Fg, void *X);

#endif // LISTAGENERICA_H_INCLUDED
