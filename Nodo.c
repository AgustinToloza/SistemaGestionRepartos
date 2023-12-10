#include <stdio.h>
#include <stdlib.h>
#include "Nodo.h"
#include "util.h"

const void* SinNodoSgte=NULL;

PtrNodo crearNodo(PtrDato dato){
    PtrNodo nodo=(PtrNodo)obtenerMemoria(sizeof(Nodo));
    nodo->dato=dato;
    nodo->sgte=NULL;
    return nodo;
}

PtrNodo destruirNodo(PtrNodo nodo){
    free(nodo);
    return NULL;
}

void setDato(PtrNodo nodo, PtrDato dato){
    nodo->dato=dato;
}

PtrDato getDato(PtrNodo nodo){
    return nodo->dato;
}

void setSiguiente(PtrNodo esteNodo, PtrNodo siguienteNodo){
    esteNodo->sgte=siguienteNodo;
}

PtrNodo getSiguiente(PtrNodo nodo){
    return nodo->sgte;
}
