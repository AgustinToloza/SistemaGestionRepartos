#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Dimensiones.h"


//*******************************************************
// Implementación de TDADimensiones
//*******************************************************

DimensionesPtr crearDimensiones(int alto, int ancho, int peso){
    DimensionesPtr d = (DimensionesPtr)obtenerMemoria(sizeof(Dimensiones));
    d->alto = alto;
    d->ancho = ancho;
    d->peso = peso;

    return d;
}

DimensionesPtr eliminarDimensiones(DimensionesPtr dimensiones){
    free(dimensiones);
    return NULL;
}

int getAlto(DimensionesPtr dimensiones){
    return dimensiones->alto;
}

int getAncho(DimensionesPtr dimensiones){
    return dimensiones->ancho;
}

int getPeso(DimensionesPtr dimensiones){
    return dimensiones->peso;
}

void setAlto(DimensionesPtr dimensiones, int alto){
    dimensiones->alto = alto;
}

void setAncho(DimensionesPtr dimensiones, int ancho){
    dimensiones->ancho = ancho;
}

void setPeso(DimensionesPtr dimensiones, int peso){
    dimensiones->peso = peso;
}
