#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Paquete.h"
#include "util.h"
#include "Lista.h"
#include "Cliente.h"

PaquetePtr crearPaquete(DimensionesPtr dimensiones, DomicilioPtr domicilio, bool estado, HorarioPtr horario, FechaPtr fecha, char* motivoFallo, int numPaquete, PtrLista lista, ClientePtr cliente){
    PaquetePtr p = (PaquetePtr)obtenerMemoria(sizeof(Paquete));
    p->dimensiones=dimensiones;
    p->domicilio=domicilio;
    p->estado=estado;
    p->horario=horario;
    p->fecha=fecha;
    char* motF=(char*)obtenerMemoria(sizeof(char)*(strlen(motivoFallo)+1));
    strcpy(motF,motivoFallo);
    p->motivoFallo=motF;
    p->numPaquete=numPaquete;
    p->estado = false;
    p->apilado = false;
    p->cliente=cliente;

    agregarDatoLista(lista,p);
    return p;
}

PaquetePtr eliminarPaquete(PaquetePtr paquete){
    free(paquete->motivoFallo);
    free(paquete);
    return NULL;
}

DimensionesPtr getDimensiones(PaquetePtr paquete){
    return paquete->dimensiones;
}

DomicilioPtr getDomicilioPaquete(PaquetePtr paquete){
    return paquete->domicilio;
}

bool getEstado(PaquetePtr paquete){
    return paquete->estado;
}

HorarioPtr getHorario(PaquetePtr paquete){
    return paquete->horario;
}

FechaPtr getFecha(PaquetePtr paquete){
    return paquete->fecha;
}

ClientePtr getCliente(PaquetePtr paquete){
    return paquete->cliente;
}


char* getMotivoFallo(PaquetePtr paquete){
    return paquete->motivoFallo;
}

int getNumPaquete(PaquetePtr paquete){
    return paquete->numPaquete;
}

void setDimensiones(PaquetePtr paquete, DimensionesPtr dimensiones)
{
    paquete->dimensiones=dimensiones;
}

void setDomicilioPaquete(PaquetePtr paquete, DomicilioPtr domicilio){
    paquete->domicilio=domicilio;
}

void setEstado(PaquetePtr paquete, bool estado){
    paquete->estado=estado;
}

void setHorario(PaquetePtr paquete, HorarioPtr horario){
    paquete->horario=horario;
}

void setFecha(PaquetePtr paquete, FechaPtr fecha){
    paquete->fecha=fecha;
}

void setMotivoFallo(PaquetePtr paquete, char* motivoFallo){
    paquete->motivoFallo=motivoFallo;
}

void setNumPaquete(PaquetePtr paquete, int numPaquete)
{
    paquete->numPaquete=numPaquete;
}

void imprimirPaqueteLista(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        PaquetePtr puntPaquete = (PaquetePtr)getCabecera(listaAux);
        printf("\n--PAQUETE %d--\n", contador);
        printf("***DIMENSIONES***");
        DimensionesPtr dimPaquete = getDimensiones(puntPaquete);
        printf("\nALTO: %d",getAlto(dimPaquete));
        printf("\nANCHO: %d",getAncho(dimPaquete));
        printf("\nPESO: %d\n",getPeso(dimPaquete));
        printf("***DOMICILIO***");
        DomicilioPtr domPaquete = getDomicilioPaquete(puntPaquete);
        printf("\nLOCALIDAD: %s",getLocalidad(domPaquete));
        printf("\nCALLE: %s",getCalle(domPaquete));
        printf("\nNUMERO: %d\n",getNumeroDomicilio(domPaquete));
        printf("***FECHA DE ENTREGA***");
        FechaPtr fechaPaquete = getFecha(puntPaquete);
        printf("\nFECHA: %d/%d/%d\n", getDia(fechaPaquete),getMes(fechaPaquete),getAnio(fechaPaquete));
        printf("***HORA DE ENTREGA***");
        HorarioPtr horarioPaquete = getHorario(puntPaquete);
        printf("\nHORARIO: %d:%d\n", getHora(horarioPaquete),getMinutos(horarioPaquete));
        printf("***NUMERO DEL PAQUETE***");
        printf("\nNUMERO: %d\n", puntPaquete->numPaquete);
        ClientePtr cliente = getCliente(puntPaquete);
        printf("***CLIENTE***");
        printf("\n%s %s\n\n",getNombreCliente(cliente),getApellidoCliente(cliente));
        if(puntPaquete->estado == true){
            printf("***ENTREGADO***\n\n");
        }else{
            printf("***NO ENTREGADO***\n");
            printf("%s\n\n", getMotivoFallo(puntPaquete));

        }
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

void imprimirPaqueteListaAApilar(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        PaquetePtr puntPaquete = (PaquetePtr)getCabecera(listaAux);
        if (puntPaquete->apilado == false){
            printf("\n--PAQUETE %d--\n", contador);
            printf("***DIMENSIONES***");
            DimensionesPtr dimPaquete = getDimensiones(puntPaquete);
            printf("\nALTO: %d",getAlto(dimPaquete));
            printf("\nANCHO: %d",getAncho(dimPaquete));
            printf("\nPESO: %d\n",getPeso(dimPaquete));
            printf("***DOMICILIO***");
            DomicilioPtr domPaquete = getDomicilioPaquete(puntPaquete);
            printf("\nLOCALIDAD: %s",getLocalidad(domPaquete));
            printf("\nCALLE: %s",getCalle(domPaquete));
            printf("\nNUMERO: %d\n",getNumeroDomicilio(domPaquete));
            printf("***FECHA DE ENTREGA***");
            FechaPtr fechaPaquete = getFecha(puntPaquete);
            printf("\nFECHA: %d/%d/%d\n", getDia(fechaPaquete),getMes(fechaPaquete),getAnio(fechaPaquete));
            printf("***HORA DE ENTREGA***");
            HorarioPtr horarioPaquete = getHorario(puntPaquete);
            printf("\nHORARIO: %d:%d\n", getHora(horarioPaquete),getMinutos(horarioPaquete));
            printf("***NUMERO DEL PAQUETE***");
            printf("\nNUMERO: %d\n", puntPaquete->numPaquete);
            ClientePtr cliente = getCliente(puntPaquete);
            printf("***CLIENTE***");
            printf("\n%s %s\n\n",getNombreCliente(cliente),getApellidoCliente(cliente));
            if(puntPaquete->estado == true){
                printf("***ENTREGADO***\n\n");
            }else{
                printf("***NO ENTREGADO***\n");
                printf("%s\n\n", getMotivoFallo(puntPaquete));
            }
        }
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);

    }
    destruirLista(listaAux,false);
    printf("\n");
}
