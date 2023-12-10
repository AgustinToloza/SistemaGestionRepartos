#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "Reparto.h"
#include "Chofer.h"
#include "Domicilio.h"
#include "Vehiculo.h"
#include "Fecha.h"
#include "Horario.h"
#include "Lista.h"
#include "Pila.h"
#include "Paquete.h"

//*******************************************************
// Implementación de TDAReparto
//*******************************************************

RepartoPtr crearReparto(choferPtr chofer, vehiculoPtr vehiculo, FechaPtr fecha, HorarioPtr horarioSalida, HorarioPtr horarioRetorno, PtrLista listaPaquete, PtrLista lista){
    RepartoPtr r = (RepartoPtr)obtenerMemoria(sizeof(Reparto));
    r->chofer = chofer;
    r->vehiculo = vehiculo;
    r->fecha = fecha;
    r->horarioSalida = horarioSalida;
    r->horarioRetorno = horarioRetorno;
    r->enviado = false;

    PtrLista listaAuxiliarPilaPaquete = crearLista();
    r->listaPaquetes = listaAuxiliarPilaPaquete;
    PtrPila pilaPaquete = crearPila();
    int option4 = 0;
    int comprobar;

    printf("---PAQUETES---\n");


    while(option4!=-1){
        imprimirPaqueteListaAApilar(listaPaquete);
        printf("***INGRESE EL PAQUETE A ASIGNAR AL REPARTO: ");
        printf("\nDesea seguir agregando paquetes (-1 para cerrar reparto): ");
        scanf("%d", &option4);
        if(option4!=-1){
            PaquetePtr paquetemod = getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4);
            paquetemod->apilado = true;
            apilar(pilaPaquete,getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4));
            agregarDatoLista(listaAuxiliarPilaPaquete,getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4));
        }
        system("cls");
    }

    r->pilaPaquete = pilaPaquete;
    agregarDatoLista(lista,r);

    return r;
}

RepartoPtr eliminarReparto(RepartoPtr reparto){
    free(reparto);
    return NULL;
}

choferPtr getChofer(RepartoPtr reparto){
    return reparto->chofer;
}

vehiculoPtr getVehiculo(RepartoPtr reparto){
    return reparto->vehiculo;
}

FechaPtr getFechaReparto(RepartoPtr reparto){
    return reparto->fecha;
}

HorarioPtr getHorarioSalidaReparto(RepartoPtr reparto){
    return reparto->horarioSalida;
}

HorarioPtr getHorarioRetornoReparto(RepartoPtr reparto){
    return reparto->horarioRetorno;
}

PtrPila getPilaPaquete(RepartoPtr reparto){
    return reparto->pilaPaquete;
}

void setChofer(RepartoPtr reparto, choferPtr chofer){
    reparto->chofer = chofer;
}

void setVehiculo(RepartoPtr reparto, vehiculoPtr vehiculo){
    reparto->vehiculo = vehiculo;
}

void setFechaReparto(RepartoPtr reparto, FechaPtr fecha){
    reparto->fecha = fecha;
}

void setHorarioSalidaReparto(RepartoPtr reparto, HorarioPtr horario){
    reparto->horarioSalida = horario;
}

void setHorarioRetornoReparto(RepartoPtr reparto, HorarioPtr horario){
    reparto->horarioRetorno = horario;
}

void setPilaPaquete(RepartoPtr reparto, PtrPila pila){
    reparto->pilaPaquete = pila;
}

