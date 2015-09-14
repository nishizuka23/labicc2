/* Programa que recebe um arquivo e uma chave como entrada
	e tenta encontrar a chave no arquivo
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* funcao que recebe uma chave e tenta encontrar
	essa chave dentro do vetor
   Parametros:
	int * vet : vetor com os numeros
	int n     : tamanho do vetor
	int chave : chave a procurar em 'vet'

   Retorno: long int
	(0, n-1)  : se a chave existir em 'vet'
	-1        : busca sem sucesso
*/
long int buscaSequencial(int *vet, int n, int chave) {

	long int i;
	for (i = 0; i < n; i++) {
		if (vet[i] == chave) {
			return i;
		}
	}
	return -1;
}


/* algoritmo que realiza busca binaria
   Parametros:
	int * vet : vetor com os numeros
	int n     : tamanho do vetor
	int chave : chave a procurar em 'vet'

   Retorno: long int
	(0, n-1)  : se a chave existir em 'vet'
	-1        : busca sem sucesso
*/
long int buscaBinaria(int * vet, int ini, int fim, int chave) {

	if (ini > fim) {
		return -1;
	}

	long int centro = (int)((ini+fim)/2.0);

	// busca com sucesso	
	if (vet[centro] == chave) {
		return centro;
	}
	if (chave < vet[centro]) {
		return buscaBinaria(vet, ini, centro-1, chave);
		// fim = centro-1; // iterativa
	}
	if (chave > vet[centro]) {
		return buscaBinaria(vet, centro+1, fim, chave);
		// ini = centro+1; // iterativa
	}
	
}

/* ordenacao BubbleSort
	funciona comparando pares de elementos, e levando o maior
	elemento para o fim do vetor

	Algoritmos de ordenacao a contagem eh feita apenas
	nas operacoes de comparacao e troca/movimentacao de valores no vetor

   Parametros:
	int * v : vetor de inteiros a ser ordenado
	int n   : tamanho do vetor
*/
void bubbleSort(int *v, int n) {
	int i, j;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n-1; i++) {
			if (v[i] > v[i+1]) {
				int aux = v[i];
				v[i] = v[i+1];
				v[i+1] = aux;
			}
		}
	}
} 
/* ordenacao InsertionSort
	funciona assumindo que existe uma parte do vetor ordenada,
	para cada elemento tenta encontrar a posicao correta na parte
	ordenada do vetor

   Parametros:
	int * v  : vetor a ordenar
	int  n   : tamanho do vetor
*/
void insertionSort(int *v, int n) {
	int i,j;
	
	for (i = 1; i < n; i++) {
		int chave = v[i];
		j = i-1;
		while (j >= 0 && v[j] > chave) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = chave;
	}
}


int * geraVetorAleatorio(int n) {
	int *aloca = (int *) malloc(sizeof(int) * n);	
	int i;
	for (i = 0; i < n; i++) {
		aloca[i] = rand()%1000000;
	}
	return aloca;
}

int * geraVetorSequencial(int n) {
	int *aloca = (int *) malloc(sizeof(int) * n);	
	int i;
	for (i = 0; i < n; i++) {
		aloca[i] = i;
	}
	return aloca;
}


int main(int argc, char* argv[]) {

	if (argc < 6) {
		printf("Numero de argumentos insuficiente\n");
		printf("Uso: ./prog <tam_vetor> <chave> <tipo_busca>\n");
		printf("\t<tipo> = 1 sequencial, 2 binaria\n\n");
		printf("\t<sort> = 1 bubble, 2 insertion\n");
		printf("\t<tipo_vetor> = 1 aleatorio, 2 sequencial\n");
		return 0;
	}	

	int n = atoi(argv[1]); // tamanho do vetor
	int chave = atoi(argv[2]); // numero a buscar nos dados
	int op = atoi(argv[3]);
	int sort = atoi(argv[4]);
	int tipovet = atoi(argv[5]);

	int * vet;
	if(tipovet == 1)
		vet = (int *)geraVetorAleatorio(n);
	else if (tipovet == 2)
		vet = (int *)geraVetorSequencial(n);
	printf("exemplos: %d, %d\n", vet[n-2], vet[n-1]);

	long int pos;

	clock_t c1;

	if (op == 1) {
		fprintf(stdout,"Realizando busca...\n");
		fflush(stdout);
		c1 = clock();
		pos = buscaSequencial(vet, n, chave);
		printf("busca: %.6fs\n", (float)(clock()-c1)/CLOCKS_PER_SEC);
	} else if (op == 2) {
		fprintf(stdout,"Ordenando...\n");
		fflush(stdout);
		c1 = clock();
		if(sort == 1)
			bubbleSort(vet, n); // nao usar - dica do Obama
		else if(sort == 2)
			insertionSort(vet, n);
		printf("sort: %.6fs\n", (float)(clock()-c1)/CLOCKS_PER_SEC);
		fprintf(stdout,"Realizando busca...\n");
		fflush(stdout);
		c1 = clock();
		pos = buscaBinaria(vet, 0, n-1, chave);
		printf("busca: %.6fs\n", (float)(clock()-c1)/CLOCKS_PER_SEC);
	}


	if (pos == -1) {
		printf("Valor nao encontrado\n\n");
	} else {
		printf("Valor encontrado na posicao: %ld\n\n", pos);
	}

	free(vet);


	return 0;
}
