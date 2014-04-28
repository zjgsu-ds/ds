#include <stdio.h>
#include <string.h>

/* See http://en.wikipedia.org/wiki/Shunting_yard_algorithm */

#define MAX_LEN 100

struct OperatorStack
{
    char data[MAX_LEN];
    int top;
};

struct OperandStack
{
    int data[MAX_LEN];
    int top;
};

void init_operator_stack(struct OperatorStack *s);
void push_operator(struct OperatorStack *s,  char b);
char pop_operator(struct OperatorStack *s);
char get_top_operator(struct OperatorStack *s);

void init_operand_stack(struct OperandStack *s);
void push_operand(struct OperandStack *s,  int b);
int pop_operand(struct OperandStack *s);

int is_left_parenthesis(char c);
int is_right_parenthesis(char c);
char matched_parenthesis(char c);
int is_operator(char c);
int precedence(char c);
int apply(struct OperatorStack *operators, struct OperandStack *operands);

int main()
{
    struct OperatorStack operators;
    struct OperandStack operands;
    char input[MAX_LEN];
    int n, i, oprd, a, b, res, pos;
    char op, last_op, matched_op;

    gets(input);
    n = strlen(input);

    init_operator_stack(&operators);
    init_operand_stack(&operands);

    i = 0;
    while (i < n) {
        op = input[i];
        if (op == ' ' || op == '\t') {
            i++;
        } else if (is_operator(op)) {
            if (operators.top == 0 || precedence(op) < precedence(get_top_operator(&operators))) {
                push_operator(&operators, op);
                i++;
            } else {
                apply(&operators, &operands);
            }
        } else if (is_left_parenthesis(op)) {
            push_operator(&operators, op);
            i++;
        } else if (is_right_parenthesis(op)) {
            matched_op = matched_parenthesis(op);

            while (get_top_operator(&operators) != matched_op)
                apply(&operators, &operands);
            pop_operator(&operators);
            i++;
        } else {
            if (sscanf(input + i, "%d%n", &oprd, &pos) == 1) {
                push_operand(&operands, oprd);
                i += pos;
            }
        }
    }

    while (operators.top)
        apply(&operators, &operands);

    printf("%d\n", pop_operand(&operands));

    return 0;
}


void init_operator_stack(struct OperatorStack *s)
{
    s->top = 0;
}

void push_operator(struct OperatorStack *s,  char b)
{
    s->data[s->top] = b;
    s->top++;
}

char pop_operator(struct OperatorStack *s)
{
    s->top--;
    return s->data[s->top];
}

char get_top_operator(struct OperatorStack *s)
{
    return s->data[s->top-1];
}


void init_operand_stack(struct OperandStack *s)
{
    s->top = 0;
}

void push_operand(struct OperandStack *s,  int b)
{
    s->data[s->top] = b;
    s->top++;
}

int pop_operand(struct OperandStack *s)
{
    s->top--;
    return s->data[s->top];
}

int is_left_parenthesis(char c)
{
    return c == '(' || c == '[';
}

int is_right_parenthesis(char c)
{
    return c == ')' || c == ']';
}

char matched_parenthesis(char c)
{
    switch (c) {
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
    }

    return 0;
}

int is_operator(char c)
{
    return c == '+' || c == '-' || c == 'x' || c == '/';
}

int precedence(char op)
{
    switch (op) {
        case '(':
            return 3;
        case '[':
            return 2;
        case '+':
        case '-':
            return 1;
        case 'x':
        case '/':
            return 0;
    }

   return -1; 
}

int apply(struct OperatorStack *operators, struct OperandStack *operands)
{
    char op = pop_operator(operators);
    int b = pop_operand(operands);
    int a = pop_operand(operands);
    int res = 0;

    switch (op) {
        case '+':
            res = a + b;
            break;
        case '-':
            res = a - b;
            break;
        case 'x':
            res = a * b;
            break;
        case '/':
            res = a / b;
            break;
    }

    push_operand(operands, res);
    return res;
}
