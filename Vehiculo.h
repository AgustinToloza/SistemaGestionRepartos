#ifndef VEHICULO_H_INCLUDED
#define VEHICULO_H_INCLUDED
#include "Lista.h"

//*********************
//    TDA VEHICULO
//*********************

// estructura que define al tipo
typedef struct Vehiculo{
    char* tipo;
    char* modelo;
    char* marca;
    char* patente;
}Vehiculo;

typedef struct VehiculoSolid{
    char tipo[10];
    char marca[10];
    char modelo[10];
    char patente[10];
}VehiculoSolid;

// LEVANTAR VEHICULOS DE BASE DE DATOS

typedef Vehiculo* vehiculoPtr;
// Operacion de crear vehiculo
// Precondicion: debe estar creada la estructura
// Postcondicion:
// Parametros:
// Tipo: camioneta, auto, moto
// Modelo: modelo del vehiculo
// Marca: marca del vehiculo
// Patente: patente del vehiculo
// Devuelve una estructura del tipo vehiculo
vehiculoPtr crearVehiculo(char* tipo, char* modelo, char* marca, char* patente, PtrLista lista);

// Operacion de eliminar vehiculo
// Precondicion: debe haber vehiculos creados previamente
// Postcondicion:
// Parametros:
// vehiculo: TDAVehiculo a eliminar
// Devuelve NULL
vehiculoPtr eliminarVehiculo(vehiculoPtr vehiculo);

// Operacion de obtencion del tipo vehiculo

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondicion: se obtiene el tipo de vehiculo

// Parametros:
// vehiculo: TDAVehiculo del cual se obtiene el tipo

// Devuelve un string al tipo de vehiculo

char* getTipo(vehiculoPtr vehiculo);

// Operacion de obtencion del modelo vehiculo

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondicion: se obtiene el modelo de vehiculo

// Parametros:
// vehiculo: TDAVehiculo del cual se obtiene el modelo

// Devuelve un string al modelo de vehiculo

char* getModelo(vehiculoPtr vehiculo);

// Operacion de obtencion de la marca vehiculo

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondicion: se obtiene la marca del vehiculo

// Parametros:
// vehiculo: TDAVehiculo del cual se obtiene la marca

// Devuelve un string a la marca del vehiculo

char* getMarca(vehiculoPtr vehiculo);

// Operacion de obtencion de la patente vehiculo

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondicion: se obtiene la patente del vehiculo

// Parametros:
// vehiculo: TDAVehiculo del cual se obtiene la patente

// Devuelve un string a la patente del vehiculo

char* getPatente(vehiculoPtr vehiculo);


// Operación de asignación del tipo

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondición: vehiculo cambia con el nuevo tipo

// Parámetros:
// vehiculo: TDAVehiculo al que se asignara el nuevo tipo
// tipo: string representando el nuevo tipo de vehiculo

// No devuelve valor.
void setTipo(vehiculoPtr vehiculo, char* tipo);

// Operación de asignación del modelo

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondición: vehiculo cambia con el nuevo modelo

// Parámetros:
// vehiculo: TDAVehiculo al que se asignara el nuevo modelo
// modelo: string representando el nuevo modelo de vehiculo

// No devuelve valor.
void setModelo(vehiculoPtr vehiculo, char* modelo);

// Operación de asignación de la marca

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondición: vehiculo cambia con la nueva marca

// Parámetros:
// vehiculo: TDAVehiculo al que se asignara la nueva marca
// marca: string representando la nueva marca de vehiculo

// No devuelve valor.
void setMarca(vehiculoPtr vehiculo, char* marca);

// Operación de asignación de la patente

// Precondicion: se debe haber creado un vehiculo con crearVehiculo
// Postcondición: vehiculo cambia con la nueva patente

// Parámetros:
// vehiculo: TDAVehiculo al que se asignara la nueva patente
// patente: string representando la nueva patente de vehiculo

// No devuelve valor.
void setPatente(vehiculoPtr vehiculo, char* patente);


#endif // VEHICULO_H_INCLUDED
