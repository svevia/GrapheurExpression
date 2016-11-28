#include <stdlib.h>
#include <stdio.h>
#include "error.h"
#include "jeton.h"
#include "lex.h"

int i=0; //initialisation variable qui compte le nombre de caract�res de la phrase trait�s
int k=0; // initialisation variable qui compte le nombre de cases de tableau remplies

void tableau_jeton(char phrase[MAX], typeJeton *lexique) // fonction pour ajouter les diff�rents lexemes au tableau
	{
		int taille=strlen(phrase); // calcul de la taille de l'expression entr�e par l'utilisateur
		//jeton lexique[Max];

while (i<taille){ // on boucle temps qu'on a pas fini de lire toute l'expression


	if (phrase[i]=='+' || phrase[i]=='*' || phrase[i]=='/' || phrase[i]=='-' ) //test des op�rateurs
		{
			lexique[k].lexem=OPERATOR;
			if (phrase[i]=='+')
				{
					lexique[k].valeur.OPER=PLUS;
					i++;
					k++;
				}
			else if (phrase[i]=='*')
				{
					lexique[k].valeur.OPER=MULTIPLICATION;
					i++;
					k++;
				}
			else if (phrase[i]=='/')
				{
					lexique[k].valeur.OPER=DIVISION;
					i++;
					k++;
				}
            else if (phrase[i]=='^')
				{
					lexique[k].valeur.OPER=POWER;
					i++;
					k++;
				}
			else if (phrase[i]=='-') // test du moins
                {
                    lexique[k].valeur.OPER=MINUS;
                    //lexique[k].lexem=MINUS;
                    //lexique[k].valeur.INDEFINI=0;
                    i++;
                    k++;
                }
		}

	else if (phrase[i]=='(') // test de la parenth�se gauche
		{
			lexique[k].lexem=PAR_OPEN;
			lexique[k].valeur.INDEFINI=0;
			i++;
			k++;
		}

	else if (phrase[i]==')') // test de la parenth�se droite
		{
			lexique[k].lexem=PAR_CLOSE;
			lexique[k].valeur.INDEFINI=0;
			i++;
			k++;
		}


    else if (phrase[i]==' ') // si il y a un espace on passe au prochain caract�re sans toucher au tableau
		{
			i++;
		}



	else if ((phrase[i]>='0')&&(phrase[i]<='9') || (phrase[i]=='.') || (phrase[i]==',')) //on cherche les nombres reels qui sont entr�s par l'utilisateur
		{
			int nbre_chiffre=0;
			float reel=0;
			int nbre_virgule=0;
			int tableau_vide[MAX]; // tableau servant a r�initialiser les tableaux temporaires
			tableau_vide[0]='\0';
			char temp_nbre[MAX];
			*temp_nbre=*tableau_vide;
			while((phrase[i+1]>='0' && phrase[i+1]<='9') || phrase[i+1]=='.' || phrase[i+1]==',') //tant que le chiffre suivant est un entier ou une virgule on continue
				{
					if (phrase[i+1]=='.' || phrase[i+1]==',') // VERIF VIRGULES MULTIPLES
						{
							nbre_virgule++;
							if (nbre_virgule>=2)
								{
									lexique[k].lexem=ERREUR;
									lexique[k].valeur.ERR=ERR101;
									error(lexique[k].valeur.ERR);
									return;
								}

						}
					temp_nbre[nbre_chiffre]=phrase[i];
					i++;
					nbre_chiffre++;
				}
			if(nbre_virgule<2){
			temp_nbre[nbre_chiffre]=phrase[i];
			reel= atof(temp_nbre); //on transforme en un seul nombre les diff�rentes entr�es du tableau
			lexique[k].lexem=REEL;
			lexique[k].valeur.VAL=reel;

			i++;
			k++;
			}
	}
	else if (phrase[i]>='a' && phrase[i]<='z') // test des caract�res de type lettre
		{
			if (phrase[i]=='x') // test de la variable x
				{
					if (phrase[i+1]<'a' || phrase[i+1]>'z')
						{
							lexique[k].lexem=VARIABLE;
							lexique[k].valeur.VAR=phrase[i];
							//printf("LA VAR est : %c\n",phrase[i]);
							k++;
							i++;

						}

                lexique[k].lexem=VARIABLE;
                lexique[k].valeur.VARIABLE='x';
				}
			else if (phrase[i]=='p' && phrase[i+1]=='i') // test pour reconna�tre pi
						{
							lexique[k].lexem=REEL;
							float pi=3.14159265359;
							lexique[k].valeur.VAL=pi;
							k++;
							i=i+2;
						}
			else // test des fonctions
				{
					char temp[MAX];
					char tableau_vide2[MAX];
					tableau_vide2[0]='\0';
					*temp=*tableau_vide2;
					int l=0;
					while(phrase[i]>='a' && phrase[i]<='z')
						{
							temp[l]=phrase[i];
							l++;
							i++;
						}
					temp[l]='\0';
					k=verifier_fonction(temp, lexique, k); //fonction utilis�e pour v�rifier l'orthographe des fonctions rentr�es
					if (lexique[k-1].valeur.ERR==ERR102) // on test si ce que l'on a rentr� dans la case pr�c�dente est une erreur afin de ne pas boucler pour rien
					{
					    error(lexique[k-1].valeur.ERR);
						return;					}
				}
		}

	else if (phrase[i]>=33 && phrase[i]<=39 || phrase[i]>=58 && phrase[i]<=64 || phrase[i]>=91 && phrase[i]<=93 || phrase[i]>=95 && phrase[i]<=96 || phrase[i]>=123 && phrase[i]<=255){
		{
			lexique[k].lexem=ERREUR; //erreur caract�re non autoris�
			lexique[k].valeur.ERR=ERR103;
			error(lexique[k].valeur.ERR);
			return;
		}
	}
	if (i==taille){
			lexique[k].lexem=FIN; // si on est arriv� au dernier caract�re on met dans la case suivante FIN pour dire que la fonction rentr�e est finie
	}
	}

}


