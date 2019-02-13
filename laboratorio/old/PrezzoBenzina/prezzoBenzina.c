/* Scrivere un programma che acquisice il cambio dollaro-euro, il prezzo della benzina espresso in dollari al gallone e calcola e visualizza il prezzo della benzina espresso in euro al litro. Ogni gallonecorrisponde a 3.785 litri. */
/* 	Costo a Denver 2.74 $/gal
	Cambio: 0.85	
*/
#define GAL_TO_LIT 3.785
#include <stdio.h>

int main(int argc, char * argv []){
	/* Variabili */
	float cambio, prezzousa;
	float euro, litri;
	float totale;
	/* Procedimento */
	scanf("%f%f", &cambio, &prezzousa);
	euro = cambio*prezzousa;
	totale = euro / GAL_TO_LIT;
	/*risultato: prezzo benza in euro/l*/
	printf("%f\n", totale);
	
	return 0;
}

