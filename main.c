#include <stdio.h>
#include <string.h>
#include "definitions.h"
#include "user_management.c"
#include "inventory_management.c"
#include "sales_management.c"

//Exibe o menu principal
void mainMenu() {
    printf("1. Registrar Produto\n2. Gerar Relatório de Estoque\n3. Registrar Venda\n4. Calcular Lucro\n5. Sair\n");
}

int main() {
    char username[MAX_NAME_LEN], password[MAX_PASSWORD_LEN];
    User user;

    //Pede as credenciais do usuário
    printf("Nome de usuário: ");
    scanf("%s", username);
    printf("Senha: ");
    scanf("%s", password);

    //Autentica o usuário e determina o nível de acesso do mesmo
    int accessLevel = authenticate(username, password, &user);
    if (accessLevel == -1) {
        printf("Login inválido.\n");
        return 0;
    }

    int choice;
    while (1) {
        mainMenu(); //Exibe o menu do usuário logado
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                //Apenas o administrador pode registrar produtos
                if (accessLevel == 1) {
                    Product product;
                    printf("Nome do Produto: ");
                    scanf("%s", product.productName);
                    printf("Preço de Custo: ");
                    scanf("%f", &product.costPrice);
                    printf("Preço de Venda: ");
                    scanf("%f", &product.sellingPrice);
                    printf("Quantidade: ");
                    scanf("%d", &product.quantity);
                    registerProduct(&product);
                } else {
                    printf("Acesso negado.\n");
                }
                break;
            case 2:
                generateStockReport();  //Gera o relatório de estoque
                break;
            case 3:
                //Adiciona lógica para registrar venda
                break;
            case 4:
                calculateProfit();  //Calcula o lucro total
                break;
            case 5:
                return 0;  //Encerra o programa
            default:
                printf("Opção inválida.\n");
        }
    }
}
