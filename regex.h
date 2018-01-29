#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* precedence */
#define OR 0
#define DASH 1
#define PLUS 1
#define DSIGN 2
#define QMARK 2
#define DOT 3
#define STAR 4
#define CARROT 5
#define QUOTE 6
#define BSLASH 7
/* ------------------ */
#define LPAREN '('
#define RPAREN ')'
#define LBRACE '{'
#define RBRACE '}'
#define LSQUARE '['
#define RSQUARE ']'
#define FSLASH '/'

#define MAX 20000

typedef struct stack_t {
    int top;
    char stack_arr[MAX];
} stack_t;

typedef enum {
    false,
    true
} truth;

typedef enum {
    overflow,
    underflow,
    syntax
} enum_stack_err;

struct env {
    FILE* infile;
    stack_t *stack;
};

// typedef stack_t stack_t;

int isop(char c);
int is_lbrace(char c);
int is_rbrace(char c);
void push(stack_t **stack, char item);
char pop(stack_t **stack);
int precedence(char op);
void stack_error(enum_stack_err err);
void postfix(char infix[], char postfix[]);