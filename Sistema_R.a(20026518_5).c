#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define Max 100

 typedef struct obra{
 	int tipo;
	char titulo[Max];
	char edicao[Max];
	char autor[Max];
	char editora[Max];
	char isbn[Max];
	char nEx[Max]; 
	int caixa;
	char ano[Max];
}produto;

	int escolha, i=0,nobras=0;
	void cadastrar();
	int cadastrarLivro(produto livro[]);
	int cadastrarRevista(produto revista[]);
	void listarlivros(produto livro[]);
	void listarRevistas(produto revista[]);
	int ListarPorCaixa();
	int ler_arquivoL(produto livro[] );
	produto livro[Max];
	produto revista[Max];

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	
	printf("/##############################################################################/ \n */R.A: 20026518-5; Lucas Vinícius Sampaio Lima; Engenharia de Software./* \n/##############################################################################/\n\n");
	
	printf("Menu:\n\n 1-Cadastrar obra; \n\n 2-Apresentar todos os livros; \n\n 3-Apresentar todas as revistas; \n\n 4-Apresentar obras por caixa; \n\n 5-Para encerrar; \n\n Digite um valor: ");
    scanf("%d", &escolha);
    
    while(escolha!=5)
	{	
		switch(escolha)
		{		
			case 1:
				
				cadastrar();
				system("pause");
				
			break;
			
			case 2:
				
				listarlivros(livro);	
				
			break;
			
			case 3:
				
				listarRevistas(revista);		
				
			break;
			
			case 4:
				
				ListarPorCaixa();
				
			break;
			
			default:
				
				system("cls");
				printf("Voce digitou uma opcao invalida. Por favor tente novamente.\n\n");
				system("pause");
				
			break;	
		}
		system("cls");
		printf("#/R.A: 20026518-5; Lucas Vinicius Sampaio Lima; Engenharia de Software./# \n\n");
	
		printf("Menu:\n\n 1-Cadastrar um livro \n\n 2-Apresentar todos os livros: \n\n 3-Apresentar todas as revistas: \n\n 4-Apresentar obras por caixa: \n\n 5-Para encerrar: \n\n Digite um valor: ");
		fflush(stdin);
    	scanf("%d", &escolha);			
	}
	return 0;
}

int ler_arquivoL(produto livro[])
{		
	FILE*arq = fopen("arquivo.txt", "r+");
	if(arq != NULL)
	{
		int i =0;
		while(1)
		{
			produto p;
			size_t r = fread(&p, sizeof(produto), 1, arq);
			if(r< 1)
			break;
			else
			livro[i++]=p;
		}
		fclose(arq);
		return i;
	}
	else{
		printf("\nErro em abrir o arquivo para a leitura!\n");
		exit(1);
	}	
}

void cadastrar()
{
	system("cls");
	
	printf("/##############################################################################/ \n */R.A: 20026518-5; Lucas Vinícius Sampaio Lima; Engenharia de Software./* \n/##############################################################################/\n\n");

	printf(" Cadastrar obra: \n\n 1-Livro; \n\n 2-Revista; \n\n 3-Voltar;\n\n Digite um valor:");
	fflush(stdin);
	scanf("%d", &escolha);
	
		
	while(escolha!=3)
	{
					
		if(escolha==1)
		{	
			cadastrarLivro(livro);				
		}
		
		if(escolha==2)
		{
			cadastrarRevista(revista);
						
		}	
		
		system("cls");
		
		printf("/##############################################################################/ \n */R.A: 20026518-5; Lucas Vinícius Sampaio Lima; Engenharia de Software./* \n/##############################################################################/\n\n");
		
		printf(" Cadastrar obra: \n\n 1-Livro; \n\n 2-Revista; \n\n 3-Voltar;\n\n Digite um valor:");
		fflush(stdin);
		scanf("%d", &escolha);
	}	
}

int cadastrarLivro(produto livro[])
{
	printf("Quantos livros você irá cadastrar:");
	fflush(stdin);
	scanf("%d", &nobras);
			       			
	for(i=0;i<nobras;i++)
	{
			   	
		FILE* arq;
		arq= fopen("arquivo.txt", "a+");
		 
						
		if(arq == NULL)
 		{
 			printf("O arquivo não foi aberto! \n");
 			return 1;
 		}
		else
		{ 
 			system("cls");
			printf("Cadastro de Livro\n");
			
			livro[i].tipo= escolha;	
			
			printf("\n Qual o titulo do livro: ");
            fflush(stdin);
			gets(livro[i].titulo);
					
			printf("\n Qual o Nº da edição do livro: ");
			setbuf(stdin, NULL);
			scanf("%s", livro[i].edicao);
								
			printf("\n Qual o ano de lançamento desta edição: ");
			setbuf(stdin, NULL);
			scanf("%s", livro[i].ano);
					
			printf("\n Qual o nome do autor(a) do livro: ");
			fflush(stdin);
			gets(livro[i].autor);
				
			printf("\n Qual o nome da editora do livro: ");
			fflush(stdin);
			gets(livro[i].editora);
			
			printf("\n Qual o ISBN do livro : ");
			setbuf(stdin, NULL);
			scanf("%s", livro[i].isbn);
					
			printf("\n Quantos exemplares possui o livro: ");
			fflush(stdin);
			scanf("%s", livro[i].nEx);
				
			printf("\n Qual caixa o livro está armazenado: ");
			fflush(stdin);
			scanf("%d", &livro[i].caixa);
			    				
		    fwrite(&livro[i], sizeof(produto),1, arq);	
			    	
			fclose(arq);		
		}	
	}
}
	
