#include <stdio.h>
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
    underflow,
    syntax;
} enum_stack_err;

struct env {
    FILE* infile;
    stack_t *stack;
};
/* Should struct be global or not? */
struct env env;
enum_stack_err error;

int main(int argc, char *argv[]) {
    char postfix[];
    // struct env env;
    env.infile = fopen(argv[1], "r");

    postfix(argv[1], );
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

int precedence(char op) {
    switch(op) {
        case '|':
            return DOT;
        case '-':
            return DASH;
        case '+':
            return PLUS;
        case '$':
            return DSIGN;
        case '?':
            return QMARK;
        case '.':
            return DOT;
        case '*':
            return STAR;
        case '^':
            return CARROT;
        case '\'':
            return QUOTE;
        case '\\':
            return BSLASH;
        default:
            return -1;
    }
}

void stack_error(enum_stack_err err) {
    if(err == overflow) {
        printf("overflow\n");
        exit(0);
    } else if(err == underflow) {
        printf("underflow\n");
        exit(0)
    } else if(err == syntax) {
        printf("Invalid syntax\n");
        exit(0);
    }
}

//infix = X
//postfix = Y
// http://www.includehelp.com/c/infix-to-postfix-conversion-using-stack-with-c-program.aspx
void postfix(char infix[], char postfix[]) {
    int i = 0;
    char *p;
    stack_t *stack = malloc(sizeof(stack_t));
    stack = env.stack;

    push(&stack, '(');
    strcat(infix, ")");

    for(p = infix; *p != '\0'; p++) {
        if(isop(*p)) {
            char x;
            x = pop(&stack);
            while(isop(x) && precedence(x) >= precedence(*p)) {
                postfix[i] = x;
                i++;
                x = pop(&stack);
            }
            x = *p
            push(x);
        } else if(isalpha(*p) || isdigit(*p)) {
            postfix[i] = *p;
            i++;
        } else if(is_lbrace(*p)) {
            push(&stack, '(');
        } else if(is_rbrace(*p)) {
            char x;
            x = pop(&stack);
            while(!is_lbrace(x))
                postfix[i] = x;
                i++;
                x = pop(&stack);
        }  else {
            stack_error(syntax);
        }
    }

}