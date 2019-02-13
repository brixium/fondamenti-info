#define N 10
#define ACOL 2
typedef struct punto_s{
	int x;
	int y;
}punto_t;
int checkDistanza(int mat[N][N], int alberi[ACOL][N], int dim){
	int i, j;
	punto_t acoor[N];
	for(i=0; i<N; i++)
		for(j=0; j<ACOL; j++){
			acoor[i].x = alberi[i][0];
			acoor[i].y = alberi[i][1];
		}
	
	for(i=0; i<dim; i++){
		j = acoor[i].x;
		k = acoor[i].y;
		for(j=-1; j<2; j++)
			for(k=-1; k<2; k++)
				if(mat[acoor[i].x+j])
					
	}
}

