
#include "Cliente.h"
#include "ListaGenerica.h"

#define MAX_LISTA_PRODUTO 10

Cliente *CriarCliente(int cod, char *nome)
{

    if(!nome){
        printf("ERRO em [%s]\n", __FUNCTION__);
        return;
    }

    Cliente *C = (Cliente *)malloc(sizeof(Cliente));

    C->nome = (char *)malloc(sizeof(char) * (strlen(nome) + 1));
    C->ID = cod;
    strcpy(C->nome, nome);
    return C;
}

void DestruirCliente(void *X)
{
    if(!X){
        printf("ERRO em [%s]\n", __FUNCTION__);
        return;
    }

   Cliente *C = (Cliente *)X;
   free(C->nome);
   free(C);
}

void MostrarCliente(void *X)
{
    if(!X){
        printf("ERRO em [%s]\n", __FUNCTION__);
        return;
    }

    Cliente *C = (Cliente *)X;
    printf("%d\t%s", C->ID, C->nome);
}

void LerClientes(ListaGenerica *LC, char *ficheiro)
{
    if(!LC || !ficheiro){
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

        Cliente *C = CriarCliente(CODIGO, CAMPOS[1]);
        AddLG(LC, C);
    }
    fclose(F);
}
