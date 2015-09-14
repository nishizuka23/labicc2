/* Programa que demonstra o uso da memoria heap
	Moacir - ICMC/USP 2015

	Objetivo: usuario entra com um valor "n"
		  e o programa aloca na memoria 'n' espacos
		  para palavras com 10 caracteres
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char ** alocaVetor(int n) {
	char ** temp = (char **) malloc(sizeof(char *) * n);
	int i;
	for (i = 0; i < n; i++) {
		temp[i] = (char *) malloc(sizeof(char) * 10);
	}
	return temp;
}

int main(int argc, char *argv[]) {

	int n;
	scanf("%d", &n);

	char** vetor = NULL;
	int i;

	vetor = alocaVetor(n);	
	for (i = 0; i < n; ++i){
		printf("%p\n", &vetor[i][0]);
		printf("%p\n", &vetor[i][1]);
		printf("%p\n", &vetor[i][2]);
		printf("%p\n", &vetor[i][3]);
		printf("%p\n", &vetor[i][4]);
		printf("%p\n", &vetor[i][5]);
		printf("%p\n", &vetor[i][6]);
		printf("%p\n", &vetor[i][7]);
		printf("%p\n", &vetor[i][8]);
		printf("%p\n", &vetor[i][9]);
	}

	vetor[0][3] = 'I';

	strcpy(vetor[1], "Bem vindo");

	for (i = 0; i < n; i++) {
		free(vetor[i]);
	}
	free(vetor);
	
	return 0;
}

/*
Endereços do vetor de 10 strings
0x9f3070
0x9f3090
0x9f30b0
0x9f30d0
0x9f30f0
0x9f3110
0x9f3130
0x9f3150
0x9f3170
0x9f3190

Na saída do programa podemos observar um 'salto' que ocorre
entre o final da string com o ponteiro seguinte. Uma explicação
para isso seria o SO alocar um espaço adicional(no caso 16bits)
para cada ponteiro.

*/