void imprimirRepartoLista(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        RepartoPtr puntReparto = (RepartoPtr)getCabecera(listaAux);
        printf("\n--REPARTO %d--\n", contador);
        printf("\n--TOTAL DE PAQUETES DEL REPARTO: %d--",longitudLista(puntReparto->listaPaquetes));
        printf("\n-PAQUETES-");
        imprimirPaqueteLista(puntReparto->listaPaquetes);
        choferPtr choferReparto = getChofer(puntReparto);
        printf("\nCHOFER: %s %s",getNombreChofer(choferReparto),getApellidoChofer(choferReparto));
        vehiculoPtr vehiculoReparto = getVehiculo(puntReparto);
        printf("\nVEHICULO: %s-%s-%s-%S",getTipo(vehiculoReparto),getModelo(vehiculoReparto),getMarca(vehiculoReparto),getPatente(vehiculoReparto));
        FechaPtr fechaReparto = getFechaReparto(puntReparto);
        printf("\nFECHA: %d/%d/%d",getDia(fechaReparto),getMes(fechaReparto),getAnio(fechaReparto));
        HorarioPtr horarioSalidaReparto = getHorarioSalidaReparto(puntReparto);
        HorarioPtr horarioRetornoReparto = getHorarioRetornoReparto(puntReparto);
        printf("\nHORARIO DE SALIDA: %d:%d",getHora(horarioSalidaReparto),getMinutos(horarioSalidaReparto));
        printf("\nHORARIO DE RETORNO: %d:%d\n\n",getHora(horarioRetornoReparto),getMinutos(horarioRetornoReparto));
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

void imprimirRepartoListaNoActivos(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        RepartoPtr puntReparto = (RepartoPtr)getCabecera(listaAux);
        if (puntReparto->enviado == false){
            printf("\n--REPARTO %d--\n", contador);
            printf("\n--TOTAL DE PAQUETES DEL REPARTO: %d--",longitudLista(puntReparto->listaPaquetes));
            printf("\n-PAQUETES-");
            imprimirPaqueteLista(puntReparto->listaPaquetes);
            choferPtr choferReparto = getChofer(puntReparto);
            printf("\nCHOFER: %s %s",getNombreChofer(choferReparto),getApellidoChofer(choferReparto));
            vehiculoPtr vehiculoReparto = getVehiculo(puntReparto);
            printf("\nVEHICULO: %s-%s-%s-%S",getTipo(vehiculoReparto),getModelo(vehiculoReparto),getMarca(vehiculoReparto),getPatente(vehiculoReparto));
            FechaPtr fechaReparto = getFechaReparto(puntReparto);
            printf("\nFECHA: %d/%d/%d",getDia(fechaReparto),getMes(fechaReparto),getAnio(fechaReparto));
            HorarioPtr horarioSalidaReparto = getHorarioSalidaReparto(puntReparto);
            HorarioPtr horarioRetornoReparto = getHorarioRetornoReparto(puntReparto);
            printf("\nHORARIO DE SALIDA: %d:%d",getHora(horarioSalidaReparto),getMinutos(horarioSalidaReparto));
            printf("\nHORARIO DE RETORNO: %d:%d\n\n",getHora(horarioRetornoReparto),getMinutos(horarioRetornoReparto));

        }
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

void imprimirRepartoListaActivos(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        RepartoPtr puntReparto = (RepartoPtr)getCabecera(listaAux);
        if (puntReparto->enviado == true){
            printf("\n--REPARTO %d--\n", contador);
            printf("\n--TOTAL DE PAQUETES DEL REPARTO: %d--",longitudLista(puntReparto->listaPaquetes));
            printf("\n-PAQUETES-");
            imprimirPaqueteLista(puntReparto->listaPaquetes);
            choferPtr choferReparto = getChofer(puntReparto);
            printf("\nCHOFER: %s %s",getNombreChofer(choferReparto),getApellidoChofer(choferReparto));
            vehiculoPtr vehiculoReparto = getVehiculo(puntReparto);
            printf("\nVEHICULO: %s-%s-%s-%S",getTipo(vehiculoReparto),getModelo(vehiculoReparto),getMarca(vehiculoReparto),getPatente(vehiculoReparto));
            FechaPtr fechaReparto = getFechaReparto(puntReparto);
            printf("\nFECHA: %d/%d/%d",getDia(fechaReparto),getMes(fechaReparto),getAnio(fechaReparto));
            HorarioPtr horarioSalidaReparto = getHorarioSalidaReparto(puntReparto);
            HorarioPtr horarioRetornoReparto = getHorarioRetornoReparto(puntReparto);
            printf("\nHORARIO DE SALIDA: %d:%d",getHora(horarioSalidaReparto),getMinutos(horarioSalidaReparto));
            printf("\nHORARIO DE RETORNO: %d:%d\n\n",getHora(horarioRetornoReparto),getMinutos(horarioRetornoReparto));
        }
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

