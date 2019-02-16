#include <stdio.h>
#include <stdlib.h>

#define STOP -1
typedef struct nodo_s{
	int val;
	struct nodo_s * next;
}list_t;

list_t * append(list_t *, int);
list_t * sottolistad(list_t *);
void freelist(list_t *);
void printlist(list_t *);

int main(int argc, char * argv[]){
	int n;
	list_t * lista = NULL;
	list_t * dis = NULL;
	list_t * p;

	scanf("%d", &n);
	while(n != STOP){
		lista = append(lista, n);
		scanf("%d", &n);
	}
	printlist(lista);
	dis = sottolistad(lista);
	printlist(dis);

	freelist(lista);
	freelist(dis);
	return 0;
}
/* Versione 1
list_t * sottolistad(list_t * h){
	list_t * hd = NULL;
	list_t * p;

	for(p = h; p && p->next; ){
		hd = append(hd, p->next->val);
		p = p->next->next;
	}
	return hd;
}
*/
/*Versione 2 sottolistad*/
list_t * sottolistad(list_t * h){
	int i;
	list_t *p, * newl = NULL;
	/* o senza p ... uso h */
	/* for(i=0; h; h=h->next) */
	for(i=0, p = h; p; p = p->next)
		if(i%2)
			newl = append(newl, p->val);
	return newl;
}

list_t * append(list_t * h, int num){
	list_t * n, * p;

	if((n = (list_t *)malloc(sizeof(list_t)))){
		n->val = num;
		n->next = NULL;
		if(h){
			for(p = h; p->next; p = p->next)
				;
			p->next = n;
		}else
			h = n;
	}else
		printf("Memory error %d\n", num);
	return h;
}

void printlist(list_t * h){
	list_t * ptr = NULL;
	for(ptr=h; ptr; ptr = ptr->next)
		printf("%d", ptr->val);
	printf("\n");
	return;
}

void freelist(list_t * h){
	list_t * tmp;
	while(h != NULL){
		tmp = h;
		h = h->next;
		free(tmp);
	}
	return;
}
