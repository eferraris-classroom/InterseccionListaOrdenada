#include "ListaOrdenada.h"
#include <stdio.h>
#include <stdlib.h>

Nodo *crearNodo(int codigo){
    Nodo *nuevo = (Nodo*) malloc(sizeof (Nodo));

    if(nuevo == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    nuevo->siguiente = NULL;
    nuevo->codigo = codigo;

    return nuevo;
}

Lista *crearLista(){
    Lista *lista = (Lista*) malloc(sizeof (Lista));

    if(lista == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    lista->tam = 0;
    lista->primero = NULL;

    return lista;
}

void insertarOrdenado(Lista *lista, Nodo *nodoAInsertar){
    if ( lista->primero == NULL ) { //no tenemos aun elementos en la lista
        lista->primero = nodoAInsertar;
    } else { //tenemos elementos en la lista, hay que insertar de forma ordenada

        Nodo * act = NULL, * ant = NULL;
        act = lista->primero;
        ant = act;

        while ( act != NULL && act->codigo < nodoAInsertar->codigo) {
            ant = act;
            act = act->siguiente;
        }

        if ( act == NULL ) {
            ant->siguiente = nodoAInsertar;
        } else if ( act == ant ) { // 1
            lista->primero = nodoAInsertar;
            nodoAInsertar->siguiente = act;
        } else {
            nodoAInsertar->siguiente = act;
            ant->siguiente = nodoAInsertar;
        }

    }

    lista->tam++;
}

void eliminar(Lista *lista, int codigoABuscar){
    if ( lista->primero == NULL ) { //no tenemos aun elementos en la lista
        printf("El elemento no se encuentra (lista vacía).\n");
    } else { //tenemos elementos en la lista, hay que insertar de forma ordenada

        Nodo * act = NULL, * ant = NULL;
        act = lista->primero;
        ant = act;

        while ( act != NULL && act->codigo != codigoABuscar) {
            ant = act;
            act = act->siguiente;
        }

        if ( act != NULL && act == ant ) {
            //primer caso, el elemento que queremos eliminar se encuentra en el comienzo de la lista
            lista->primero = act->siguiente;
            free( act );
            lista->tam--;
        } else if ( act != NULL && act != ant ) {
            //segundo caso, el elemento que queremos eliminar se encuentra en el "medio" de dos nodos
            ant->siguiente = act->siguiente;
            free(act);
            lista->tam--;
        }

    }

}

void imprimir(Lista *lista){
    Nodo *aux = lista->primero;

    if(aux == NULL){
        printf("La lista ordenada esta vacía.\n");
        return;
    }

    printf("\nLista ordenada:\n");
    for(; aux != NULL; aux = aux->siguiente){
        printf("%d ", aux->codigo);
    }

    printf("\n");

}

void liberar(Lista *lista){
    Nodo *aux = lista->primero;

    while(aux != NULL){
        Nodo *ant = aux;
        aux = aux->siguiente;
        free(ant);
    }

    free(lista);
}

Lista *interseccionOrdenadas(Lista *lista1, Lista *lista2) {
    Lista *nueva = crearLista();

    Nodo *aux1 = lista1->primero;
    Nodo *aux2 = lista2->primero;

    while(aux1 != NULL && aux2 != NULL){
        if(aux1->codigo > aux2->codigo) { // Avanza el segundo
            aux2 = aux2->siguiente;
        } else if(aux1->codigo < aux2->codigo){ // Avanza el primero
            aux1 = aux1->siguiente;
        } else { // Son iguales, se guarda el valor y avanzan los dos
            insertarOrdenado(nueva, crearNodo(aux1->codigo));
            aux1 = aux1->siguiente;
            aux2 = aux2->siguiente;
        }
    }

    return nueva;
}
