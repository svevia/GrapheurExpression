typedef enum{FONCTION, OPERATOR, VARIABLE, REEL, ERREUR, FIN, PAR_OPEN, PAR_CLOSE} typeLexem
typedef enum{PLUS, MINUS, MULTIPLICATION, DIVISION} typeOperator

union{
    typeFonction FUN;
    typeOperator OPER;
    typeError ERR;
    float VAL;
}typeValeur


typedef struct{
    typeLexem lexem;
    typeValeur valeur;
}typeJeton
