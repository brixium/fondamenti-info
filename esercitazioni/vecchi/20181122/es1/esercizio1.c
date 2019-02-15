/* 2018 11 22 Esercizio 1
	Oggi vedremo qualche esercizio sui file sia testo che binario
	Scriver un programma che legge dati.txt contente n interi (n non specificato).
	Controllare se i numeri sono primi o meno. Se sono primi, salvarli su un file, se no salvarli su un altro.
*/
#include <stdio.h>
#define SRCDATI "./dati.txt"
#define DSTP  "./primi.bin"
#define DSTNP "./nonprimi.bin"
int isPrimo(int);
int main(int argc, char * argv[]){
	int num;
	FILE * fin;
	FILE * primi;
	FILE * nonpr;
	if(fin = fopen(SRCDATI, "r")){
		if(primi = fopen(DSTP, "wb")){
			if(nonpr = fopen(DSTNP, "wb")){
				fscanf(fin, "%d", &num);
				while(!feof(fin)){
					if(isPrimo(num))
						/*fprintf(primi, "%d", num); no perché trattasi di file binari*/
						fwrite(&num, sizeof(int), 1, primi);
					else
						/*fprintf(nonpr, "%d", num);*/
						fwrite(&num, sizeof(int), 1, nonpr);
					fscanf(fin, "%d", &num);
				}
				fclose(nonpr);
			}else
				printf("Errore! Non posso aprire il file %s .\n", DSTNP);
			fclose(primi);
		}else
				printf("Errore! Non posso aprire il file %s .\n", DSTP);
		fclose(fin);
	}else
			printf("Errore! Non posso aprire il file %s .\n", SRCDATI);

	return 0;
}

int isPrimo(int n){
	int i=2;
	while(i<=(n/2)){
		if((n%i)==0)
			return 0;
		i++;
	}
	return 1;
}
