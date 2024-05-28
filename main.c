#include <stdio.h>
#include "biblio.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 0;
    int opcao = 0;
    inicializa();
    //login();

    do{
        int id = 0;
        printf("\n");
        printf("============== \n");
        printf("Menu Principal \n");
        printf("============== \n");
        printf("1. Cadastrar novo livro: \n");
        printf("2. Consultar um livro \n");
        printf("3. Consultar todos os livros \n");
        printf("4. Emprestimo de livros \n");
        printf("5. Devolucao de livros \n");
        printf("9. Sair do programa \n");
        printf("Digite sua opcao: \n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("===================================== \n");
                printf("   Cadastrar um novo livro \n");
                printf("===================================== \n");
                cadastro_livro(i);
                printf("Livro Cadastrado com Sucesso! Aperte um botao para continuar. \n");
                i++;
                getchar();
                break;
            case 2:
                printf("=========================================== \n");
                printf("   Digite o ID do livro para consultar \n");
                printf("=========================================== \n");
                printf("ID: ");
                scanf("%d", &id);
                printf("\n");
                getchar(); // Limpar o caractere de nova linha pendente no buffer
                consultarUmLivro(id - 1);
                printf("Aperte um botao para continuar. \n");
                getchar();
                break;
            case 3:
                printf("===================================== \n");
                printf("    Lista com todos os livros \n");
                printf("===================================== \n");
                listarLivro(i);
                printf("Aperte um botao para continuar. \n");
                getchar();
                break;
            case 4:
                printf("===================================== \n");
                printf("    Emprestimo de livros \n");
                printf("===================================== \n");
                printf("ID: ");
                scanf("%d", &id);
                printf("\n");
                getchar(); // Limpar o caractere de nova linha pendente no buffer
                emprestimo(id);
                printf("Aperte um botao para continuar. \n");
                getchar();
                break;
            case 5:
                printf("===================================== \n");
                printf("    Devolucao de livros \n");
                printf("===================================== \n");
                printf("ID: ");
                scanf("%d", &id);
                printf("\n");
                getchar(); // Limpar o caractere de nova linha pendente no buffer
                devolver(id);
            printf("Aperte um botao para continuar. \n");
            getchar();
            break;
            case 9:
                printf("Fim. \n");
                break;
            default:
                printf("Opcao Invalida. \n");
        }
    } while (opcao != 9);
    return 0;
}