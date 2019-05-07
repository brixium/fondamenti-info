/*
Scrivere un sottoprogramma che ricevuta in ingresso una stringa, restituisce una struttura dati che contenga (con una opportuna gestione della memoria, priva di sprechi) un insieme di stringhe di 160 caratteri ciascuna, contenenti le parti della stringa iniziale suddivisa in pezzi da 160 caratteri.
Ad esempio, se la stringa iniziale contiene la frase seguente:

	Il testo di questa stringa ha una lunghezza complessiva di 331 caratteri, per cui verra’
	spezzato in 3 stringhe di 160 caratteri ciascuna per consentire l’invio di 3 sms distinti.
	E’ necessario predisporre una opportuna struttura dati in grado di contenere esattamente le
	3 stringhe di al piu’ 160 caratteri, senza sprechi.

il sottoprogramma dovrà creare e restituire 3 stringhe, cosiffatte:

1)	Il testo di questa stringa ha una lunghezza complessiva di x caratteri, per cui verra’
	spezzato in 3 stringhe di 160 caratteri ciascuna per consentire l’invio d

2)	i 3 sms distinti. E’ necessario predisporre una opportuna struttura dati in grado di
	contenere esattamente le 3 stringhe di al piu’ 160 caratteri, senza sprechi

3)	di memoria.

Il sottoprogramma restituisce e non visualizza nulla.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Esplicito*/
#define MAXLEN 160
/*Solo a scopi pratici*/
#define MSGLEN 1024

typedef struct msg{
	char corpo[MAXLEN+1];
	struct msg * next;
}sms_t;

sms_t * splitMessage(char[], int);

int main(int argc, char * argv[]){
/*	int i;*/
	int realmsgl;
	char message[MSGLEN+1];
	sms_t * ris = NULL;

	strcpy(message, "Il testo di questa stringa ha una lunghezza complessiva di 331 caratteri, per cui verra' spezzato in 3 stringhe di 160 caratteri ciascuna per consentire l'invio di 3 sms distinti. E' necessario predisporre una opportuna struttura dati in grado di contenere esattamente le 3 stringhe di al piu' 160 caratteri, senza sprechi.\0");
	realmsgl = strlen(message);
	ris = splitMessage(message, realmsgl);
	/*
	printf("Stringa originaria splittata a dovere");
	for(i=0; i<realmsgl; i++){
		if(i%MAXLEN == 0)
			printf("\n");
		printf("%c", message[i]);
	}
	printf("\nStringa tua:\n");
	*/
	while(ris){
		printf("%s\n", ris->corpo);
		ris=ris->next;
	}
	return 0;
}

sms_t * splitMessage(char msg[], int dim){
	/*
	SPIEGAZIONE VARIABILI
	i : contatore del numero del messaggio nella sequenza
	j : punta al carattere della stringa in ingresso
	k : punta al carattere della stringa nella struttura finale restituita
	nmsg : numero di messaggi in totale da scrivere

	bibbia : raccolta degli sms
	mess   : singolo sms

	Purtroppo non so se gli sprechi di memoria siano accettabili oppure no, in quanto essi sono limitati agli ultimi caratteri vuoti dell'ultima stringa
	*/
	int i, j, k, nmsg;
	sms_t * bibbia = NULL;
	sms_t * mess = NULL;

	nmsg = ceil(1.0*dim/MAXLEN);
	j=0;

	bibbia = (sms_t *)malloc(sizeof(sms_t));

	for(i=0, mess=bibbia; i<nmsg; i++){
		k=0;
		while(k<MAXLEN){
			mess->corpo[k] = msg[j];
			j++;
			k++;
		}
		mess->corpo[k] = '\0';
		if(nmsg-1!=i){
			mess->next = (sms_t *)malloc(sizeof(sms_t));
			mess = mess->next;
		}
	}
	return bibbia;
}
