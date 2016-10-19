/**************************
* Includes
*
**************************/
#include <stdio.h>
#include <string.h>
#include "graph.h"
#include <math.h>

int bascule = 0;
int xMin = 0;
int xMax = 1;

//Testing structure
struct point
{
	float x, y;
};

point tab[20];

//Testing method
void fillpointTab()
{
	point tmp = { 0.0, 0.0 };
	for (int i = 0; i < 20; ++i)
	{
		tmp.x = i - 10;
		tmp.y = sin((long double)i);
		tab[i] = tmp;
	}
}

//permet de placer un point dans l'intervalle [-1;1] en fonction de l'intervalle donn� par l'utilisateur
float inter_abscisse(float x, float x1, float x2){
	return(2 / (x2 - x1))*(x - ((x2 + x1) / 2));
}

//permet de placer un point dans l'intervalle [-1;0.65] en fonction de l'intervalle donn�e par l'utilisateur
float inter_ordonnee(float y, float y1, float y2){
	return(((1.65 / (y2 - y1))*(y - ((y2 + y1) / 2))) - 0.175);
}

//Testing method
void convertTab(){
	int tabLength = sizeof(tab) / sizeof(point);
	point tmp = { 0.0, 0.0 };
	point res = { 0.0, 0.0 };
	for (int i = 0; i<tabLength; ++i)
	{
		tmp = tab[i];
		res.x = inter_abscisse(tmp.x, xMin, xMax);
		res.y = inter_ordonnee(tmp.y, xMin, xMax);
		tab[i] = res;
	}
}

/**
* myKey
*
* Gestion des touches du clavier
*
* @parma c code ascci definissant une touche du clavier
*
*/
void myKey(int c)
{
	switch (c)
	{
	case 'a':
		bascule ^= 1; /* La bascule passe alternativement de 0 a 1 */
		break;
	}
}

void drawCurve()
{
	int tabLength = sizeof(tab) / sizeof(point);
	point tmp1 = { 0.0, 0.0 };
	point tmp2 = { 0.0, 0.0 };
	for (int i = 0; i<tabLength - 1; ++i)
	{
		tmp1 = tab[i];
		tmp2 = tab[i + 1],
			line(tmp1.x, tmp1.y, tmp2.x, tmp2.y);
	}
}

/**
* myDraw
*
* Proc�dure
*
*/
void myDraw(void)
{
	drawGrid();
	/* trace une ligne blanche diagonale */
	setcolor(1.0F, 1.0F, 1.0F);
	line(0, -1, 0, 1); //Abscisse
	line(-1, 0, 1, 0); //Ordonnee
	drawCurve();
	if (bascule)
	{
		/* Trace un rectangle rouge a l'ecran si active
		* par appui de la touche 'a' */
		//setcolor(1.0F,0.0F,0.0F);
		//bar(-0.5F,-0.5F,0.5F,0.5F);  
	}
	/* ecrit le message "bonjour" en jaune */
	//setcolor(1.0F,1.0F,0.0F);
	//outtextxy(0.0,0.0,"Bonjour");  
}


/**
* main
*
* La fonction principale avec deux arguments permettant de r�cup�rer les �l�ments en ligne de comment.
*
* Dans  cet  exemple  les  fonctions  (dites  callback)  myDraw  et  myKey  sont  install�es  ici  par
* l'appel  InitGraph  en  tant  que fonctions  r�agissantes  aux  �v�nements  de  "re-dessinage"  (pour  myDraw)
* et  aux  �v�nements  d'appui  sur  une  touche  du
* clavier (myKey).

* @parma ac : nombre de parametres
* @parma av : tableau contenant les parametres
*
*/
int main(int ac, char *av[])
{
	/*printf("Entrez la borne minimale : ");
	scanf("%d", &xMin);
	printf("Entrez la borne minimale : ");
	scanf("%d", &xMax);*/
	xMin = -10;
	xMax = 10;
	fillpointTab();
	convertTab();
	InitGraph(ac, av, "Essai Glut", 800, 700, xMin, xMax, myDraw, myKey);
	return 0;
}


