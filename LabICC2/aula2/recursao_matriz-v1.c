#include <stdio.h>
#include <stdlib.h>

void percorre_mat(int **mat, int l, int c, int n, int m) {

	static int num = 0;
	// 'visito' e marco a posicao l,c
	mat[l][c] = 1;

	// utiliza 4 vizinhos para percorrer a matriz
	// direita, cima, esquerda, baixo

	// direita
	if (c+1 < m) {
		if (mat[l][c+1] == 0) percorre_mat(mat, l, c+1, n, m);	
	}
	
	// cima
	if (l-1 >= 0) {
		if (mat[l-1][c] == 0) percorre_mat(mat, l-1, c, n, m);	
	}

	// esquerda
	if (c-1 >= 0) {
		if (mat[l][c-1] == 0) percorre_mat(mat, l, c-1, n, m);	
	}

	// baixo
	if (l+1 < n) {
		if (mat[l+1][c] == 0) percorre_mat(mat, l+1, c, n, m);	
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

	int **mat = (int **) calloc(n, sizeof(int *));
	int i;
	for (i = 0 ; i < n ; i++) {
		mat[i] = (int *) calloc(m, sizeof(int));
	}

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