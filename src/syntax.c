#include "syntax.h"



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
            
            break;

    }


    return createNode(tab[i], NULL, NULL);
}

