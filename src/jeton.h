typedef enum{FONCTION, OPERATOR, VARIABLE, REEL, ERREUR, FIN, PAR_OPEN, PAR_CLOSE} typeLexem; //Pour chaque nouvel élément ajouté, il faut modifier le fichier Eval.c
typedef enum{PLUS='+', MINUS='-', MULTIPLICATION='*', DIVISION='/'} typeOperator;
typedef enum{SIN,COS} typeFonction;
typedef enum{ERR1,ERR2} typeError;

union typeValeur{
    typeFonction FUN;
    typeOperator OPER;
    typeError ERR;
    float VAL;
};


typedef struct{
    typeLexem lexem;
    union typeValeur valeur;
    int priority;
}typeJeton;


typedef struct node{
    typeJeton jeton;
    struct node* left;
    struct node* right;
}node;

typedef struct{
    float x;
    float y;
}point;
