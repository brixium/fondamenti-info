#include <stdio.h>
#include <stdlib.h>

typedef struct node_s{
	int val;
	struct node_s *next;
}node_t;

node_t * pushlist(node_t * , int);
void printlist(node_t *);
node_t * searchlist(node_t *, int);
node_t * deletelist(node_t *, int);
node_t * appendlist(node_t *, int);
void freelist(node_t *);

node_t * pushlist(node_t * h, int num){
	node_t * ptr = NULL;
	if((ptr = (node_t *)malloc(sizeof(node_t)))){
		ptr->val = num;
		ptr->next = h;
	}
	return ptr;
}

void printlist(node_t * h){
	node_t * ptr = NULL;
	for(ptr = h; ptr; ptr = ptr->next)
		printf("%d ", ptr->val);
	printf("\n");
	return ;
}

node_t * searchlist(node_t * h, int num){
	node_t * ptr = NULL;
	for(ptr = h; ptr !=NULL; ptr = ptr->next)
		if(ptr->val == num)
			return ptr;
	return NULL;
}

node_t * deletelist(node_t * h, int num){
	node_t *cur, *prev;
	
	for(cur = h, prev = NULL; cur!= NULL && cur->val != num; prev = cur, cur = cur->next)
		;
	if(cur == NULL)
		return h;
	if(prev == NULL)
		h = h->next;
	else
		prev->next = cur->next;
	free(cur);
	return h;
}

node_t * appendlist(node_t * h, int n){
	node_t * ptr;
	node_t * e;
	if((e = (node_t *)malloc(sizeof(node_t)))){
		e->val = n;
		e->next = NULL;
		if(!h)
			h = e;
		else{
			for(ptr = h; ptr->next!=NULL; ptr = ptr->next)
				;
			ptr->next = e;
		}
	}else
		printf("Memory allocation error in append\n");
	return h;
}

void freelist(node_t * h){
	node_t * tmp;

	while(h != NULL){
		tmp = h;
		h = h->next;
		free(tmp);
	}
	return;
}
