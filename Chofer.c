#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "Cuil.h"
#include "Domicilio.h"
#include "Chofer.h"
#include "Lista.h"

//*******************************************************
// Implementación de TDAChofer
//*******************************************************

choferPtr crearChofer(char* nombre, char* apellido, CuilPtr cuil, DomicilioPtr domicilio, PtrLista lista){
    choferPtr ch = (choferPtr)obtenerMemoria(sizeof(Chofer));
    char* nom=(char*)obtenerMemoria(sizeof(char)*(strlen(nombre)+1));
    char* ape=(char*)obtenerMemoria(sizeof(char)*(strlen(apellido)+1));
    char* cal=(char*)obtenerMemoria(sizeof(char)*(strlen(domicilio->calle)+1));
    char* loc=(char*)obtenerMemoria(sizeof(char)*(strlen(domicilio->localidad)+1));
    strcpy(nom,nombre);
    strcpy(ape,apellido);
    strcpy(cal,domicilio->calle);
    strcpy(loc,domicilio->localidad);
    ch->domicilio=domicilio;
    ch->domicilio->calle = cal;
    ch->domicilio->localidad = loc;
    ch->apellido=ape;
    ch->nombre=nom;
    ch->cuil=cuil;

    /*ChoferEstatico ch2;
    strcpy(ch2.nombre,nom);
    strcpy(ch2.apellido,ape);
    strcpy(ch2.genero,ch->cuil->genero);
    strcpy(ch2.numeroCuil,ch->cuil->numeroCuil);
    strcpy(ch2.localidad,loc);
    strcpy(ch2.calle,cal);
    ch2.numero = ch->domicilio->numero;*/

    agregarDatoLista(lista,ch);

    return ch;
}

choferPtr eliminarChofer(choferPtr Chofer){
    free(Chofer->nombre);
    free(Chofer->apellido);
    free(Chofer->domicilio->calle);
    free(Chofer->domicilio->localidad);
    free(Chofer);
    return NULL;
}

char* getNombreChofer(choferPtr chofer){
    return chofer->nombre;
}

char* getApellidoChofer(choferPtr chofer){
    return chofer->apellido;
}

CuilPtr getCuilChofer(choferPtr chofer){
    return chofer->cuil;
}
DomicilioPtr getDomiciliochofer(choferPtr chofer){
    return chofer->domicilio;
}

void setNombreChofer(choferPtr chofer, char* nombre){
    chofer->nombre=nombre;
}

void setApellidoChofer(choferPtr chofer, char* apellido){
    chofer->apellido=apellido;
}

void setCuilChofer(choferPtr chofer, CuilPtr cuil){
    chofer->cuil=cuil;
}

void setDomicilioChofer(choferPtr chofer, DomicilioPtr domicilio){
    chofer->domicilio=domicilio;
}

void imprimirChoferLista(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        choferPtr puntChofer = (choferPtr)getCabecera(listaAux);
        printf("\n--CHOFER %d--\n", contador);
        printf("\nNOMBRE: %s",getNombreChofer(puntChofer));
        printf("\nAPELLIDO: %s",getApellidoChofer(puntChofer));
        DomicilioPtr domChofer = getDomiciliochofer(puntChofer);
        printf("\nLOCALIDAD: %s",getLocalidad(domChofer));
        printf("\nCALLE: %s",getCalle(domChofer));
        printf("\nNUMERO: %d\n",getNumeroDomicilio(domChofer));
        CuilPtr cuilChofer = getCuilChofer(puntChofer);
        printf("\nGENERO: %s",getGenero(cuilChofer));
        printf("\nNUMERO CUIL: %s\n",getNumeroCuil(cuilChofer));
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

int CuilChoferComparacion (PtrLista lista,char cuilNumero[])
{
    int flag=0;
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux))
    {
        choferPtr puntChofer = (choferPtr)getCabecera(listaAux);
        CuilPtr cuilChofer = getCuilChofer(puntChofer);
        if(strcmp(getNumeroCuil(cuilChofer),cuilNumero)==0)
        {
            return flag=-1;
        }
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
    return flag;
}

