/*
I numeri di Catalan sono una successioneCn di interi positivi. Il nome di questi numeri è stato scelto in onore del matematico belga Eugène Charles Catalan (1814-1884) che li aveva studiati intorno al 1838 per stabilire in quanti modi si può ricondurre il prodotto di r fattori ad una successione di prodotti a coppie. I numeri di Catalan si possono ottenere ricorsivamente, secondo la seguente relazione:
	C0 = 1
			
		 n-1
		 ---
		 \
	Cn = /   C(i) * C(n-i-1)
		 ---
		 i=0
		 
Si scriva una funzione ricorsiva cat che, ricevuto un numero n come parametro formale, ritorna il valore di Cn.
Si scriva poi il programma principale che acquisisca dall’utente un numero intero positivo x (e finché non é tale lo richiede) e quindi calcola e visualizza i primi x+1 numeri di Catalan, da C0 a Cx.
*/

#include <stdio.h>
#include <stdlib.h>

int cat(int);

int main(int argc, char * argv[]){
	int x;
	
	do{
		scanf("%d", &x);
	}while(x<0);
	printf("%d\n", cat(x));
	return 0;
}

int cat(int n){
	int i,sum;
	if(n==0)
		return 1;
	sum = 0;
	for(i=0; i<=n-1; i++)
		sum = sum + (cat(i)*cat(n-i-1));
	return sum;
}

