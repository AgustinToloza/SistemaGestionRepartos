#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "Domicilio.h"

//*******************************************************
// Implementación de TDADomicilio
//*******************************************************

DomicilioPtr crearDomicilio(char* localidad, char* calle, int numero){
    DomicilioPtr d = (DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    char* loc = (char*)obtenerMemoria(sizeof(char)*(strlen(localidad)+1));
    char* cal = (char*)obtenerMemoria(sizeof(char)*(strlen(calle)+1));
    strcpy(loc,localidad);
    strcpy(cal,calle);
    d->calle = cal;
    d->localidad = loc;
    d->numero = numero;

    return d;
}

DomicilioPtr eliminarDomicilio(DomicilioPtr domicilio){
    free(domicilio);
    return NULL;
}

char* getLocalidad(DomicilioPtr domicilio){
    return domicilio->localidad;
}

char* getCalle(DomicilioPtr domicilio){
    return domicilio->calle;
}

int getNumeroDomicilio(DomicilioPtr domicilio){
    return domicilio->numero;
}

void setLocalidad(DomicilioPtr domicilio, char* localidad){
    domicilio->localidad = localidad;
}

void setCalle(DomicilioPtr domicilio, char* calle){
    domicilio->calle = calle;
}

void setNumeroDomicilio(DomicilioPtr domicilio, int numero){
    domicilio->numero = numero;
}
