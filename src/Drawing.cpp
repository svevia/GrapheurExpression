#include "Drawing.h"

int bascule = 0;

//tableau de points
point* tab;
int taille;

//Le pas doit nous permettre de calculer et d'afficher le bon nombre de graduations sur l'axe des abscisses
double pasCalculeX = 0.1;
double pasCalculeY = 0.1;

//Bornes
int xMinG = -10;
int xMaxG = 10;
int yMinG = -10;
int yMaxG = 10;

void setBornes(int xMin, int xMax, int yMin, int yMax)
{
	xMinG = xMin;
	xMaxG = xMax;
	yMinG= yMin;
	yMaxG = yMax;
}

void setTab(point* res, int t)
{
	taille = t;
	tab = res;
}

//permet de placer un point dans l'intervalle [-1;1] en fonction de l'intervalle donné par l'utilisateur
float inter_abscisse(float x, float x1, float x2){
	return(2 / (x2 - x1))*(x - ((x2 + x1) / 2));
}

//permet de placer un point dans l'intervalle [-1;1] en fonction de l'intervalle donnée par l'utilisateur
float inter_ordonnee(float y, float y1, float y2){
	return(2 / (y2 - y1))*(y - ((y2 + y1) / 2));
}

//permet de convertir le tableau de points créé par fillPointTab() en tableau de points situés dans le bon intervalle défini par xMin et xMax
void convertTab(){
	point tmp = { 0.0, 0.0 };
	point res = { 0.0, 0.0 };
	for (int i = 0; i<taille; ++i)
	{
		tmp = tab[i];
		res.x = inter_abscisse(tmp.x, xMinG, xMaxG);
		res.y = inter_ordonnee(tmp.y, yMinG, yMaxG);
		tab[i] = res;
	}
}

// Fonction dessinant la courbe
void drawCurve()
{
	int val1 = 0;
	int val2 = 0;
	point tmp1 = { 0.0, 0.0 };
	point tmp2 = { 0.0, 0.0 };
	setcolor(0.7F,0.8F,1.0F);
	for (int i = 0; i<taille - 1; ++i)
	{
		val1 = i;
		val2 = i + 1;
		tmp1 = tab[val1];
		tmp2 = tab[val2];
		line(tmp1.x, tmp1.y, tmp2.x, tmp2.y);
	}
}

/**
* myDraw
*
* Procédure
*
*/
void myDraw(void)
{
	char tmp[MAXINPUT] = "";
	drawGrid(pasCalculeX, pasCalculeY);
	setcolor(0.3F,0.3F,0.3F);
	line(inter_abscisse(0,xMinG,xMaxG), inter_ordonnee(yMinG, yMinG, yMaxG), inter_abscisse(0, xMinG, xMaxG), inter_ordonnee(yMaxG, yMinG, yMaxG)); //Abscisse
	line(inter_abscisse(xMinG, xMinG, xMaxG), inter_ordonnee(0, yMinG, yMaxG), inter_abscisse(xMaxG, xMinG, xMaxG), inter_ordonnee(0, yMinG, yMaxG)); //Ordonnée
	drawCurve();
	if (bascule)
	{
		/* Trace un rectangle rouge à l'ecran si active
		* par appui de la touche 'a' */
		//setcolor(1.0F,0.0F,0.0F);
		//bar(-0.5F,-0.5F,0.5F,0.5F);  
	}
	// Affichage des bornes à l'écran
	setcolor(0.0F,1.0F,0.0F);

	sprintf(tmp, "xMin: %d", xMinG);
	outtextxy(-0.95,0.90,tmp); 

	sprintf(tmp, "xMax: %d", xMaxG);
	outtextxy(-0.95, 0.82, tmp);

	sprintf(tmp, "yMin: %d", yMinG);
	outtextxy(-0.95, 0.74, tmp);

	sprintf(tmp, "yMax: %d", yMaxG);
	outtextxy(-0.95, 0.66, tmp);
}

/**
* myKey
*
* Gestion des touches du clavier
*
* @parma c code ascci définissant une touche du clavier
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

/**
* Fonction gérant les tests des données rentrées par l'utilisateur concernant les bornes
*
* @param input : chaine saisie par l'utilisateur
* @return bool
*/
bool checkInput(char* input, int* borne)
{
	int length, i;
	length = strlen(input);
	for (i = 0; i < length; i++)
	{
		if (i != 0 && input[i] == '-')
		{
			printf("Veuillez saisir une valeur numerique.\n");
			return false;
		}
		if (!isdigit(input[i]) && input[i] != '-')
		{
			printf("Veuillez saisir une valeur numerique.\n");
			return false;
		}
	}
	*borne = atoi(input);
	return true;
}

void calculerPas(int xMin, int xMax, int yMin, int yMax)
{
	pasCalculeX = ((2.0)/(abs(xMax-xMin)));
	pasCalculeY = ((2.0) / (abs(yMax - yMin)));
}

/**
* Fonction permettant le scan des valeurs des bornes et la gestion des erreurs éventuelles.
*
* @return bool
*/
bool scanBornes(int* borne)
{
	char tmp[MAXINPUT] = "";
	scanf("%s", &tmp);
	if (!checkInput(tmp, borne)) return false;
	return true;
}

bool checkBornes(int xMin, int xMax, int yMin, int yMax)
{
	if (xMin > xMax || yMin > yMax)
	{
		printf("Bornes incorrectes. Les bornes minimum doivent etre strictement superieures aux bornes maximum.\n");
		return false;
	}
	else if (xMax == xMin || yMax == yMin)
	{
		printf("Bornes incorrectes. Les bornes minimum et maximum ne peuvent etre egales.\n");
		return false;
	}
	return true;
}