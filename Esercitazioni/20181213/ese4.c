/*
* Esercizio 4: Si definisce grado minimo e grado massimo rispettivaemnte il numero minimo e max di occorrenze dei caratteri
 scrivere un sottoprogramma claocla gradi che ricevuta in ingresso una stringa e qualsiasi altro parametro ritenuto strettamente necessario calcola e trasmette al chiamante il grado miniomi oe  il grado massimo

 Esempio: ordine. Min: 1, max: 1; amaca: min: 1, max: 3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcolaGrado(char[], int *, int *);

int main(int argc, char * argv[]){
	
	return 0;
}

void calcolaGrado(char s[], int * min, int * max){
	int * tmp, dim;
	int used, i, h, cont;
	dim = strlen(s);
	if(dim){
		if(tmp = (int *) malloc(sizeof(int)*(dim))){
			for(i=0; i<dim; i++)
				*(tmp+i) = 0;
			for(i=0; i<dim; i++){
				for(h=0, used = 0; h<i && !used; h++){
					if(s[h] == s[i])
						used = 1;
					if(!used)
						*(tmp+i) = 1;
					else
						*(tmp+h-1) = *(tmp+h-1)+1;
				}
				*min = *(tmp);
				*max = *(tmp);
				for(i=1; i<dim; i++)
					if(*(tmp+i) > *max)
						*max = *(tmp+i);
					else
						if(*(tmp+i) < *min && *(tmp+i)!=0)
							*min = *(tmp+i);
			}
			free(tmp);
		}else{
			*min = -1;
			*max = -1;
			printf("Errore nell'allocazione di memoria!");
		}

	}else{
		*min = 0;
		*max = 0;
	}
}
