/* Programa para demonstrar uso de recursao e comparacao com iteracao
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void percorre_mat(int **mat, int l, int c, int n, int m) {

	static int num = 0;
	if(mat[l][c] != -1){
		// 'visito' e marco a posicao l,c
		mat[l][c] = num++;
	}
		// utiliza 4 vizinhos para percorrer a matriz
		// direita, cima, esquerda, baixo

		// direita
		if (c+1 < m) {
			if (mat[l][c+1] == 0) percorre_mat(mat, l, c+1, n, m);	
		}
		// direita cima
		if (c+1 < m && l-1 >= 0) {
			if (mat[l-1][c+1] == 0) percorre_mat(mat, l-1, c+1, n, m);	
		}
		// direita baixo
		if (c+1 < m && l+1 < n) {
			if (mat[l+1][c+1] == 0) percorre_mat(mat, l+1, c+1, n, m);	
		}
		
		// cima
		if (l-1 >= 0) {
			if (mat[l-1][c] == 0) percorre_mat(mat, l-1, c, n, m);	
		}

		// esquerda
		if (c-1 >= 0) {
			if (mat[l][c-1] == 0) percorre_mat(mat, l, c-1, n, m);	
		}

		// esquerda cima
		if (c-1 >= 0 && l-1 >= 0) {
			if (mat[l-1][c-1] == 0) percorre_mat(mat, l-1, c-1, n, m);	
		}

		// esquerda baixo
		if (c-1 >= 0 && l+1 < n) {
			if (mat[l+1][c-1] == 0) percorre_mat(mat, l+1, c-1, n, m);	
		}

		// baixo
		if (l+1 < n) {
			if (mat[l+1][c] == 0) percorre_mat(mat, l+1, c, n, m);	
		}
	
}

void bloqueio(int **mat, int n, int m, int p){
	int nbloqueios = (p * n * m)/100;

	int i = 0;
	int x;
	int y;

	srand(time(NULL));

	while(i < nbloqueios){
		x = rand() % n;
		y = rand() % m;
		if(mat[x][y] != -1)	mat[x][y] = -1;
		i++;
	}
}

int main(int argc, char * argv[]) {

	if (argc < 3) {
		printf("Numero incorreto de parametros\n");
		printf("Uso: ./prog <linhas> <colunas> \n");
		return 0;
	}
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	int p = atoi(argv[3]);
	if(p < 0 || p > 100){
		printf("Parametro P deve ser entre 0 e 100");
		return -1;
	}

	int **mat = (int **) calloc(n, sizeof(int *));
	int i;
	for (i = 0 ; i < n ; i++) {
		mat[i] = (int *) calloc(m, sizeof(int));
	}

	bloqueio(mat, n, m, p);

	percorre_mat(mat, 0, 0, n, m);

	int j;
	for (i = 0 ; i < n ; i++) {
		for (j = 0; j < m; j++) {
			printf("%d\t", mat[i][j]);
		}
		printf("\n\n");
		free(mat[i]);
	}
	free(mat);

	return 0;
}	