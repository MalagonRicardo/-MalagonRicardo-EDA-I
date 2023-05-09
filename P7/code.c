#include <stdio.h>
#include <stdlib.h>

struct nodo {
  int dato;
  struct nodo *siguiente;
};

struct listaCircular {
  struct nodo *inicio;
};

struct nodo *crearNodo(int dato) {
  struct nodo *nuevoNodo = (struct nodo *) malloc(sizeof(struct nodo));
  nuevoNodo->dato = dato;
  nuevoNodo->siguiente = NULL;
  return nuevoNodo;
}

void insertar(struct listaCircular *lista, int dato) {
  struct nodo *nuevoNodo = crearNodo(dato);
  if (lista->inicio == NULL) {
    lista->inicio = nuevoNodo;
    nuevoNodo->siguiente = nuevoNodo;
  } else {
    nuevoNodo->siguiente = lista->inicio;
    struct nodo *ultimo = lista->inicio;
    while (ultimo->siguiente != lista->inicio) {
      ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = nuevoNodo;
    lista->inicio = nuevoNodo;
  }
}

void imprimirListaCircular(struct listaCircular lista) {
  if (lista.inicio == NULL) {
    printf("La lista está vacía.\n");
  } else {
    printf("Lista: ");
    struct nodo *actual = lista.inicio;
    do {
      printf("%d ", actual->dato);
      actual = actual->siguiente;
    } while (actual != lista.inicio);
    printf("\n");
  }
}

void buscarElemento(struct listaCircular lista, int valorBuscado) {
  if (lista.inicio == NULL) {
    printf("La lista está vacía.\n");
  } else {
    struct nodo *actual = lista.inicio;
    int encontrado = 0;
    do {
      if (actual->dato == valorBuscado) {
        printf("Se encontró el elemento en la estructura.\n");
        encontrado = 1;
        break;
      }
      actual = actual->siguiente;
    } while (actual != lista.inicio);
    if (!encontrado) {
      printf("El elemento no se encuentra en la estructura.\n");
    }
    imprimirListaCircular(lista);
  }
}

int main() {
  printf("Bienvenido, para realizar una búsqueda\n"); 

  struct listaCircular lista;
  lista.inicio = NULL;

  insertar(&lista, 5);
  insertar(&lista, 7);
  insertar(&lista, 1);
  insertar(&lista, 3);
  insertar(&lista, 12);
  insertar(&lista, 69);
  insertar(&lista, 6);
  insertar(&lista, 9);

  int valorBuscado;
  printf("Introduzca un valor para buscar: ");
  scanf("%d", &valorBuscado);

  buscarElemento(lista, valorBuscado);

  return 0;
}