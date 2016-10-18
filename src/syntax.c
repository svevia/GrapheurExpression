#include "syntax.h"

node* createNode(typeJeton jet, struct node* nl, struct node* nr){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->jeton=jet;
    newNode->left=nl;
    newNode->right=nr;
    
    return newNode;
}


int tabSize(typeJeton tab[]){
    int i = 0;
    while(tab[i].lexem != FIN){
        i++;
    }
    return i;
}



node* syntax(typeJeton tab[], int i) {
    
    switch (tab[i].lexem) {
        case OPERATOR:
            
            break;

    }


    return createNode(tab[i], NULL, NULL);
}

int checkExpression(typeJeton tab[]){
    int nbrPar = 0;
    int i;
    for(i = 0; i<tabSize(tab);i++){
        switch (tab[i].lexem) {
            case PAR_OPEN:
                nbrPar++;
                break;
                
            case PAR_CLOSE:
                nbrPar--;
                break;
            case FONCTION:
                if(tab[i+1].lexem != PAR_OPEN){
                    return 203; //erreur fonction
                }
                break;
        }
    }
    if(nbrPar != 0){
        return 202; //erreur parenthésage
    }
    return 200;
}
