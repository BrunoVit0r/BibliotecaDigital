#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

p_livro v[MAX]; // Definição da variável v

void inicializa(){
    for (int i = 0; i < MAX; i++) {
        v[i] = NULL;
    }
}

// Cadastrar um livro
void cadastro_livro(int i) {
    if (v[i] == NULL) {
        v[i] = (p_livro) malloc(sizeof(livro));

        printf("Digite o titulo do livro: \n");
        fgets(v[i]->titulo, sizeof(v[i]->titulo), stdin);

        printf("Digite o autor: \n");
        fgets(v[i]->autor, sizeof(v[i]->autor), stdin);

        printf("Digite o Genero: \n");
        fgets(v[i]->genero, sizeof(v[i]->genero), stdin);

        printf("Digite o Ano de Publicacao: \n");
        scanf("%d", &v[i]->anoPublicacao);
        getchar(); // Limpar o caractere de nova linha pendente no buffer

        printf("Digite o ISBN: \n");
        fgets(v[i]->isbn, sizeof(v[i]->isbn), stdin);

        FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "w");

        if (arquivo) {
            fprintf(arquivo, "ID: %d\n", i+1);
            fprintf(arquivo, "Titulo: %s", v[i]->titulo);
            fprintf(arquivo, "Autor:  %s", v[i]->autor);
            fprintf(arquivo, "Genero:  %s", v[i]->genero);
            fprintf(arquivo, "Ano de Publicacao:  %d\n", v[i]->anoPublicacao);
            fprintf(arquivo, "ISBN:  %s", v[i]->isbn);
            fprintf(arquivo, "--------------------\n\n");
        } else {
            printf("\n Deu erro ao abrir o arquivo! \n");
        }
        fclose(arquivo);
    } else {
        printf("\n Livro ja cadastrado na posicao %d! \n", i);
    }
}

// Consulta específica das informações de um livro
void consultarUmLivro(int id) {
    FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "r");

    if (arquivo) {
        // Verificar se o ID está dentro do intervalo válido
        if (id < 0 || id >= MAX) {
            printf("ID inválido. Por favor, insira um ID entre 0 e %d.\n", MAX - 1);
            fclose(arquivo);
            return;
        }

        // Procurar o livro com o ID especificado
        int idArquivo;
        int idEncontrado = 0;
        char buffer[256];

        while (fgets(buffer, sizeof(buffer), arquivo)) {
            if (sscanf(buffer, "ID: %d", &idArquivo) == 1) {
                if (idArquivo == id + 1) {  // Ajustar para índice de vetor
                    idEncontrado = 1;

                    if (v[id] == NULL) {
                        v[id] = (p_livro) malloc(sizeof(livro));
                    }

                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Titulo: %[^\n]", v[id]->titulo);
                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Autor: %[^\n]", v[id]->autor);
                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Genero: %[^\n]", v[id]->genero);
                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Ano de Publicacao: %d", &v[id]->anoPublicacao);
                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "ISBN: %[^\n]", v[id]->isbn);

                    // Imprimir as informações do livro
                    printf("ID: %d\n", id + 1);
                    printf("Titulo: %s\n", v[id]->titulo);
                    printf("Autor: %s\n", v[id]->autor);
                    printf("Genero: %s\n", v[id]->genero);
                    printf("Ano de Publicacao: %d\n", v[id]->anoPublicacao);
                    printf("ISBN: %s\n", v[id]->isbn);
                    printf("\n");

                    break;
                }
                    // Pular as linhas correspondentes aos dados do livro se o ID não corresponde
                    fgets(buffer, sizeof(buffer), arquivo); // Título
                    fgets(buffer, sizeof(buffer), arquivo); // Autor
                    fgets(buffer, sizeof(buffer), arquivo); // Gênero
                    fgets(buffer, sizeof(buffer), arquivo); // Ano de Publicação
                    fgets(buffer, sizeof(buffer), arquivo); // ISBN
                    fgets(buffer, sizeof(buffer), arquivo); // Linha separadora
            }
        }

        if (!idEncontrado) {
            printf("Nenhum livro encontrado com o ID %d. Por favor, cadastre um novo livro.\n", id + 1);
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

// Lista todos os livros
void listarLivro(int i){
    int encontrado = 0; // Variável para controlar se um livro foi encontrado

    for (int j = 0; j < i; j++) {
        if (v[j] != NULL) {
            printf("ID: %d\n", j+1);
            printf("Titulo: %s", v[j]->titulo);
            printf("Autor: %s", v[j]->autor);
            printf("Genero: %s", v[j]->genero);
            printf("Ano de Publicacao: %d\n", v[j]->anoPublicacao);
            printf("ISBN: %s\n", v[j]->isbn);
            printf("\n");

            encontrado = 1; // Um livro foi encontrado
        }
    }

    if (!encontrado) {
        printf("O livro nao foi encontrado.\n\n");
    }
}

void removerLivro(int i) {

}