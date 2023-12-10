#include <stdio.h>
#include <stdlib.h>
#include "Pila.h"
#include "util.h"

const void* FinPila=NULL;

int longitudPilaAyudante(PtrNodo nodo, int longitud);

PtrPila crearPila(){
    PtrPila pila=(PtrPila)obtenerMemoria(sizeof(Pila));
    pila->primero=NULL;
    return pila;
}

PtrPila destruirPila(PtrPila pila){

    while(!pilaVacia(pila)){
        desapilar(pila);
    }

    free(pila);

    return NULL;
}

bool pilaVacia(PtrPila pila){
    return (pila->primero==FinPila);
}

int longitudPila(PtrPila pila){

    int longitud=0;
    PtrNodo nodo=pila->primero;
    while(nodo!=FinPila){
        nodo=getSiguiente(nodo);
        longitud++;
    }
    return longitud;
}

int longitudPilaRecur(PtrPila pila){
    int longitud=longitudPilaAyudante(pila->primero,0);
    return longitud;
}

int longitudPilaAyudante(PtrNodo nodo, int longitud){

    if(nodo==FinPila){
        return longitud;
    } else {
        longitudPilaAyudante(getSiguiente(nodo), longitud++);
    }
    return longitud;
}

void apilar(PtrPila pila, PtrDato dato){

    if(pila!=NULL){
        PtrNodo nodo=crearNodo(dato);
        setDato(nodo,dato);
        setSiguiente(nodo,pila->primero);
        pila->primero=nodo;
    }
}

PtrDato desapilar(PtrPila pila){
    PtrDato dato=NULL;
    if(!pilaVacia(pila)){
        PtrNodo nodo=pila->primero;
        pila->primero=getSiguiente(nodo);
        dato=getDato(nodo);
        nodo=destruirNodo(nodo);
    }
    return dato;
}

PtrDato primeroPila(PtrPila pila){

    PtrDato dato=NULL;
    if(!pilaVacia(pila)){
        PtrNodo nodo=pila->primero;
        dato=getDato(nodo);
    }
    return dato;
}
