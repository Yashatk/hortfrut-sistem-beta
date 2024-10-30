#ifndef DEFINITIONS_H
#define DEFINITIONS_H

//Constantes que definem o tamanho máximo do nome e da senha
#define MAX_NAME_LEN 100
#define MAX_PASSWORD_LEN 15

//Armazenamento dos dados de usuário
typedef struct {
    char username[MAX_NAME_LEN];        // Nome de usuário
    char password[MAX_PASSWORD_LEN];    // Senha
    int accessLevel;                    // Nível de acesso: 0 para operador, 1 para administrador
} User;

//Armazenamento das informações de produto
typedef struct {
    char productName[MAX_NAME_LEN]; // Nome do produto
    float costPrice;                // Preço de custo
    float sellingPrice;             // Preço de venda
    int quantity;                   // Quantidade em estoque
} Product;

#endif
