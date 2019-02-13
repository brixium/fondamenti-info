/*Martedì 20 novembre 2018*/
/*
scriver progsammma che legge dal file dati.txt 100 valori interi e crea 2 nuovi file: pari.txt e dispari.txt in cui mette rispettivamente i numeri pari e quelli dispari letti dal file sorgente
*/
#include <stdio.h>
#define N 100
int main(int argc, char * argv[]){
	int n, i;
	FILE * fin;
	FILE * fdis, * fpari; 
	if(fin = fopen("dati.txt", "r")){
		if(fpari = fopen("pari.txt", "w")){
			if(fdis = fopen("dispari.txt", "w")){
				for(i=0; i<N; i++){
					fscanf(fin, "%d", &n);
					if(n%2)
						fprintf(fpari, "%d", n);
					else
						fprintf(fdis, "%d", n);
				}
				fclose(fdis);
			/*Messaggi di errore*/
			}else
				printf("Errore! Impossibile aprire file dispari.txt");
			/*fclose(fin); questo no perché a ciasucn if la sua chiusa */
			fclose(fpari);
		}else
			printf("Errore! Impossibile aprire file pari.txt");
		fclose(fin);	
	}else
		printf("Errore! Impossibile aprire file dati.txt");
	return 0;
}


/*Scrivere programma che ricevuto in ingresso il riferimento ad un file, restituisce 1 se il file è vuoto, 0 altrimenti*/
/**/
int filevuoto(FILE * fp){
	/*Utilizziamo un char perché è il più versatile*/
	char c;
	fscanf(fp, "%c", &c);
	if(feof(fin)==0)
		return 0;
	return 1;
}
