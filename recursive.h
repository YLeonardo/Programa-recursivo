#ifndef recursive.h _H
#define recursive.h _H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int StackEntry;

typedef struct node_stack {
    StackEntry entry;
    struct node_stack *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Node *createNode(StackEntry);
Stack *createStack();
bool stackEmpty(Stack *);
void push(StackEntry, Stack *);
StackEntry pop(Stack *); 

Node *createNode(StackEntry item) {
    Node *np = (Node *) malloc(sizeof(Node));

    if (np == NULL) {
        printf("Error, no se puede asignar memoria\n");
    } else {
        np->entry = item;
        np->next = NULL;
    }

    return np;
}

Stack *createStack() {
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
}

bool stackEmpty(Stack *s) {
    return s->top == NULL;
}

void push(StackEntry item, Stack *s) {
    Node *np = createNode(item);

    if (stackEmpty(s)) {
        np->next = NULL;
    } else {
        np->next = s->top;
    }
    s->top = np;
}

StackEntry pop(Stack *s) {
    StackEntry item;

    if(stackEmpty(s)) {
       item = -1;
    } else {
        item = s->top->entry;
        Node *np = s->top;
        s->top = s->top->next;
        free(np);
    }

    return item;
}


int contador(char*a,char*b,int pos,Stack *e);
int comprobador(char*a,char*b,int pos);

#endif