int verifier_fonction(char *mot,typeJeton *j, int ligne) // fonction de v�rification orthographique
	{
		if(strcmp(mot, "sin") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=SIN;
				ligne++;
			}
		else if(strcmp(mot, "cos") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=COS;
				ligne++;
			}
		else if(strcmp(mot, "tan") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=TAN;
				ligne++;
			}
		else if(strcmp(mot, "exp") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=EXP;
				ligne++;
			}
		 else if(strcmp(mot, "log") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=LOG;
				ligne++;
			}
		else if(strcmp(mot, "sqrt") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=SQRT;
				ligne++;
			}
		else if(strcmp(mot, "abs") == 0)
			{
				j[ligne].lexem=FONCTION;
				j[ligne].valeur.FUN=ABS;
				ligne++;
			}
		else
			{
				j[ligne].lexem=ERREUR; //FONCTION INNEXISTANTE
				j[ligne].valeur.ERR=ERR104;
				error(j[ligne].valeur.ERR);
				ligne++;
			}

	return ligne;
}

int main(){
	int i;
	typeJeton test[MAX];                            // On d�finit 100 variable structur� du type typeJeton
	char fonction_saisie[MAX];
	//printf("Saisissez une fonction :\n");        //Demande de saisie d'une fonction
	//gets(fonction_saisie);                       //Sauvegarde de la fonction saisie dans le tableau de caract�re fonction_saisie
	strcpy(fonction_saisie,"TaN(X-3.0+PI)");
	printf("F= %s \n",fonction_saisie);
	for(i=0;i<strlen(fonction_saisie);i++){
        fonction_saisie[i]=tolower(fonction_saisie[i]); //on transforme toutes les lettres en lettres minuscules afin de n'avoir � tester que par rapport aux minuscules
	}


	tableau_jeton(fonction_saisie , test); //Appel de la fonction de d�composition lexicale

	Test_Lex(k,test);                        //Fonction test permet de tester le bon fonctionnement de notre partie �tude lexical

	return 0;
}
