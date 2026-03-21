
#include "Funcionarios.h"

Funcionarios *CriarFuncionarios(int _codigo, char *_nome)
{
    if(!_nome){
        printf("ERRO EM [%s]\n", __FUNCTION__);
        return;
    }

    Funcionarios *F = (Funcionarios *)malloc(sizeof(Funcionarios));

    F->NOME = (char *)malloc(sizeof(char) * (strlen(_nome) + 1));

    F->CODIGO = _codigo;
    strcpy(F->NOME, _nome);

    return F;
}

void MostrarFuncionarios(void *X)
{
    if(!X){
        printf("ERRO EM [%s]\n", __FUNCTION__);
        return;
    }

    Funcionarios *F = (Funcionarios *)X;

    printf("%d\t%s\n", F->CODIGO, F->NOME);
}

void DestruirFuncionarios(void *X)
{
    if(!X){
        printf("ERRO EM [%s]\n", __FUNCTION__);
        return;
    }

    Funcionarios *F = (Funcionarios *)X;

    free(F->NOME);
    free(F);
}

void LerFuncionarios(ListaGenerica *LF, char *ficheiro)
{
    if(!LF || !ficheiro){
        printf("ERRO EM [%s]\n", __FUNCTION__);
        return;
    }

    FILE *F = fopen(ficheiro, "r");
    if (!F) return;

    char BUFFER[1001];

    while (!feof(F))
    {
        fgets(BUFFER, 1000, F);

        int CODIGO;
        int i = 0;

        char *CAMPOS[2];
        char *token = strtok(BUFFER, "\t");
        while(token != NULL)
        {
            CAMPOS[i] = token;
            token = strtok(NULL, "\t");
            i++;
        }

        CODIGO = atoi(CAMPOS[0]);

        Funcionarios *Func = CriarFuncionarios(CODIGO, CAMPOS[1]);
        AddLG(LF, Func);

    }
    fclose(F);
}
