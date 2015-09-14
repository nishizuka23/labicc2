#include "ex2.h"

void insere(lista* l, int n){
	no* e = l->ini;

	no* aux = (no*) malloc (sizeof(no));
	aux->idade = n;
	aux->prox = NULL;
	if(e != NULL){
		while(e->prox != NULL){
			e = e->prox;
		}
		e->prox = aux;
	}
	else 
		l->ini = aux;
	return;
}

int remove_fila(lista* l){
	no* aux;
	aux = l->ini;
	l->ini = l->ini->prox;
	return aux->idade;
}

int vazia(lista* l){
	if(l->ini == NULL)
		return 1;
	return 0;
}

lista* cria_lista(){
	lista* l;
	l = (lista*) malloc (sizeof(lista));
	l->ini = NULL;
	return l;
}