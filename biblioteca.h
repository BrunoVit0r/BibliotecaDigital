// Created by Bruno Vitor on 13/05/2024.
#include <stdio.h>
#include <stdlib.h>

#define MAX 999

typedef struct {
    int idLivro;  // Identificador único para o livro
    char titulo[100];  // Título do livro
    char autor[100];  // Autor do livro
    char genero[50];  // Gênero literário do livro
    int anoPublicacao;  // Ano de publicação do livro
    char isbn[20];  // ISBN do livro
} Livro;

typedef Livro *p_livro;

extern p_livro v[MAX];

void inicializa();

void cadastroLivro(int i); // Cadastrar um livro

void consultarUmLivro(int i); // Consulta expecifica das informacoes de um livro

void listarLivro(int i); // Lista todos os livros

void removerLivro(int i); // Remover um livro do cadastro



