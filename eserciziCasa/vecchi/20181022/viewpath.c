/* Scrivere un programma che acquisisce una stringa di al più 50 caratteri che contenga il nome di un file completo di percorso e visualizza il solo nome. I separatori di directory posson essere sia il carattere '/' nel caso di linux/unix, sia '\\'. in questo caso, siccome il backslash \ è un carattere speciale, è necessario definire il carattere con due '\\' */
#include <stdio.h>
#define MAX 50
#define SEPU '/'
#define SEPW '\\'
int main(int argc, char * argv[]){
	char input[MAX+1], output[MAX+1];
	int i, j, pos, cond;
	cond = 1;
	scanf("%s", &input[0]);
	for(i=MAX; i>=0 && cond; i--)
		if(input[i] == '\\' || input[i] == '/'){
			pos = i+1;
			cond = 0;
		}
	for(i = 0, j = pos; i<MAX-pos; i++, j++)
		output[i] = input[j];
	output[i] = '\0';
	printf("%s\n", output);
	return 0;
	/*
	char seq[N+1];
	int s,i;
	gets(seq);
	s = -1
	for(i=0; seq[i] !='\0'; i++)
		if(seq[i]==SEPU || seq[i] == SEPW)
			s = i;
	printf(%s\n", &seq[s+i]);
	return 0;
	*/
}
