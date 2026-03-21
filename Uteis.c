
#include "Uteis.h"

int Aleatorio(int mini, int maxi)
{
  return mini + (int) (rand() / (double) (RAND_MAX + 1) * (maxi - mini + 1));
}

int aleatorio1(int mini,int maxi){
    return mini + rand()%(maxi-mini +1);
}

float aleatorioFloat(float mini, float maxi){
    float range = maxi - mini;
    float random_val = ((float)rand() / RAND_MAX) * range + mini;
    return random_val;
}
