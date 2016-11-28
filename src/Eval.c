#include "Eval.h"

	
/* ------------ Prototype de la fonction ------------
Nom de la fonction : CalculRes, contraction des mots Calcul et Resultat qui correspondent à l'objectif de cette fonction.
Parametre d'entree : - xParam, qui correspond au x de f(x); de type flottant.
					 - racine, l'racine binaire; de type node*.
Parametre de sortie : - y, le resultat de l'operation; de type flottant.
Objectif de cette fonction : Retourner un resultat pour un operateur, une variable et un reel (possiblement nul) donne.
Pour cela, nous devons recuperer l'operateur, la variable et le reel dans l'racine binaire -passe en parametre-.


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


float CalculRes(float xParam,node* racine)
{
    float y1,y2;
    double resultat=0.0f;
            switch(racine->jeton.lexem)
            {
                case OPERATOR:
                //Tester si les deux fils du noeud opérateur sont des REELS
                /*    if(racine->left->jeton.lexem==OPERATOR)
					{
                        CalculRes(xParam,racine->left);
                    }
				*/
                    y1 = racine->left->jeton.valeur.VAL; //Mise en memoire du reel
                    y2 = racine->right->jeton.valeur.VAL;
                    printf("y1 :%f --- y2:%f \n",y1,y2); //affichage pour verification
                    switch(racine->jeton.valeur.OPER)
                    {
                        case PLUS:
                            //addition des deux reels
							resultat = CalculRes(xParam,racine->left) + CalculRes(xParam,racine->right);
                        break;
                        case MINUS:
                            //soustraction des deux reels
							resultat = CalculRes(xParam,racine->left) - CalculRes(xParam,racine->right);
                        break;
                        case MULTIPLICATION:
                            //multiplication des deux reels
							resultat = CalculRes(xParam,racine->left) * CalculRes(xParam,racine->right);
                        break;
                        case DIVISION:

							resultat = CalculRes(xParam,racine->left) / CalculRes(xParam,racine->right);
                        break;
                    }
                break;

                case REEL:
					resultat = racine->jeton.valeur.VAL;
                break;

                case VARIABLE:
					resultat = xParam;//donne a y2 la valeur de xParam
                break;

                case FONCTION:
                    switch(racine->jeton.lexem)
                    {
                        case SIN:
                            resultat=(float)sin(racine->left->jeton.valeur.VAL); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le sin renvoie un double et non un float.
						break;
                        case COS:
                            resultat=(float)cos(racine->left->jeton.valeur.VAL); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le cos renvoie un double et non un float.
                        break;
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
					 - racine, l'racine binaire; de type node*.
Parametre de sortie : - Mettre en place un type erreur ? Sinon c'est une procedure.
Objectif de cette fonction : .
Cette fonction a pour objectif de mettre en mémoire le resultat retourne par la fonction CalculRes.
Pour creer la multitude de points requis pour l'affichage, nous appelerons CalculRes (plage de calcul/pas) fois.


Algorithme de la fonction :
Debut
	Appeller CalculRes () fois
Fin
*/

point* stockage (float pas,int borneMoins,int bornePlus, node* racine){
	int taille = (int) ((float)((bornePlus-borneMoins)/pas));
    short int i;

    point* TableauPoints = (point*) malloc(sizeof(point)*taille);

    for(i=0;i<=taille;i++){
        TableauPoints[i].x=(float)(borneMoins+(i*pas));
        TableauPoints[i].y=CalculRes(TableauPoints[i].x,racine);
        printf("y: %f  \n",TableauPoints[i].y);
        printf("x: %f  \n",TableauPoints[i].x);
    }
    return TableauPoints;
}
