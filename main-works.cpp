#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

char produtos[15][50], valor_produtos[15][50], users[15][50], senhas[15][50];
bool login_aut, status_produto[15], status_carrinho[100];
int carrinho[100];

void enche_carrinho()
{
    int i;
    for (i = 1; i < 3; i++)
    {
        carrinho[i] = 1;
        status_carrinho[i] = true;
    }
    for (i = 3; i < 3; i++)
    {
        carrinho[i] = 3;
        status_carrinho[i] = true;
    }
    for (i = 5; i < 100; i++)
    {
        carrinho[i] = 0;
        status_carrinho[i] = false;
    }
}

void add_carrinho(int valor1)
{
    int i;
    for (i = 1; i < 100; i++)
    {
        if (carrinho[i] == 0 && status_carrinho[i] == false)
        {
            carrinho[i] = valor1;
        }
        break;
    }
}

void mostra_info(int valor1)
{
    int tmp;

    while (tmp != 2)
    {
        system("cls");
        printf("-----------------PRODUTO-----------------\n");
        printf("   NOME:   %s\n", produtos[valor1]);
        printf("   VALOR:  %s\n", valor_produtos[valor1]);
        printf("   ADICIONAR AO CARRINHO [1]\n");
        printf("   VOLTAR                [2]");
        printf("\n");
        printf("\n");
        printf("   DIGITE: ");
        scanf("%i", &tmp);

        if (tmp == 1)
        {
            add_carrinho(valor1);
        }
    }
}

void busca()
{
    int i;
    char busca_tmp[15];
    char sair[3] = "2";
    bool busca;

    while (strcmp(busca_tmp, sair) != 0)
    {
        system("cls");
        printf("---------------BUSCA---------------\n");
        printf(" Digite [2] para voltar!\n");
        printf(" Digite um Produto (ex: Batata): ");
        scanf("%s", &busca_tmp);
        for (i = 0; i < 16; i++)
        {
            if (strcmp(busca_tmp, produtos[i]) == 0 && busca_tmp != "2")
            {
                mostra_info(i);
            }
            else
            {
                busca = false;
            }
        }
        if (busca == false)
        {
            printf("Esse produto não está cadastrado!!\n");
            system("pause");
        }
    }
}

void lista_produtos()
{
    int i;
    system("cls");
    printf("-------------LISTA DE PRODUTOS-------------\n");
    for (i=1;i<5;i++)
    {
        if (status_produto[i] == true)
        {
            printf("   NOME:   %s\n", produtos[i]);
            printf("   VALOR:  %s\n", valor_produtos[i]);
            printf("\n");
        }
    }
    system("pause");
}

void mostra_carrinho()
{
    int i;

    system("cls");
    printf("-----------MEU CARRINHO-----------\n");
    for (i = 1; i < 5; i++)
    {
        printf("   PRODUTO %i\n", i);
        printf("   NOME:   %s\n", produtos[1]);
        printf("   VALOR:  %s\n", valor_produtos[1]);
        printf("\n");
    }
    printf("\n");
    system("pause");
}

void menu()
{
    int tmp1, i;

    strcpy(produtos[1], "Batata");
    strcpy(valor_produtos[1], "R$ 12,50");
    strcpy(produtos[2], "Brócolis");
    strcpy(valor_produtos[2], "R$ 9,35");
    strcpy(produtos[3], "Melância");
    strcpy(valor_produtos[3], "R$ 35,50");
    strcpy(produtos[4], "Amora");
    strcpy(valor_produtos[4], "R$ 18,00");
    strcpy(produtos[5], "Tomate");
    strcpy(valor_produtos[5], "R$ 5,89");
    strcpy(produtos[6], "Alface");
    strcpy(valor_produtos[6], "R$ 2,50");
    strcpy(produtos[7], "Beterraba");
    strcpy(valor_produtos[7], "R$ 6,50");

    while (tmp1 != 4)
    {
        if (login_aut == true)
        {
            system("cls");
            printf("-------------------MENU-------------------\n");
            printf(" BUSCAR PRODUTO                [1]\n");
            printf(" EXIBIR LISTA DE PRODUTOS      [2]\n");
            printf(" MOSTRAR MEU CARRINHO          [3]\n");
            printf(" SAIR                          [4]\n");
            printf("\n");
            printf("\n");
            printf(" DIGITE:");
            scanf("%i", &tmp1);

            if (tmp1 == 1)
            {
                busca();
            }
            if (tmp1 == 2)
            {
                lista_produtos();
            }
            if (tmp1 == 3)
            {
                mostra_carrinho();
            }
        }
    }
}

void login()
{
    char tmp1[15], tmp2[15];
    int i;
    bool user, pass;

    strcpy(users[0], "admin.com");
    strcpy(senhas[0], "admin123");
    while (login_aut == false)
    {
        system("cls");
        printf("login: %s\n", users[0]);
        printf("senha: %s\n", senhas[0]);
        printf("------------LOGIN------------\n");
        printf("   Digite seu e-mail: ");
        scanf("%s", &tmp1);
        printf("%s\n", tmp1);
        printf("   Digite sua senha: ");
        scanf("%s", &tmp2);
        printf("%s\n", tmp2);

        for (i = 0; i < 16; i++)
        {
            if (strcmp(users[i], tmp1) == 0 && strcmp(senhas[i], tmp2) == 0)
            {
                user = true;
                pass = true;
            }
        }

        if (user == true && pass == true)
        {
            login_aut = true;
        }
        else
        {
            printf("Usuário ou Senhas Incorretos!!!\n");
            system("pause");
        }
    }
}

int main()
{
    int i;
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    login();
    enche_carrinho();
    for (i = 1; i < 5; i++)
    {
        status_produto[i] = true;
    }
    menu();
}