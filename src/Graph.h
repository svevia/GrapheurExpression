/**
* @file Graph.h
*
* @brief pr�sente quelques outils d'affichage n�cessaires dans le cadre de ce
* projet.
* Il contient la d�claration des proc�dures disponibles pour ouvrir une fen�tre
* et y dessiner des figures. Les coordonn�es des points dans la fen�tre sont
* d�finies sur l'intervalle [-1;1], (-1,-1) etant le coin inferieur gauche de
* la fenetre et (1,1) le coin superieur droit.
* 
* Pour une d�monstration de l'utilisation de ces proc�dures, voir le fichier
* main.cpp.
*
*/

/**
* InitGraph
*
* Proc�dure d'initialisation de la fen�tre et de l'environnement OpenGL 
*
* @param ac nombre de param�tres
* @param av tableau contenant les param�tres 
* @param WinName le nom (titre) de la fen�tre d'affichage
* @param w la largeur de la fen�tre
* @param h la hauteur de la fen�tre
* @param Draw fonction qui affiche le graphique dans la fen�tre
* @param Key fonction appel�e lors de l'appui sur une touche c du clavier,
*	 c d�signant le code ascii de la touche
*
*/
void InitGraph(int ac,char *av[], const char *WinName,
               const int w, const int h, void (*Draw)(void),
               void (*Key)(int c));
/**
* line
*
* Cette proc�dure permet de tracer une ligne entre deux points (x0, y0) et
* (x1,y1) 
*
* @param x0 abscisse du 1er point
* @param y0 ordonn�e du 1er point
* @param x0 abscisse du 2eme point
* @param y0 ordonn�e du 2eme point
*
*/
void line(const float x0, const float y0, const float x1, const float y1);


/**
* setcolor
*
* Cette proc�dure permet de d�finir la couleur utilis�e pour tracer les lignes.
* La couleur est d�finie par les valeurs des composantes rouge, vert et bleue.
*
* @param r composante rouge
* @param v composante verte
* @param b composante bleue
*
*/
void setcolor(const float r, const float v, const float b);

/**
* beginlines
*
* Cette proc�dure permet de commencer le trac� d'une ligne bris�e compos�e
* de n segments de droite d�finis par (n+1) points.
*
* @param x0 l'abscisse du premier point de la ligne bris�e
* @param y0 l'ordonn�e du premier point de la ligne bris�e
*
*/
void beginlines(const float x0, const float y0);

/**
* lineto
*
* Cette proc�dure permet d'ajouter un point � la ligne bris�e en cours. Le
* dernier point d�fini et le nouveau point d�limitent un nouveau segment de
* droite dans la ligne bris�e.
*
* @param x l'abscisse du nouveau point de la ligne bris�e
* @param y l'ordonnee du nouveau point de la ligne bris�e
*
*/
void lineto(const float x, const float y);

/**
* finishlines
*
* Cette proc�dure permet de terminer le trac� de la ligne bris�e en cours.
*
*/
void finishlines(void);

void drawGrid(double pasX, double pasY);

/**
* bar
*
* Cette proc�dure permet de tracer un rectangle d�fini par son coin sup�rieur
* gauche et son coin inf�rieur droit.
*
* @param x0 abscisse du coin sup�rieur gauche du rectangle
* @param y0 ordonnee du coin sup�rieur gauche du rectangle
* @param x1 abscisse du coin inf�rieur droit du rectangle
* @param y1 ordonnee du coin inf�rieur droit du rectangle
*
*/
void bar(const float x0, const float y0, const float x1, const float y1);

/**
* outtextxy
*
* Cette proc�dure permet d'�crire une cha�ne de caract�res dans une zone de
* texte d�finie par les coordonn�es x et y
*
* @param x abscisse de l'origine (coin sup�rieur gauche) de la zone de texte
* @param y ordonnee de l'origine (coin sup�rieur gauche) de la zone de texte
* @param s cha�ne de caract�res contenant le texte � afficher
*
*/
void outtextxy(const float x, const float y, const char *s);



