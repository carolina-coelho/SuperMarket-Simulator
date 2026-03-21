
#include "ListaGenerica.h"

ListaGenerica *CriarLG()
{
    ListaGenerica *L = (ListaGenerica *)malloc(sizeof(ListaGenerica));
    L->Inicio = NULL;
    L->Fim = NULL;
    L->NEL = 0;
    return L;
}
void DestruirLG(ListaGenerica *lg, void (*fdest)(void *))
{
    if (!lg) return;
    NOG *P = lg->Inicio;
    NOG *AUX;
    while(P)
    {
        AUX = P->Prox;
        fdest(P->Info);
        free(P);
        P = AUX;
    }
    free(lg);
}
void ShowLG(ListaGenerica *lg, void (*f)(void *))
{
    if (!lg) return;
    NOG *P = lg->Inicio;
    while(P)
    {
        f(P->Info);
        P = P->Prox;
    }
}

void AddLG(ListaGenerica *lg, void *X)
{
    if (!lg || !X) return;
    NOG *P = (NOG *)malloc(sizeof(NOG));
    P->Prox = lg->Inicio;
    P->Info = X;
    lg->Inicio = P;
    lg->NEL++;
}

int PertenceLG(ListaGenerica *lg, void *X, int (*fcomp)(void *, void *))
{
    if (!lg || !X) return 0;
    NOG *P = lg->Inicio;
    while(P)
    {
        if (fcomp(P->Info, X) == 1) return 1;
        P = P->Prox;
    }
    return 0;
}

size_t MemoriaOcupada(ListaGenerica *lg, size_t (*fmem)(void *X))
{
    if (!lg) return 0;
    size_t soma_mem = sizeof(*lg);
    NOG *P = lg->Inicio;
    while(P)
    {
        soma_mem += sizeof(*P) + fmem(P->Info);
        P = P->Prox;
    }
    return soma_mem;
}

void *GetElementoPosicao(ListaGenerica *lg, int pos)
{
    if (!lg) return NULL;
    if ((pos < 0) || (pos >= lg->NEL)) return NULL;
    NOG *P = lg->Inicio;
    for (int i = 0; i < pos; i++)
        P = P->Prox;
    return P->Info;
}

void AddFG(FilaGenerica *Fg, void *X)
{
    if (!Fg || !X) return;
    NOG *P = (NOG *)malloc(sizeof(NOG));
    P->Prox = NULL;
    P->Info = X;

    if (!Fg->Fim)
        Fg->Inicio = Fg->Fim = P;
    else
    {
        Fg->Fim->Prox = P;
        Fg->Fim = P;
    }
    Fg->NEL++;
}

AddFG(FC, P);
RemoverFila(FCF);

void *RemoverFila(FilaGenerica *Fg)
{
    if (!Fg) return NULL;
    if (!Fg->Inicio) return NULL;
    void *X = Fg->Inicio->Info;
    NOG *Aux = Fg->Inicio->Prox;
    free(Fg->Inicio);
    free(X);
    Fg->Inicio = Aux;
    Fg->NEL--;

    return X;
}
