#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <windows.h>

char /*clientes*/ idcliente[200][10], nome[200][50], cidade[200][30], uf[200][3], documento[200][20], telefone[200][50];
char linha[200], tmp[200];
char /*parcelas*/ idparcela[200][50], idcliente_p[200][50], datavenc[200][50], datapag[200][50], valor_p[200][50], codbanco[200][50];
char /*bancos*/ bancos[5][10];
int tot, p, col;
bool status_cliente[200], status_parcela[200];
FILE *file;

void enche_bancos()
{
    strcpy(bancos[0], "DINHEIRO");
    strcpy(bancos[1], "Banco Do Brasil");
    strcpy(bancos[2], "Caixa Econômica");
    strcpy(bancos[3], "Bradesco");
    strcpy(bancos[4], "Nubank");
}

//----------------------------------------------------------------------------
//--------------LEITURA DO ARQUIVO
void separa()
{
    p = 0;
    while (linha[col] != '"' && col < strlen(linha))
    {
        tmp[p] = linha[col];
        col++; //posicao na linha
        p++;   //posicao no campo
    }
    col = col + 3;
    tmp[p] = '\0';
}

void le_dados(int valor)
{
    char *result;
    int i;

    if (valor == 0)
    {
        file = fopen("CLIENTES.txt", "r");
        if (file == NULL)
        {
            printf("ERRO ao abrir o arquivo CLIENTES.txt\n");
        }
    }
    if (valor == 1)
    {
        file = fopen("PARCELAS.txt", "r");
        if (file == NULL)
        {
            printf("ERRO ao abrir o arquivo PARCELAS.txt\n");
        }
    }
    if (file != NULL)
    {
        tot = 0;
        while (!feof(file))
        {
            if (valor == 0)
            {
                result = fgets(linha, 200, file);
                if (linha[strlen(linha) - 1] == '\n')
                {
                    linha[strlen(linha) - 1] = '\0';
                }
            }

            if (valor == 1)
            {
                result = fgets(linha, 200, file);
                if (linha[strlen(linha) - 1] == '\n')
                {
                    linha[strlen(linha) - 1] = '\0';
                }
            }
            col = 1;

            if (valor == 0)
            {
                separa();
                strcpy(idcliente[tot], tmp);
                separa();
                strcpy(nome[tot], tmp);
                separa();
                strcpy(cidade[tot], tmp);
                separa();
                strcpy(uf[tot], tmp);
                separa(); //lixo1
                separa();
                strcpy(telefone[tot], tmp);
                separa(); //lixo
                separa();
                strcpy(documento[tot], tmp);
                for (i = 0; i <= tot; i++)
                {
                    status_cliente[i] = true;
                }
            }

            if (valor == 1)
            {
                separa();
                strcpy(idparcela[tot], tmp);
                separa();
                strcpy(idcliente_p[tot], tmp);
                separa();
                strcpy(datavenc[tot], tmp);
                separa();
                strcpy(datapag[tot], tmp);
                separa();
                strcpy(valor_p[tot], tmp);
                separa();
                strcpy(codbanco[tot], tmp);
                for (i = 0; i <= tot; i++)
                {
                    status_parcela[i] = true;
                }
            }
            tot++;
        }
        fclose(file);
        tot--;
    }
}

//----------------------------------------------------------------------------
//--------MOSTRADORES
void mostra_info_parcela()
{
    int x;

    system("cls");
    printf("------------------------------------------------DADOS DAS PARCELAS------------------------------------------------\n");
    printf(" ID       CLIENTE    VALOR      DATA DE VENCIMENTO    DATA DE PAGAMENTO   CÓD BANCO   BANCO\n");
    for (x = 0; x <= tot; x++)
    {
        if (status_parcela[x] == true)
        {
            if (strcmp(codbanco[x], "0") == 0)
            {
                printf(" %-9s%-11s%-11s%-22s%-20s%-12s%s\n", idparcela[x], idcliente_p[x], valor_p[x], datavenc[x], datapag[x], codbanco[x], bancos[0]);
            }
            if (strcmp(codbanco[x], "001") == 0)
            {
                printf(" %-9s%-11s%-11s%-22s%-20s%-12s%s\n", idparcela[x], idcliente_p[x], valor_p[x], datavenc[x], datapag[x], codbanco[x], bancos[1]);
            }
            if (strcmp(codbanco[x], "104") == 0)
            {
                printf(" %-9s%-11s%-11s%-22s%-20s%-12s%s\n", idparcela[x], idcliente_p[x], valor_p[x], datavenc[x], datapag[x], codbanco[x], bancos[2]);
            }
            if (strcmp(codbanco[x], "237") == 0)
            {
                printf(" %-9s%-11s%-11s%-22s%-20s%-12s%s\n", idparcela[x], idcliente_p[x], valor_p[x], datavenc[x], datapag[x], codbanco[x], bancos[3]);
            }
            if (strcmp(codbanco[x], "260") == 0)
            {
                printf(" %-9s%-11s%-11s%-22s%-20s%-12s%s\n", idparcela[x], idcliente_p[x], valor_p[x], datavenc[x], datapag[x], codbanco[x], bancos[4]);
            }
        }
    }
    printf("\n");
    printf("\n");
    system("pause");
    system("cls");
}

