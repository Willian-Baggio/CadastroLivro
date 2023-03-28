# CadastroLivro
Este é um simples sistema de cadastro de livros em linguagem C, que permite ao usuário cadastrar, listar, buscar livros ou remove-los. No código foi feito um algoritmo de bolha para a ordenação das informações do livro e um algoritmo de busca sequencial binária que permite o retorno das informações de um livro pelo seu código caso este esteja cadastrado.

# Como utilizar
Para executar o programa, é necessário compilar o arquivo CadastroLivro.c. Uma maneira de compilar o código é utilizando um compilador de C, como o Codeblocks, por exemplo

Ao executar o programa, será exibido um menu com as opções disponíveis:

1 - Cadastrar Livro<br />
2 - Imprimir Informações dos Livros<br />
3 - Pesquisar Livros<br />
4 - Ordenar Livros<br />
5 - Remover Livros<br />
6 - Alterar Livro<br />
0 - Sair<br />

Para escolher uma opção, basta digitar o número correspondente e pressionar Enter. Dependendo da opção escolhida, o programa solicitará informações adicionais, como o título e o autor do livro a ser cadastrado, ou o código do livro a ser buscado.

# Funcionalidades disponíveis
## Cadastrar Livro
Permite cadastrar um novo livro, informando os seguintes dados:

<li>Código</>
<li>Título</li>
<li>Autor</li>
<li>Ano de publicação</li>
<li>Editora</li><br />

## Imprime Informações
Permite imprimir as informações do Livro informando o seu código, a lista é ordenada a partir do código do livro mostrando toas as iformações dos livros cadastrados. Caso contrário, uma mensagem de erro é exibida.

## Pesquisa Livro
Permite buscar um livro pelo código, a busca é realizada usando o algoritmo de pesquisa sequencial binária, se o livro for encontrado, são exibidos seus dados. Caso contrário, uma mensagem de erro é exibida.

## Ordena Livro
Permite ordenar os livros pelo seu ano de lançamento, nessa função é usado o algoritmo de ordenação bolha. Caso contrário, uma mensagem de erro é exibida.

## Remover Livro
Permite remover algumas ou todas as informações de um livro pelo código. Caso contrário, uma mensagem de erro é exibida.

## Alterar Livro
Permite alterar as informações do livro, para isso é nescessário informar o código do livro. Caso contrário, uma mensagem de erro é exibida.

