#include <stdio.h>
#include "definitions.h"

//Registra novos produto em um arquivo txt == inventory.txt
void registerProduct(Product *product) {
    FILE *file = fopen("inventory.txt", "a+");  //Abre o arquivo no modo editor
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de inventário");
        return;
    }
    //Grava o produto em um formato padronizado: nome; preco custo; preco venda; quantidade
    fprintf(file, "%s %.2f %.2f %d\n", product->productName, product->costPrice, product->sellingPrice, product->quantity);
    fclose(file);
}

//Gera um relatório do estoque de produtos
void generateStockReport() {
    FILE *file = fopen("inventory.txt", "r");  //Abre o arquivo em modo leitor
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de inventário");
        return;
    }
    Product product;
    //Mostra o cabeçalho do relatório
    printf("Produto\tPreço de Custo\tPreço de Venda\tQuantidade\n");
    //Lê os produtos e retorna suas informações
    while (fscanf(file, "%s %f %f %d", product.productName, &product.costPrice, &product.sellingPrice, &product.quantity) != EOF) {
        printf("%s\t%.2f\t\t%.2f\t\t%d\n", product.productName, product.costPrice, product.sellingPrice, product.quantity);
    }
    fclose(file);
}
