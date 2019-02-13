/* 
Scrivere un programma in C che chiede all’utente di inserire una sequenza di numeri interi terminata dallo 0 (lo 0 non fa parte della sequenza). Il programma ignora i valori negativi e valuta e stampa a video le coppie di numeri consecutivi che soddisfano tutte le condizioni che seguono:

    sono diversi tra di loro,
    sono entrambi numeri pari,
    il loro prodotto è un quadrato perfetto.
*/
#include <stdio.h>
int main(int argc, char * argv []){
    int input, previous, c, prodotto, i;
    c = 0;
    do{
        scanf("%d", &input);
        if(input>0){
            if(c!=0 && previous!=input && input%2 == 0 && previous%2 == 0){
                prodotto = previous * input;
                for(i=2; i<prodotto; i++)
                    if(prodotto % (i*i) == 0)
                        printf("%d %d\n", input , previous);
                
            }
            previous = input;
            c++;
        }
    }while(input!=0);
    return 0;
}
