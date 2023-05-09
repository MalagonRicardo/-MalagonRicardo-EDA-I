#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
   
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

void push(struct Stack* stack, int item){
    if (isFull(stack))
    return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack){
    if (isEmpty(stack))
    return INT_MIN;
    return stack->array[stack->top--];
}

int peek(struct Stack* stack){
    if (isEmpty(stack))
    return INT_MIN;
    return stack->array[stack->top];
}

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* arr;
};

struct Queue* createQueue(unsigned capacity){
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->arr = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFul(struct Queue* queue){
    return (queue->size == queue->capacity);
}

int isEmpt(struct Queue* queue){
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item){
    if (isFul(queue))
    return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("tienes el turno %d de la cola\n", item);
}

int rear(struct Queue* queue){
    if (isEmpt(queue))
    return INT_MIN;
    return queue->arr[queue->rear];
}


int main(){
    int opcion = 0;
    struct Stack* stack = createStack(10);
    push(stack, 10);
    push(stack, 9);
    push(stack, 8);
    push(stack, 7);
    push(stack, 6);
    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);
    struct Queue* queue = createQueue(10);
    while(true){
        printf("\nBienvenido al Sistema de Turnos     \n¿Que desea hacer?\n");
        printf("  1. Formarse\n  2. Salir\n");
        scanf("%d", &opcion);
        
        switch(opcion){
            case 1:
            if (stack->top == -1){
                printf("Ya no hay turnos disponibles");
            }
            else{
            enqueue(queue, pop(stack));
            }
            break;
            case 2:
            if (stack->top == -1){
                printf("Ya no hay mas turnos disponibles\n");
                exit(0);
            }
            else{
                printf("Ultimo elemento formado en la cola: %d \n", rear(queue));
                printf("Ultimo elemento formado en el tope de la pila: %d\n", peek(stack));
                exit(0);
            }
        }

    }

    return 0;
}