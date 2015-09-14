#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	struct no* prox;
	int idade;
}no;

typedef struct lista{
	no* ini;
} lista;


void insere(lista*,int);
int remove_fila(lista*);
int vazia(lista*);
lista* cria_lista();