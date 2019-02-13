/*Input file contente num interi contare quante volte appare numer* */
#include <stdio.h>
#include <stdlib.h>
#define NOMEFILE "numeri.txt"
typedef struct list_s{
	int val;
	int nocc;
	struct list_s * next;
}list_t;

int main(int argc, char * argv[]){
	
	return 0;
}

list_t * contaval(char nomefile[]){
	FILE * fp;
	list_t * h = NULL;
	int num;
	if(fp = fopen(NOMEFILE, "r")){
		fscanf(fp, "%d", &num);
		while(!feof(fp)){
			h = updateorappend(h, val); /*O aggiorna il valore incrementandolo oppure lo crea*/
			fscanf("%d", &num);
		}
		fclose(fp);
	}else
		printf("Errore nell'accesso alfile");
	return h;
}

list_t * updateorappend(list_t * h, int n){
	list_t * ptr;
	if(!h)
		h = push(h, n);
	else{
		for(ptr = h; ptr ->next; ptr = ptr->next)
			if(ptr->val == n){
				(ptr->nocc)++; /*riga 7*/
				return h;
			}
		if(ptr->val == n)
			(ptr->nocc)++;
		else
			ptr->next = append(ptr->next, n);
	}
	return h;
}
