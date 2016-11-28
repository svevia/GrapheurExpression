/**************************
* Includes
*
**************************/
extern "C" {
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
}
#include <ctype.h>
#ifndef JETON_H_INCLUDED
#define JETON_H_INCLUDED
extern "C" {
#include "jeton.h"
}
#endif
extern "C" {
#include "lex.h"
#include "syntax.h"
#include "Eval.h"
}
#include "Drawing.h"

/**
* main
*
* La fonction principale avec deux arguments permettant de r�cup�rer les �l�ments en ligne de comment.
*
* Dans  cet  exemple  les  fonctions  (dites  callback)  myDraw  et  myKey  sont  install�es  ici  par
* l'appel  InitGraph  en  tant  que fonctions  r�agissantes  aux  �v�nements  de  "re-dessinage"  (pour  myDraw)
* et  aux  �v�nements  d'appui  sur  une  touche  du clavier (myKey).
*
* @parma ac : nombre de param�tres
* @parma av : tableau contenant les param�tres
*
*/
int main(int ac, char *av[])
{
	// Variables
	bool scanOK = false;
	char* fonction = "";
	typeJeton* resLex = (typeJeton*)malloc(sizeof(typeJeton)*100) ;
	node* resSyntax;
	point* tab;
	//Bornes xMin et xMax d�finies par l'utilisateur (par d�faut � -10 et 10)
	int xMin = -10;
	int xMax = 10;
	//Bornes yMin et yMax d�finies par l'utilisateur (par d�faut � -10 et 10)
	int yMin = -10;
	int yMax = 10;

	// Scan fonction
	printf("Saisissez une fonction :\n");        //Demande de saisie d'une fonction
	scanf("%s",fonction);							//Sauvegarde de la fonction saisie dans le tableau de caractere fonction
	
	// Scan bornes
	while (!scanOK)
	{
		scanOK = scanBornes(&xMin);
	}
	while (!scanOK)
	{
		scanOK = scanBornes(&xMax);
	}
	while (!scanOK)
	{
		scanOK = scanBornes(&yMin);
	}
	while (!scanOK)
	{
		scanOK = scanBornes(&yMax);
	}
	setBornes(xMin, xMax, yMin, yMax);
	calculerPas(xMin, xMax, yMin, yMax);

	// Analyse lexicale
	 analyseLex(fonction,resLex);

	// Analyse syntaxique
	resSyntax = syntax(resLex);

	// Evaluation
	tab = stockage(0.05,xMin,xMax,resSyntax);
	setTab(tab);

	// Dessin
	convertTab();
	InitGraph(ac, av, "Grapheur", 800, 700, myDraw, myKey);
	return 0;
}


