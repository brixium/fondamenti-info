#include <stdio.h> /* standard input output library */
#define SECINMIN 60
#define MININHR 60
int main(int argc, char * argv []){
	/*DICHIARAZIONE DELLE VARIABILI*/
	int t, tr, h, m, s;
	scanf("%d", &t);
	
	h = t/(SECINMIN*MININHR);
	tr = t-h*SECINMIN*MININHR;
	m = tr/SECINMIN;
	s = t%SECINMIN;
	
	printf("%d %d %d\n", h, m, s);
	return 0;
}

