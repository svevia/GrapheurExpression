#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef JETON_H_INCLUDED
#define JETON_H_INCLUDED
#include "jeton.h"
#endif

int getTaille(float pas, int borneMoins, int bornePlus);
point* stockage (float pas,int borneMoins,int bornePlus, node* racine);
float CalculRes(float xParam,node* racine);
