/*Esercizio 3*/

int replaceSquares(int v[], int dim){
	int i, nmod;
	double rad;

	nmod = 0;
	for(i=0; i<dim; i++){
		rad = sqrt(v[i]);
		if(rad == (int)rad){ /*trovo il quadrato perfetto*/
			v[i] = rad;
			nmod++;
		}
	}
	return nmod;
}
/* Non l'ho copiato tutto, non stressate pls
int replaceSquareNoSqrt(int v[], int dim){
	int i, nmod, rad, prod;
	
	nmod = 0;
	for(i=0; i<dim; i++){
		rad = 1;
		prod = rad*rad;
		while(prod< v[i]){
			rad++;
			prod = rad * rad;
		}
		if(prod == v[i]){
			v[i] = rad;
			nmod++;
		}
	}
	return nmod;
}
*/
/*uccidetemi pls*/
