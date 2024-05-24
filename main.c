#include <stdio.h>
#include "biblio.h"

int main() {
    int i = 0;
    int opcao = 0;
    inicializa();

    do{
        int id = 0;
        printf("\n");
        printf("============== \n");
        printf("Menu Principal \n");
        printf("============== \n");
        printf("1. Cadastrar novo livro: \n");
        printf("2. Consultar um livro \n");
        printf("3. Consultar todos os livros \n");
        printf("9. Sair do programa \n");
        printf("Digite sua opcao: \n");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastro_livro(i);
                printf("Aperte um botao para continuar \n");
                i++;
                getchar();
                break;
            case 2:
                printf("Digite o ID do livro para consultar \n");
                scanf("%d", &id);
                getchar(); // Limpar o caractere de nova linha pendente no buffer
                consultarUmLivro(id - 1);
                printf("Aperte um botao para continuar \n");
                getchar();
                break;
            case 3:
                printf("Lista com todos os livros \n");
                listarLivro(i);
                printf("Aperte um botao para continuar \n");
                getchar();
                break;
            case 9:
                printf("Fim \n");
                break;
            default:
                printf("Opcao Invalida \n");
        }
    } while (opcao != 9);
    return 0;
}