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

float Eval (float x, noeud* arbre)
{
	switch(arbre->jeton.lexeme)
	{
		case OPE:
			float y1 = arbre->fg; //recopie du prof | pourquoi y1 prend la valeur de fg ? => Mise en memoire du reel ?
			float y2 = arbre->fd; //recopie du prof
			break;
			
		case REEL:
		
			break;
			
		case X:
			break;
	}
	
	return resultat; //On retourne le resultat de l'operation
}