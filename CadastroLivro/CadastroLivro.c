#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct livro
{
    int codigo, ano;
    char titulo[30], area[30], autor[30], editora[30];
};

struct livro ficha[20];
struct livro troca;

int codigo, op, i, j, busca, acha, len, resultadoScanf, busca, ahca;

int verifica = 0;

/*----- FUNÇÃO CADASTRA LIVROS -----*/
void CadastroLivro()
{
    for (i=0; i<20; i++)
    {
        system("cls");
        printf("\nDigite o codigo do livro: ");
        fflush(stdin);
        scanf("%d", &ficha[i].codigo);

        do {
            printf("\nDigite o titulo do livro: ");
            fflush(stdin);
            scanf("%[^\n]s", &ficha[i].titulo);
            if (strlen(ficha[i].titulo) < 4) {
                printf("\nO titulo do livro deve ter pelo menos 4 caracteres.\n");
                resultadoScanf = 0;
            } else {
                resultadoScanf = 1;
            }
            while (getchar() != '\n');
        } while (resultadoScanf != 1);

        do {
            printf("\nDigite nome do autor: ");
            fflush(stdin);
            scanf("%[^\n]s", &ficha[i].autor);
            if (strlen(ficha[i].autor) < 4) {
                printf("\nO nome do autor deve ter pelo menos 4 caracteres.\n");
                resultadoScanf = 0;
            } else {
                resultadoScanf = 1;
            }
            while (getchar() != '\n');
        } while (resultadoScanf != 1);

        do {
            printf("\nDigite area do livro: ");
            fflush(stdin);
            scanf("%[^\n]s", &ficha[i].area);
            if (strlen(ficha[i].area) < 4) {
                printf("\nA area do livro deve ter pelo menos 4 caracteres.\n");
                resultadoScanf = 0;
            } else {
                resultadoScanf = 1;
            }
            while (getchar() != '\n');
        } while (resultadoScanf != 1);


        do
        {
            printf("\nDigite o ano do livro: ");
            fflush(stdin);
            verifica = scanf("%d", &ficha[i].ano);
            fflush(stdin);

            if (verifica == 0)
            {
                printf("\nO ano do livro deve ser um numero\n");
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
            }else if (ficha[i].ano < 1000 || ficha[i].ano > 9999)
            {
                printf("\nO ano deve conter 4 digitos.\n");
                verifica = 0;
            }else
            {
                verifica = 1;
            }
        }while (verifica != 1);


        do {
            printf("\nDigite a editora do livro: ");
            fflush(stdin);
            scanf("%[^\n]s", &ficha[i].editora);
            if (strlen(ficha[i].editora) < 4) {
                printf("\nA editora do livro deve ter pelo menos 4 caracteres.\n");
                resultadoScanf = 0;
            } else {
                resultadoScanf = 1;
            }
            while (getchar() != '\n');
        } while (resultadoScanf != 1);

        system("pause");
        system("cls");
        main();
        if (i == 20)
        {
            printf("Tamanho do vetor atingido");
        }
    }
}

/*----- FUNÇÃO IMPRIME INFORMA합ES -----*/

void ImprimeInformacoes()
{
    system("cls");
    for (i=0; i<20; i++)
    {
        printf("\n===============================\n");
        printf("\nCODIGO: %d", ficha[i].codigo);
        printf("\nTITULO: %s", ficha[i].titulo);
        printf("\nAUTOR: %s", ficha[i].autor);
        printf("\nAREA: %s", ficha[i].area);
        printf("\nANO: %d", ficha[i].ano);
        printf("\nEDITORA: %s \n", ficha[i].editora);
        printf("\n===============================\n");
    }
    system("pause");
    system("cls");
    main();
}

/*----- FUNÇÃO PESQUISAR LIVROS -----*/

void PesquisarLivros()
{
    int busca, acha;

    system("cls");
    printf("\nDigite o codigo que deseja buscar: ");
    scanf("%d", &busca);

    i = 0;
    acha = 0;

    while((i<20)  && (acha == 0))
    {
        if (ficha[i].codigo == busca)
            acha = 1;
        else
            i++;
    }
    if (acha == 1)
    {
        printf("\nCODIGO: %d", ficha[i].codigo);
        printf("\nTITULO: %s", ficha[i].titulo);
        printf("\nAUTOR: %s", ficha[i].autor);
        printf("\nAREA: %s", ficha[i].area);
        printf("\nANO: %d", ficha[i].ano);
        printf("\nEDITORA: %s\n", ficha[i].editora);
    }
    else
    {
        printf("\nRegistro nao encontrado\n");
    }
    system("pause");
    system("cls");
    main();
}

