/*
*	Esercizio 5
*	sempre 2 array
*	il secondo è = oppure più piccolo del primo. Verifica se il secondo è contenuto nel primo. Restituisce 1 se è vero, 0 altrimenti. 2 variabili che dobbiamo sapere
*/

int 

int main(int argc, char * argv[]){
	
	return 0;
}

int arrayinarray(int map[][NCBIG], int search[][NCSMALL], int nrm, int ncm, int nrs, int ncs){
	int i,j;
	int maxrow, maxcol;

	maxcol = ncm - ncs + 1;
	maxrow = nmr - mrs + 1;
	for(i=0; i<maxrow; i++)
		for(j=0; j<maxcol; j++)
			if(map[i][j] == search[0][0])
				if(overlap(map, search, nrs, ncs, i, j))
					return 1;
	return 0;
}

int overlap(int m1[][NCBIG], int m2[][NCSMALL], int nr, int nc, int istart, int jstart){
	int i, j;

	for(i=0; i<nr; i++)
		for(j=0; j<nc; j++)
			if(m1[istart+i][jstart+j] != m2[i][j])
				return 0;
	return 1;
}
