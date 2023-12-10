#ifndef TDAPAQUETE_H_INCLUDED
#define TDAPAQUETE_H_INCLUDED
#include "Dimensiones.h"
#include "Domicilio.h"
#include "Horario.h"
#include "Fecha.h"
#include <stdbool.h>
#include "Lista.h"
#include "Cliente.h"

//*******************************************************
// TDAPaquete
//*******************************************************

// Estructura que define al tipo
typedef struct Paquete {
    DimensionesPtr dimensiones;
    DomicilioPtr domicilio;
    bool estado;
    bool apilado;
    FechaPtr fecha;
    HorarioPtr horario;
    char* motivoFallo;
    int numPaquete;
    ClientePtr cliente;
} Paquete;

// Typedef de puntero al tipo de dato
typedef Paquete* PaquetePtr;

// Primitivas

// Operaci�n de creaci�n (Constructor)
// Precondicion: el paquete no ha sido creada
// Postcondici�n: se crea un Paquete con dimensiones, numero, domicilio, fecha/hora de entrega, estado de la entrega, y motivo de fallo de entrega si lo hubiese
// Par�metros:
// dimensiones: TDA que incluye las dimensiones del paquete
// domicilio: TDA que incluye la direcci�n de entrega del paquete
// estado: bool que representa el estado de la entrega
// fechaHora: TDA que incluye la fecha y hora de entrega del paquete
// motivoFallo: puntero a char que representa el motivo de fallo de entrega
// numPaquete: entero que representa el n�mero del paquete
// Devuelve puntero a la estructura Paquete en memoria din�mica
PaquetePtr crearPaquete(DimensionesPtr dimensiones, DomicilioPtr domicilio, bool estado, HorarioPtr horario, FechaPtr fecha, char* motivoFallo, int numPaquete, PtrLista lista, ClientePtr cliente);

// Operaci�n de destrucci�n (Destructor)
// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se destruye el Paquete y se libera la memoria que ocupaba
// Par�metros:
// paquete: TDAPaquete a destruir
// Devuelve NULL
PaquetePtr eliminarPaquete(PaquetePtr paquete);

// Operaci�n de obtenci�n de las dimenciones

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene a las dimensiones del paquete

// Par�metros:
// paquete: TDAPaquete del cual se obtiene las dimensiones

// Devuelve un puntero a las dimensiones

DimensionesPtr getDimensiones(PaquetePtr paquete);

// Operaci�n de obtenci�n del domicilio

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene el domicilio de entrega

// Par�metros:
// paquete: TDAPaquete del cual se obtiene el domicilio

// Devuelve un puntero al domicilio
DomicilioPtr getDomicilioPaquete(PaquetePtr paquete);

// Operaci�n de obtenci�n del estado de entrega

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene el estado de entrega del paquete

// Par�metros:
// paquete: TDAPaquete del cual se obtiene el domicilio

// Devuelve un bool del estado de la entrega
bool getEstado(PaquetePtr paquete);

// Operaci�n de obtenci�n del la hora de entrega

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene la hora de entrega

// Par�metros:
// paquete: TDAPaquete del cual se obtine la hora de entrega

// Devuelve un puntero a la hora
HorarioPtr getHorario(PaquetePtr paquete);

// Operaci�n de obtenci�n del la fecha de entrega

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene la fecha de entrega

// Par�metros:
// paquete: TDAPaquete del cual se obtine la fecha de entrega

// Devuelve un puntero a la fecha
FechaPtr getFecha(PaquetePtr paquete);

// Operaci�n de obtenci�n del motivo de fallo de la entrega

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene el motivo de fallo de entrega del paquete

// Par�metros:
// paquete: TDAPaquete del cual se obtiene el motivo de fallo

// Devuelve un string del motivo de fallo de la entrega

char* getMotivoFallo(PaquetePtr paquete);




ClientePtr getCliente(PaquetePtr paquete);

// Operaci�n de obtenci�n del numero de paquete

// Precondicion: se debe haber creado un Paquete con crearPaquete
// Postcondici�n: se obtiene el numero del paquete

// Par�metros:
// paquete: TDAPaquete del cual se obtiene el numero de paquete

// Devuelve un entero del numero de paquete

int getNumPaquete(PaquetePtr paquete);

// Operaci�n de asignaci�n de las dimensiones del paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con las nuevas dimensiones

// Par�metros:
// paquete: TDAPaquete al que se asignara el nuevo domicilio
// dimensiones: dimensionesPtr representando las nuevas dimensiones del paquete

// No devuelve valor.
void setDimensiones(PaquetePtr paquete, DimensionesPtr dimensiones);

// Operaci�n de asignaci�n del domiciio de entrega del paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con el nuevo domcilio de entrega

// Par�metros:
// paquete: TDApaquete al que se asignara el nuevo domicilio
// domicilio: domicilioPtr representando el nuevo domicilio de entrega del paquete

// No devuelve valor.
void setDomicilioPaquete(PaquetePtr paquete, DomicilioPtr domicilio);

// Operaci�n de asignaci�n del estado de entrega del paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con el nuevo estado de entrega

// Par�metros:
// paquete: TDApaquete al que se asignara el nuevo estado
// estado: bool representando el estado de entrega del paquete

// No devuelve valor.
void setEstado(PaquetePtr paquete, bool estado);

// Operaci�n de asignaci�n del horario de entrega del paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con el nuevo horario de entrega

// Par�metros:
// paquete: TDApaquete al que se asignara el nuevo horario
// Horario: TDAHorario representando el horario de entrega del paquete

// No devuelve valor.
void setHorario(PaquetePtr paquete, HorarioPtr horario);

// Operaci�n de asignaci�n de la fecha de entrega del paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con la nueva fecha de entrega

// Par�metros:
// paquete: TDApaquete al que se asignara la nueva fecha
// fecha: TDAFecha representando la fecha de entrega del paquete

// No devuelve valor.
void setFecha(PaquetePtr paquete, FechaPtr fecha);

// Operaci�n de asignaci�n del motivo del fallo de entrega del paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con el nuevo motivo del fallo de entrega

// Par�metros:
// paquete: TDApaquete al que se asignara el nuevo motivo del fallo
// motivo del fallo: string representando el motivo del fallo de entrega del paquete

// No devuelve valor.
void setMotivoFallo(PaquetePtr paquete, char* motivoFallo);

// Operaci�n de asignaci�n del motivo numero de paquete

// Precondicion: se debe haber creado un paquete con crearPaquete
// Postcondici�n: paquete cambia con el nuevo numero de paquete

// Par�metros:
// paquete: TDApaquete al que se asignara el nuevo motivo del fallo
// numPaquete: entero representando el numero de paquete

// No devuelve valor
void setNumPaquete(PaquetePtr paquete, int numPaquete);




#endif // TDAPAQUETE_H_INCLUDED