void listarlivros(produto livro[])
{
	int j;
	
	system("cls");
	
		printf("/##############################################################################/ \n */R.A: 20026518-5; Lucas Vinícius Sampaio Lima; Engenharia de Software./* \n/##############################################################################/\n\n");
	
	printf("Cadastro de Livro: \n \n");
	
	FILE*arq;
	arq= fopen("arquivo.txt", "r");
	fread(livro, sizeof(int), 1, arq);
	
	int len_vet = ler_arquivoL(livro);
	
	for(j=0; j< len_vet; j++)
	{
		if(livro[j].tipo==1)
		{	
			printf("Livro \n\nTitulo: %s", livro[j].titulo );
			printf("\nEdição Nº: %s ", livro[j].edicao);
			printf("\nAno de lançamento desta edicao: %s ", livro[j].ano);
	  		printf("\nAutor: %s  ", livro[j].autor);
	  		printf("\nEditora: %s ", livro[j].editora);
    		printf("\nISBN: %s", livro[j].isbn);
			printf("\nExemplares disponiveis: %s ", livro[j].nEx);
	  	    printf("\nEstá armazenado na caixa: %d", livro[j].caixa);					
      		printf("\n/#############################################################/\n\n");
		}
	}
	printf("Pressione qualquer tecla para voltar:");
	fclose(arq);
	getch();	
}
	
int cadastrarRevista(produto revista[])
{
	printf("Quantas revistas você irá cadastrar:");
	fflush(stdin);
	scanf("%d", &nobras);
	
	for(i=0;i<nobras;i++){
			FILE* arqui;
	arqui= fopen("arquivo.txt", "a+");
					
	if(arqui== NULL)
 	{
 		printf("O arquivo não foi aberto! \n");
 		return 1;
 	}
	else
	{
		system("cls");
		printf(" Cadastro de Revista\n");
							
			revista[i].tipo= escolha;
			
         	printf("\n Qual o titulo da revista:");
          	fflush(stdin);
			gets(revista[i].titulo);
						
			printf("\n Qual o Nº da edição da revista:");
			setbuf(stdin, NULL);
			scanf("%s", revista[i].edicao);
				   				
			printf("\n Ano de lançamento desta edicao:");
			setbuf(stdin, NULL);
			scanf("%s", revista[i].ano);
				
			printf("\n Qual o nome do autor(a) da revista:");
			fflush(stdin);
			gets(revista[i].autor);			
				
			printf("\n Qual a editora da revista:");
			fflush(stdin);
			gets(revista[i].editora);
							
			printf("\n Qual o ISBN da revista :");
			setbuf(stdin, NULL);
			scanf("\n%s", revista[i].isbn);
				
			printf("\n Quantos exemplares possui a revista:");
			fflush(stdin);
			scanf("%s", revista[i].nEx);
					
			printf("\n Qual caixa a revista está armazenado:");
			fflush(stdin);
			scanf("%d", &revista[i].caixa);
			
			fwrite(&revista[i], sizeof(produto),1, arqui); 			
				        
			fclose(arqui);
		}	
	}
}	
	
void listarRevistas(produto revista[])
{	
	system("cls");
	
	printf("/##############################################################################/ \n */R.A: 20026518-5; Lucas Vinícius Sampaio Lima; Engenharia de Software./* \n/##############################################################################/\n\n");
	
	printf("Cadastro de Revista: \n \n");
	
	FILE*arqui;
	arqui= fopen("arquivo.txt", "r");
	
	fread(revista, sizeof(int), 1, arqui);
	int len_vet = ler_arquivoL(revista);
	
	int j;
	
	for(j=0; j< len_vet; j++)
	{	
		if(revista[j].tipo==2)
		{
			printf("Revista \n\nTitulo: %s", revista[j].titulo );
			printf("\nEdição Nº: %s ", revista[j].edicao);
			printf("\nAno de lançamento desta edicao: %s ", revista[j].ano);
			printf("\nAutor: %s  ", revista[j].autor);
	 		printf("\nEditora: %s ", revista[j].editora);
	 		printf("\nISBN: %s", revista[j].isbn);
	  		printf("\nExemplares disponiveis: %s ", revista[j].nEx);
      	    printf("\nEstá armazenado na caixa: %d", revista[j].caixa);					
      		printf("\n/#############################################################/\n\n");
		}
	}
	printf("Pressione qualquer tecla para voltar:");
	fclose(arqui);
	getch();	
}				

