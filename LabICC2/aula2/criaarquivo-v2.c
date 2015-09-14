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
		fwrite(&i, sizeof(int), 1, f);
	}		

	fclose(f);

	printf("%fs\n", (float)(clock()-t)/CLOCKS_PER_SEC);

	return 0;
}

/*
	n = 10				0.000104s
	n = 100				0.000180s
	n = 1000			0.000204s
	n = 10000			0.001440s
	n = 100000			0.011550s
	n = 1000000			0.070844s
	n = 10000000		0.658332s
	n = 100000000		6.415646s
*/