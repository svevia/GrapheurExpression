#include "syntax.h"

node* createNode(typeJeton jet,node* nl,node* nr){
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
struct node* syntax(typeJeton tab[], int* i) {
    /*node* arbre = NULL;
    int end = 0;
    int prio = 0;
    while(end==0){
        int i=0;
        typeJeton* tmp = NULL;
        while(tab[i].lexem!=FIN){
            if((tmp==NULL)&&(tab[i].priority >= prio)){
                tmp = &tab[i];
            }
            else if(tab[i].priority >= prio && tmp->priority < tab[i].priority){
                tmp = &tab[i];
            }
            
            }
        
        }*/


    
    int j;
    struct node *newNode;
    printf(" i = %d\n", *i);
    printf("lexem %d\n", tab[*i].lexem);
    switch (tab[*i].lexem) {
            
        case FONCTION:{
            j = *i;
            *i+=2;
            printf(" fonction : %u\n", tab[j].valeur.FUN);
            return createNode(tab[j], syntax(tab, i), NULL);
            break;
        }
        case OPERATOR:
            j = *i;
            *i+=1;
            int k = *i-1;
            //tmp stock le père
            //tmp = syntax(tab, i++);
            //struct node* newNode = createNode(tab[j], NULL, tmp);
            printf("OPERATOR : %u\n", tab[j].valeur.OPER);
            return createNode(tab[j], syntax(tab, &k), syntax(tab, i));
            break;
            
        case REEL:
            j = *i;
            *i+=1;
            //struct node* newNode = createNode(tab[i], NULL, NULL);
            //syntax(tab, i++);
            printf("REEL : %lg\n", tab[j].valeur.VAL);
            return syntax(tab, i);
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
            default:
                break;
        }
    }
    if(nbrPar != 0){
        return 202; //erreur parenthésage
    }
    return 200;
}



/*typeJeton* assignPriority(typeJeton tab[]){
    int priority = 0;
    for(int i =0; i < tabSize(tab);i++){
        switch (tab[i].lexem) {
            case PAR_OPEN:
                priority+=10;
                break;
            case PAR_CLOSE:
                priority-=10;
                break;
            case OPERATOR:
                if (tab[i].valeur.OPER == MULTIPLICATION || tab[i].valeur.OPER == DIVISION) {
                    tab[i].priority = priority+1;
                }
                tab[i].priority = priority;
            case FONCTION:
                tab[i].priority = priority+2;
                break;
            default:
                break;
        }
    }
    return sortTab(tab);
}*/


int main(){
    int size = 8;
    typeJeton tab[size];
    typeJeton* x1 = (typeJeton*) malloc(sizeof(typeJeton));
    x1->lexem = FONCTION;
    x1->valeur.FUN = SIN;
    tab[0] = *x1;
    
    typeJeton* x2 = (typeJeton*) malloc(sizeof(typeJeton));
    x2->lexem = PAR_OPEN;
    tab[1] = *x2;
    
    typeJeton* x3 = (typeJeton*) malloc(sizeof(typeJeton));
    x3->lexem = REEL;
    x3->valeur.VAL = 4.0;
    tab[2] = *x3;
    
    typeJeton* x4 = (typeJeton*) malloc(sizeof(typeJeton));
    x4->lexem = OPERATOR;
    x4->valeur.OPER = PLUS;
    tab[3] = *x4;
    
    typeJeton* x5 = (typeJeton*) malloc(sizeof(typeJeton));
    x5->lexem = REEL;
    x5->valeur.VAL = 3.0;
    tab[4] = *x5;
    
    typeJeton* x6 = (typeJeton*) malloc(sizeof(typeJeton));
    x6->lexem = PAR_CLOSE;
    tab[5] = *x6;
    
    typeJeton* x7 = (typeJeton*) malloc(sizeof(typeJeton));
    x7->lexem = FIN;
    tab[6] = *x7;
    
    int i =0;
    syntax(tab, &i);
    
    return 0;
}





