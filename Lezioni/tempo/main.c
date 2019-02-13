#include <stdio.h>

int main(int argc, char * argv[]){
	int t, tr, h, m, s;
	
	scanf("%d", &t);
	s = t%60;
	tr = t/ 60;
	m = tr%60;
	tr = tr/60;
	h = tr %60;
	printf("%d %d %d", h, m, s);
	return 0;
}
