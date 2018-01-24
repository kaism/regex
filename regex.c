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
    infix_t infix;
    postfix_t postfix;
};

typedef struct infix_t {
    int top;
    char stack[MAX];
} infix_t;

typedef postfix_t {
    int top;
    char stack[MAX];
} postfix_t;

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


void push(struct env **env, char item, char *fix) {
    int top;
    char stack[]
    if(strcmp(fix, "stack")) {
        top = (*env)->top;
        strcpy(stack, (*env)->stack);
    }

    if(strcmp(fix, "infix")) {
        top = (*env)->infix->top;
        strcpy(stack, (*env)->infix->stack);
    }

    if(strcmp(fix, "postfix")) {
        top = (*env)->postfix->top;
        strcpy(stack, (*env)->postfix->stack);
    }

    if((*env)->top > MAX - 1) {
        printf("stack overflow\n");
        stack_error(overflow);
    } else{
        (*env)->top++;
        if(strcmp(fix, "stack"))
            (*env)->stack[(*env)->top] = item;
        else if(strcmp(fix, "infix"))
            (*env)->stack[(*env)->top] = item;
        else if(strcmp(fix, "postfix"))
            (*env)->stack
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
// http://www.includehelp.com/c/infix-to-postfix-conversion-using-stack-with-c-program.aspx
void postfix(struct env **env) {
    push(env, '(', "stack");
    push(env, ')', "infix");

}