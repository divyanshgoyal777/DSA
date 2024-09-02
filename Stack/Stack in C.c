#include <stdio.h>

#define SIZE 10

struct stack
{
    int array[SIZE];
    int top;
};

int main()
{
    struct stack s;
    initstack(&s);
    push(&s,10);
    push(&s,2);
    push(&s,3);
    push(&s,3);
    push(&s,67);
    push(&s,12);
    push(&s,3);
    push(&s,23);
    push(&s,45);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    getTop(&s);

    return 0;
}

void initstack(struct stack *s)
{
    s->top = -1;
}

void push(struct stack *s, int n)
{
    if(s->top == SIZE-1)
    {
        printf("Stack is full\n");
        return;
    }
    s->top++;
    s->array[s->top] = n;
    printf("%d is pushed\n", n);
}

int pop(struct stack *s)
{
    if(s->top == -1)
    {
        printf("Stack is empty\n");
        return NULL;
    }
    int n = s->array[s->top];
    s->top--;
    printf("%d is popped\n", n);
    return n;
}

void getTop(struct stack *s){
    if(s->top == -1){
        printf("Stack is empty, no top value");
        return;
    }
    printf("Top stack value is %d",s->array[s->top]);
}
