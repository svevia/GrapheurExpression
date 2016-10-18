#include <stdio.h>
#include <stdlib.h>
#include "jeton.h"

/* ------------ Prototype de la fonction ------------
Nom de la fonction : Eval, contraction du mot Evaluateur qui correspond a notre partie du projet.
Parametre d'entree : - x, la variable; de type flottant.
					 - arbre, l'arbre binaire; de type noeud*.
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

float CalculRes (float x,node* arbre,float pas,short int bornePlus,short int borneMoins)
{
    float y1,y2;
    float resultat=0.0f;
    if((arbre->left!=NULL)&&(arbre->right!=NULL)){
        //while(){
            switch(arbre->jeton.lexem)
            {
                case OPERATOR:
                    y1 = arbre->left->jeton.valeur.VAL; //recopie du prof | pourquoi y1 prend la valeur de fg ? => Mise en memoire du reel ?
                    y2 = arbre->right->jeton.valeur.VAL; //recopie du prof

                    switch(arbre->jeton.lexem)
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
                    Eval(x,arbre->left);
                break;

                case VARIABLE:
                    Eval(x,arbre->left);
                break;

                case FONCTION:
                    switch(arbre->jeton.lexem)
                    {
                        case SIN:
                            resultat=sin(resultat);
                        break;
                        case COS:
                            resultat=cos(resultat);
                        break;
                    }
                break;
            }
            Stockage(pas,borneMoins,bornePlus,resultat);
            return resultat; //On retourne le resultat de l'operation
        }
    }
}

void Stockage (float pas,short int bornePlus,short int borneMoins){
    short int taille = int(float((bornePlus-borneMoins))/pas);
    point TableauPoints[taille];
}
