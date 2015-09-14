/* Programa que cria um arquivo binario contendo numeros inteiros
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {

	clock_t t;
	

	if (argc < 3) {
		printf("Numero de argumentos insuficiente\n");
		printf("Uso: ./prog <nome_arquivo> <qtde_numeros>\n\n");
		return 0;
	}	

	FILE *f = fopen(argv[1], "w");

	t = clock();

	srand(time(NULL));

	int n = atoi(argv[2]); // total de elementos

	int i;
	for (i = 0 ; i < n; i++) {
		int valor = rand();
		fwrite(&valor, sizeof(int), 1, f);
	}		

	fclose(f);

	printf("%fs\n", (float)(clock()-t)/CLOCKS_PER_SEC);

	return 0;
}


/*
	1.Ideia geral 
	Programa que cria um arquivo binario contendo numeros inteiros

	2.Entendimento do programa
	Programa pega o nome do arquivo a ser criado, a quantidade N de
	números nesse arquivo e gera N números inteiros aleatórios. Por
	fim, ele escreve esses números num novo arquivo com o nome dado 
	pelo parametro.

	3-4.Tempo
	n = 10			0.000254s		
	n = 100			0.000132s
	n = 1000		0.000198s
	n = 10000		0.002509s
	n = 100000		0.016346s
	n = 1000000		0.086980s
	n = 10000000	0.752922s
	n = 100000000	7.491380s

	
*/