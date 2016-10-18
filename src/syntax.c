#include "syntax.h"


//Créer un noeud de l'arbre
node* createNode(typeJeton jet, struct node* nl, struct node* nr){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->jeton=jet;
    newNode->left=nl;
    newNode->right=nr;
    
    return newNode;
}

//Vérifie les valeurs du tableau jetons et crée l'arbre en cosnséquence
node* syntax(typeJeton tab[], int i) {
    switch (tab[i].lexem) {
        case FONCTION:
            j=i;
            tmp = syntax(tab, i++);
            node* newNode = createNode(tab[j], tmp, NULL);
            break;
        case OPERATOR:
            j = i;
            //tmp stock le père
            tmp = syntax(tab, i++);
            node* newNode = createNode(tab[j], node, tmp);
            break;
        case REEL:
            node* newNode = createNode(tab[i], NULL, NULL);
            syntax(tab, i++);
            i++;
            break;
        case VARIABLE:
            node* newNode(tab[i], NULL, NULL);
        case FIN:
            break;
        default:

    }


    //return createNode(tab[i], NULL, NULL);
}

