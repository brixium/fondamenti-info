/*
(5 punti) Scrivere un sottoprogramma rot che ricevuta in ingresso una stringa voc, un numero intero senz’altro positivo n ed un intero dir (che vale senz’altro solo 0 o 1), la modifica in modo tale che la stringa finale sia quella iniziale, fatta scorrere di n posizioni a sinistra se dir vale 0, a destra se dir vale 1. con gli ultimi n caratteri riportati in testa. Se per esempio la stringa iniziale è Esempio ed n è 1 e dir è 1, la stringa finale sarà oEsempi. Data la stringa iniziale Fondamenti, n pari a 4 e dir pari a 0, la stringa finale è amentiFond.

(1 punto) Scrivere il programma che acquisisce da riga di comando la stringa s, l’intero n e l’intero dir e dopo aver utilizzato il sottoprogramma rot visualizza la stringa risultante.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rot(char *voc, int n, int dir);

int main(int argc, char * argv[]){
	int n, dir;
	if(argc > 1){
		n = atoi(argv[2]);
		dir = atoi(argv[3]);
		rot(argv[1], n, dir);
		printf("%s\n", argv[1]);
	}
	
	return 0;
}

void rot(char *voc, int n, int dir){
	char * aux = NULL;
	int vlen;

	vlen = strlen(voc);
	if((aux = (char *)malloc(sizeof(char)*vlen))){
		if(dir){
			memcpy(&aux[n], &voc[0], vlen-n);
			memcpy(&aux[0], &voc[vlen-n], n);
		}else{
			memcpy(&aux[0], &voc[n], vlen-n);
			memcpy(&aux[vlen-n], &voc[0], n);
		}
		aux[vlen] = '\0';
		strcpy(voc, aux);
		free(aux);
	}else
		printf("No memory\n");
}
