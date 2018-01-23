#include <stdio.h>

#define STAR '*'
#define PLUS '+'
#define QMARK '?'
#define DSIGN '$'
#define CARROT '^'
#define DOT '.'
#define DASH '-'
#define OR '|'
#define QUOTE '\''
#define LPAREN '('
#define RPAREN ')'
#define LBRACE '{'
#define RBRACE '}'
#define LSQUARE '['
#define RSQUARE ']'
#define FSLASH '/'
#define BSLASH '\\'
#define MAX 20000

struct env {
    FILE* infile;
    int val;
    int top;
    char stack[MAX];
    char infix[MAX];
    char postfix[MAX];
};

typedef enum {
    false,
    true
} truth;

typedef enum {
    overflow,
    underflow
} enum_stack_err;

struct env env;

int main(int argc, char *argv[]) {

    /* extract from input file, etc. */

    struct env env;
    env.infile = fopen(argv[1], "r");

    infix(&env, argv[1]);
}

int isop(struct env *env) {
    char c;
    while((c = getc(env->infile)) != EOF) {
        if(c == '*')
            return true;
        else if(c == '+')
            return true;
        else if(c == '?')
            return true;
         else if(c == '$')
            return true;
        else if(c == '^')
            return true;
        else if(c == '.')
            return true;
        else if(c == '-')
            return true;
        else if(c == '\'')
            return true;
        else if(c == '/')
            return true;
        else if(c == '\\')
            return true;
        else
            return false;
    }
}

int is_lbrace(struct env *env) {

    while((c == getc(env->infile)) != EOF) {
        if(c == '(')
            return true;
        if(c == '{')
            return true;
        else if(c == '[')
            return true;
        else
            return false;
    }
}

int is_rbrace(struct env *env) {

    while((c == getc(env->infile)) != EOF) {
        if(c == ')')
            return true;
        else if(c == '}')
            return true;
        else if(c == ']')
            return true;
        else
            return false;
    }
}


void push(struct env **env, char item) {
    if((*env)->top > MAX - 1) {
        printf("stack overflow\n");
        stack_error(overflow);
    } else{
        (*env)->top++;
        (*env)->stack[env->top] = item;
    }
}

char pop(struct env **env) {
    if((*env)->top < 0) {
        printf("stack underflow\n");
        stack_error(underflow);
    } else {
        char item = (*env)->top;
        (*env)->top--;
        return item;
    }
    return '\0';
}

void stack_error(enum_stack_err err) {
    if(err == overflow)
        ;//this
    else if(err == underflow)
        ;// that
}

//infix = X
//postfix = Y
void postfix(struct env **env, char infix[]) {
    push(env, '(');
    
}