#ifndef REPARTO_H_INCLUDED
#define REPARTO_H_INCLUDED
#include "Chofer.h"
#include "Vehiculo.h"
#include "Fecha.h"
#include "Paquete.h"
#include "Horario.h"
#include "Lista.h"
#include "Pila.h"

//*******************************************************
// TDAReparto
//*******************************************************

// Estructura que define al tipo
typedef struct Reparto {
    choferPtr chofer;
    vehiculoPtr vehiculo;
    FechaPtr fecha;
    HorarioPtr horarioSalida;
    HorarioPtr horarioRetorno;
    PtrPila pilaPaquete;
    PtrLista listaPaquetes;
    bool enviado;
    bool completado;
} Reparto;

// Typedef de puntero al tipo de dato
typedef Reparto* RepartoPtr;

// Operaci�n de creaci�n (Constructor)
// Precondicion: el reparto no ha sido creado
// Postcondici�n: se crea un reparto con chofer, vehiculo, paquetes y fecha
// Par�metros:
// chofer: TDA que incluye los datos del chofer del reparto
// vehiculo: TDA que incluye el vehiculo del reparto
// paquetes: TDA que incluye los paquetes del reparto
// fecha: TDA que incluye la fecha y hora de salida del reparto
// Devuelve puntero a la estructura Reparto en memoria din�mica
RepartoPtr crearReparto(choferPtr chofer, vehiculoPtr vehiculo,FechaPtr fecha, HorarioPtr horarioSalida, HorarioPtr horarioRetorno, PtrLista listaPaquete, PtrLista lista);

// Operaci�n de destrucci�n (Destructor)
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se destruye reparto y se libera la memoria que ocupaba
// Par�metros:
// fecha: TDAReparto a destruir
// Devuelve NULL
RepartoPtr eliminarReparto(RepartoPtr reparto);

// Operaci�n de obtenci�n del chofer
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se obtiene el chofer del reparto
// Par�metros:
// reparto: TDAReparto del que se obtiene el chofer
// Devuelve puntero a estructura representando el chofer
choferPtr getChofer(RepartoPtr reparto);

// Operaci�n de obtenci�n del vehiculo
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se obtiene el vehiculo del reparto
// Par�metros:
// reparto: TDAReparto del que se obtiene el vehiculo
// Devuelve puntero a estructura representando el vehiculo
 vehiculoPtr getVehiculo(RepartoPtr reparto);

// Operaci�n de obtenci�n de la fehca
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se obtiene la fecha del reparto
// Par�metros:
// reparto: TDAReparto del que se obtiene la fecha
// Devuelve un puntero a estructura representando la fecha
FechaPtr getFechaReparto(RepartoPtr reparto);

// Operaci�n de obtenci�n del horario de salida
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se obtiene el horario de salida del reparto
// Par�metros:
// reparto: TDAReparto del que se obtiene el horario de salida
// Devuelve un puntero a estructura representando el horario de salida
HorarioPtr getHorarioSalidaReparto(RepartoPtr reparto);

// Operaci�n de obtenci�n del horario de retorno
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se obtiene el horario de retorno del reparto
// Par�metros:
// reparto: TDAReparto del que se obtiene el horario de retorno
// Devuelve un puntero a estructura representando el horario de retorno
HorarioPtr getHorarioRetornoReparto(RepartoPtr reparto);

// Operaci�n de obtenci�n de la pila de paquetes
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondici�n: se obtiene la pila de paquetes
// Par�metros:
// reparto: TDAReparto del que se obtiene la pila de paquetes
// Devuelve un puntero a estructura representando la pila de paquetes
PtrPila getPilaPaquete(RepartoPtr reparto);

// Operaci�n de asignaci�n de chofer
// Precondicion: reparto debe haberse creado
// Postcondici�n: reparto cambia con el nuevo valor de chofer
// Par�metros:
// reparto: TDAReparto al que se asignara el nuevo valor de chofer
// chofer: puntero a estructura representando el nuevo valor de chofer
// No devuelve valor.
void setChofer(RepartoPtr reparto, choferPtr chofer);

// Operaci�n de asignaci�n de vehiculo
// Precondicion: reparto debe haberse creado
// Postcondici�n: reparto cambia con el nuevo valor de vehiculo
// Par�metros:
// reparto: TDAReparto al que se asignara el nuevo valor de vehiculo
// vehiculo: puntero a estructura representando el nuevo valor de vehiculo
// No devuelve valor.
void setVehiculo(RepartoPtr reparto, vehiculoPtr vehiculo);

// Operaci�n de asignaci�n de fecha
// Precondicion: reparto debe haberse creado
// Postcondici�n: reparto cambia con el nuevo valor de fecha
// Par�metros:
// reparto: TDAReparto al que se asignara el nuevo valor de fecha
// fecha: puntero a estructura representando el nuevo valor de fecha
// No devuelve valor.
void setFechaReparto(RepartoPtr reparto, FechaPtr fecha);

// Operaci�n de asignaci�n de horario salida
// Precondicion: reparto debe haberse creado
// Postcondici�n: reparto cambia con el nuevo valor de horario salida
// Par�metros:
// reparto: TDAReparto al que se asignara el nuevo valor de horario salida
// horario: puntero a estructura representando el nuevo valor de horario salida
// No devuelve valor.
void setHorarioSalidaReparto(RepartoPtr reparto, HorarioPtr horario);

// Operaci�n de asignaci�n de horario retorno
// Precondicion: reparto debe haberse creado
// Postcondici�n: reparto cambia con el nuevo valor de horario retorno
// Par�metros:
// reparto: TDAReparto al que se asignara el nuevo valor de horario retorno
// horario: puntero a estructura representando el nuevo valor de horario retorno
// No devuelve valor.
void setHorarioRetornoReparto(RepartoPtr reparto, HorarioPtr horario);

// Operaci�n de asignaci�n de la pila de paquetes
// Precondicion: reparto debe haberse creado
// Postcondici�n: reparto cambia con el nuevo valor de la pila de paquetes
// Par�metros:
// reparto: TDAReparto al que se asignara el nuevo valor de la pila de paquetes
// pila: puntero a estructura representando el nuevo valor de la pila de paquetes
// No devuelve valor.
void setPilaPaquete(RepartoPtr reparto, PtrPila pila);

#endif // REPARTO_H_INCLUDED
