#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    double value;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
    int size;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (!s) {
        fprintf(stderr, "Erro: Falha na alocacao da pilha.\n");
        exit(1);
    }
    s->top = NULL;
    s->size = 0;
    return s;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}
void push(Stack* s, double v) {
    Node* n = (Node*) malloc(sizeof(Node));
    if (!n) {
        fprintf(stderr, "Erro: Falha na alocacao de no.\n");
        free(s);
        exit(1);
    }
    n->value = v;
    n->next = s->top;
    s->top = n;
    s->size += 1;
}

double pop(Stack* s) {
    if (isEmpty(s)) {
        fprintf(stderr, "Erro: Pilha vazia (operandos insuficientes).\n");
        exit(1);
    }
    Node* t = s->top;
    double v = t->value;
    s->top = t->next;
    free(t);
    s->size -= 1;
    return v;
}
void freeStack(Stack* s) {
    Node* cur = s->top;
    while (cur != NULL) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    free(s);
}

int isOperator(const char* tok) {
    return strlen(tok) == 1 && (tok[0] == '+' || tok[0] == '-' || tok[0] == '*' || tok[0] == '/');
}

double evaluateRPN(char* expr) {
    Stack* s = createStack();
    char* token = NULL;
    const char* delim = " \t\n";
    token = strtok(expr, delim);

    if (token == NULL) {
        fprintf(stderr, "Erro: Expressao vazia.\n");
        freeStack(s);
        exit(1);
    }

    while (token != NULL) {
        char* endptr;
        double num = strtod(token, &endptr);

        if (endptr != token && *endptr == '\0') {
            push(s, num);
        } else if (isOperator(token)) {
            char op = token[0];
           
            if (s->size < 2) {
                fprintf(stderr, "Erro: Expressao malformada (operandos insuficientes para o operador '%c').\n", op);
                freeStack(s);
                exit(1);
            }
            double val2 = pop(s);
            double val1 = pop(s);
            double res = 0.0;

            switch (op) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/':
                    if (val2 == 0.0) {
                        fprintf(stderr, "Erro: Tentativa de divisao por zero.\n");
                        freeStack(s);
                        exit(1);
                    }
                    res = val1 / val2;
                    break;
                default:
                    fprintf(stderr, "Erro: Operador invalido '%c'.\n", op);
                    freeStack(s);
                    exit(1);
            }
            push(s, res);
        } else {
            fprintf(stderr, "Erro: Token invalido '%s'.\n", token);
            freeStack(s);
            exit(1);
        }

        token = strtok(NULL, delim);
    }

    if (s->size == 0) {
        fprintf(stderr, "Erro: Expressao vazia.\n");
        freeStack(s);
        exit(1);
    } else if (s->size > 1) {
        fprintf(stderr, "Erro: Expressao malformada (operandos extras).\n");
        freeStack(s);
        exit(1);
    }

    double finalResult = pop(s);
    freeStack(s);
    return finalResult;
}
int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Uso: %s \"<expressao em RPN>\"\n", argv[0]);
        fprintf(stderr, "Exemplo: %s \"10 5 +\"\n", argv[0]);
        return 1;
    }
    char* input = strdup(argv[1]);
    if (!input) {
        fprintf(stderr, "Erro: Falha na alocacao de memoria.\n");
        return 1;
    }

    double result = evaluateRPN(input);
    free(input);

    printf("Resultado: %.2f\n", result);
    return 0;
}
