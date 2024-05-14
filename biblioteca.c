// Created by Bruno Vitor on 13/05/2024.
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

void inicializa(){
    for (int i = 0; i < MAX; i++) {
        v[i] = NULL;
    }
};

// Cadastrar um livro
void cadastroLivro(int i){
    if (v[i] == NULL) {
        v[i] = (p_livro) malloc(sizeof(livro));
        fflush(stdin);

        printf("Digite o titulo do livro: \n");
        gets(v[i]->titulo);

        printf("Digite o autor: \n");
        gets(v[i]->autor);
        fflush(stdin);

        printf("Digite o Genero: \n");
        gets(v[i]->genero);
        fflush(stdin);

        printf("Digite o Ano de Publicacao: \n");
        scanf("%d", &v[i]->anoPublicacao);
        fflush(stdin);

        printf("Digite o ISBN: \n");
        gets(v[i]->isbn);
    }
};

// Consulta expecifica das informacoes de um livro
void consultarUmLivro(int i){
    if( v[i] != NULL){
        printf("Titulo:              %s \n", v[i]->titulo);
        printf("Autor:               %s \n", v[i]->autor);
        printf("Genero:              %s \n", v[i]->genero);
        printf("Ano de Publicacao:   %d \n", v[i]->anoPublicacao);
        printf("ISBN:                %s \n", v[i]->isbn);
        printf("\n");
    }
};

// Lista todos os livros
void listarLivro(int i){
    for (int i = 0; i < MAX; i++) {
        listarLivro(i);
    }
};





