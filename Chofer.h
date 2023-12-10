#ifndef CHOFER_H_INCLUDED
#define CHOFER_H_INCLUDED
#include "Cuil.h"
#include "Domicilio.h"
#include "Lista.h"
//*********************
//    TDA CHOFER
//********************/

//Definicion de la estructura
typedef struct Chofer{
    char* nombre;
    char* apellido;
    CuilPtr cuil;
    DomicilioPtr domicilio;
}Chofer;

typedef struct ChoferEstatico{
    char nombre[15];
    char apellido[15];
    char genero[10];
    char numeroCuil[12];
    char localidad[15];
    char calle[15];
    int numero;
}ChoferEstatico;

// Typedef de puntero al tipo de dato
typedef Chofer* choferPtr;

//PRIMITIVAS

// Operaci�n de creaci�n (Constructor)

// Precondicion: el chofer no fue creado
// Postcondicion: se crea un Chofer con un nombre, apellido, cuil, domicilio

// Parametros:
// Nombre: string que representa el nombre del chofer
// Apellido: string que representa el apellido del chofer
// Cuil: TDA que incluye el cuil del chofer(?
// Domicilio: TDA que incluye el domicilio del chofer(?

// Devuelve un puntero a la estructura Chofer en memoria dinamica

choferPtr crearChofer(char* nombre, char* apellido, CuilPtr cuil, DomicilioPtr domicilio, PtrLista lista);

// Operaci�n de destrucci�n (Destructor)

// Precondicion: se debe haber creado un Chofer con crearChofer
// Postcondicion: se destruye el Chofer y se libera la memoria que ocupaba

// Parametros:
// Chofer: TDAChofer a eliminar

// Devuelve NULL

choferPtr eliminarChofer(choferPtr Chofer);

// Operacion de obtencion del nombre del chofer

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondicion: se obtiene el nombre del chofer

// Parametros:
// vehiculo: TDAChofer del cual se obtiene el nombre

// Devuelve un string al nombre del chofer

char* getNombreChofer(choferPtr chofer);

// Operacion de obtencion del apellido del chofer

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondicion: se obtiene el apellido del chofer

// Parametros:
// vehiculo: TDAChofer del cual se obtiene el apellido

// Devuelve un string al apellido del chofer

char* getApellidoChofer(choferPtr chofer);

// Operacion de obtencion del cuil del chofer

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondicion: se obtiene el cuil del chofer

// Parametros:
// vehiculo: TDAChofer del cual se obtiene el cuil

// Devuelve un puntero al cuil del chofer

CuilPtr getCuilchofer(choferPtr chofer);

// Operacion de obtencion del domicilio del chofer

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondicion: se obtiene el domicilio del chofer

// Parametros:
// vehiculo: TDAChofer del cual se obtiene el domicilio

// Devuelve un puntero al domicilio del chofer

DomicilioPtr getDomiciliochofer(choferPtr chofer);

// Operaci�n de asignaci�n del nombre

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondici�n: chofer cambia con el nuevo nombre

// Par�metros:
// chofer: TDAChofer al que se asignara el nuevo nombre
// nombre: string representando el nuevo nombre del chofer

// No devuelve valor.
void setNombreChofer(choferPtr chofer, char* nombre);

// Operaci�n de asignaci�n del apellido

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondici�n: chofer cambia con el nuevo apellido

// Par�metros:
// chofer: TDAChofer al que se asignara el nuevo apellido
// apellido: string representando el nuevo apellido del chofer

// No devuelve valor.
void setApellidoChofer(choferPtr chofer, char* apellido);

// Operaci�n de asignaci�n del cuil

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondici�n: chofer cambia con el nuevo cuil

// Par�metros:
// chofer: TDAChofer al que se asignara el nuevo cuil
// cuil: CuilpPtr representando el nuevo cuil del chofer

// No devuelve valor.
void setCuilchofer(choferPtr chofer, CuilPtr cuil);

// Operaci�n de asignaci�n del domicilio

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondici�n: chofer cambia con el nuevo domicilio

// Par�metros:
// chofer: TDAChofer al que se asignara el nuevo domicilio
// domicilio: domicilioPtr representando el nuevo domicilio del chofer

// No devuelve valor.
void setDomicilioChofer(choferPtr chofer, DomicilioPtr domicilio);

// Operaci�n que muestra los choferes

// Precondicion: se debe haber creado un chofer con crearChofer
// Postcondici�n: se muestra los choferes ingresados

// Par�metros:
// chofer: TDAChofer que muestra los choferes


// No devuelve valor.
void mostrarChofer(choferPtr chofer);

#endif // CHOFER_H_INCLUDED
