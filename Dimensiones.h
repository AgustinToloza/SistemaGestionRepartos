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

// Operación de creación (Constructor)
// Precondicion: las dimensiones no han sido creadas
// Postcondición: se crean dimensiones con alto, ancho y peso
// Parámetros:
// alto: entero representando el alto
// ancho: entero representando el ancho
// peso: entero representando el peso
// Devuelve puntero a la estructura Dimensiones en memoria dinámica
DimensionesPtr crearDimensiones(int alto, int ancho, int peso);

// Operación de destrucción/eliminacion (Destructor)
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondición: se destruye dimensiones y se libera la memoria que ocupaba
// Parámetros:
// dimensiones: TDADimensiones a destruir
// Devuelve NULL
DimensionesPtr eliminarDimensiones(DimensionesPtr dimensiones);

// Operación de obtención del alto de las dimensiones
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondición: se obtiene el alto de las dimensiones
// Parámetros:
// dimensiones: TDADimensiones del que se obtiene el alto
// Devuelve un entero representando el alto
int getAlto(DimensionesPtr dimensiones);

// Operación de obtención del ancho de las dimensiones
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondición: se obtiene el ancho de las dimensiones
// Parámetros:
// dimensiones: TDADimensiones del que se obtiene el ancho
// Devuelve un entero representando el ancho
int getAncho(DimensionesPtr dimensiones);

// Operación de obtención de las dimensiones
// Precondicion: dimensiones deben haberse creado con crearDimension
// Postcondición: se obtiene peso de las dimensiones
// Parámetros:
// dimensiones: TDADimensiones del que se obtiene el peso
// Devuelve un entero representando el peso
int getPeso(DimensionesPtr dimensiones);

// Operación de asignación de alto
// Precondicion: dimensiones debe haberse creado
// Postcondición: dimensiones cambia con el nuevo valor de alto
// Parámetros:
// dimensiones: TDADimensiones al que se asignara el nuevo valor de alto
// alto: entero representando el nuevo valor de alto
// No devuelve valor.
void setAlto(DimensionesPtr dimensiones, int alto);

// Operación de asignación de ancho
// Precondicion: dimensiones debe haberse creado
// Postcondición: dimensiones cambia con el nuevo valor de ancho
// Parámetros:
// dimensiones: TDADimensiones al que se asignara el nuevo valor de ancho
// ancho: entero representando el nuevo valor de ancho
// No devuelve valor.
void setAncho(DimensionesPtr dimensiones, int ancho);

// Operación de asignación de peso
// Precondicion: dimensiones debe haberse creado
// Postcondición: dimensiones cambia con el nuevo valor de peso
// Parámetros:
// dimensiones: TDADimensiones al que se asignara el nuevo valor de peso
// peso: entreo representando el nuevo valor de peso
// No devuelve valor.
void setPeso(DimensionesPtr dimensiones, int peso);


#endif // DIMENSIONES_H_INCLUDED
