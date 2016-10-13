#include <stdio.h>
#include <stdlib.h>
#include "jeton.h"


Lex(){
    typeJeton tab[20];
    char str[200];
    char temporaire[20];
    int i=0;
    while (str[i] != '\0'){
        switch(str[i]){
        case '+':
            tab[i].lexem = OPERATOR;
            tab[i].valeur.OPER = PLUS;
        break;

        case '-':
            tab[i].lexem = OPERATOR;
            tab[i].valeur.OPER = MINUS;
        break;

        case '*':
            tab[i].lexem = OPERATOR;
            tab[i].valeur.OPER = MULTIPLICATION;
        break;

        case '/':
            tab[i].lexem = OPERATOR;
            tab[i].valeur.OPER = DIVISION;
        break;

        default:


            //Pour détecter s'il s'agit d'une fonction
            if (str[i]>= 'a' && str[i]<= 'z'){

            }
        }
        i++;
    }
    return tab;
}
