
#include "Produtos.h"
#include "ListaGenerica.h"

#define STRING char *
#define MAX_LINHA_FICHEIRO 150

typedef char LinhaTexto[MAX_LINHA_FICHEIRO];

LinhaTexto LT;

Produtos *CriarProdutos(int _codigo, char *_nome, float _preco, float _tcompra, float _tcaixa)
{
    if(!_nome){
        printf("ERRO EM [%s]", __FUNCTION__);
        return;
    }

    Produtos *P = (Produtos *)malloc(sizeof(Produtos));

    P->NOME = (char *)malloc(sizeof(char) * (strlen(_nome) + 1));

    P->CODIGO = _codigo;
    strcpy(P->NOME, _nome);
    P->PRECO = _preco;
    P->TCOMPRA = _tcompra;
    P->TCAIXA = _tcaixa;

    P->NEL = 0;

    return P;
}

void MostrarProdutos(void *X)
{
    if(!X){
        printf("ERRO EM [%s]\n", __FUNCTION__);
        return;
    }

    Produtos *P = (Produtos *)X;

    printf("\n%d\t%s\t%.2f\t%.1f\t%.1f", P->CODIGO, P->NOME, P->PRECO, P->TCOMPRA, P->TCAIXA);
}

void DestruirProdutos(void *X)
{
    if(!X){
        printf("ERRO EM [%s]\n", __FUNCTION__);
        return;
    }

    Produtos *P = (Produtos *)X;

    free(P->NOME);
    free(P);
}

void LerProdutos(ListaGenerica *LP, char *ficheiro)
{
    if(!LP || !ficheiro){
        printf("ERRO EM [%s]", __FUNCTION__);
        return;
    }

    FILE *F = fopen(ficheiro, "r");
    if (!F) return;

    char BUFFER[1001];

    while (!feof(F))
    {
        fgets(BUFFER, 1000, F);

        int CODIGO;
        float PRECO;
        float TCOMPRA;
        float TCAIXA;
        int i = 0;

        char *CAMPOS[5];
        char *token = strtok(BUFFER, "\t");
        while(token != NULL)
        {
            CAMPOS[i] = token;
            token = strtok(NULL, "\t");
            i++;
        }

        CODIGO = atoi(CAMPOS[0]);
        PRECO = atof(CAMPOS[2]);
        TCOMPRA = atof(CAMPOS[3]);
        TCAIXA = atof(CAMPOS[4]);

        Produtos *P = CriarProdutos(CODIGO, CAMPOS[1], PRECO, TCOMPRA, TCAIXA);
        AddLG(LP, P);

        P->NEL++;

    }
    fclose(F);
}

STRING *Read_Split_Line_File(FILE *f, int n_campos_max, int *n_campos_lidos, char *separadores)
{
    *n_campos_lidos = 0;
    if (!f) return NULL;
    if (fgets(LT , MAX_LINHA_FICHEIRO , f) != NULL)
    {

        STRING *Res = (STRING *)malloc(n_campos_max*sizeof(STRING));
        char *pch = strtok (LT, separadores);
        int cont = 0;
        while (pch != NULL)
        {
            Res[cont] = (char *)malloc((strlen(pch)+1)*sizeof(char));
            strcpy(Res[cont++], pch);
            pch = strtok (NULL, separadores);
        }
        *n_campos_lidos = cont;
        return Res;
    }
    return NULL;
};

int ler_Prod(Produtos *vetor, int tam)
{
    int n_campos_max = 5;
    int n_campos_lidos;
    int n_linhas_lidas = 0;
    int i;
    int n=0;

    FILE *F1 = fopen("produtos.txt","r");
    if (!F1)
	{
        printf("\n\n\tImpossivel abrir Ficheiro \n\n");
        return -1;
    }

    fgets(LT , MAX_LINHA_FICHEIRO , F1);

while(!feof(F1))
    {
        STRING *V = Read_Split_Line_File(F1, n_campos_max, &n_campos_lidos, "\t");

		vetor[n].CODIGO = atoi(V[0]);
		strcpy(vetor[n].NOME ,V[1]);
		vetor[n].PRECO = atof(V[2]);
		vetor[n].TCOMPRA = atof(V[3]);
		vetor[n].TCAIXA = atof(V[4]);

		n++;

        for (i = 0; i < n_campos_lidos; i++)
            free (V[i]);
        free (V);
    }
	    fclose(F1);
}
