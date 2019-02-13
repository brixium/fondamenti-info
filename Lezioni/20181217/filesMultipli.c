/*Come includere un secondo file, che riutilizzerò:
	creare due file con lo stesso nome ma due estensioni diverse, per esempio:
	liste.h e liste.c
	In liste.h ci saranno solo i prototipi, in liste.c ci saranno tutti i sottoprogrammi definiti in liste.h
	Alla fine, nel nostro file includere il nome del file header con relativo percorso
	
	Quando compilo il main non va a compilare automaticamente i file header
	Compilazione in due passaggi: compilare liste.c, che non produce un eseguibile, perché non c'è il main
	Passo 1: creo del codice oggetto (non eseguibile)
	Passo 2: compilo il main 
	
	Bisogna settare delle flag in gcc
	Oppure posso compilare insieme i file lista.h e lista.c, che crea un file .o (codice oggetto) e poi, una volta scritto il main, andare a compilare e creare l'eseguibile
	Per alcuni progetti, si scrive un MAKEFILE chiamabile con make che serve per compilare il sorgente ordinatamente partendo prima dai sottoprogrammi e poi finiscono col main
	 __________     _______________
	|typedef   |   |sottoprogramma |
	|prototipi |   |               |
	|          |-->|               |
	|          |   |               |
	|__________|   |_______________|
	  liste.h          liste.c
*/

#include <stdio.h>
#include "nomeFile.h"
#include "../libreria/liste.h"
