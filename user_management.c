#include <stdio.h>
#include <string.h>
#include "definitions.h"

//Registra novos usuário em um arquivo txt == users.txt
void registerUser(User *user) {
    FILE *file = fopen("users.txt", "a+");  //Abre o arquivo no modo editor
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de usuários");
        return;
    }
    //Grava o usuário em um formato padronizado: nome; senha; nível de acesso
    fprintf(file, "%s %s %d\n", user->username, user->password, user->accessLevel);
    fclose(file);
}

//Autenticação do usuário verificando nome e senha
int authenticate(char *username, char *password, User *user) {
    FILE *file = fopen("users.txt", "r");  //Abre o arquivo em modo leitor
    if (file == NULL) {
        perror("Erro ao abrir o arquivo de usuários");
        return -1;
    }
    //Lê e faz comparação com o arquivo txt da senha para efetuar o login
    while (fscanf(file, "%s %s %d", user->username, user->password, &user->accessLevel) != EOF) {
        if (strcmp(username, user->username) == 0 && strcmp(password, user->password) == 0) {
            fclose(file);
            return user->accessLevel;  //Retorna o usuário a seu  nivel de acesso 
        }
    }
    fclose(file);
    return -1;
}
