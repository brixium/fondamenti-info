/*
*	Un file binario con le date di nascit a di 100 persone. La data è composta da gg mm aaaa. Quante persone sono nate nello stesso giorno, mese ed anno; quante persone sono nate in giorno e mese uguale ma anno diverso.
*/
/*100 date sono 100 * 3 interi (33 date composte da gg mm aaaa)*/
#include <stdio.h>
#define NDATE 100
#define FIN "./date.bin"
typedef struct date_s{
	int g, m, a;
}date_t;

int main(int argc, char * argv[]){
	FILE * fin;
	date_t p[N];
	date_t cerca;
	int i, cont, bday;
	scanf("%d%d%d", &cerca.g, &cerca.m, &cerca.a);
	if(fin = fopen(FIN, "rb")){
		fread(p, sizeof(date_t), N, fin);			
		fclose(fin);
		cont = 0;
		bday = 0;
		for(i=0; i<N; i++){
			if(p[i].g==cerca.g && p[i].m==cerca.m){
				bday++;
				if(p[i].a == cerca.a)
					cont++;
			}
			printf("%d\t%d\n", cont, bday);
		}
	}else{
		printf("Errore lettura file");
	}
	return 0;
}
