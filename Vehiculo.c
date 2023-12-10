#include <stdio.h>
#include <stdlib.h>
#include "Vehiculo.h"
#include "util.h"
#include "Lista.h"

//*******************************************************
//          Implementación de TDAVehiculo
//*******************************************************

vehiculoPtr crearVehiculo(char* tipo, char* modelo, char* marca, char* patente, PtrLista lista){

    vehiculoPtr vehiculo=(vehiculoPtr)obtenerMemoria(sizeof(vehiculo));
    char* tip=(char*)obtenerMemoria(sizeof(char)*(strlen(tipo)+1));
    char* mod=(char*)obtenerMemoria(sizeof(char)*(strlen(modelo)+1));
    char* mar=(char*)obtenerMemoria(sizeof(char)*(strlen(marca)+1));
    char* pat=(char*)obtenerMemoria(sizeof(char)*(strlen(patente)+1));
    strcpy(tip,tipo);
    strcpy(mod,modelo);
    strcpy(mar,marca);
    strcpy(pat,patente);
    vehiculo->tipo=tip;
    vehiculo->modelo=mod;
    vehiculo->marca=mar;
    vehiculo->patente=pat;


    agregarDatoLista(lista,vehiculo);

    return vehiculo;
}

vehiculoPtr eliminarVehiculo(vehiculoPtr vehiculo){
    free(vehiculo);
    return NULL;
}

char* getTipo(vehiculoPtr vehiculo){
    return vehiculo->tipo;
}

char* getModelo(vehiculoPtr vehiculo){
    return vehiculo->modelo;
}

char* getMarca(vehiculoPtr vehiculo){
    return vehiculo->marca;
}

char* getPatente(vehiculoPtr vehiculo){
    return vehiculo->patente;
}

void setTipo(vehiculoPtr vehiculo, char* tipo){
    vehiculo->tipo = tipo;
}

void setModelo(vehiculoPtr vehiculo, char* modelo){
    vehiculo->modelo = modelo;
}

void setMarca(vehiculoPtr vehiculo, char* marca){
    vehiculo->marca = marca;
}

void setPatente(vehiculoPtr vehiculo, char* patente){
    vehiculo->patente = patente;
}

void imprimirVehiculoLista(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        vehiculoPtr puntVehiculo = (vehiculoPtr)getCabecera(listaAux);
        printf("\n--VEHICULO %d--\n", contador);
        printf("\nTIPO: %s",getTipo(puntVehiculo));
        printf("\nMARCA: %s",getMarca(puntVehiculo));
        printf("\nMODELO: %s",getModelo(puntVehiculo));
        printf("\nPATENTE: %s\n",getPatente(puntVehiculo));
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

void escribirArchivoVehiculos(PtrLista lista, FILE *archivo){
    archivo=fopen("vehiculos.bin","w");
    fflush(archivo);
    fclose(archivo);
    VehiculoSolid vehiculo;
    char* punto = ".";
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    archivo=fopen("vehiculos.bin","a");
    while(!listaVacia(listaAux)){
        vehiculoPtr puntVehiculo = (vehiculoPtr)getCabecera(listaAux);
        char* tip = (char*)obtenerMemoria(sizeof(char)*(strlen(getTipo(puntVehiculo))+1));
        char* mar = (char*)obtenerMemoria(sizeof(char)*(strlen(getMarca(puntVehiculo))+1));
        char* mod = (char*)obtenerMemoria(sizeof(char)*(strlen(getModelo(puntVehiculo))+1));
        char* pat = (char*)obtenerMemoria(sizeof(char)*(strlen(getPatente(puntVehiculo))+1));
        tip = getTipo(puntVehiculo);
        mar = getMarca(puntVehiculo);
        mod = getModelo(puntVehiculo);
        pat = getPatente(puntVehiculo);
        strcpy(vehiculo.tipo,tip);
        strcpy(vehiculo.marca,mar);
        strcpy(vehiculo.modelo,mod);
        strcpy(vehiculo.patente,pat);
        fputs(&vehiculo.tipo, archivo);
        fputs(punto, archivo);
        fputs(&vehiculo.marca, archivo);
        fputs(punto, archivo);
        fputs(&vehiculo.modelo, archivo);
        fputs(punto, archivo);
        fputs(&vehiculo.patente, archivo);
        fputs(punto, archivo);
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    fclose(archivo);

    printf("\n");
}
void levantarBaseVehiculos(PtrLista lista, FILE *archivo){
    char* all = (char*)obtenerMemoria(sizeof(char)*2000);
    int input;
    archivo=fopen("vehiculos.bin","r");
    fgets(all, 1999, archivo);
    fclose(archivo);
    vehiculoPtr v1 = (vehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    vehiculoPtr v2 = (vehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    char tipo[100];
    char marca[100];
    char modelo[100];
    char patente[100];
    printf("%s\n", all);
    //scanf("%d", &input);
    int contador = 0;

    char* token = (char*)obtenerMemoria(sizeof(char)*2000);
    token = strtok(all, ".");

    while (token != NULL) {
        printf(" %s\n", token);
        if(contador==0){

            strcpy(tipo,token);

        }
         if(contador==1){

            strcpy(marca,token);

        }
        if(contador==2){

            strcpy(modelo,token);

        }

        if(contador==3){

            strcpy(patente,token);
            printf("%s tipo\n", tipo);
            printf("%s marca\n", marca);
            printf("%s mnodelo\n", modelo);
            printf("%s patente\n", patente);
            v1 = crearVehiculo(tipo,modelo,marca,patente,lista);

            contador = 0;
        }else{
            contador++;
        }
        token = strtok(NULL, ".");
        //scanf("%d", &input);


    }


    //scanf("%d", &input);

    //free(all);
}
