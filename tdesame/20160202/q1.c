/*
Scrivere un sottoprogramma get_id che ricevuta in ingresso una stringa link ed una stringa header, trova e restituisce al chiamante l’identificativo numerico intero id presente nella stringa link, dopo la parte iniziale individuata dall’header.
Esempio:
Ingresso: 	link: http://131.175.56.243/measure/60min/sensor/variable/400/2016/01/29
			header: http://131.175.56.243/measure/60min/sensor/variable/
Uscita:
			400
*/
#include <stdio.h>
#include <math.h>

#define TERM '/'
#define MAX 255
int get_id(char [], char []);

int main(int argc, char * argv[]){

	char link[MAX], header[MAX];
	scanf("%s", &link[0]);
	scanf("%s", &header[0]);

	printf("%d\n", get_id(link, header));
	return 0;
}
/*Funziona*/
int get_id(char link[], char header[]){
	int i, alert, k, ris;
	
	alert = 0;
	ris = 0;

	for(i=0; header[i]!= '\0' && !alert; i++)
		if(header[i] != link[i])
			return -1;
	for(k=0; link[i] != TERM; i++, k++)
		;
	for(i=i-k; link[i] != TERM; i++, k--)
		ris = ris + (link[i]-'0') * pow(10, k);
	return ris/10;
}
