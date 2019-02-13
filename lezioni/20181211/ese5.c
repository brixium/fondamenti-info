/*
E5: fagiani e volpi
Supponendo che le leggi che regolano l’andamento della popolazione di fagiani e di volpi siano le seguenti:

f<sub>i</sub> =f<sub>i-1</sub> +0.04∗f<sub>i-1</sub> −0.0005∗f<sub>i-1</sub> ∗v<sub>i-1</sub> 
v<sub>i</sub> =v<sub>i-1</sub> −0.03∗v<sub>i-1</sub> +0.00025∗f<sub>i-1</sub> ∗v<sub>i-1</sub>

dove fi e v<sub>i</sub> rappresentano rispettivamente i fagiani e le volpi vive nell’i-esimo periodo, si scriva un programma che chiede all’utente di inserire un valore intero n e la popolazione iniziale f0 e v<sub>0</sub> e calcola il numero di fagiani e di volpi al periodo n (ossia v<sub>n</sub> e v<sub>n</sub>).

f = f   +0.04*f   -0.005*f   *v
 i   i-1       i-1        i-1  i-1

v  = v   -0.03*v   +0.0025*f   *v
 i    i-1       i-1         i-1  i-1

*/
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define CF1 0.04
#define CF2 -0.005
#define CF3 -0.03
#define CF4 0.0025

int main(int argc, char * argv[]){
	int n, f0, v0;
	/*clock_t start, end;
	double cpu_time_used, user_time;
	struct timespec now, tmstart;
	*/
	scanf("%d%d%d", &n, &f0, &v0);
	/*clock_gettime((CLOCK_REALTIME, &tmstart);
	start = clock();*/
	fagianievolpi(f0, v0, n, &fn, &vn);
/*	end = clock();
	cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
	clock_gettime(CLOCK_REALTIME, &now);
	user_time = (double)((now.tv_sec+now.tv:nsec*1e-9) - (double)(tmstart.tv_sec+tmstart.tv_nsec*1e-9)); */
	printf("f:%d\tv:%d\n "/*(cpu time %fs - user time %fs)\n*/", fn, vn/*, cpu_time_used, user_time*/);
	
	return 0;
}

void fagianievolpi(int f0, int v0, int n, int * fn, int * vn){
	*fn = fagiani(f0, v0, n);
	*vn = volpi(v0, f0, n);
	return ;
}
int fagiani(int f0, int v0, int n){
	if(n==0)
		return f0;
	return (1+CF1) * fagiani(f0, v0, n-1) + CF2 * fagiani(f0, v0, n-1) * volpi(v0, f0, n-1);
}
int volpi(int v0, int f0, int n){
	if(n==0)
		return v0;
	return (1+CF1) * volpi(v0, f0, n-1) + CF2 * volpi(v0, f0, n-1) * fagiani(f0, v0, n-1);
}
