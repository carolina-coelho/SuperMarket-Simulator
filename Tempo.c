
#include "Tempo.h"

void StartRelogio(Relogio *R, int Vel, const char *H_Inicio)
{
    R->START = time(0);
    R->VELOCIDADE = Vel;
    struct tm *tmp = localtime(&R->START);
    sscanf(H_Inicio, "%d:%d:%d", &tmp->tm_hour, &tmp->tm_min, &tmp->tm_sec);
    R->Hora_Inicio = mktime(tmp);
    printf("Hora de Arranque = [%s]\n", asctime(localtime(&(R->Hora_Inicio))));
}

time_t VerTimeRelogio(Relogio *R)
{
    time_t Dif = difftime(time(0), R->START);
    time_t Simulada = R->Hora_Inicio + Dif * R->VELOCIDADE;
    return Simulada;
}

void WaitSegundos(int s)
{
    clock_t T0 = clock();
    clock_t T1 = T0 + s;
    while (clock() < T1);
}

void Wait(int s)
{
    WaitSegundos(s*CLOCKS_PER_SEC);
}
