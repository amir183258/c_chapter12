#define OPERATORS "+-*/^%"
#define OPERATORS_COUNT 6

#define HIGHEST_PRECEDENCE "^"
#define HIGH_PRECEDENCE "*/%"
#define LOW_PRECEDENCE "+-"

enum precedence {HIGHEST, HIGH, LOW};

void convertToPostfix(char infix[], char postfix[]);
int isOperator(char c);
int precedence(char operator1, char operator2);
void convertToPostfix(char infix[], char postfix[]);
