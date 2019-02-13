/*
	es2: leggere il contenuto del file dati.bin contentente delle temperature e stampare a video la media delle temperature.
Sappaimo quanti sono i dati: modalità di accesso diverse.
*/

#include <stdio.h>
#define HR 24
#define MIN 60
#define FIN "./dati.bin"

int main(int argc, char * argv[]){
	int i, ndati;
	FILE * fin;
	float temp[MIN*HR], tot;
	tot = 0.0;
	if(fin = fopen(FIN, "rb")){
		ndati = MIN * HR;
		fread(temp, sizeof(float), ndati, fin);
		for(i=0; i<ndati; i++)
			tot += temp[i];
		printf("Media: %f\n", tot/ndati);
		fclose(fin);
	}else
		printf("Errore nell'aprire il file %s", FIN);
	return 0;
}
