/*
Scrivere la definizione di tipo per elementi di una lista per la gestione di rilevazioni ambientali di temperatura (valore reale) e umidità (valore intero) in un dato istante (si utilizzi una stringa di 12 caratteri)
*/

#define ISTLEN 12

typedef struct rilev_s{
	float temp;
	int hum;
	char ist [ISTLEN+1];
	struct rilev_s * next;
}rilam;
