#include <stdio.h>
#include <stdlib.h>
/*Potrei anche fare void ma restituisco il nuovo indirizzo*/
/*BIsogna partire dalla testa, ciclare sulla lista e liberare il primo elemento che trovi*/
list_t * freelist(list_t * h){
	list_t * ptr;
	while(h){
		ptr = h;
		h = h->next;
		free(ptr);
	}
	return h;
}
/*elimina il primo elemento che aha al suo interno il valore val*/
list_t * delete(list_t * h, int num){
	list_t * ptr, * del;
	if(!h)
		return h;
	if(h->val == num){
		del = h;
		h = h->next;
		free(del);
	}else{
		for(ptr = h; ptr->next && ptr->next->val!=num; ptr= ptr->next)
			if(ptr->next->val == num){
				del = ptr->next;
				ptr->next = del->next;
				free(del);
			}
	}
	return h;
}
/*ok*/
