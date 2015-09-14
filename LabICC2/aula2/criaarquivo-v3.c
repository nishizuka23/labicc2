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

	FILE *f = fopen(argv[1], "rw");

	

	srand(time(NULL));

	int n = atoi(argv[2]); // total de elementos

	int i;

	t = clock();
	for (i = 0 ; i < n; i++) {
		fwrite(&i, sizeof(int), 1, f);
	}		
	printf("%fs\n", (float)(clock()-t)/CLOCKS_PER_SEC);

	rewind(f);

	t = clock();

	for (i = 0 ; i < n; i++) {
		fread(&i, sizeof(int), 1, f);
	}
	printf("%fs\n", (float)(clock()-t)/CLOCKS_PER_SEC);

	

	fclose(f);
	return 0;
}

/*
	Comparação: 
	n = 10 			0.000003s
					0.000010s

	n = 100			0.000005s
					0.000009s

	n = 1000		0.000043s
					0.000034s

	n = 10000		0.000561s
					0.000424s

	n = 100000 		0.006876s
					0.004076s

	n = 1000000		0.053376s	
					0.022138s

	n = 10000000	0.345089s
					0.220467s

	n = 100000000	3.278737s
					2.182946s






*/