#define MAX 100
#define MAXINPUT 100

typedef enum{
    FONCTION=10,
    OPERATOR,
    VARIABLE,
    REEL,
    ERREUR,
    FIN,
    PAR_OPEN,
    PAR_CLOSE,
	INDEFINI}typeLexem;

typedef enum{
    PLUS=30,
    MINUS,
    MULTIPLICATION,
    DIVISION,
    POWER}typeOperator;

typedef enum{
    SIN=20,
    COS,
    TAN,
    EXP,
    LOG,
    SQRT,
    ABS}typeFonction;

typedef enum{
    ERR100=100,                  //aucune erreur
    ERR101=101,                 //Double virgule
    ERR102=102,                 //La case pr�c�dente est une erreur
    ERR103=103,                  //Le caract�re saisi est non autoris�
    ERR104=104}typeError;      //Fonction inexistante

union typeValeur{
    typeFonction FUN;
    typeOperator OPER;
    typeError ERR;
    float VAL;
    char VAR; //R�cup�rer valeur de la variable test
    typeLexem INDEFINI;
    typeLexem VARIABLE;
};

typedef struct{
    typeLexem lexem;
    union typeValeur valeur;
    int priority;//utilis� pour le syntaxique, ne pas s'en occupper
}typeJeton;


typedef struct node{
    typeJeton jeton;
    struct node* left;
    struct node* right;
	int pos;//utilis� pour le syntaxique, ne pas s'en occupper
}node;

typedef struct{
    float x;
    float y;
}point;
