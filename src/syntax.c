#include "syntax.h"

node* createNode(typeJeton jet,node* nl,node* nr,int pos){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->jeton=jet;
    newNode->left=nl;
    newNode->right=nr;
	newNode->pos = pos;
	switch (jet.lexem) {
		case OPERATOR:
			printf("Operateur : %c ----- prio : %i\n", jet.valeur.OPER,jet.priority);
			break;
		case FONCTION:
			printf("Fonction : %i ----- prio : %i\n", jet.valeur.FUN, jet.priority);
			break;
		case REEL:
			printf("Reel : %f\n", jet.valeur.VAL);
			break;
		case VARIABLE:
			printf("variable\n");
			break;
	}

    return newNode;
}


void printtreenode(node* root)
{
	if (root == NULL) {
		printf("\n");
		return;
	}

	switch (root->jeton.lexem) {
	case OPERATOR:
		printf("Operateur : %c\n", root->jeton.valeur.OPER);
		break;
	case FONCTION:
		printf("Fonction : %i\n", root->jeton.valeur.FUN);
		break;
	case REEL:
		printf("Reel : %f\n", root->jeton.valeur.VAL);
		break;
	case VARIABLE:
		printf("variable\n");
		break;
	}
	printtreenode(root->right);
	printtreenode(root->left);


}

int tabSize(typeJeton tab[]){
    int i = 0;
    while(tab[i].lexem != FIN){
        i++;
    }
    return i;
}

