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

typedef stack_t {
    int top;
    char stack_arr[MAX];
} stack_t;

typedef enum {
    false,
    true
} truth;

typedef enum {
    overflow,
    underflow
} enum_stack_err;

struct env {
    FILE* infile;
    int val;
    int top;
    stack_t *stack;
};
/* Should struct be global or not? */
struct env env;

int main(int argc, char *argv[]) {

    // struct env env;
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


void push(stack_t **stack, char item) {
    int top = (*stack)->top;
    char stack_arr[];
    // stack_t *new_stack = malloc(sizeof(stack_t));
    if(strcmp((*stack)->stack_arr, '\0'))
       strcpy(stack_arr, (*stack)->stack_arr); 
    

    if(top > MAX - 1) {
        printf("stack overflow\n");
        stack_error(overflow);
    } else{
        top++;
        stack_arr[top] = item;
    }
    (*stack)->top = top;
    strcpy((*stack)->stack_arr, stack_arr);
}

char pop(stack_t **stack) {
    if((*stack)->top < 0) {
        printf("stack underflow\n");
        stack_error(underflow);
    } else {
        char item = (*stack)->top;
        (*stack)->top--;
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
void postfix(char infix[], char postfix[]) {
    int i;
    char *p;
    stack_t *stack = malloc(sizeof(stack_t));

    push(&stack, '(');
    strcat(infix, ")");

    for(p = infix; p != '\0'; *p++) {
        if(isop(infix[i])) {

        } else if(isalpha() || isdigit()
    }

}