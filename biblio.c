#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pessoa_P P; // Definicao de variavel P

p_livro v[MAX]; // Definicao da variavel v

void inicializa(){
    for (int i = 0; i < MAX; i++) {
        v[i] = NULL;
    }
}

void login(){
    char login[30];
    char senha[30];

    // Alocação de memória para a pessoa
    P[0] = (pessoa *)malloc(sizeof(pessoa));

    // Armazenar string dentro do vetor
    strcpy(P[0]->login, "eduardo"); // Usuario e senha pré cadastrados
    strcpy(P[0]->senha, "1234");
    do {
        printf("Login:\n");
        scanf("%s", login);
        getchar();
        printf("Senha:\n");
        scanf("%s", senha);
        getchar();

        // Verificação para efetuar login
        if (strcmp(login, P[0]->login) == 0 && strcmp(senha, P[0]->senha) == 0) {
            printf("Usuario Logado\n");
            break;
        } else {
            printf("Login e/ou senha incorretos\n");
        }
    }while(1);
    // Liberação da memória
    free(P[0]);
}

// Cadastrar um livro
void cadastro_livro(int i) {
    // int disponivel = 0;
    // disponivel = 1 esta reservado
    if (v[i] == NULL) {
        v[i] = (p_livro) malloc(sizeof(livro));

        printf("Digite o ID do livro: \n");
        scanf("%d", &v[i]->idLivro);
        getchar(); // Limpar o caractere de nova linha pendente no buffer

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

        FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "a");

        if (arquivo) {
            fprintf(arquivo, "ID: %d\n", v[i]->idLivro);
            fprintf(arquivo, "Titulo: %s", v[i]->titulo);
            fprintf(arquivo, "Autor:  %s", v[i]->autor);
            fprintf(arquivo, "Genero:  %s", v[i]->genero);
            fprintf(arquivo, "Ano de Publicacao:  %d\n", v[i]->anoPublicacao);
            fprintf(arquivo, "ISBN:  %s", v[i]->isbn);
            fprintf(arquivo, "--------------------\n\n");
        } else {
            printf("\n Erro ao abrir o arquivo! \n");
        }
        fclose(arquivo);
    } else {
        printf("\n Livro ja cadastrado na posicao %d! \n", i);
    }
}

// Consulta especifica das informacoes de um livro
void consultarUmLivro(int id) {
    FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "r");

    if (arquivo) {
        // Verificar se o ID esta dentro do intervalo valido
        if (id < 0 || id >= MAX) {
            printf("ID invalido. Por favor, insira um ID entre 0 e %d.\n", MAX - 1);
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

                    // Imprimir as informacoes do livro
                    printf("ID: %d\n", id + 1);
                    printf("Titulo: %s\n", v[id]->titulo);
                    printf("Autor: %s\n", v[id]->autor);
                    printf("Genero: %s\n", v[id]->genero);
                    printf("Ano de Publicacao: %d\n", v[id]->anoPublicacao);
                    printf("ISBN: %s\n", v[id]->isbn);
                    printf("\n");
                    break;
                }
                    // Pular as linhas correspondentes aos dados do livro se o ID nao corresponde
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
    FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo. Tente novamente.\n");
        return;
    }

    char buffer[1000]; // Buffer para armazenar temporariamente linhas do arquivo

    while (fgets(buffer, sizeof(buffer), arquivo) != NULL) {
        printf("%s", buffer);
    }

    fclose(arquivo);
}

// Conectar o login da pessoa com o livro ID que ela escolheu
// Emprestimo de livro (reserva) e Informar data de devolucao para a pessoa

void removerLivro(int i) {

}