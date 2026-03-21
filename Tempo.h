#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    time_t START;
    int VELOCIDADE;
    time_t Hora_Inicio;
}Relogio;

void StartRelogio(Relogio *R, int Vel, const char *H_Inicio);
time_t VerTimeRelogio(Relogio *R);
void WaitSegundos(int s);
void Wait(int s);

#endif // TEMPO_H_INCLUDED
