#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 25

typedef struct node {
    char element;
    struct node* next;
    struct node* prev;
} node;

typedef struct deque {
    node* front;
    node* rear;
} deque;

void check(deque* d) {
    d->front = NULL;
    d->rear = NULL;
}

void addFront(deque* d, char c) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = c;
    new_node->prev = NULL;
    new_node->next = d->front;
    if (d->front == NULL) {
        d->rear = new_node;
    } else {
        d->front->prev = new_node;
    }
    d->front = new_node;
}

void addRear(deque* d, char c) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->element = c;
    new_node->next = NULL;
    new_node->prev = d->rear;
    if (d->rear == NULL) {
        d->front = new_node;
    } else {
        d->rear->next = new_node;
    }
    d->rear = new_node;
}

char delFront(deque* d) {
    if (d->front == NULL) {
        printf("la Deque esta vacia.\n");
        return '\0';
    }
    char c = d->front->element;
    node* temp = d->front;
    d->front = d->front->next;
    if (d->front == NULL) {
        d->rear = NULL;
    } else {
        d->front->prev = NULL;
    }
    free(temp);
    return c;
}

char delRear(deque* d) {
    if (d->rear == NULL) {
        printf("la Deque esta vacia.\n");
        return '\0';
    }
    char c = d->rear->element;
    node* temp = d->rear;
    d->rear = d->rear->prev;
    if (d->rear == NULL) {
        d->front = NULL;
    } else {
        d->rear->next = NULL;
    }
    free(temp);
    return c;
}

int es_palindromo(char* word) {
    deque d;
    check(&d);
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        addRear(&d, word[i]);
    }
    while (d.front != d.rear && d.front->prev != d.rear) {
        if (delFront(&d) != delRear(&d)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    printf("Bienvenido al Revisor de Palabras\n");
    char word[MAX_LENGTH];
    printf("Ingrese una palabra: ");
    scanf("%s", word);
    if (es_palindromo(word)) {
        printf("La palabra %s es un palindromo.\n", word);
    } else {
        printf("La palabra %s no es un palindromo.\n", word);
    }
    return 0;
}