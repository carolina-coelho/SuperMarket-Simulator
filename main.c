#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Produtos.h"
#include "Funcionarios.h"
#include "ListaGenerica.h"

#include "Uteis.h"

int main()
{

//    ListaGenerica *LC = CriarLG();
//    LerClientes(LC, "clientes.txt");
//    ShowLG(LC, MostrarCliente);

//    ListaGenerica *LP = CriarLG();
//    LerProdutos(LP, "produtos.txt");
//    ShowLG(LP, MostrarProdutos);

    ListaGenerica *LF = CriarLG();
    LerFuncionarios(LF, "funcionarios.txt");
    ShowLG(LF, MostrarFuncionarios);

//    DestruirLG(LC, DestruirCliente);
//    DestruirLG(LP, DestruirProdutos);
    DestruirLG(LF, DestruirFuncionarios);
}
