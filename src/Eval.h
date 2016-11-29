#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef JETON_H_INCLUDED
#define JETON_H_INCLUDED
#include "jeton.h"
#endif

short int getTaille(float pas,short int borneMoins, short int bornePlus);
point* stockage (float pas,short int borneMoins,short int bornePlus, node* racine);
float CalculRes(float xParam,node* racine);
