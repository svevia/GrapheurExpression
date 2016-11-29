#include "Eval.h"

/* ------------ Prototype de la fonction ------------
Nom de la fonction : CalculRes, contraction des mots Calcul et Resultat qui correspondent à l'objectif de cette fonction.
Parametre d'entree : - xParam, qui correspond au x de f(x); de type flottant.
					 - racine, l'racine binaire; de type node*.
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


float CalculRes(float xParam,node* racine)
{
	float resultat=0.0f;
            switch(racine->jeton.lexem)
            {
                case OPERATOR:
                    switch(racine->jeton.valeur.OPER)
                    {
                        case PLUS:
                            //addition des deux reels
							resultat = CalculRes(xParam,racine->left) + CalculRes(xParam,racine->right);
                        break;
                        case MINUS:
                            //on soustrait au fils gauche la valeur du fils droit
							resultat = CalculRes(xParam,racine->left) - CalculRes(xParam,racine->right);
                        break;
                        case MULTIPLICATION:
                            //multiplication des deux reels
							resultat = CalculRes(xParam,racine->left) * CalculRes(xParam,racine->right);
                        break;
                        case DIVISION:
							if (racine->right == 0) {
								//gestion de l'erreur 301;
								//erreur de division par 0;
							}
							else {
								//division du fils gauche par le fils droit
								resultat = CalculRes(xParam, racine->left) / CalculRes(xParam, racine->right);
							}
                        break;
                    }
                break;

                case REEL:
					resultat = racine->jeton.valeur.VAL;
                break;

                case VARIABLE:
					resultat = xParam;//donne au resultat la valeur de xParam
                break;

                case FONCTION:
                    switch(racine->jeton.valeur.FUN)
                    {
                        case SIN:
                            resultat=(float)sin(CalculRes(xParam,racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le sin renvoie un double et non un float.
						break;
                        case COS:
                            resultat=(float)cos(CalculRes(xParam, racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le cos renvoie un double et non un float.
                        break;
						case TAN:
							resultat = (float)tan(CalculRes(xParam, racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le tan renvoie un double et non un float.
							break;
						case SQRT:
							resultat = (float)sqrt(CalculRes(xParam, racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le sqrt renvoie un double et non un float.
							break;
						case LOG:
							resultat = (float)log(CalculRes(xParam, racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le log renvoie un double et non un float.
							break;
						case ABS:
							resultat = (float)abs((int)CalculRes(xParam, racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le abs renvoie un int et non un float.
							break;
						case EXP:
							resultat = (float)exp(CalculRes(xParam, racine->left)); //en effet le fils droit est a NULL, seul le fils gauche a une valeur
							//Le casting en float est obligatoire pour eviter la generation de warning, en effet le exp renvoie un double et non un float.
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
					 - racine, l'arbre binaire; de type node*.
Parametre de sortie : - Mettre en place un type erreur ? Sinon c'est une procedure.
Objectif de cette fonction : .
Cette fonction a pour objectif de mettre en mémoire le resultat retourne par la fonction CalculRes.
Pour creer la multitude de points requis pour l'affichage, nous appelerons CalculRes (plage de calcul/pas) fois.


Algorithme de la fonction :
Debut
	Appeller CalculRes 1 fois
	Renvoyer l'adresse de la 1ere case du tableau pour le groupe suivant
Fin

N.B : Comme CalculRes est une fonction recursive, elle s'appelle toute seule par la suite.
*/

point* stockage (float pas,short int borneMoins,short int bornePlus, node* racine){
	short int taille = getTaille(pas, borneMoins, bornePlus);
    short int i;

    point* TableauPoints = (point*) malloc(sizeof(point)*taille);

    for(i=0;i<=taille;i++){
        TableauPoints[i].x=(float)(borneMoins+(i*pas)); // La premiere ligne du tableau sera les x que nous incrementons a partir de la borne inferieure et du pas fourni par l'utilisateur
        TableauPoints[i].y=CalculRes(TableauPoints[i].x,racine); // CalculRes nous retourne le resultat du calcul
        //printf("y: %f  \n",TableauPoints[i].y); //affichage du y pour tests
        //printf("x: %f  \n",TableauPoints[i].x); //affichage du x pour tests
    }
    return TableauPoints;
}

/* ------------ Prototype de la fonction ------------
Nom de la fonction : getTaille, cette fonction retournera la taille du tableau.
Parametre d'entree : - pas, qui correspond au pas saisie par l'utilisateur; de type flottant.
					 - borneMoins, la borne inferieure saisie par l'utilisateur; de type short int.
					 - bornePlus, la borne superieure saisie par l'utilisateur; de type short int.
Parametre de sortie : - le resultat retourne est de type short int et correspond a la taille du tableau de valeur.
Objectif de cette fonction : Retourner la taille du tableau de valeur.
*/

short int getTaille(float pas, short int borneMoins,short int bornePlus)
{
	return (int)((float)((bornePlus - borneMoins) / pas));
}
