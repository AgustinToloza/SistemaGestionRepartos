#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Fecha.h"

int calcularDiaJuliano(int dia, int mes, int anio){
    return (1461 * (anio + 4800 + (mes - 14)/12))/4
           + (367 * (mes - 2 - 12 * ((mes - 14)/12)))/12
           - (3 * ((anio + 4900 + (mes - 14)/12)/100))/4 + dia - 32075;
}

FechaPtr crearFecha(int dia, int mes, int anio){

    FechaPtr f=(FechaPtr)obtenerMemoria(sizeof(Fecha));
    f->diaJuliano=calcularDiaJuliano(dia,mes,anio);

    return f;
}

FechaPtr destruirFecha(FechaPtr fecha){
    free(fecha);
    return NULL;
}

int calcularDiferenciaFechas(FechaPtr fecha1, FechaPtr fecha2){
    return fecha1->diaJuliano - fecha2->diaJuliano;
}

int getDia(FechaPtr fecha){
    int j = fecha->diaJuliano;
    int f = j + 1401 + (((4 * j + 274277) / 146097) * 3) / 4 -38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    return ((h % 153) / 5) + 1;
}

int getMes(FechaPtr fecha){
    int j = fecha->diaJuliano;
    int f = j + 1401 + (((4 * j + 274277) / 146097) * 3) / 4 -38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    return ((h / 153 + 2) % 12) + 1;
}

int getAnio(FechaPtr fecha){
    int j = fecha->diaJuliano;
    int f = j + 1401 + (((4 * j + 274277) / 146097) * 3) / 4 -38;
    int e = 4 * f + 3;
    int g = (e % 1461) / 4;
    int h = 5 * g + 2;
    int mes =((h / 153 + 2) % 12) + 1;
    return (e / 1461) - 4716 + (12 + 2 - mes) / 12;

}

void setDia(FechaPtr fecha, int dia){
    int mes,anio;

    mes=getMes(fecha);
    anio=getAnio(fecha);
    fecha->diaJuliano=calcularDiaJuliano(dia,mes,anio);
}

void setMes(FechaPtr fecha, int mes){
    int dia,anio;

    dia=getDia(fecha);
    anio=getAnio(fecha);
    fecha->diaJuliano=calcularDiaJuliano(dia,mes,anio);
}

void setAnio(FechaPtr fecha, int anio){
    int dia,mes;

    dia=getDia(fecha);
    mes=getMes(fecha);
    fecha->diaJuliano=calcularDiaJuliano(dia,mes,anio);
}

void traerFechaCorta(FechaPtr fecha, char* buffer){
    sprintf(buffer,"%d",getDia(fecha));
    *(buffer +2)='/';
    sprintf(buffer+3,"%d",getMes(fecha));
    *(buffer +5)='/';
    sprintf(buffer+6,"%d",getAnio(fecha));
}

char* traerFechaCortaDinamica(FechaPtr fecha){
    char* buffer=(char*)obtenerMemoria(sizeof(char)*11);
    traerFechaCorta(fecha, buffer);
    return buffer;
}