//cree et place un node en fonction de sa position dans le tableau initial
int placerNode(typeJeton tab[],node** arbre, int pos) {
	if (*arbre == NULL) {// si l'arbre est nul, on place le node en tant que racine
		*arbre = createNode(tab[pos],NULL,NULL,pos);
		return 0;
	}
	else {
		node* tmp = *arbre;// noeud actuel de lecture
		while (1) {// la fonction sera quitté à la creation d'un node
			if (tmp->jeton.lexem != VARIABLE || tmp->jeton.lexem != REEL) {
				if (pos < tmp->pos || tmp->jeton.lexem == FONCTION) {
					if (tmp->left != NULL) {
						tmp = tmp->left; // on décale le noeud actuel sur la gauche et on poursuit la lecture de l'arbre
					}
					else {
						tmp->left = createNode(tab[pos], NULL, NULL,pos);//position trouvée : on crée le node
						return 1;
					}
				}

				else if (pos > tmp->pos) {
					if (tmp->right != NULL) {
						tmp = tmp->right; // on décale le noeud actuel sur la droite et on poursuit la lecture de l'arbre
					}
					else {
						tmp->right = createNode(tab[pos], NULL, NULL,pos);//position trouvée : on crée le node
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int checkExpression(typeJeton tab[]) {// verifie des incohérence dans l'expression en entrée
	int nbrPar = 0;
	int i;

	// verifie que le nombre de parenthèse est cohérent
	for (i = 0; i<tabSize(tab); i++) {
		switch (tab[i].lexem) {
		case PAR_OPEN:
			nbrPar++;
			break;

		case PAR_CLOSE:
			nbrPar--;
			break;
		case FONCTION:
			if (tab[i + 1].lexem != PAR_OPEN) {
				exit(203); //erreur fonction
			}
			break;
		default:
			break;
		}
	}


	if (nbrPar != 0) {
		exit(202); //erreur parenthésage
	}
	return 200;
}



typeJeton* assignPriority(typeJeton tab[]) {// assigne les priorité aux operateurs et fonctions

	/**
	Paretnhèse ouvrante : ajoute 10 à toutes les priorité à l'intèreieur de la parenthèse
	fonction : priorité = 5
	Addition/ Soustration : priorité = 2
	Multiplication/division : priorité = 3
	**/
	int i = 0;
	int priority = 0;
	for (i; i < tabSize(tab); i++) {
		switch (tab[i].lexem) {
		case PAR_OPEN:
			priority += 10;
			break;
		case PAR_CLOSE:
			priority -= 10;
			break;
		case OPERATOR:
			printf("op");
			if (tab[i].valeur.OPER == MULTIPLICATION || tab[i].valeur.OPER == DIVISION) {
				tab[i].priority = priority + 3;
				break;
			}
			else {
				tab[i].priority = priority + 2;
				break;
			}
		case FONCTION:
			tab[i].priority = priority + 5;
			break;
		default:
			tab[i].priority = -1;
			break;
		}
	}
	return tab;
}

//Vérifie les valeurs du tableau jetons et crée l'arbre en cosnséquence
node* syntax(typeJeton tab[]) {
	int posPrioMini = 0;
	node* arbre = NULL;
	int changement = 1;
	int i = 0;
	checkExpression(tab);//verifie que l'expression est correct
	assignPriority(tab);//assigne les priorité
	//premiere phase : positionnement des operteurs et fonction --on regarde les priorités pour placer les node
	//En cas d'egalite de priorite, on prend la derniere occurence
	while (changement != 0) {
		changement = 0;
		posPrioMini = 0;
		i = 0;
		for (i; i < tabSize(tab); i++) {
			if (tab[i].lexem == OPERATOR || tab[i].lexem == FONCTION) {
				if (tab[posPrioMini].priority == -1 && tab[i].priority > 0) {
					posPrioMini = i;
					changement++;
				}
				else if (tab[i].priority <= tab[posPrioMini].priority && tab[i].priority != -1) {
					posPrioMini = i;
					changement++;
				}
			}
		}
		if (changement != 0) {
			placerNode(tab, &arbre, posPrioMini);
			tab[posPrioMini].priority = -1;//on retire cette priorité des prochains calculs
		}
	};
	i = 0;
	for (i; i < tabSize(tab); i++) {//seconde phase : on place les reel et les variables en fonction de leur postion
		if (tab[i].lexem == VARIABLE || tab[i].lexem == REEL) {
			placerNode(tab, &arbre, i);
		}
	}
	return arbre;
}



/*int main(){
    typeJeton tab[20];
    typeJeton* x1 = (typeJeton*) malloc(sizeof(typeJeton));
    x1->lexem = FONCTION;
    x1->valeur.FUN = SIN;
    tab[0] = *x1;
    
    typeJeton* x2 = (typeJeton*) malloc(sizeof(typeJeton));
    x2->lexem = PAR_OPEN;
    tab[1] = *x2;
    
    typeJeton* x3 = (typeJeton*) malloc(sizeof(typeJeton));
    x3->lexem = REEL;
    x3->valeur.VAL = (float)4.0;
    tab[2] = *x3;
    
    typeJeton* x4 = (typeJeton*) malloc(sizeof(typeJeton));
    x4->lexem = OPERATOR;
    x4->valeur.OPER = MULTIPLICATION;
    tab[3] = *x4;
    
    typeJeton* x5 = (typeJeton*) malloc(sizeof(typeJeton));
    x5->lexem = REEL;
    x5->valeur.VAL = (float)3.0;
    tab[4] = *x5;

	typeJeton* x6 = (typeJeton*)malloc(sizeof(typeJeton));
	x6->lexem = OPERATOR;
	x6->valeur.OPER = PLUS;
	tab[5] = *x6;

	typeJeton* x7 = (typeJeton*)malloc(sizeof(typeJeton));
	x7->lexem = REEL;
	x7->valeur.VAL = (float)2.0;
	tab[6] = *x7;
    
    typeJeton* x8 = (typeJeton*) malloc(sizeof(typeJeton));
    x8->lexem = PAR_CLOSE;
    tab[7] = *x8;
    
    typeJeton* x9 = (typeJeton*) malloc(sizeof(typeJeton));
    x9->lexem = FIN;
    tab[8] = *x9;
    
    node* arbre = syntax(tab);
	printtreenode(arbre);
	getchar();
    return 200;
}*/





