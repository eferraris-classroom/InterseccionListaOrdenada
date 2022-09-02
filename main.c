#include <stdio.h>
#include "ListaOrdenada.h"

int main() {

    Lista *lista1 = crearLista();
    Lista *lista2 = crearLista();

    insertarOrdenado(lista1, crearNodo(20));
    insertarOrdenado(lista1, crearNodo(2));
    insertarOrdenado(lista1, crearNodo(7));
    insertarOrdenado(lista1, crearNodo(11));
    insertarOrdenado(lista1, crearNodo(-1));

    insertarOrdenado(lista2, crearNodo(-2));
    insertarOrdenado(lista2, crearNodo(20));
    insertarOrdenado(lista2, crearNodo(7));
    insertarOrdenado(lista2, crearNodo(13));
    insertarOrdenado(lista2, crearNodo(0));

    imprimir(lista1);
    imprimir(lista2);

    Lista *res = interseccionOrdenadas(lista1, lista2);

    imprimir(res);

    liberar(lista1);
    liberar(lista2);
    liberar(res);

    return 0;
}
