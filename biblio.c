#include "biblio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    strcpy(P[0]->login, "eduardo"); // Usuario e senha pre cadastrados
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
        }
            printf("Login e/ou senha incorretos\n");
    }while(1);
    // Liberação da memória
    free(P[0]);
}

// Cadastrar um livro
void cadastro_livro(int i) {

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

        printf("O livro esta disponivel? (1 para Sim, 0 para Nao): \n");
        scanf("%d", &v[i]->disponibilidade);

        FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "a");

        if (arquivo) {
            fprintf(arquivo, "ID: %d\n", v[i]->idLivro);
            fprintf(arquivo, "Titulo: %s", v[i]->titulo);
            fprintf(arquivo, "Autor:  %s", v[i]->autor);
            fprintf(arquivo, "Genero:  %s", v[i]->genero);
            fprintf(arquivo, "Ano de Publicacao:  %d\n", v[i]->anoPublicacao);
            fprintf(arquivo, "ISBN:  %s", v[i]->isbn);
            fprintf(arquivo, "Disponibilidade: %s\n", v[i]->disponibilidade ? "disponivel" : "indisponivel");
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

                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Disponibilidade: %d", &v[id]->disponibilidade);

                    // Imprimir as informacoes do livro
                    printf("ID: %d\n", id + 1);
                    printf("Titulo: %s\n", v[id]->titulo);
                    printf("Autor: %s\n", v[id]->autor);
                    printf("Genero: %s\n", v[id]->genero);
                    printf("Ano de Publicacao: %d\n", v[id]->anoPublicacao);
                    printf("ISBN: %s\n", v[id]->isbn);
                    printf("Disponibilidade: %s\n", v[id]->disponibilidade ? "Disponivel" : "Indisponivel");
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
                    fgets(buffer, sizeof(buffer), arquivo); // Para disponibilidade
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

// Listar todos os livros
void listarLivro(int i) {
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

// Emprestimo de livros (reserva)
void emprestimo(int id) {
    FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "r+");
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
        char dataAtual[12];
        char dataDevolucao[12];

        // Calcular a data atual
        time_t p = time(NULL);
        struct tm p_tm = *localtime(&p);
        sprintf(dataAtual, "%02d/%02d/%04d", p_tm.tm_mday, p_tm.tm_mon + 1, p_tm.tm_year + 1900);

        // Calcular a data de devolucao (14 dias apos a data atual)
        time_t t = time(NULL);
        t += 14 * 24 * 60 * 60; // Adiciona 14 dias em segundos
        struct tm tm = *localtime(&t);
        sprintf(dataDevolucao, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        long posicao = 0;  // Para armazenar a posição no arquivo

        while (fgets(buffer, sizeof(buffer), arquivo)) {
            if (sscanf(buffer, "ID: %d", &idArquivo) == 1) {
                if (idArquivo == id) {  // Ajustar para índice de vetor
                    idEncontrado = 1;

                    if (v[id] == NULL) {
                        v[id] = (p_livro) malloc(sizeof(livro));
                    }

                    // Ler as informações do livro
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

                    posicao = ftell(arquivo); // Guardar a posição antes de ler a disponibilidade

                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Disponibilidade: %d", &v[id]->disponibilidade);

                    // Verificar disponibilidade
                    if (v[id]->disponibilidade == 0) {
                        printf("O livro ja esta reservado.\n");
                        break;
                    }

                    if (v[id]->disponibilidade == 1) {
                        // Marcar o livro como indisponivel
                        v[id]->disponibilidade = 0;

                        // Voltar a posicao da disponibilidade e atualizar o status
                        fseek(arquivo, posicao, SEEK_SET);
                        fprintf(arquivo, "Disponibilidade: %d\n", v[id]->disponibilidade);
                        fseek(arquivo, 0, SEEK_END);

                        printf("Livro emprestado com sucesso em %s\n", dataAtual);
                        printf("Data de Devolucao do livro: %s\n", dataDevolucao);
                        printf("\n");
                    }
                    break;
                }
            }
        }

        if (!idEncontrado) {
            printf("Nenhum livro encontrado com o ID %d. Por favor, cadastre um novo livro.\n", id);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}


void devolver(int id) {
FILE *arquivo = fopen("C:\\BibliotecaDigital\\bd\\clientes_cadastrados.txt", "r+");
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
        char dataDevolucao[12];

        // Calcular a data de devolucao (14 dias apos a data atual)
        time_t t = time(NULL);
        t += 14 * 24 * 60 * 60; // Adiciona 14 dias em segundos
        struct tm tm = *localtime(&t);
        sprintf(dataDevolucao, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        long posicao = 0;  // Para armazenar a posição no arquivo

        while (fgets(buffer, sizeof(buffer), arquivo)) {
            if (sscanf(buffer, "ID: %d", &idArquivo) == 1) {
                if (idArquivo == id) {  // Ajustar para indice de vetor
                    idEncontrado = 1;

                    if (v[id] == NULL) {
                        v[id] = (p_livro) malloc(sizeof(livro));
                    }

                    // Ler as informações do livro
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

                    posicao = ftell(arquivo); // Guardar a posição antes de ler a disponibilidade

                    fgets(buffer, sizeof(buffer), arquivo);
                    sscanf(buffer, "Disponibilidade: %d", &v[id]->disponibilidade);

                    // Verificar disponibilidade
                    if (v[id]->disponibilidade) {
                        // Marcar o livro como disponível
                        v[id]->disponibilidade = 1;

                        // Voltar a posicao da disponibilidade e atualizar o status
                        fseek(arquivo, posicao, SEEK_SET);
                        fprintf(arquivo, "Disponibilidade: %s\n", v[id]->disponibilidade ? "disponivel" : "indisponivel");
                        fseek(arquivo, 0, SEEK_END);

                        printf("Livro devolvido com sucesso em %s\n", dataDevolucao);
                    } else {
                        printf("O livro esta indisponivel.\n");
                    }
                    break;
                }
            }
        }

        if (!idEncontrado) {
            printf("Nenhum livro encontrado com o ID %d. Por favor, cadastre um novo livro.\n", id);
        }
        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

void removerLivro(int i) {

}