/*-----FUNÇÃO REMOVE LIVROS-----*/
void RemoveLivros()
{
    int op_livro;

    i = 0;
    acha = 0;

    system("cls");
    printf("\nInforme o codigo do livro que deseja alterar: ");
    scanf("%d", &busca);

    while((i<20) && (acha == 0))
    {
        if (ficha[i].codigo == busca)
            acha = 1;
        else
            i++;
    }
    if (acha == 1)
    {
        system("cls");
        printf("\n");
        printf ("\t\t\t\t       Exclusao de dados\n");
        printf ("\t\t\t===============================================\n");
        printf ("\t\t\t|\t                                      |\n");
        printf("\t\t\t|    1 - Excluir todos os dados               |\n");
        printf("\t\t\t|    2 - Excluir titulo do livro              |\n");
        printf("\t\t\t|    3 - Excluir nome do autor                |\n");
        printf("\t\t\t|    4 - Excluir area do livro                |\n");
        printf("\t\t\t|    5 - Excluir ano do livro                 |\n");
        printf("\t\t\t|    6 - Excluir nome da editora              |\n");
        printf("\t\t\t|    7 - Sair                                 |\n");
        printf ("\t\t\t|                                             |\n");
        printf ("\t\t\t===============================================\n");
        printf ("\n\n");
        printf("\nDigite um opcao: ");
        scanf("%d", &op_livro);
        system("cls");
    }else
    {
        printf("\nRegistro nao encontrado\n");
        system("pause");
        system("cls");
        main();
    }
    switch (op_livro)
    {
        case 1:
            for (i=0; i<20; i++)
            {
                system("cls");
                memset(&ficha[i].codigo,0,sizeof(ficha[i].codigo));
                memset(&ficha[i].titulo,0,sizeof(ficha[i].titulo));
                memset(&ficha[i].autor,0,sizeof(ficha[i].autor));
                memset(&ficha[i].area,0,sizeof(ficha[i].area));
                memset(&ficha[i].ano,0,sizeof(ficha[i].ano));
                memset(&ficha[i].editora,0,sizeof(ficha[i].editora));
                printf("\nTodos os dados fora excluidos\n");
                system("pause");
                system("cls");
            }break;

        case 2:
            for (i=0; i<20; i++)
            {
                system("cls");
                memset(&ficha[i].titulo,0,sizeof(ficha[i].titulo));
                printf("\nTitulo excluido\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 3:
        for (i=0; i<20; i++)
            {
                system("cls");
                memset(&ficha[i].autor,0,sizeof(ficha[i].autor));
                printf("\nAutor do livro excluido\n");
                system("pause\n");
                system("cls");
                main();
            }break;

        case 4:
            for (i=0; i<20; i++)
            {
                system("cls");
                memset(&ficha[i].area,0,sizeof(ficha[i].area));
                printf("\nArea do livro excluido\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 5:
            for (i=0; i<20; i++)
            {
                system("cls");
                memset(&ficha[i].ano,0,sizeof(ficha[i].ano));
                printf("\nAno do livro excluido\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 6:
            for (i=0; i<20; i++)
            {
                system("cls");
                memset(&ficha[i].editora,0,sizeof(ficha[i].editora));
                printf("\nEditora do livro excluido\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 7:
            system("cls");
            main();
            break;

        default: printf("\nValor invalido");
        void RemoveLivros();

    }
}

    /*-----FUNÇÃO ALTERA LIVRO-----*/

void AlteraLivro()
{
    int op_livro;

    i = 0;
    acha = 0;

    system("cls");
    printf("\nInforme o codigo do livro que deseja alterar: ");
    scanf("%d", &busca);

    while((i<20) && (acha == 0))
    {
        if (ficha[i].codigo == busca)
            acha = 1;
        else
            i++;
    }
    if (acha == 1)
    {
        system("cls");
        printf("\n");
        printf ("\t\t\t\t     Alteracao de Cadastro\n");
        printf ("\t\t\t================================================\n");
        printf ("\t\t\t|\t                                       |\n");
        printf("\t\t\t|    1 - Alterar codigo do livro               |\n");
        printf("\t\t\t|    2 - Alterar titulo do livro               |\n");
        printf("\t\t\t|    3 - Alterar nome do autor                 |\n");
        printf("\t\t\t|    4 - Alterar area do livro                 |\n");
        printf("\t\t\t|    5 - Alterar ano do livro                  |\n");
        printf("\t\t\t|    6 - Alterar nome da editora               |\n");
        printf("\t\t\t|    7 - Sair                                  |\n");
        printf ("\t\t\t|                                              |\n");
        printf ("\t\t\t================================================\n");
        printf ("\n\n");
        printf("\nDigite um opcao: ");
        scanf("%d", &op_livro);
        system("cls");
    }
    else
    {
        printf("\nRegistro nao encontrado\n");
        system("pause");
        system("cls");
        main();
    }

    switch (op_livro)
    {
        case 1:
            for (i=0; i<20; i++)
            {
                system("cls");
                printf("\nInforme o codigo do livro que deseja alterar: ");
                fflush(stdin);
                scanf("%d", &ficha[i].codigo);
                printf("\nCodigo alterado\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 2:
            for (i=0; i<20; i++)
            {
                do {
                    printf("\nDigite o titulo do livro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &ficha[i].titulo);
                    if (strlen(ficha[i].titulo) < 4) {
                        printf("\nO titulo do livro deve ter pelo menos 4 caracteres.\n");
                        resultadoScanf = 0;
                    } else {
                        resultadoScanf = 1;
                    }
                    while (getchar() != '\n');
                } while (resultadoScanf != 1);
                printf("\nTitulo do livro alterado\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 3:
            for (i=0; i<20; i++)
            {
                do {
                    printf("\nDigite o autor do livro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &ficha[i].autor);
                    if (strlen(ficha[i].autor) < 4) {
                        printf("\nO autor do livro deve ter pelo menos 4 caracteres.\n");
                        resultadoScanf = 0;
                    } else {
                        resultadoScanf = 1;
                    }
                    while (getchar() != '\n');
                } while (resultadoScanf != 1);
                printf("\nAutor do livro alterado\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 4:
            for (i=0; i<20; i++)
            {
                do {
                    printf("\nDigite a area do livro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &ficha[i].area);
                    if (strlen(ficha[i].area) < 4) {
                        printf("\nA area do livro deve ter pelo menos 4 caracteres.\n");
                        resultadoScanf = 0;
                    } else {
                        resultadoScanf = 1;
                    }
                    while (getchar() != '\n');
                } while (resultadoScanf != 1);
                printf("\nArea do livro alterado\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 5:
            for (i=0; i<20; i++)
            {
                do
                {
                    printf("\nDigite o ano do livro: ");
                    fflush(stdin);
                    verifica = scanf("%d", &ficha[i].ano);
                    fflush(stdin);

                    if (verifica == 0)
                    {
                        printf("\nO ano do livro deve ser um numero\n");
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                    }else if (ficha[i].ano < 1000 || ficha[i].ano > 9999)
                    {
                        printf("\nO ano deve conter 4 digitos.\n");
                        verifica = 0;
                    }else
                    {
                        verifica = 1;
                    }
                }while (verifica != 1);
                printf("\nAno do livro alterado\n");
                system("pause");
                system("cls");
                main();
            }break;

        case 6:
            for (i=0; i<20; i++)
            {
                do {
                    printf("\nDigite a editora do livro: ");
                    fflush(stdin);
                    scanf("%[^\n]s", &ficha[i].editora);
                    if (strlen(ficha[i].editora) < 4) {
                        printf("\nA editora do livro deve ter pelo menos 4 caracteres.\n");
                        resultadoScanf = 0;
                    } else {
                        resultadoScanf = 1;
                    }
                    while (getchar() != '\n');
                } while (resultadoScanf != 1);
                printf("\nEditora do livro alterado\n");
                system("pause");
                system("cls");
                main();
            }break;
        case 7:
            main();
            break;

            default: printf("\nValor invalido\n");
            void RemoveLivros();

    }
}

/*/----- MENU -----/*/

int main()
{
    int op, i, j, busca, acha, len, verifica;

    verifica = 0;

    printf("\n");
        printf ("\t\t\t\t       Livrarias\n");
        printf ("\t\t\t=========================================\n");
        printf ("\t\t\t|\t                                |\n");
        printf("\t\t\t|    1 - Cadastrar livros               |\n");
        printf("\t\t\t|    2 - Imprimir os livros cadastrados |\n");
        printf("\t\t\t|    3 - Pesquisar livros por codigo    |\n");
        printf("\t\t\t|    4 - Excluir dados do livro         |\n");
        printf("\t\t\t|    5 - Alterar dados do livro         |\n");
        printf("\t\t\t|    0 - Sair                           |\n");
        printf ("\t\t\t|                                       |\n");
        printf ("\t\t\t=========================================\n");
        printf ("\n\n");
    printf("\nInforme a opcao desejada: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        CadastroLivro();
        break;
    case 2:
        ImprimeInformacoes();
        break;
    case 3:
        PesquisarLivros();
        break;
    case 4:
        RemoveLivros();
        break;
    case 5:
        AlteraLivro();
        break;
    case 0:
        printf("\nFim do programa");
        break;

    default: printf("Opcao invalida");
    }

    return(0);
}
