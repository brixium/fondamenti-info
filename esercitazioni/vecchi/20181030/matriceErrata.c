/* Input: una matrice. Visualizza 1 se è un quadrato magico. La somma dei numeri presenti in riga, colonna ed entrambe le diagonali sia lo stesso numero. Nel caso lo sia, stampo quel numero, in ogni altro caso stampo 0*/
#include <stdio.h>
#define DIM 3
#define OCCORRENZE 8
int main(int argc, char * argv[]){
	int m[DIM][DIM], i, j, magia, totale, sommina, parziale, pdp, pdm, controllo;
	for(i=0;i<DIM;i++){
		for(j=0;i<DIM;j++){
			scanf("%d", &m[i][j]);
		}
	}
	sommina = 0;
	totale = 0;
	controllo = 1;
	pdp = 0;
	pdm = 0;
	for(j=0; j<DIM; j++){
		sommina = sommina + m[0][j];
	}
	for(i=0; i<DIM && controllo; i++)
		for(j=0; j<DIM && controllo; j++){
			parziale = parziale + m[i][j];
			if(i==j)
				pdp = pdp + m[i][j];
		}
		if(parziale!=sommina)
			controllo=0;
		parziale = 0;
	}

	if(controllo == 0)
		magia = 0;
	else
		magia = sommina;

	return 0;
}
