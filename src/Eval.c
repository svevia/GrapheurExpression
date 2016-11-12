#include "Eval.h"

/* ------------ Prototype de la fonction ------------
Nom de la fonction : CalculRes, contraction des mots Calcul et Resultat qui correspondent à l'objectif de cette fonction.
Parametre d'entree : - xParam, qui correspond au x de f(x); de type flottant.
					 - arbre, l'arbre binaire; de type node*.
Parametre de sortie : - y, le resultat de l'operation; de type flottant.
Objectif de cette fonction : Retourner un resultat pour un operateur, une variable et un reel (possiblement nul) donne.
Pour cela, nous devons recuperer l'operateur, la variable et le reel dans l'arbre binaire -passe en parametre-.


Algorithme de la fonction :
Debut
	Selon la valeur contenue dans le lexeme
		Cas REEL : On conserve en memoire ce reel
		Cas X : X prendra la valeur saisie par l'utilisateur puis sera incremente selon le pas saisi par l'utilisateur
		Cas OPE : nous devons appliquer l'operateur aux deux valeurs recuperees dans le noeud precedant
	Fin Selon
	y prend la valeur du resultat de l'operation
	Retourner y
Fin


N.B : Cette fonction sera inseree dans une boucle et sera appelle ((plage de calcul)/pas) fois.
Ces deux donnees seront saisies par l'utilisateur.
*/

float CalculRes(float xParam,node* arbre)
{
    float y1,y2;
    float resultat=0.0f;
            switch(arbre->jeton.lexem)
            {
                case OPERATOR:
                //Tester si les deux fils du noeud opérateur sont des REELS
                    if(arbre->left->jeton.lexem==OPERATOR){
                        CalculRes(xParam,arbre->left);
                    }

                    y1 = arbre->left->jeton.valeur.VAL; //Mise en memoire du reel
                    y2 = arbre->right->jeton.valeur.VAL;
                    printf("y1 :%f --- y2:%f \n",y1,y2);
                    switch(arbre->jeton.valeur.OPER)
                    {
                        case PLUS:
                            resultat=y1+y2;
                        break;
                        case MINUS:
                            resultat=y1-y2;
                        break;
                        case MULTIPLICATION:
                            resultat=y1*y2;
                        break;
                        case DIVISION:
                            resultat=y1/y2;
                        break;
                    }
                break;

                case REEL:
                    CalculRes(xParam,arbre->left);
                break;

                case VARIABLE:
					y2 = xParam;//donner a y2 la valeur de xParam
                break;

                case FONCTION:
                    switch(arbre->jeton.lexem)
                    {
                        case SIN:
                            resultat=(float)sin(arbre->left->jeton.valeur.VAL); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le sin renvoie un double et non un float.
						break;
                        case COS:
                            resultat=(float)cos(arbre->left->jeton.valeur.VAL); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le cos renvoie un double et non un float.
                        break;

						/*case TAN: // A ajouter dans l'enum typeFonction
							resultat=tan(arbre->left->jeton.valeur.VAL); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
						break;*/
                    }
                break;
            }
            return resultat; //On retourne le resultat de l'operation
}

/* ------------ Prototype de la fonction ------------
Nom de la fonction : Stockage, puisque cette fonction permet de stocker le resultat retourne par CalculRes dans un tableau.
Parametre d'entree : - pas, le pas choisis par l'utilisateur; de type flottant.
					 - borneMoins, la borne inferieur d'affichage de la fonction; de type short int.
					 - bornePlus, la borne superieure d'affichage de la fonction; de type short int.
					 - arbre, l'arbre binaire; de type node*.
Parametre de sortie : - Mettre en place un type erreur ? Sinon c'est une procedure.
Objectif de cette fonction : .
Cette fonction a pour objectif de mettre en mémoire le resultat retourne par la fonction CalculRes.
Pour creer la multitude de points requis pour l'affichage, nous appelerons CalculRes (plage de calcul/pas) fois.


Algorithme de la fonction :
Debut
	Appeller CalculRes () fois
Fin
*/

float Stockage (float pas,short int borneMoins,short int bornePlus, node* arbre){
	int taille = 1;
	taille = (int) ((float)((bornePlus-borneMoins)/pas));
    short int i;

    point TableauPoints[10]; // A modifier, lorsque je met taille => erreur.

    for(i=0;i<=taille;i++){
        TableauPoints[i].x=(float)(borneMoins+(i*pas));
        TableauPoints[i].y=CalculRes(TableauPoints[i].x,arbre);
        printf("y: %f  \n",TableauPoints[i].y);
        printf("x: %f  \n",TableauPoints[i].x);
    }
    return TableauPoints[0].y; //pour les tests uniquement
}

//mis en dur juste pour le test (sinon c'est dans syntax.c)
node* createNode(typeJeton jet, struct node* nl, struct node* nr){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->jeton=jet;
    newNode->left=nl;
    newNode->right=nr;
    return newNode;
}
