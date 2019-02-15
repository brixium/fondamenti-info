/*Facciamo esercizi belli*/
#define BASE 10
#include <stdio.h>
int main(int argc, char * argv []){
	int num, ncifre, aux, halp, out, i, k;
	do
		scanf("%d", &num);
	while(num<=0);
	do 
		scanf("%d", &k);
	while(k<=0);
	ncifre = 0;
	out=0;
	halp = num;
	while(halp>0){
		halp = halp / 10;
		ncifre++;
	}
	if(k>=ncifre){
		for(i=0; i<k; i++){
			out = out + (num%BASE);
			out = out * BASE;
			num = num / BASE;
		}
		out= out/BASE;
		for(i=0; i<k; i++){
			aux = out%BASE;
			out=out/BASE;
			printf("%d", aux);
		}
		printf("\n");
	}else
		printf("%d\n",num);
	return 0;
}

