#include "regex.h"

/* Should struct be global or not? */
struct env env;

enum_stack_err error;

int main(int argc, char *argv[]) {
    char postfix_exp[MAX];
    char infix_exp[MAX];
    // struct env env;
    env.infile = fopen(argv[1], "r");

    printf("Enter infix notation: ");
    scanf("%s", infix_exp);

    postfix(infix_exp, postfix_exp);

    printf("postfix: %s", postfix_exp);
}

int isop(char c) {
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

int is_lbrace(char c) {
    if(c == '(')
        return true;
    else if(c == '{')
        return true;
    else if(c == '[')
        return true;
    else
        return false;
}

int is_rbrace(char c) {
    if(c == ')')
        return true;
    else if(c == '}')
        return true;
    else if(c == ']')
        return true;
    else
        return false;
}


void push(stack_t **stack, char item) {
    int top;
    char *stack_arr;

    top = (*stack)->top;
    stack_arr = (*stack)->stack_arr;

   if(top > MAX - 1) {
        printf("stack overflow\n");
        stack_error(overflow);
    } else{
        top++;
        stack_arr[top] = item;
    }
    (*stack)->top = top;
    // strcpy((*stack)->stack_arr, stack_arr);
}

char pop(stack_t **stack) {
    int top = (*stack)->top;
    if(top < 0) {
        printf("stack underflow\n");
        stack_error(underflow);
    } else {
        char item = (*stack)->stack_arr[top];
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
        exit(0);
    } else if(err == syntax) {
        printf("Invalid syntax\n");
        exit(0);
    }
}

//infix = X
//postfix = Y
// http://www.includehelp.com/c/infix-to-postfix-conversion-using-stack-with-c-program.aspx
void postfix(char infix[], char postfix_exp[]) {
    int i = 0;
    char *p;
    stack_t *stack = malloc(sizeof(stack_t));
    env.stack = malloc(sizeof(stack_t));
    env.stack->top = 0;
    // env.stack->stack_arr = "";
    stack = env.stack;

    push(&stack, '(');
    strcat(infix, ")");
    // printf("%s\n%s", infix, stack->stack_arr);

    for(p = infix; *p; p++) {
        // printf("bitch\n");
        printf("%c\n", *p);
        if(isop(*p)) {
            char x;
            x = pop(&stack);
            while(isop(x) && precedence(x) >= precedence(*p)) {
                postfix_exp[i] = x;
                i++;
                x = pop(&stack);
            }
            x = *p;
            push(&stack, x);
        } else if(isalpha(*p) || isdigit(*p)) {
            postfix_exp[i] = *p;
            i++;
        } else if(is_lbrace(*p)) {
            push(&stack, '(');
        } else if(is_rbrace(*p)) {
            char x;
            x = pop(&stack);
            while(x != '(')
                postfix_exp[i] = x;
                i++;
                x = pop(&stack);
        } else {
            stack_error(syntax);
        }
        printf("postfix: %s\n", postfix_exp);
        printf("infix: %s\n", infix);
    }
    free(stack);
    free(env.stack);
}