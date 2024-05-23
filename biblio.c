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
            fprintf(arquivo, "Titulo: %s", v[i]->titulo);
            fprintf(arquivo, "Autor: %s", v[i]->autor);
            fprintf(arquivo, "Genero: %s", v[i]->genero);
            fprintf(arquivo, "Ano de Publicacao: %d\n", v[i]->anoPublicacao);
            fprintf(arquivo, "ISBN: %s\n", v[i]->isbn);
        } else {
            printf("\n Deu erro ao abrir o arquivo! \n");
        }
        fclose(arquivo);
    } else {
        printf("\n Livro já cadastrado na posição %d! \n", i);
    }
}


// Consulta expecifica das informacoes de um livro
void consultarUmLivro(int i){
    if( v[i] != NULL){
        printf("Titulo:              %s \n", v[i]->titulo);
        printf("Autor:               %s \n", v[i]->autor);
        printf("Genero:              %s \n", v[i]->genero);
        printf("Ano de Publicacao:   %d \n", v[i]->anoPublicacao);
        printf("ISBN:                %s \n", v[i]->isbn);
        printf("\n");
    } else {
        printf("Por favor, cadastre um novo livro. \n");
    }
}

// Lista todos os livros
void listarLivro(int i){
    int encontrado = 0; // Variável para controlar se um livro foi encontrado

    for (int j = 0; j < i; j++) {
        if (v[j] != NULL) {
            printf("Livro %d: \n", j+1);
            printf("Titulo: %s\n", v[j]->titulo);
            printf("Autor: %s\n", v[j]->autor);
            printf("Genero: %s\n", v[j]->genero);
            printf("Ano de Publicacao: %d\n", v[j]->anoPublicacao);
            printf("ISBN: %s\n", v[j]->isbn);
            printf("\n");

            encontrado = 1; // Um livro foi encontrado
        }
    }

    if (!encontrado) {
        printf("O livro não foi encontrado.\n");
    }
}

void removerLivro(int i) {

}