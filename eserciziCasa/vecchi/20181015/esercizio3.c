/*
Scrivere un programma in C che acquisisca una sequenza str di 20 caratteri. Per ogni carattere car contenuto nella stringa str, a partire dall'ultimo fino ad arrivare al primo, il programma visualizza (senza lasciare spazi) il carattere car, seguito dal numero di volte in cui compare consecutivamente in quel punto della stringa. Per esempio, se l'utente inserisce aabbbddbbbbhhhhhzzzz il programma visualizza z4h5b4d2b3a2.
*/
#include <stdio.h>
#define LUNG 20
int main(int argc, char * argv[]){
/*DICHIARAZIONE VAR*/
    char seq [LUNG];
    char lastc;
    int i, count;
/*INIT*/
    for(i=0; i<LUNG; i++){
        scanf("%c", &lastc);
        seq[i] = lastc;
    }
    count = 0;
    lastc = seq[LUNG-1];
/*TODO*/
    for(i=LUNG-1; i>=0; i--){
        if(lastc==seq[i])
            count++;
        else{
            printf("%c%d",lastc, count);
            count = 1;
        }
        lastc = seq[i];
        if(i==0)
            printf("%c%d",lastc, count);
    }
    printf("\n");
    return 0;
}
