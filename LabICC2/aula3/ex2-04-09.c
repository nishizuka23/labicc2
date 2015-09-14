#include "ex2.h"


int main(){

	lista* l;
	int fila1, fila2;

	fila1 = 0;
	fila2 = 0;
	int idade;

	l = cria_lista();
	while(scanf("%d", &idade) != EOF){
		insere(l,idade);
		
	}
	while(!vazia(l)){
		fila1++;
		if(remove_fila(l) >= 60){
			fila2++;
			printf("%d - %d\n", fila2, fila1);
		}
		
	}

	return 0;
}

