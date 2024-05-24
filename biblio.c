#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>

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

        FILE *arquivo;
        arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "a");
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


// Consulta expecifica das informacoes de um livro
void consultarUmLivro(int id){
    // Verificar se o ID está dentro do intervalo válido
    if (id < 0 || id >= MAX) {
        printf("ID invalido. Por favor, insira um ID entre 0 e %d.\n", MAX - 1);
        return;
    }

    if (v[id] != NULL) {
        printf("ID: %d\n", id + 1);
        printf("Titulo: %s", v[id]->titulo);
        printf("Autor: %s", v[id]->autor);
        printf("Genero: %s", v[id]->genero);
        printf("Ano de Publicacao: %d\n", v[id]->anoPublicacao);
        printf("ISBN: %s\n", v[id]->isbn);
        printf("\n");
    } else {
        printf("Nenhum livro encontrado com o ID %d. Por favor, cadastre um novo livro.\n", id + 1);
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