/**************************
* Includes
*
**************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
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
* La fonction principale avec deux arguments permettant de récupérer les éléments en ligne de comment.
*
* Dans  cet  exemple  les  fonctions  (dites  callback)  myDraw  et  myKey  sont  installées  ici  par
* l'appel  InitGraph  en  tant  que fonctions  réagissantes  aux  évènements  de  "re-dessinage"  (pour  myDraw)
* et  aux  évènements  d'appui  sur  une  touche  du clavier (myKey).
*
* @parma ac : nombre de paramètres
* @parma av : tableau contenant les paramètres
*
*/
int main(int argc, char *argv[])
{
	// Variables
	bool scanOK = false;
	char fonction[100];
	typeJeton* resLex = (typeJeton*)malloc(sizeof(typeJeton)*100) ;
	node* resSyntax;
	point* tab;
	//Bornes xMin et xMax définies par l'utilisateur (par défaut à -10 et 10)
	int xMin = -10;
	int xMax = 10;
	//Bornes yMin et yMax définies par l'utilisateur (par défaut à -10 et 10)
	int yMin = -10;
	int yMax = 10;

	// Scan fonction
	printf("Saisissez une fonction :\n");        //Demande de saisie d'une fonction
	scanf_s("%s", fonction, 200);					//Sauvegarde de la fonction saisie dans le tableau de caractere fonction
	fflush(stdin);
	printf("\n", fonction);
	fflush(stdout);

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
	char *myargv[1];
	int myargc = 1;
	myargv[0] = strdup("Graph");
	InitGraph(myargc, myargv, "Grapheur", 800, 700, myDraw, myKey);
	return 0;
}


