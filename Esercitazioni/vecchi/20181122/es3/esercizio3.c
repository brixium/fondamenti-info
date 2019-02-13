#include <stdio.h>
#define FIN "./uguaglianze.txt"
/*File di testo con uguaglianze: contare quali sono vere e fare la percentuale compresa tra 0 e 1. Nella riga l'ultimo carattere è un ;*/
int main(int argc, char * argv[]){
	FILE * fin;
	int pri;
	int sec;
	int status, ntrue, nline;
	char x;
	float ris;
	pri = 0;
	sec = 0;
	status = 0;
	ntrue = 0;
	nline = 0;
	if(fin = fopen(FIN, "r")){
		while(!feof(fin)){
			fscanf(fin, "%c", &x);
			if(x=='=')
				status = 1;
			else if(x==';'){
				status = 0;
				/*printf("%d\t", (int)'9' - (int)'0' );*/
				printf("pri: %d, sec: %d \n", pri, sec);
				if(pri==sec)
					ntrue++;
				pri = 0;
				sec = 0;
				nline++;
			}else if(x>='0' && x<'9'){
				/*printf("x: %d; ", x);*/
				if(status==0){
					if(x!='+')
						pri = pri + (int) (x - '0');
				}else
					if(x!='+')
						sec = sec + (int) (x - '0');
			}
		}
		ris = ntrue / (float)nline;
		printf("%d / %d\n", ntrue, nline);
		printf("%f\n", ris);
		fclose(fin);
	}else
		printf("Errore in lettura di %s\n", FIN);
	return 0;
}
