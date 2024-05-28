
#define MAX 999

typedef struct {
    char login[30];
    char senha[30];
}pessoa;

typedef pessoa *pessoa_P[1];
extern pessoa_P P;

typedef struct Livro {
    int idLivro;  // Identificador unico para o livro
    char titulo[100];  // Titulo do livro
    char autor[100];  // Autor do livro
    char genero[50];  // Genero literario do livro
    int anoPublicacao;  // Ano de publicacao do livro
    char isbn[20];  // ISBN do livro
    int disponibilidade; // 0 = indisponivel, 1 = disponivel
    char data[12];
}livro;

typedef livro *p_livro;

extern p_livro v[MAX];

void inicializa();

void login();

void cadastro_livro(int i); // Cadastrar um livro

void consultarUmLivro(int id); // Consulta expecifica das informacoes de um livro

void listarLivro(int i); // Lista todos os livros

void emprestimo(); // Reservar um livro para o usuario

void devolver(int id); // Devolucao de livros

void removerLivro(int i); // Remover um livro do cadastro

