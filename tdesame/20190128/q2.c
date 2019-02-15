/*
Un punto nel piano cartesiano è definito dalla coppia di coordinate intere x e y: si definisca l'opportuno tipo di dato point_t.

Data una matrice NxN di punti, i punti della diagonale, quelli di ogni riga e quelli di ogni colonna definiscono linee spezzate (ciascuna di N-1 lati). Si definisce regolare una matrice dove la lunghezza della spezzata definita dalla diagonale ha lunghezza maggiore della lunghezza di tutte le spezzate definite dalle righe e dalle colonne della matrice.

Si definisca un sottoprogramma 'regolare' che ricevuta in ingresso una matrice di punti e qualsiasi parametro ritenuto strettamente necessario,restituisce 1 se la matrice è regolare, 0 altrimenti.
Si supponga che esista una direttiva
#define N ...
e di avere a disposizione un sottoprogramma
float dist(point_t p1, point_t p2)
che calcola e restituisce la distanza euclidea tra due punti.

*/
#include <stdio.h>
#include <math.h>
#define N 5
typedef struct point_s{
	int x;
	int y;
}point_t;

int regolare(point_t[][N], int);
float dist(point_t, point_t);

int main(int argc, char * argv[]){
	
	return 0;
}

int regolare(point_t mat[][N], int dim){
	int i, j, flag;
	float rowl, coll, diagl;
	
	flag = 1;
	diagl = 0;
	for(i=0; i<dim-1; i++)
		for(j=0; j<dim-1; j++)
			if(i==j)
				diagl = diagl + dist(mat[i][j], mat[i+1][j+1]);
	
	for(i=0; i<dim && flag; i++){
		rowl = 0;
		coll = 0;
		for(j=0; j<dim-1; j++){
			rowl = rowl + dist(mat[i][j], mat[i][j+1]);
			coll = coll + dist(mat[j][i], mat[j+1][i]);
		}
		if(rowl>diagl || coll>diagl)
			flag = 0;
	}
	return flag;
}
float dist(point_t p1, point_t p2){
	float meas;
	meas = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
	return meas;
}
