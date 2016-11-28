#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "Graph.h"
#ifndef JETON_H_INCLUDED
#define JETON_H_INCLUDED
#include "jeton.h"
#endif

void setBornes(int xMin, int xMax, int yMin, int yMax);

void setTab(point* res);

float inter_abscisse(float x, float x1, float x2);

float inter_ordonnee(float y, float y1, float y2);

void convertTab();

void drawCurve();

void myDraw(void);

void myKey(int c);

bool checkInput(char* input, int* borne);

void calculerPas(int xMin, int xMax, int yMin, int yMax);

bool scanBornes(int* borne);