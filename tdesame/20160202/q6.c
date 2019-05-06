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

#define MAXLEN 160

typedef struct msg{
	char str[MAXLEN+1];
	struct msg * next;
}sms_t;

