#include <stdio.h> // para usar printf e scanf
#include <stdlib.h> // funções utilitárias, como alocação de memória
#include <string.h> // para manipulação de strings, como comparação

typedef struct { // estrutura de cadastro
    char nome[50];
    char senha[50]; // Alterado para string
    int id;
} Usuario;

// Função para login de primeiro acesso
int fazerLogin() {
    char usuario[50];
    char senhaAdmin[50];

    // Login do admin no primeiro acesso 
    printf("Digite o nome do usuário: ");
    scanf("%s", usuario); // Corrigido para %s (sem &)
    printf("Digite a senha do usuário: ");
    scanf("%s", senhaAdmin); // Corrigido para %s (sem &)

    // Validando o login "admin" "admin"
    if (strcmp(usuario, "admin") == 0 && strcmp(senhaAdmin, "admin") == 0) {
        return 1; // Login bem-sucedido
    } else {
        printf("Login falhou! Login ou senha incorretos.\n"); // Corrigido para printf
        return 0; // Falha no login
    }
}

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
    scanf("%s", usuario.senha); // Corrigido para %s (agora uma string)

    // Salvando as informações no arquivo txt
    fprintf(arquivo, "%d %s %s\n", usuario.id, usuario.nome, usuario.senha); // Alterado para %s
    fclose(arquivo);

    printf("Cadastro salvo com sucesso!\n");
}

int verificarUsuario(char *nome, char *senha) {
    FILE *arquivo = fopen("Usuario.txt", "r"); // abrir o arquivo para leitura
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    Usuario usuario;
    // Lê o arquivo linha por linha
    while (fscanf(arquivo, "%d %s %s", &usuario.id, usuario.nome, usuario.senha) != EOF) {
        // Verifica se o usuário e a senha correspondem
        if (strcmp(usuario.nome, nome) == 0 && strcmp(usuario.senha, senha) == 0) {
            fclose(arquivo);
            return 1; // Usuário encontrado
        }
    }
    fclose(arquivo);
    return 0; // Usuário não encontrado
}

int main() {
    // Tentar fazer login 
    if (!fazerLogin()) {
        return 1; // Encerra o programa se o login falhar
    }

    int opcaocadastrar; // variável para a opção de cadastro
    int opcaocadastrarprod; // variável para a opção de cadastro de produto
    int opcaovenda; // variável para a opção de venda

    // Loop para mostrar o menu até que o usuário escolha sair
    while (1) {
        // Menu de opções
        printf("Escolha uma das opções: \n");
        printf("1- Cadastrar usuário\n");
        printf("2- Cadastrar produto\n");
        printf("3- Venda\n");
        printf("4- Sair\n");
        scanf("%d", &opcaocadastrar); // Lê a opção do usuário

        // Estrutura switch para opções
        switch (opcaocadastrar) {
            case 1:
                cadastrarUsuario(); // Chamando a função de cadastrar usuário
                break;
            case 2:
                // Implementar a lógica de cadastro de produto
                printf("Função de cadastro de produto ainda não implementada.\n");
                break;
            case 3:
                // Implementar a lógica de venda
                printf("Função de venda ainda não implementada.\n");
                break;
            case 4:
                printf("Saindo do sistema...\n");
                return 0; // Encerra o programa
            default:
                printf("Opção inválida! Tente novamente.\n"); // Tratamento de opção inválida
                break;
        }
    }
}
