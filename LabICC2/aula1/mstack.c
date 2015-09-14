/* Programa que demonstra o uso da memoria stack

	Moacir Ponti - ICMC/USP 2015
*/
#include <stdio.h>

int counter;

void funcaoexemplo(int soma) {

	static float num = 1.0f;
	num += (float)soma;
	char a;
	printf("Enreceço de a na função: %p\n", &a);
	printf("Endereço de num: %p\n", &num);
	printf("Endereço de soma: %p\n", &soma);

	counter = 10;
}

int main (int argc, char *argv[]) {

	counter = 0;
	funcaoexemplo(3);	
	
	char a;	char b;	float c;
	printf("Endereço de counter: %p\n", &counter);
	printf("Enreceço de a: %p\n", &a);
	printf("Enreceço de b: %p\n", &b);
	printf("Enreceço de c: %p\n", &c);

	return 0;
}

/*
	Aluno: Eduardo Tadahiro Nishizuka 7696393

	Neste exemplo podemos ver os endereços das variáveis, 
	onde estão alocadas e suas diferenças.

	Podemos perceber que as variaveis "num" e "counter"
	são alocadas seguidamente, porém numa posição total-
	mente diferente das demais variáveis.
*/