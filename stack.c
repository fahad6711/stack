#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int top;
    int capacity;
    int *array;
};

struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack))
        return -1;
    return stack->array[stack->top];
}

void freeStack(struct Stack* stack) {
    free(stack->array);
    free(stack);
}

int main() {
    struct Stack* stack = createStack(100);
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    printf("Top item is %d\n", peek(stack));
    printf("Popped item is %d\n", pop(stack));
    printf("Top item is %d\n", peek(stack));
    freeStack(stack);
    return 0;
}