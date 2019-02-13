#include <stdio.h>
/*Input: due numeri interi relativi. Output: 1 se uno è divisiore dell'altro; viceversa 0*/
int main(int argc, char * argv []){
	int n1, n2, ris;
	ris=0;
	scanf("%d%d", &n1, &n2);
	if(n1%n2==0||n2%n1==0)
		ris = 1;
	printf("%d\n", ris);
}
