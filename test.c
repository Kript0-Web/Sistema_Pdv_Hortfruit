#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define ARQUIVO "produtos.txt"

// Estrutura para armazenar as informações de um produto
struct Produto {
    int id;               // ID do produto (posição no estoque)
    char nome[50];        // Nome do produto
    float preco;          // Preço do produto
    int quantidade;       // Quantidade no estoque
};

// Função para salvar os produtos no arquivo
void salvarProdutos(struct Produto produtos[], int contador) {
    FILE *file = fopen(ARQUIVO, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve todos os produtos no arquivo
    for (int i = 0; i < contador; i++) {
        fprintf(file, "ID:%d | Nome:%s | Preco: R$%.2f | Quantidade:%d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }

    fclose(file);
}

// Função para carregar os produtos do arquivo
int carregarProdutos(struct Produto produtos[]) {
    FILE *file = fopen(ARQUIVO, "r");
    if (file == NULL) {
        printf("Arquivo não encontrado. Criando um novo...\n");
        return 0;
    }

    int contador = 0;
    // Carrega os produtos do arquivo
    while (fscanf(file, "%d %49s %f %d", &produtos[contador].id, produtos[contador].nome,
                  &produtos[contador].preco, &produtos[contador].quantidade) != EOF) {
        contador++;
    }

    fclose(file);
    return contador;
}

// Função para cadastrar um novo produto
void cadastrarProduto(struct Produto produtos[], int *contador) {
    if (*contador >= MAX_PRODUTOS) {
        printf("Limite de produtos cadastrados atingido.\n");
        return;
    }

    struct Produto novoProduto;

    novoProduto.id = *contador + 1; // Define a posição no estoque com base no contador atual
    printf("Nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Preço do produto: ");
    scanf("%f", &novoProduto.preco);
    printf("Quantidade no estoque: ");
    scanf("%d", &novoProduto.quantidade);

    // Adiciona o novo produto ao array
    produtos[*contador] = novoProduto;
    (*contador)++;

    printf("Produto cadastrado com sucesso! ID do produto: %d\n\n", novoProduto.id);

    // Salva os produtos no arquivo
    salvarProdutos(produtos, *contador);
}

// Função para listar todos os produtos cadastrados
void listarProdutos(struct Produto produtos[], int contador) {
    if (contador == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de produtos cadastrados:\n");
    for (int i = 0; i < contador; i++) {
        printf("ID: %d | Nome: %s | Preço: R$ %.2f | Quantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

int main() {
    struct Produto produtos[MAX_PRODUTOS]; // Array para armazenar os produtos
    int contador = 0;  // Contador de produtos cadastrados
    int opcao;

    // Carregar os produtos do arquivo
    contador = carregarProdutos(produtos);

    do {
        printf("\n--- Menu ---\n");
        printf("1. Cadastrar produto\n");
        printf("2. Listar produtos\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &contador);
                break;
            case 2:
                listarProdutos(produtos, contador);
                break;
            case 3:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}
