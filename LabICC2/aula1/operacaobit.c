/* Programa para demonstrar operacoes bit a bit
	com uso dos parametros da funcao main

	Moacir - ICMC/USP 2015
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[]) {

	clock_t t;

	int i;
	printf("\n\n");

	int num = atoi(argv[1]);

	t = clock();

	for(i = 0; i < 10000000;i++){
		num << atoi(argv[2]);
	}

	printf("%fs\n", (float)(clock() - t)/CLOCKS_PER_SEC);

	t = clock();
	for(i = 0; i < 10000000;i++){
		num*64;
	}		
	
	printf("%fs\n", (float)(clock() - t)/CLOCKS_PER_SEC);

	return 0;
}


/*
	Este codigo visa mostrar a diferença entre as operações
	de deslocamento de bits e a multiplicação. Porém, o 
	compilador(gcc) otimiza o código, transformando a multi-
	plicação em descolamento 
*/
