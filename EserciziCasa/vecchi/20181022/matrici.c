#include <stdio.h>

#define D 3

int main (int argc, char * argv []){
	int mat[D][D],p,s,i,j;
	
	for(i=0;i<D;i++)
		for(j=0;j<D;j++)
			/*printf("inserire l'elemento della matrice in posizione [%d] [%d]  \n",i, j);*/
			scanf("%d",&mat[i][j]);
	p=1;
	s=0;
	for(j=0;j<D;j++){
		for(i=0;i<D;i++)
			p=p*mat[i%D][(i+j)%D];
		s=s+p;
		p=1;
	}
	for(j=0;j<D;j++){
		for(i=0;i<D;i++)
			p=p*mat[i%D][(D-1+j-i)%D];
		s=s-p;
		p=1;
	}
/*	printf("il determinante e'  %d",s);*/
	printf("%d\n",s);	
	return 0;
}
