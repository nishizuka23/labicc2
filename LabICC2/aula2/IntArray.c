#include "IntArray.h"
#include <time.h>


INT_ARRAY* createRandom(long int size){
	INT_ARRAY * a = (INT_ARRAY *) malloc (sizeof(INT_ARRAY));
	srand(time(NULL));
	int i;
	for(i = 0; i < size; i++){
		a->array[i] = rand() % 100000000;
	}
	a.size = size;

	return a;
}

INT_ARRAY* createFromFile(char* filename){
	INT_ARRAY * a = (INT_ARRAY *) malloc (sizeof(INT_ARRAY));
	FILE *f = fopen(filename, "r");
	fread(&a, sizeof(INT_ARRAY), 1, f);
	fclose(f);
	return a;
}

void saveInFile(INT_ARRAY* intArray, char* filename){
	FILE *f = fopen(filename, "w");
	fwrite(&intArray, sizeof(INT_ARRAY), 1, f);
	fclose(f);
}

long int getSize(INT_ARRAY* intArray){
	return intArray->array / sizeof(int);
}

void bubbleSort(INT_ARRAY* intArray){
	int n = getSize(intArray);
	int i, j;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n-1; i++) {
			if (intArray->array[i] > intArray->array[i+1]) {
				int aux = intArray->array[i];
				intArray->array[i] = intArray->array[i+1];
				intArray->array[i+1] = aux;
			}
		}
	}
} 

void insertionSort(INT_ARRAY* intArray){
	int n = getSize(intArray);
	int i,j;

	for (i = 1; i < n; i++) {
		int chave = intArray->array[i];
		j = i-1;
		while (j >= 0 && intArray->array[j] > chave) {
			intArray->array[j+1] = intArray->array[j];
			j--;
		}
		intArray->array[j+1] = chave;
	}
}

long int sequencialSearch(INT_ARRAY* intArray, int key){
	int n = getSize(intArray);
	long int i;
	for (i = 0; i < n; i++) {
		if (intArray->array[i] == key) {
			return i;
		}
	}
	return -1;
}

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


long int binarySearch(INT_ARRAY* intArray, int key){
	int n = getSize(intArray);
	return buscaBinaria(intArray->array, 0, n-1, key);
}