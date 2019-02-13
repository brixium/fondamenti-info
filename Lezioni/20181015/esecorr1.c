#include <stdio.h>
#define BASE 10
int main(int argc, char * argv []){
	int val, rev, digit;

	scanf("%d", &val);

	rev = 0;
	while(val > 0){
		digit = val % BASE;
		rev = rev*BASE + digit;
		val = val / BASE;
	}
	printf("%d\n", rev);
	return 0;
}
