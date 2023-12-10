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

// Operación de creación (Constructor)
// Precondicion: el reparto no ha sido creado
// Postcondición: se crea un reparto con chofer, vehiculo, paquetes y fecha
// Parámetros:
// chofer: TDA que incluye los datos del chofer del reparto
// vehiculo: TDA que incluye el vehiculo del reparto
// paquetes: TDA que incluye los paquetes del reparto
// fecha: TDA que incluye la fecha y hora de salida del reparto
// Devuelve puntero a la estructura Reparto en memoria dinámica
RepartoPtr crearReparto(choferPtr chofer, vehiculoPtr vehiculo,FechaPtr fecha, HorarioPtr horarioSalida, HorarioPtr horarioRetorno, PtrLista listaPaquete, PtrLista lista);

// Operación de destrucción (Destructor)
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se destruye reparto y se libera la memoria que ocupaba
// Parámetros:
// fecha: TDAReparto a destruir
// Devuelve NULL
RepartoPtr eliminarReparto(RepartoPtr reparto);

// Operación de obtención del chofer
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se obtiene el chofer del reparto
// Parámetros:
// reparto: TDAReparto del que se obtiene el chofer
// Devuelve puntero a estructura representando el chofer
choferPtr getChofer(RepartoPtr reparto);

// Operación de obtención del vehiculo
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se obtiene el vehiculo del reparto
// Parámetros:
// reparto: TDAReparto del que se obtiene el vehiculo
// Devuelve puntero a estructura representando el vehiculo
 vehiculoPtr getVehiculo(RepartoPtr reparto);

// Operación de obtención de la fehca
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se obtiene la fecha del reparto
// Parámetros:
// reparto: TDAReparto del que se obtiene la fecha
// Devuelve un puntero a estructura representando la fecha
FechaPtr getFechaReparto(RepartoPtr reparto);

// Operación de obtención del horario de salida
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se obtiene el horario de salida del reparto
// Parámetros:
// reparto: TDAReparto del que se obtiene el horario de salida
// Devuelve un puntero a estructura representando el horario de salida
HorarioPtr getHorarioSalidaReparto(RepartoPtr reparto);

// Operación de obtención del horario de retorno
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se obtiene el horario de retorno del reparto
// Parámetros:
// reparto: TDAReparto del que se obtiene el horario de retorno
// Devuelve un puntero a estructura representando el horario de retorno
HorarioPtr getHorarioRetornoReparto(RepartoPtr reparto);

// Operación de obtención de la pila de paquetes
// Precondicion: reparto debe haberse creado con crearReparto
// Postcondición: se obtiene la pila de paquetes
// Parámetros:
// reparto: TDAReparto del que se obtiene la pila de paquetes
// Devuelve un puntero a estructura representando la pila de paquetes
PtrPila getPilaPaquete(RepartoPtr reparto);

// Operación de asignación de chofer
// Precondicion: reparto debe haberse creado
// Postcondición: reparto cambia con el nuevo valor de chofer
// Parámetros:
// reparto: TDAReparto al que se asignara el nuevo valor de chofer
// chofer: puntero a estructura representando el nuevo valor de chofer
// No devuelve valor.
void setChofer(RepartoPtr reparto, choferPtr chofer);

// Operación de asignación de vehiculo
// Precondicion: reparto debe haberse creado
// Postcondición: reparto cambia con el nuevo valor de vehiculo
// Parámetros:
// reparto: TDAReparto al que se asignara el nuevo valor de vehiculo
// vehiculo: puntero a estructura representando el nuevo valor de vehiculo
// No devuelve valor.
void setVehiculo(RepartoPtr reparto, vehiculoPtr vehiculo);

// Operación de asignación de fecha
// Precondicion: reparto debe haberse creado
// Postcondición: reparto cambia con el nuevo valor de fecha
// Parámetros:
// reparto: TDAReparto al que se asignara el nuevo valor de fecha
// fecha: puntero a estructura representando el nuevo valor de fecha
// No devuelve valor.
void setFechaReparto(RepartoPtr reparto, FechaPtr fecha);

// Operación de asignación de horario salida
// Precondicion: reparto debe haberse creado
// Postcondición: reparto cambia con el nuevo valor de horario salida
// Parámetros:
// reparto: TDAReparto al que se asignara el nuevo valor de horario salida
// horario: puntero a estructura representando el nuevo valor de horario salida
// No devuelve valor.
void setHorarioSalidaReparto(RepartoPtr reparto, HorarioPtr horario);

// Operación de asignación de horario retorno
// Precondicion: reparto debe haberse creado
// Postcondición: reparto cambia con el nuevo valor de horario retorno
// Parámetros:
// reparto: TDAReparto al que se asignara el nuevo valor de horario retorno
// horario: puntero a estructura representando el nuevo valor de horario retorno
// No devuelve valor.
void setHorarioRetornoReparto(RepartoPtr reparto, HorarioPtr horario);

// Operación de asignación de la pila de paquetes
// Precondicion: reparto debe haberse creado
// Postcondición: reparto cambia con el nuevo valor de la pila de paquetes
// Parámetros:
// reparto: TDAReparto al que se asignara el nuevo valor de la pila de paquetes
// pila: puntero a estructura representando el nuevo valor de la pila de paquetes
// No devuelve valor.
void setPilaPaquete(RepartoPtr reparto, PtrPila pila);

#endif // REPARTO_H_INCLUDED