void mostra_info_cliente()
{
    int x;

    system("cls");
    printf("---------------------------------------------------DADOS DOS CLIENTES---------------------------------------------------\n");
    printf(" ID    NOME                    CIDADE                  UF   TELEFONE(S)                        DOCUMENTO\n");
    for (x = 0; x <= tot; x++)
    {
        if (status_cliente[x] == true)
        {
            printf(" %s  %-24s%-24s%-5s%-35s%s\n", idcliente[x], nome[x], cidade[x], uf[x], telefone[x], documento[x]);
        }
    }
    printf("\n");
    printf("\n");
    system("pause");
    system("cls");
}

void mostra_tudo()
{
    for (int x = 0; x < tot; x++)
    {
        printf("%s %s %s %s %s %s\n", idcliente[x], nome[x], cidade[x], uf[x], telefone[x], documento[x]);
    }
    for (int x = 0; x < tot; x++)
    {
        printf("%s %s %s %s %s %s\n", idparcela[x], idcliente_p[x], datavenc[x], datapag[x], valor_p[x], codbanco[x]);
    }
}
//----------------------------------------------------------------------------
//--------------------BUSCAS
void busca_parcela(char busca[10])
{
    int i, cont;
    for (i = 0; i <= tot; i++)
    {
        if (strcmp(busca, idparcela[i]) == 0)
        {
            mostra_info_parcela();
        }
    }
}

void busca_cliente(char busca[30])
{
    int i, cont;
    for (i = 0; i <= tot; i++)
    {
        if (strcmp(busca, idcliente[i]) == 0)
        {
            mostra_info_cliente();
            system("pause");
            system("cls");
        }
    }
}

void busca_menu()
{
    char busca_tmp[10];
    int b3, b4;

    while (b3 != 3)
    {
        printf("-------------------------\n");
        printf("  BUSCAR CLIENTES: [1] \n");
        printf("  BUSCAR PARCELAS: [2] \n");
        printf("  VOLTAR:          [3] \n");
        printf("-------------------------\n");
        printf("\n");
        printf("\n");
        printf("DIGITE: ");
        scanf("%i", &b3);

        if (b3 == 1)
        {
            system("cls");
            printf("------------------------------\n");
            printf("   BUSCAR POR ID:        [1] \n");
            printf("   BUSCAR POR NOME:      [2] \n");
            printf("------------------------------\n");
            printf("\n");
            printf("\n");
            printf("DIGITE: ");
            scanf("%i", &b4);
            if (b4 == 1)
            {
                printf("----------------------------\n");
                printf("\n");
                printf("  DIGITE A ID DO CLIENTE: ");
                scanf("%s", &busca_tmp);
                system("cls");
                busca_cliente(busca_tmp);
            }
            if (b4 == 2)
            {
                printf("----------------------------\n");
                printf("\n");
                printf("  DIGITE O NOME DO CLIENTE: ");
                scanf("%s", &busca_tmp);
                system("cls");
                busca_cliente(busca_tmp);
            }
        }
        if (b3 == 2)
        {
            system("cls");
            printf("----------------------------------------\n");
            printf("BUSCAR POR ID:                [1]: \n");
            printf("BUSCAR POR CÓD. VENCIMENTO:   [2]: \n");
            printf("BUSCAR POR CÓD. CLIENTE:      [3]: \n");
            printf("\n");
            printf("\n");
            printf("DIGITE: ");
            scanf("%i", &b4);
        }
    }
}

//----------------------------------------------------------------------------
//-------------------ALTERAR DADOS
void altera_parcela()
{
    char busca_tmp[10];

    printf("----------------------\n");
    printf("DIGITE A ID DA PARCELA (XXXXX/X): ");
    scanf("%s", &busca_tmp);
    busca_parcela(busca_tmp);
}

void altera_dados()
{
    int b2;

    while (b2 != 3)
    {
        printf("------------------------------------\n");
        printf("ALTERAR DADOS DE UM CLIENTE:     [1]\n");
        printf("ALTERAR DADOS DE UMA PARCELA:    [2]\n");
        printf("VOLTAR:    [3]\n");
        printf("------------------------------------\n");
        printf("\n");
        printf("\n");
        printf("DIGITE: ");
        scanf("%i", &b2);

        if (b2 == 2)
        {
            system("cls");
            altera_parcela();
        }
    }
}

