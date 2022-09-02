#ifndef CODIGOSAESTUDIAR_LISTAORDENADA_H
#define CODIGOSAESTUDIAR_LISTAORDENADA_H

typedef struct nodo {
    int codigo;
    struct nodo *siguiente;
} Nodo;

typedef struct listaOrdenada {
    Nodo *primero;
    int tam;
} Lista;

Lista *crearLista();
Nodo *crearNodo(int codigo);
void insertarOrdenado(Lista *lista, Nodo *nodoAInsertar);
void eliminar(Lista *lista, int codigoABuscar);
void imprimir(Lista *lista);
void liberar(Lista *lista);

Lista *interseccionOrdenadas(Lista *lista1, Lista *lista2);

#endif
