#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registro()
{
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);// copiar os valores da string
	
	FILE *file; // cria o arquivo dentro do banco de dados 
	file = fopen(arquivo, "w");//cria o arquivo 
	fprintf(file, cpf);// salva o valor da variavel no arquivo 
	fclose(file);// fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser Cadastrado:");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o Sobrenome a ser Cadastrado:");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	

	printf("Digite o cargo a ser Cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
			
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
	char conteudo[100];
	
	printf(" Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");// consultar/ ler oque tem no cpf
	
	if(file == NULL)// validaçao de numeros nulos 
	{
	   printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}	
	
	while(fgets(conteudo, 100, file) != NULL)// validação do enquanto
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Usuario nao Encontrado no Sistema !!.\n");
		system("pause");
	}	
	
}


int main()
    {
    int opcao=0;// Definindo Variaveis 
    int laco=1;

    for(laco=1;laco=1;)
    {
	
	   system("cls");

	   setlocale(LC_ALL, "Portuguese");//Definindo idioma 
	
 	   printf("***Cartório Da EBAC***\n\n");//inicio menu
	   printf("Abaixo, Selecione a Opção Desejada:\n\n");
	   printf("\t 1-Registrar Nomes\n\n");
	   printf("\t 2- Consultar Nomes\n\n");
	   printf("\t 3- Deletar Nomes\n\n");//fim menu 
	   printf("\t 4- Sair do Sistema\n\n");
	
       scanf("%d", &opcao);//armazenando a escolha do usuario 
    
       system("cls");
       
       switch(opcao)//incio de seleção 
       {
       	  case 1:
       	  registro();
    	  break;
    	  
    	  case 2:
    	  consulta();
    	  break;
    	  
    	  case 3:
    	  deletar();
		  break;
		  
		  case 4:
		  printf(" Obrigado por utilizar o Sistema !!\n");
		  return 0;
		  break;
		  
		  
		  default:
		  printf("Essa opção não está disponivel...");
		  system("pause");
		  break;
	   }
	 
		  
    }
}

