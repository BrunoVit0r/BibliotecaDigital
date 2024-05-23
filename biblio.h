#define MAX 999

typedef struct Livro {
    int idLivro;  // Identificador unico para o livro
    char titulo[100];  // Titulo do livro
    char autor[100];  // Autor do livro
    char genero[50];  // Genero literario do livro
    int anoPublicacao;  // Ano de publicacao do livro
    char isbn[20];  // ISBN do livro
}livro;

typedef livro *p_livro;

extern p_livro v[MAX];

void inicializa();

void cadastro_livro(int i); // Cadastrar um livro

void consultarUmLivro(int i); // Consulta expecifica das informacoes de um livro

void listarLivro(int i); // Lista todos os livros

void removerLivro(int i); // Remover um livro do cadastro

