/*
    Ajoutez vos erreurs ci-dessous en appellant cette fonction dans votre code � l'endroit o� l'erreur est d�tect�e

*/
void error(int Code_Error){
    switch (Code_Error){
    case 101 : printf("Erreur 101 : Double virgule\n");
    break;
    case 102 : printf("Erreur 102 : La case pr�c�dente est une erreur\n");
    break;
    case 103 : printf("Erreur 103 : Le caract�re saisi est non autorise\n");
    break;
    case 104 : printf("Erreur 104 : Fonction inexistante\n");
    break;
    }
}
