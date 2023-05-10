#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Estructura para los nodos de la lista
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Función para crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data, int pos) {
    if (pos == 1) {
        struct Node* newNode = createNode(data);
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
        *head = newNode;
    } else {
        int i = 1;
        struct Node* curr = *head;
        while (i < pos-1 && curr != NULL) {
            curr = curr->next;
            i++;
        }
        if (curr != NULL) {
            struct Node* newNode = createNode(data);
            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next != NULL) {
                curr->next->prev = newNode;
            }
            curr->next = newNode;
        }
    }
}

void delete(struct Node** head, int pos) {
    if (*head == NULL) {
        return;
    }
    if (pos == 1) {
        if ((*head)->next == *head) {
            *head = NULL;
        } else {
            struct Node* temp = *head;
            (*head)->prev->next = (*head)->next;
            (*head)->next->prev = (*head)->prev;
            *head = (*head)->next;
            free(temp);
        }
    } else {
        int i = 1;
        struct Node* curr = *head;
        while (i < pos && curr != NULL) {
            curr = curr->next;
            i++;
        }
        if (curr != NULL) {
            curr->prev->next = curr->next;
            if (curr->next != NULL) {
                curr->next->prev = curr->prev;
            }
            free(curr);
        }
    }
}
void printList(struct Node* head) {
    struct Node* current = head;
    printf("La lista es: ");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int opcion, data, pos;
    struct Node* head = createNode(1);
    insert(&head, 2,2);
    insert(&head, 3,3);
    insert(&head, 4,4);
    printList(head);
 
        while(true){

        printf("Menú de opciones:\n");
        printf("1. Agregar elemento\n");
        printf("2. Eliminar elemento\n");
        printf("3. Salir\n");

        printf("Ingrese una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a agregar: ");
                scanf("%d", &data);
                printf("Ingrese la posición donde agregar el elemento: ");
                scanf("%d", &pos);
                insert(&head, data, pos);
                printList(head);
                break;
            case 2:
                printf("Ingrese la posición del elemento a eliminar: ");
                scanf("%d", &pos);
                delete(&head, pos);
                printList(head);
                break;
            case 3:
                exit(0);
        }
    }
    return 0;
}