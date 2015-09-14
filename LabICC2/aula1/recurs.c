/* Programa para demonstrar uso de recursao e comparacao com iteracao

	
*/

#include <stdio.h>
#include <time.h>

int fibo_rec(int m) {
	// casos triviais/base
	static int count = 0;
	static int count1 = 0;
	count++;
	printf("%d\n", count);
	if (m == 1 || m == 2) {
		count1++;
		printf("count: %d\n", count1);
		return 1;
	} else {
		return fibo_rec(m-1) + fibo_rec(m-2);
	}
}

// iterativo
int fibo_iter(int m) {
	int f1 = 0;
	int f2 = 1;
	int i = 0;
	for (i = 0; i < m; i++) {
		f2 = f1+f2;
		f1 = f2-f1;
	}
	return f1; 
}

int main(int argc, char * argv[]) {
	clock_t t;
	if (argc < 2) {
		printf("Numero incorreto de parametros\n");
		printf("Uso: ./prog <numero_serie_fibonacci>\n");
		return 0;
	}
	int m = atoi(argv[1]);

	t = clock();

	printf("Iterativo: ");
	printf("%d\n\n", fibo_iter(m));			

	printf("Recursivo: ");
	printf("%d\n\n", fibo_rec(m));			
	
	printf("%fs\n",(float)(clock() - t)/CLOCKS_PER_SEC);
	return 0;
}

/*
	n = 10 	0.000035s	9 iteraçoes			5x fib(1)
	n = 15	0.000058s	109 iteracoes		55x fib(1)
	n = 20	0.000158s	1219 iteracoes		610x fib(1)
	n = 25	0.001130s	13529 iteracoes 	6765x fib(1)
	n = 30	0.007857s	150049 iteracoes 	75025x fib(1)
	n = 35	0.103931s
	n = 40	1.012813s
	n = 45	10.823347s
*/
