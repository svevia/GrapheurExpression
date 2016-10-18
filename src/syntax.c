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



//Vérifie les valeurs du tableau jetons et crée l'arbre en cosnséquence
struct node* syntax(typeJeton tab[], int i) {
    int j;
    struct node* tmp;
    struct node *newNode;
    switch (tab[i].lexem) {
        case FONCTION:
            j=i;
            //tmp = syntax(tab, i++);
            printf("%u", tab[j].valeur.FUN);
            return newNode = createNode(tab[j], syntax(tab, i++), NULL);
            break;
        case OPERATOR:
            j = i;
            //tmp stock le père
            //tmp = syntax(tab, i++);
            //struct node* newNode = createNode(tab[j], NULL, tmp);
            printf("%u", tab[j].valeur.OPER);
            return newNode = createNode(tab[j], syntax(tab, i++), syntax(tab, i+2));
            break;
        case REEL:
            //struct node* newNode = createNode(tab[i], NULL, NULL);
            //syntax(tab, i++);
            j = i;
            printf("%f", tab[j].valeur.VAL);
            return newNode = createNode(tab[j],NULL, NULL);
            break;
        case VARIABLE:
            //struct node* newNode = createNode(tab[i], NULL, NULL);
        case FIN:
            return newNode;
            break;
        default:
            break;

    }
    return NULL;
}
    //return createNode(tab[i], NULL, NULL);

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
