#include "../liste/liste.h"

int main(int argc, char * argv[]){
	node_t * h = NULL;
	h = appendlist(h, 5);
	printlist(h);
	h = deletelist(h, 5);
	printlist(h);
	return 0;
}
