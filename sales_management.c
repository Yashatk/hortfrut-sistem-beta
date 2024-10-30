#include <stdio.h>
#include "definitions.h"

//Registra a venda em um arquivo txt == sales.txt
void recordSale(char *productName, int quantitySold, float sellingPrice) {
    FILE *file = fopen("sales.txt", "a+");  // Abre o arquivo em modo de adição
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de vendas");
        return;
    }
    //Grava a venda em um formato padronizado: nome do produto; quantidade vendida; preco venda
    fprintf(file, "%s %d %.2f\n", productName, quantitySold, sellingPrice);
    fclose(file);
}

//Realiza o lucro total a partir dos arquivos de inventário e das vendas
void calculateProfit() {
    FILE *inventory = fopen("inventory.txt", "r");  //Abre o arquivo de inventário
    FILE *sales = fopen("sales.txt", "r");  //Abre o arquivo de vendas
    if (inventory == NULL || sales == NULL) {
        perror("Erro ao abrir arquivos");
        return;
    }

    float totalProfit = 0;  //Lucro total
    Product product;

    //Faz o retorno sobre cada produto no inventário
    while (fscanf(inventory, "%s %f %f %d", product.productName, &product.costPrice, &product.sellingPrice, &product.quantity) != EOF) {
        char saleProductName[MAX_NAME_LEN];
        int quantitySold;
        float sellingPrice;

        //Compara cada venda com o produto correspondente a mesma
        while (fscanf(sales, "%s %d %f", saleProductName, &quantitySold, &sellingPrice) != EOF) {
            if (strcmp(product.productName, saleProductName) == 0) {
                //Calcula o lucro da venda e adiciona ao total final
                totalProfit += (sellingPrice - product.costPrice) * quantitySold;
            }
        }
        rewind(sales);  //Reinicia o arquivo de vendas para o proximo produto
    }
    printf("Lucro Total: %.2f\n", totalProfit);

    fclose(inventory);
    fclose(sales);
}
