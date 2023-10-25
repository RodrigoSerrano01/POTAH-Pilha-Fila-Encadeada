#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
	
	
/* estrutura criada - item da pilha
   =================================*/
typedef struct reg
{
	int chave;
	struct reg *proximo;
}registro;


/* variaveis globais
   =================*/
registro *inicio;  /*ponteiro para o primeiro item da pilha*/
registro *fim;     /*ponteiro para o ultimo item da pilha*/
int controle;


/* prototipos
   ==========*/
int 	seleciona_menu(void);
void 	inclui_item(void);
void 	exclui_item(void);
void 	pilha(void);
void 	pesquisa_valor(void);
registro *percorre_fila(int);
void 	display(registro *);
registro *localiza_item(int);
void 	elimina_fila(void);


/*======================== FUNCOES ========================*/
int seleciona_menu(void)
{
	char s;
	system("cls");
	printf("\n\n");
	printf("1. Inserir um item\n");
	printf("2. Deletar um item\n");
	printf("3. Listar itens\n");
	printf("4. Pesquisar\n");
	printf("5. Sair\n");
	do
	{
		printf("\nOpcao : ");
		s = getch();
    }
	while(s<'0' || s>'5');
	system("cls");
	return s - 48;
}


void inclui_item(void)
{
	registro *aux;
	aux = (registro *)malloc(sizeof(registro));
	if(!aux)
	{
		printf("\n\n                   Sem Memoria");
		printf("<=======Digite qualquer tecla para continuar=======>");
		getch();
		exit(0);
	}
	printf("\n\n");
	printf("\nInsira o valor : ");
	scanf("%d",&aux->chave);
	if(fim==NULL)
	{
		inicio = aux;
	}
	else
		fim->proximo = aux;
	aux->proximo = NULL;
	fim = aux;
}

void exclui_item(void)
{
			inicio=inicio->proximo;
			if(inicio==NULL){
				fim=NULL;
				printf("Fila Vazia!");	
	}
}


registro *localiza_item(int val)
{
	registro *aux, *anterior;
	anterior = aux = inicio;
	if(val == inicio->chave)
	{
		controle = 1;
		return inicio;
	}
	else 
		aux = aux->proximo;
	while(aux)
	{
		if(val == aux->chave) 
			return anterior;
		anterior = aux;
		aux = aux->proximo;
	}
	printf("\n\n");
	printf("              Valor nao encontrado!\n");
	printf("<=======Digite qualquer tecla para continuar=======>");
	getch();
	return NULL;
}

void pilha(void)
{
	registro *aux;
	aux=inicio;
	if(inicio==NULL)
	{
		printf("\n\n");
		printf("                 Fila Vazia!\n");
		printf("<=======Digite qualquer tecla para continuar=======>");
		getch();
		return;
	}
	while(aux)
	{
		display(aux);
		aux=aux->proximo;
	}
	printf("\n\n");
	printf("<=======Digite qualquer tecla para continuar=======>");
	getch();
}

void display(registro *aux)
{
	printf("[%d]",aux->chave);
}



void pesquisa_valor(void)
{
	int val;
	registro *aux;
	if(inicio==NULL)
	{
		printf("\n\n");
		printf("                 Fila Vazia!\n");
		printf("<=======Digite qualquer tecla para continuar=======>");
		getch();
		return;
	}
	printf("\n\n");
	printf("\nInsira o valor a procurar: ");
	scanf("%d",&val);
	aux = percorre_fila(val);
	if(aux==NULL)
	{
		printf("\n\n");
		printf("              Valor nao encontrado!\n");
		printf("<=======Digite qualquer tecla para continuar=======>");
		getch();
	}
	else
	{
	display(aux);
	printf("\n\n");
	printf("<=======Digite qualquer tecla para continuar=======>");
	getch();
	}
}

registro *percorre_fila(int val)
{
	registro *aux;
	aux = inicio;
	while(aux)
	{
		if(val == aux->chave) 
			return aux;
		aux = aux->proximo;
	}
	return NULL;
}

void elimina_fila()
{
	registro *aux;
	aux = inicio;
	while(aux)
	{
		inicio = aux;
		aux = aux->proximo;
		free(inicio);
	}
}

main(void)
{
	inicio = fim = NULL;
	for(;;)
	{
		switch (seleciona_menu())
		{
			case 1:	inclui_item();
					break;
			case 2:	exclui_item();
					break;
			case 3:	pilha();
					break;
			case 4:	pesquisa_valor();
					break;
			case 5:	elimina_fila();
					exit(0);
		}
	}/*for*/
}
