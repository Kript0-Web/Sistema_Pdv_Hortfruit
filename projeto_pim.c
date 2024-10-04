#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { // estrutura de cadastro
    char nome[50];
    int senha;
    int id;
} Usuario;

void cadastrarUsuario() {
    FILE *arquivo = fopen("Usuario.txt", "a"); // abrir o arquivo para adicionar
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    Usuario usuario;

    // Coletando dados do usuário
    printf("Digite o Id do usuário: ");
    scanf("%d", &usuario.id); 

    printf("Digite o nome do usuário: ");
    scanf("%s", usuario.nome); 

    printf("Digite a senha do usuário: ");
    scanf("%d", &usuario.senha);

    // Salvando as informações no arquivo txt
    fprintf(arquivo, "%d %s %d\n", usuario.id, usuario.nome, usuario.senha);
    fclose(arquivo);

    printf("Cadastro salvo com sucesso!\n");
}

int main() {
    cadastrarUsuario();
    return 0;
}