//----------------------------------------------------------------------------

void ordenarParcelasEmOrdemCrescente()
{
    char auxiliar[50];

    for (int x = 0; x < 76; x++)
    {
        for (int j = x + 1; j < 76; j++)
        {
            float tempValor1 = atof(idparcela[x]);
            float tempValor2 = atof(idparcela[j]);
            if (tempValor1 > tempValor2)
            {
                //IDPARCELA
                strcpy(auxiliar, idparcela[x]);
                strcpy(idparcela[x], idparcela[j]);
                strcpy(idparcela[j], auxiliar);

                //VALOR
                strcpy(auxiliar, valor_p[x]);
                strcpy(valor_p[x], valor_p[j]);
                strcpy(valor_p[j], auxiliar);

                //ID CLIENTE PARCELA
                strcpy(auxiliar, idcliente_p[x]);
                strcpy(idcliente_p[x], idcliente_p[j]);
                strcpy(idcliente_p[j], auxiliar);

                //DATA VENCIMENTO
                strcpy(auxiliar, datavenc[x]);
                strcpy(datavenc[x], datavenc[j]);
                strcpy(datavenc[j], auxiliar);

                //DATA PAGAMENTO
                strcpy(auxiliar, datapag[x]);
                strcpy(datapag[x], datapag[j]);
                strcpy(datapag[j], auxiliar);

                //COD BANCO
                strcpy(auxiliar, codbanco[x]);
                strcpy(codbanco[x], codbanco[j]);
                strcpy(codbanco[j], auxiliar);
            }
        }
    }
}

//----------------------------------------------------------------------------

void listacliente()
{
    int b8;
    b8 = 0;
    while (b8 != 4)
    {
        printf("-------------------------------------\n");
        printf("   CLASSIFICAR POR ID:                 [1]\n");
        printf("   CLASSIFICAR POR ORDEM ALFABETICA:   [2]\n");
        printf("   MOSTRAR TUDO                        [3]\n");
        printf("   VOLTAR:                             [4]\n");
        printf("-------------------------------------\n");
        printf("\n");
        printf("\n");
        printf("DIGITE: ");
        scanf("%i", &b8);

        if (b8 == 1)
        {
        }
        if (b8 == 2)
        {
        }
        if (b8 == 3)
        {
            mostra_info_cliente();
        }
    }
}

//----------------------------------------------------------------------------

void listaparcela()
{
    int b8;
    b8 = 0;
    while (b8 != 4)
    {
        printf("-------------------------------------\n");
        printf("   CLASSIFICAR POR ID DA PARCELA:       [1]\n");
        printf("   CLASSIFICAR POR DATA DE VENCIMENTO:  [2]\n");
        printf("   MOSTRAR TUDO                         [3]\n");
        printf("   VOLTAR:                              [4]\n");
        printf("-------------------------------------\n");
        printf("\n");
        printf("\n");
        printf("DIGITE: ");
        scanf("%i", &b8);

        if (b8 == 1)
        {
        }
        if (b8 == 2)
        {
        }
        if (b8 == 3)
        {
            mostra_info_parcela();
        }
    }
}

//----------------------------------------------------------------------------

void menu()
{
    int b1, val, lixo;
    b1 = 0;
    val = 1;

    while (b1 != 7)
    {
        system("cls");
        printf("-------------------------------------\n");
        printf("   REALIZAR BUSCA:             [1]\n");
        printf("   EXIBIR LISTA DE CLIENTES:   [2]\n");
        printf("   EXIBIR LISTA DE PARCELAS:   [3]\n");
        printf("   ALTERAR DADOS:              [4]\n");
        printf("   MOSTRAR DATAS:              [5]\n");
        printf("   SAIR:                       [7]\n");
        printf("-------------------------------------\n");
        printf("\n");
        printf("\n");
        printf("DIGITE: ");
        scanf("%i", &b1);

        if (b1 == 1)
        {
            system("cls");
            busca_menu();
        }

        if (b1 == 2)
        {
            system("cls");
            listacliente();
        }

        if (b1 == 3)
        {
            system("cls");
            listaparcela();
        }
        if (b1 == 3)
        {
            system("cls");
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
        }
    }
}

//----------------------------------------------------------------------------
int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");
    le_dados(0);
    le_dados(1);
    enche_bancos();
    mostra_tudo();
    system("cls");
    printf("DADOS IMPORTADOS COM SUCESSO!\n");
    printf("\n");
    printf("\n");
    system("pause");
    system("cls");
    menu();
}
