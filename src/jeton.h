typedef enum{FONCTION, OPERATOR, VARIABLE, REEL, ERREUR, FIN, PAR_OPEN, PAR_CLOSE} typeLexem;
typedef enum{PLUS='+', MINUS='-', MULTIPLICATION='*', DIVISION='/'} typeOperator;
typedef enum{SIN, COS} typeFonction;
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
}typeJeton;


typedef struct{
    typeJeton jeton;
    struct node* left;
    struct node* right;
}node;
