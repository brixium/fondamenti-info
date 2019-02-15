#include <stdio.h>

int main(int argc, char * argv[]){
	int a,b, ai, bi, mcd, mcm, i;
	i=2;
	scanf("%d %d", &a, &b);
	bi=b;
	ai = a;
	/*MCD*/
	if(a%b==0)
		mcd = b;
	else if(b%a==0)
		mcd = a;
	else{
		mcd = 1;
		while(i<a/2){
			if(ai%i==0&&bi%i==0){
				mcd = mcd*i;
				ai=bi/2;
				bi=bi/2;
			}else{
				i++;
			}
		}
	}
	/* mcm */
	mcm = (a*b)/mcd;
	printf("%d\n%d\n", mcd, mcm);
	return 0;
}
