#include "error.h"
/*
    Ajoutez vos erreurs ci-dessous en appellant cette fonction dans votre code � l'endroit o� l'erreur est detectee

*/
void error(int Code_Error){
    switch (Code_Error){
    case 101 : printf("Erreur 101 : Double virgule\n");
    break;
    case 102 : printf("Erreur 102 : La case precedente est une erreur\n");
    break;
    case 103 : printf("Erreur 103 : Le caractere saisi est non autorise\n");
    break;
    case 104 : printf("Erreur 104 : Fonction inexistante\n");
    break;
    }
}
