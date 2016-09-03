#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * siguiente;
} node_t;

void imprimir_lista(node_t * cabecera) {
    node_t * current = cabecera;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->siguiente;
    }
}

int pop(node_t ** cabecera) {
    int retval = -1;
    node_t * siguiente_node = NULL;

    if (*cabecera== NULL) {
        return -1;
    }

    siguiente_node = (*cabecera)->siguiente;
    retval = (*cabecera)->val;
    free(*cabecera);
    *cabecera = siguiente_node;

    return retval;
}

int remover_por_valor(node_t ** cabecera, int val) {
    /* TODO: fill in your code here */
}

int main() {

    node_t * lista_prueba = malloc(sizeof(node_t));
    lista_prueba->val = 1;
    lista_prueba->siguiente = malloc(sizeof(node_t));
    lista_prueba->siguiente->val = 2;
    lista_prueba->siguiente->siguiente = malloc(sizeof(node_t));
    lista_prueba->siguiente->siguiente->val = 3;
    lista_prueba->siguiente->siguiente->siguiente = malloc(sizeof(node_t));
    lista_prueba->siguiente->siguiente->siguiente->val = 4;
    lista_prueba->siguiente->siguiente->siguiente->siguiente = NULL;

    remover_por_valor(&lista_prueba, 3);

    imprimir_lista(lista_prueba);
}
