#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MIN_LEN 4
#define MAX_LEN 100

struct livro
{
    int codigo, ano;
    char titulo[30], nome[50], area[20], autor[30], editora[30];
};

struct livro ficha[20];
struct livro troca;

bool codigoJaExistente(int codigo)
    {
        for (int i=0; i<20; i++)
        {
            if (ficha[i].codigo == codigo)
            {
                return true;
            }
        }
        return false;
    }


int main()
{
    int op, i, j, busca, acha, len, verifica;

    verifica = 0;


    /*----- FUN플O CADASTRA LIVROS -----*/

    void CadastroLivro()
    {
        for (i=0; i<20; i++)
        {

            system("cls");
            printf("\nDigite o codigo do livro: ");
            scanf("%d", &ficha[i].codigo);

            if (codigoJaExistente(ficha[i].codigo))
            {
                printf("\nCodigo ja cadastrado\n");
            } else
            {
                ficha[i].codigo[i+1] = ficha[i].codigo;
                i++;
                    printf("Código cadastrado com sucesso\n");
            }




            do
            {
                printf("\nDigite o titulo do livro: ", i + 1);
                scanf("%[^\n]s", &ficha[i].titulo);
                fflush(stdin);
                len = strlen(ficha[i].titulo);

                if (len < MIN_LEN)
                {
                    printf("\nO titulo do livro deve ter pelo menos %d letras.\n", MIN_LEN);
                }else
                {
                    for (j = 0; j < len; j++)
                    {
                        if (!isalpha(ficha[i].titulo[j]))
                        {
                            printf("\nO titulo do livro deve conter apenas letras.\n");
                            break;
                        }
                    }
                }
            }while (len < MIN_LEN || j < len);

            do
            {
                printf("\nDigite o nome do autor: ");
                scanf("%[^\n]s", &ficha[i].autor);
                fflush(stdin);
                len = strlen(ficha[i].autor);

                if (len < MIN_LEN)
                {
                    printf("\nO nome do autor deve ter pelo menos %d letras.\n", MIN_LEN);
                }else
                {
                    for (j = 0; j < len; j++)
                    {
                        if (!isalpha(ficha[i].autor[j]))
                        {
                            printf("\nO nome do autor deve conter apenas letras.\n");
                            break;
                        }
                    }
                }
            }while (len < MIN_LEN || j < len);

            do
            {
                printf("\nDigite a area do livro: ");
                scanf("%[^\n]s", &ficha[i].area);
                fflush(stdin);
                len = strlen(ficha[i].area);

                if (len < MIN_LEN)
                {
                    printf("\nA area do livro deve ter pelo menos %d letras.\n", MIN_LEN);
                }else
                {
                    for (j = 0; j < len; j++)
                    {
                        if (!isalpha(ficha[i].area[j]))
                        {
                            printf("\nA area do livro deve conter apenas letras.\n");
                            break;
                        }
                    }
                }
            }while (len < MIN_LEN || j < len);


            do
            {
                printf("\nDigite o ano do livro: ");
                verifica = scanf("%d", &ficha[i].ano);

                if (verifica == 0)
                {
                    printf("\nO ano do livro deve ser um numero");
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


            do
            {
                printf("\nDigite o nome da editora: ");
                scanf("%[^\n]s", &ficha[i].editora);
                fflush(stdin);
                len = strlen(ficha[i].editora);

                if (len < MIN_LEN)
                {
                    printf("\nA editora do livro deve ter pelo menos %d letras.\n", MIN_LEN);
                }else
                {
                    for (j = 0; j < len; j++)
                    {
                        if (!isalpha(ficha[i].editora[j]))
                        {
                            printf("\nA editora do livro deve conter apenas letras.\n");
                            break;
                        }
                    }
                }
            }while (len < MIN_LEN || j < len);

            system("pause");
            system("cls");
            main();
            if (i == 20)
            {
                printf("Tamanho do vetor atingido");
            }
        }
    }

    /*----- FUN플O IMPRIME INFORMA합ES -----*/

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

    /*----- FUNCAO PESQUISAR LIVROS -----*/

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

    /*----- FUN플O ORDENA LIVROS -----*/

    void OrdenaLivros()
    {
        system("cls");
        for (i=0; i<19; i++)
        {
            for (j=i+1; j<20; j++)
            {
                if (ficha[i].ano > ficha[j].ano)
                {
                    troca = ficha[i];
                    ficha[i] = ficha[j];
                    ficha[j] = troca;
                }
            }
        }
        for (i=0; i<20; i++)
        {
            printf("\nCODIGO: %d, TITULO: %s, ANO: %d\n", ficha[i].codigo, ficha[i].titulo, ficha[i].ano);
        }
        system("pause");
        system("cls");
        main();
    }


    /*-----FUN플O REMOVE LIVROS-----*/
    void RemoveLivros()
    {
        int op_livro, busca, acha;

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
                    printf("\nO titulo do livro sera excluido\n");
                    system("pause");
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
                    printf("\nA nome do autor sera excluido\n");
                    system("pause");
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
                    printf("\nA area do livro sera excluida\n");
                    system("pause");
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
                    printf("\nO ano do livro sera excluido\n");
                    system("pause");
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
                    printf("\nA editora do livro sera excluida\n");
                    system("pause");
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
        int op_livro, busca, acha;

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
                printf("\t\t\t|    3 - Alterar nome do autro                 |\n");
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
                    do
                    {
                        printf("\nInforme o titulo do livro que deseja alterar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", &ficha[i].titulo);
                        len = strlen(ficha[i].titulo);

                        if (len < MIN_LEN)
                        {
                            printf("\nO titulo do livro deve ter pelo menos %d letras\n", MIN_LEN);
                        }else
                        {
                            for (j = 0; j < len; j++)
                            {
                                if (!isalpha(ficha[i].titulo[j]))
                                {
                                    printf("\nO titulo do livro deve conter apenas letras.\n");
                                    break;
                                }
                            }
                        }
                    }while (len < MIN_LEN || j < len);
                    printf("\nTitulo do livro alterado\n");
                    system("pause");
                    system("cls");
                    main();
                }break;

            case 3:
                for (i=0; i<20; i++)
                {
                    do
                    {
                        printf("\nDigite o nome do autor: ");
                        scanf("%[^\n]s", &ficha[i].autor);
                        fflush(stdin);
                        len = strlen(ficha[i].autor);

                        if (len < MIN_LEN)
                        {
                            printf("\nO nome do autor deve ter pelo menos %d letras.\n", MIN_LEN);
                        }else
                        {
                            for (j = 0; j < len; j++)
                            {
                                if (!isalpha(ficha[i].autor[j]))
                                {
                                    printf("\nO nome do autor deve conter apenas letras.\n");
                                    break;
                                }
                            }
                        }
                    }while (len < MIN_LEN || j < len);
                    printf("\nAutor do livro alterado\n");
                    system("pause");
                    system("cls");
                    main();
                }break;

            case 4:
                for (i=0; i<20; i++)
                {
                    do
                    {
                        printf("\nInforme a area do livro que deseja alterar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", &ficha[i].area);
                        len = strlen(ficha[i].area);

                        if (len < MIN_LEN)
                        {
                            printf("\nA area do livro deve ter pelo menos %d letras\n", MIN_LEN);
                        }else
                        {
                            for (j = 0; j < len; j++)
                            {
                                if (!isalpha(ficha[i].area[j]))
                                {
                                    printf("\nA area do livro deve conter apenas letras.\n");
                                    break;
                                }
                            }
                        }
                    }while (len < MIN_LEN || j < len);
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
                        verifica = scanf("%d", &ficha[i].ano);

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
                    do
                    {
                        printf("\nInforme a editora do livro que deseja alterar: ");
                        fflush(stdin);
                        scanf("%[^\n]s", &ficha[i].editora);
                        len = strlen(ficha[i].editora);

                        if (len < MIN_LEN)
                        {
                            printf("\nA editora do livro deve ter pelo menos %d letras\n", MIN_LEN);
                        }else
                        {
                            for (j = 0; j < len; j++)
                            {
                                if (!isalpha(ficha[i].editora[j]))
                                {
                                    printf("\nA editora do livro deve conter apenas letras.\n");
                                    break;
                                }
                            }
                        }
                    }while (len < MIN_LEN || j < len);
                    printf("\Editora do livro alterado\n");
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

    printf("\n");
        printf ("\t\t\t\t       Livrarias\n");
        printf ("\t\t\t=========================================\n");
        printf ("\t\t\t|\t                                |\n");
        printf("\t\t\t|    1 - Cadastrar livros               |\n");
        printf("\t\t\t|    2 - Imprimir os livros cadastrados |\n");
        printf("\t\t\t|    3 - Pesquisar livros por codigo    |\n");
        printf("\t\t\t|    4 - Ordenar os livros por ano      |\n");
        printf("\t\t\t|    5 - Excluir dados do livro         |\n");
        printf("\t\t\t|    6 - Alterar dados do livro         |\n");
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
        OrdenaLivros();
        break;
    case 5:
        RemoveLivros();
        break;
    case 6:
        AlteraLivro();
        break;
    case 0:
        printf("\nFim do programa");
        break;

    default: printf("Opcao invalida");
    }

    return(0);

}
