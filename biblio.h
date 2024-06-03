/**
 * @authors Brenda Gaudêncio, Bruno Vitor, Eduardo Faria, Guilherme Nogueira
 * @date 03/05/2024
 */
#define MAX 999

/**
 * Definição de estrutura para informações de login
 */
typedef struct {
    char login[30];
    char senha[30];
}pessoa;

/**
 * Definicao de ponteiro para struct pessoa
 */
typedef pessoa *pessoa_P[1];
/**
 * Exportando o ponteiro de struct pessoa
 */
extern pessoa_P P;

/**
 * Definição de estrutura para cadastrar as informações do livro
 */
typedef struct Livro {
    int idLivro;  // Identificador unico para o livro
    char titulo[100];  // Titulo do livro
    char autor[100];  // Autor do livro
    char genero[50];  // Genero literario do livro
    int anoPublicacao;  // Ano de publicacao do livro
    char isbn[20];  // ISBN do livro
    int disponibilidade; // 0 = indisponivel, 1 = disponivel
    char data[12]; // Armazenamento de data atual e de devolução
}livro;

/**
 * Definicao de ponteiro para struct livro
 */
typedef livro *p_livro;

/**
 * Exportando o ponteiro de struct livro
 */
extern p_livro v[MAX];

/**
 * Inicializar a aplicação
 */
void inicializa();

/**
 * Login do usuário
 */
void login();

/**
 * Cadastrar livro
 */
void cadastro_livro(int i); // Cadastrar um livro

/**
 * Consulta especifica das informaçôes de um livro
 */
void consultarUmLivro(int id); // Consulta expecifica das informacoes de um livro

/**
 * Listar todos os livros
 */
void listarLivro(int i); // Lista todos os livros

/**
 * Emprestimo de livros (reserva)
 */
void emprestimo(); // Reservar um livro para o usuario

/**
 * Devolução de livro
 */
void devolver(int id); // Devolucao de livros

/**
 * Remover um livro da base de dados
 */
void removerLivro(int i); // Remover um livro do cadastro

