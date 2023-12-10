#ifndef TDAFECHA_H_INCLUDED
#define TDAFECHA_H_INCLUDED
//*******************************************************
// Interfaz de TDAFecha
//*******************************************************
// Estructura que define al tipo

typedef struct Fecha {
int diaJuliano;
} Fecha;

// Typedef de puntero al tipo de ato
typedef Fecha* FechaPtr;

// Primitivas
// Operación de creación (Constructor)
// Precondicion: la fecha no ha sido creada
// Postcondición: se crea una fecha con día, mes y año
// Parámetros:
// dia: entero representando el día del mes
// mes: entero representando el mes
// anio: entero representando el anio
// Devuelve puntero a la estructura Fecha en memoria dinámica
FechaPtr crearFecha(int dia, int mes, int anio);

// Operación de destrucción (Destructor)
// Precondicion: fecha debe haberse creado con crearFecha
// Postcondición: se destruye fecha y se libera la memoria que ocupaba
// Parámetros:
// fecha: TDAFecha a destruir
// Devuelve NULL
FechaPtr destruirFecha(FechaPtr fecha);

// Operación de obtención de día del mes
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene el día del mes de fecha
// Parámetros:
// fecha: TDAFecha del que es obtiene el día
// Devuelve un entero representando el día del mes
int getDia(FechaPtr fecha);

// Operación de obtención del mes
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene el mes de fecha
// Parámetros:
// fecha: TDAFecha del que es obtiene el mes
// Devuelve un entero representando el mes
int getMes(FechaPtr fecha);
// Operación de obtención de año
// Precondicion: fecha debe haberse creado
// Postcondición: se obtiene el año de fecha
// Parámetros:
// fecha: TDAFecha del que es obtiene el año
// Devuelve un entero representando el año
int getAnio(FechaPtr fecha);

// Operación de asignación de día
// Precondicion: fecha debe haberse creado
// Postcondición: fecha cambia con el nuevo valor de dia
// Parámetros:
// fecha: TDAFecha al que se asignara el nuevo valor de dia
// dia: entreo representando el nuevo valor de día del mes
// No devuelve valor.
void setDia(FechaPtr fecha, int dia);

// Operación de asignación de mes
// Precondicion: fecha debe haberse creado
// Postcondición: fecha cambia con el nuevo valor de mes
// Parámetros:
// fecha: TDAFecha al que se asignara el nuevo valor de mes
// dia: entreo representando el nuevo valor del mes
// No devuelve valor.
void setMes(FechaPtr fecha, int mes);

// Operación de asignación de año
// Precondicion: fecha debe haberse creado
// Postcondición: fecha cambia con el nuevo valor de año
// Parámetros:
// fecha: TDAFecha al que se asignará el nuevo valor de año
// dia: entero representando el nuevo valor de año
// No devuelve valor.
void setAnio(FechaPtr fecha, int anio);


#endif // FECHA_H_INCLUDED
