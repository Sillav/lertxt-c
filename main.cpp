#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

char /*clientes*/ idcliente[200][10], nome[200][50], cidade[200][30], uf[200][3], documento[200][20], telefone[200][50];
char linha[200], tmp[200];
char /*parcelas*/ idparcela[200][50], idcliente_p[200][50], datavenc[200][50], datapag[200][50], valor_p[200][50], codbanco[200][50];
int tot, p, col;
bool status_cliente[200], status_parcela[200];
FILE *file;

//----------------------------------------------------------------------------
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
//----------------------------------------------------------------------------
void le_dados(int valor)
{
   char *result;

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
         }
         tot++;
      }
      fclose(file);
      tot--;
   }
}
//----------------------------------------------------------------------------

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

void menu()
{
   int b1, val, lixo;
   bool sair;

   val = 0;
   sair = false;
   do
   {
      printf("IMPORTAR ARQUIVO [1]\n");
      printf("MOSTRAR DADOS [2]\n");
      printf("SAIR [3]\n");
      scanf("%i", &b1);

      if (b1 == 1)
      {
         system("cls");
         le_dados(0);
         le_dados(1);
         mostra_tudo();
         system("cls");
         printf("DADOS IMPORTADOS COM SUCESSO!\n");
         printf("\n");
         printf("\n");
         system("pause");
         system("cls");
         b1 = 0;
         val = 1;
      }

      if (b1 == 2)
      {
         if (val == 1)
         {
            system("cls");
            printf("----------DADOS DO CLIENTE----------\n");
            printf("ID: %s\n", idcliente[1]);
            printf("Nome do Cliente: %s\n", nome[1]);
            printf("Cidade: %s  Estado: %s\n", cidade[1], uf[1]);
            printf("Telefones: %s\n", telefone[1]);
            printf("----------DADOS DA PARCELA----------\n");
            printf("ID da Parcela: %s%s\n", idcliente_p[1], idparcela[1]);
            printf("Valor da Parcela: %s Código do Banco: %s", valor_p[1], codbanco[1]);
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
         }
         else
         {
            printf("PRIMEIRO IMPORTE OS ARQUIVOS!\n");
            printf("\n");
            printf("\n");
            system("pause");
            system("cls");
         }
         b1 = 0;
      }

      if (b1 == 3)
      {
         sair = true;
      }

   } while (sair == false);
}

//----------------------------------------------------------------------------
int main()
{
   setlocale(LC_ALL,"Portuguese");
   menu();
   getch();
}
