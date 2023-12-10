#ifndef DIMENSIONES_H_INCLUDED
#define DIMENSIONES_H_INCLUDED

//*******************************************************
// Interfaz de TDADimensiones
//*******************************************************

// Estructura que define al tipo
typedef struct Dimensiones {
    int alto;
    int ancho;
    int peso;
} Dimensiones;

// Typedef de puntero al tipo de dato
typedef Dimensiones* DimensionesPtr;

// Primitivas

// Operaci�n de creaci�n (Constructor)
// Precondicion: las dimensiones no han sido creadas
// Postcondici�n: se crean dimensiones con alto, ancho y peso
// Par�metros:
// alto: entero representando el alto
// ancho: entero representando el ancho
// peso: entero representando el peso
// Devuelve puntero a la estructura Dimensiones en memoria din�mica
DimensionesPtr crearDimensiones(int alto, int ancho, int peso);

// Operaci�n de destrucci�n/eliminacion (Destructor)
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondici�n: se destruye dimensiones y se libera la memoria que ocupaba
// Par�metros:
// dimensiones: TDADimensiones a destruir
// Devuelve NULL
DimensionesPtr eliminarDimensiones(DimensionesPtr dimensiones);

// Operaci�n de obtenci�n del alto de las dimensiones
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondici�n: se obtiene el alto de las dimensiones
// Par�metros:
// dimensiones: TDADimensiones del que se obtiene el alto
// Devuelve un entero representando el alto
int getAlto(DimensionesPtr dimensiones);

// Operaci�n de obtenci�n del ancho de las dimensiones
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondici�n: se obtiene el ancho de las dimensiones
// Par�metros:
// dimensiones: TDADimensiones del que se obtiene el ancho
// Devuelve un entero representando el ancho
int getAncho(DimensionesPtr dimensiones);

// Operaci�n de obtenci�n de las dimensiones
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondici�n: se obtiene peso de las dimensiones
// Par�metros:
// dimensiones: TDADimensiones del que se obtiene el peso
// Devuelve un entero representando el peso
int getPeso(DimensionesPtr dimensiones);

// Operaci�n de asignaci�n de alto
// Precondicion: dimensiones debe haberse creado
// Postcondici�n: dimensiones cambia con el nuevo valor de alto
// Par�metros:
// dimensiones: TDADimensiones al que se asignara el nuevo valor de alto
// alto: entero representando el nuevo valor de alto
// No devuelve valor.
void setAlto(DimensionesPtr dimensiones, int alto);

// Operaci�n de asignaci�n de ancho
// Precondicion: dimensiones debe haberse creado
// Postcondici�n: dimensiones cambia con el nuevo valor de ancho
// Par�metros:
// dimensiones: TDADimensiones al que se asignara el nuevo valor de ancho
// ancho: entero representando el nuevo valor de ancho
// No devuelve valor.
void setAncho(DimensionesPtr dimensiones, int ancho);

// Operaci�n de asignaci�n de peso
// Precondicion: dimensiones debe haberse creado
// Postcondici�n: dimensiones cambia con el nuevo valor de peso
// Par�metros:
// dimensiones: TDADimensiones al que se asignara el nuevo valor de peso
// peso: entreo representando el nuevo valor de peso
// No devuelve valor.
void setPeso(DimensionesPtr dimensiones, int peso);


#endif // DIMENSIONES_H_INCLUDED
