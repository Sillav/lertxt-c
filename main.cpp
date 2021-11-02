#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

char /*clientes*/ idcliente[200][10], nome[200][50], cidade[200][30], uf[200][3], documento[200][20], telefone[200][50];
char linha[200], tmp[200];
char /*parcelas*/ idparcela[200][50], idcliente_p[200][50], datavenc[200][50], datapag[200][50], valor_p[200][50], codbanco[200][50];
int tot,p,col;
bool status[200];
FILE *file;

//----------------------------------------------------------------------------
void separa(){
    p = 0;
	 while (linha[col]!='"' && col<strlen(linha))  {
            tmp[p]=linha[col];
            col++; //posicao na linha
            p++; //posicao no campo
          }
          col=col+3;
          tmp[p]='\0';     
     }
//----------------------------------------------------------------------------
void le_dados(int valor){
char *result;

   if(valor == 0){
      file = fopen("CLIENTES.txt", "r");
      if (file == NULL){
     printf("ERRO ao abrir o arquivo CLIENTES.txt\n");
   }
   }
   if(valor == 1){
      file = fopen("PARCELAS.txt", "r");
      if (file == NULL){
     printf("ERRO ao abrir o arquivo PARCELAS.txt\n");
   }
   }
   if(file != NULL){
      tot=0;
	  while (!feof(file))
      {
	      if(valor == 0){
         result = fgets(linha, 200, file);
          if (linha[strlen(linha)-1]=='\n'){
             linha[strlen(linha)-1]='\0';
          }
         }

         if(valor == 1){
         result = fgets(linha, 200, file);
          if (linha[strlen(linha)-1]=='\n'){
             linha[strlen(linha)-1]='\0';
          }
         }
         col = 1;
   
         if(valor == 0){
         separa();
	      strcpy(idcliente[tot],tmp);
         separa();
	      strcpy(nome[tot],tmp);
	      separa();
	      strcpy(cidade[tot],tmp);
	      separa();
	      strcpy(uf[tot],tmp);
	      separa(); //lixo1
	      separa();
         strcpy(telefone[tot],tmp);
         separa(); //lixo
	      separa();
	      strcpy(documento[tot],tmp);  
         }

          if(valor == 1){
          separa();
          strcpy(idparcela[tot],tmp);
          separa();
          strcpy(idcliente_p[tot],tmp);
          separa();
          strcpy(datavenc[tot],tmp);
          separa();
          strcpy(datapag[tot],tmp);
          separa();
          strcpy(valor_p[tot],tmp);
          separa();
          strcpy(codbanco[tot],tmp);  
          }    
      tot++;   
      }
      fclose(file);	
      tot--;
   } 
   }
//----------------------------------------------------------------------------
int main()
{
   le_dados(0);
   le_dados(1);
   
   for (int x=0; x<tot; x++){
     printf("%s %s %s %s %s %s\n",idcliente[x],nome[x],cidade[x],uf[x], telefone[x], documento[x]);    
  }
  for (int x=0; x<tot; x++){
     printf("%s %s %s %s %s %s\n", idparcela[x], idcliente_p[x], datavenc[x], datapag[x], valor_p[x], codbanco[x]); 
  }
  system("pause");
   
}
