#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#ifndef JETON_H_INCLUDED
#define JETON_H_INCLUDED
#include "jeton.h"
#endif

void tableau_jeton(char phrase[MAX], typeJeton *lexique);

int verifier_fonction(char *mot,typeJeton *j, int ligne);

void analyseLex(char* fonction, typeJeton* resLex);