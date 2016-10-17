#include "syntax.h"


//Créer un noeud de l'arbre
node* createNode(typeJeton jet, struct node* nl, struct node* nr){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->jeton=jet;
    newNode->left=nl;
    newNode->right=nr;
    
    return newNode;
}

node* syntax(typeJeton tab[], int i) {
    
    switch (tab[i].lexem) {
        case OPERATOR:
            j = i;
            tmp = syntax(tab, i++);
            node * newNode = createNode(tab[j], node, tmp);
            break;
        case REEL:

            break;
        default:

    }


    return createNode(tab[i], NULL, NULL);
}

