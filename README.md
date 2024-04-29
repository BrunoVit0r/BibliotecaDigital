# Biblioteca Digital

## Requisitos Detalhados:

- **Estrutura de Dados para Livros:**
Crie uma estrutura `Livro` que armazene informações essenciais sobre cada livro na biblioteca:

```c
typedef struct {
    int idLivro;  // Identificador único para o livro
    char titulo[100];  // Título do livro
    char autor[100];  // Autor do livro
    char genero[50];  // Gênero literário do livro
    int anoPublicacao;  // Ano de publicação do livro
    char isbn[20];  // ISBN do livro
} Livro;

```

- **Cadastro de Livros:**
- **Cadastro de Livros:**
O programa deve permitir o cadastro de novos livros, coletando todas as informações necessárias e armazenando-as na estrutura **`Livro`**.
- **Remoção de Livros:**
Implemente uma funcionalidade que permita ao usuário remover livros do sistema, identificando-os pelo seu ID.
- **Consulta de Livros:**
Desenvolva uma função que permita ao usuário consultar informações detalhadas de um livro específico, utilizando seu ID para busca.
- **Listagem de Livros:**
O sistema deve ser capaz de listar todos os livros cadastrados, com opções para filtrar por autor, gênero ou ano de publicação.
- **Persistência de Dados:**
Todas as informações dos livros devem ser armazenadas em um arquivo, para garantir que os dados sejam preservados entre as sessões do programa.
- **Interface do Usuário:**
Desenvolva uma interface de linha de comando que facilite a interação com o sistema, permitindo realizar todas as operações de maneira simples e intuitiva.
- **Digrama de Caso de Uso:**
    
    Criar um Diagrama de Caso de Uso que represente todas as interações possíveis dos usuários com o sistema de biblioteca digital.
    
    ### Requisitos Adicionais:
    
    - **Documentação do Projeto:**
    Preparem uma documentação completa para o sistema de Biblioteca Digital. A documentação deve incluir:
        - **Parte Escrita:**
            - **Descrição Geral do Sistema:** Um resumo do propósito e das funcionalidades do sistema.
            - **Requisitos Funcionais:** Uma descrição detalhada de todas as funcionalidades e casos de uso implementados no sistema.
            - **Diagramas:** Incluir diagramas de caso de uso já desenvolvidos, diagramas de fluxo de dados e quaisquer outros diagramas relevantes que ajudem a visualizar a arquitetura e o fluxo do sistema.
            - **Guia do Usuário:** Instruções passo a passo sobre como usar o sistema, incluindo screenshots das interfaces de usuário.
            - **Seção de Problemas e Soluções:** Uma discussão sobre quaisquer desafios enfrentados durante o desenvolvimento e como foram resolvidos.
        - **Comentários no Código:**
            - **Código Fonte Comentado:** Todos os arquivos de código devem incluir comentários detalhados explicando a funcionalidade de blocos de código importantes e a lógica por trás de decisões de programação críticas.
            - **Funções e Módulos:** Cada função e módulo deve ter uma breve descrição de sua finalidade e de quaisquer parâmetros ou valores de retorno.
            - **Estruturas de Dados:** Comentários detalhados sobre as estruturas de dados usadas, explicando o motivo da escolha e como elas são utilizadas no sistema.
        
        Esta documentação deve ser entregue em formato digital, preferencialmente em PDF, e deve ser clara, concisa e bem organizada para facilitar a compreensão e a manutenção do sistema.