int ListarPorCaixa()
{
	int j;
	system("cls");
	
	printf("/##############################################################################/ \n */R.A: 20026518-5; Lucas Vinícius Sampaio Lima; Engenharia de Software./* \n/##############################################################################/\n\n");
	
	printf("Qual caixa deseja abrir: \n\n 1-Caixa Um; \n 2-Caixa Dois; \n 3-Caixa Três;\n 4-Voltar; \n\n Digite um valor: ");
	scanf("%d", &escolha);
	
	while(escolha!=4)
	{		
		if(escolha==1)
		{
			system("cls");
			printf("Caixa 1: \n \n");

			FILE*arq;
			arq= fopen("arquivo.txt", "r");
			fread(livro, sizeof(int), 10, arq);
	
			int len_vet = ler_arquivoL(livro);

			for(j=0; j< len_vet; j++)
			{
      			if((livro[j].caixa==1)||(revista[j].caixa==1))
				{	
					if(livro[j].tipo==1){
						printf("Livro: \n");
					}
					else
					{
						if(livro[j].tipo==2){
							printf("Revista:\n");
						}
					}
				  	printf(" \n\nTitulo: %s", livro[j].titulo );
					printf("\nEdição Nº: %s ", livro[j].edicao);
					printf("\nAno de lançamento desta edicao: %s ", livro[j].ano);
	  				printf("\nAutor: %s  ", livro[j].autor);
	  				printf("\nEditora: %s ", livro[j].editora);
    				printf("\nISBN: %s", livro[j].isbn);
					printf("\nExemplares disponiveis: %s ", livro[j].nEx);
	   				printf("\nEstá armazenado na caixa: %d", livro[j].caixa);					
      				printf("\n/#############################################################/\n\n");
				}					
			}
			fclose(arq);
			system("pause");		
		}
		if(escolha==2)
		{
			system("cls");
			printf("Caixa 2: \n \n");
			
			FILE*arq;
			arq= fopen("arquivo.txt", "r");
			fread(livro, sizeof(int), 10, arq);
	
			int len_vet = ler_arquivoL(livro);

			for(j=0; j< len_vet; j++)
			{
			
      			if((livro[j].caixa==2)||(revista[j].caixa==2))
				{
						if(livro[j].tipo==1){
						printf("Livro: \n");
					}
					else
					{
						if(livro[j].tipo==2){
							printf("Revista:\n");
						}
					}
					printf(" \n\nTitulo: %s", livro[j].titulo );
					printf("\nEdição Nº: %s ", livro[j].edicao);
					printf("\nAno de lançamento desta edicao: %s ", livro[j].ano);
	  				printf("\nAutor: %s  ", livro[j].autor);
	  				printf("\nEditora: %s ", livro[j].editora);
    				printf("\nISBN: %s", livro[j].isbn);
					printf("\nExemplares disponiveis: %s ", livro[j].nEx);
	  				printf("\nEstá armazenado na caixa: %d", livro[j].caixa);					
      				printf("\n/#############################################################/\n\n");  	    
				}		
			}
			fclose(arq);
			system("pause");						
		}
		if(escolha==3)
		{
	
			system("cls");
			printf("Caixa 3: \n \n");
			
			FILE*arq;
			arq= fopen("arquivo.txt", "r");
			fread(livro, sizeof(int), 10, arq);
			
			int len_vet = ler_arquivoL(livro);

			for(j=0; j< len_vet; j++)
			{
			
      			if((livro[j].caixa==3)||(revista[j].caixa==3))
				{
						if(livro[j].tipo==1){
						printf("Livro: \n");
					}
					else
					{
						if(livro[j].tipo==2)
						{
							printf("Revista:\n");
						}
					}
					printf(" \n\nTitulo: %s", livro[j].titulo );
					printf("\nEdição Nº: %s ", livro[j].edicao);
					printf("\nAno de lançamento desta edicao: %s ", livro[j].ano);
	  				printf("\nAutor: %s  ", livro[j].autor);
	  				printf("\nEditora: %s ", livro[j].editora);
    				printf("\nISBN: %s", livro[j].isbn);
					printf("\nExemplares disponiveis: %s ", livro[j].nEx);
	  				printf("\nEstá armazenado na caixa: %d", livro[j].caixa);					
      				printf("\n/#############################################################/\n\n");     
				}			
			}
			fclose(arq);
			system("pause");	
		}
		system("cls");
		printf("Qual caixa deseja abrir: \n\n 1-Caixa Um; \n 2-Caixa Dois; \n 3-Caixa Três;\n 4-Voltar; \n\n Digite um valor: ");
		fflush(stdin);
		scanf("%d", &escolha);
	}
}
