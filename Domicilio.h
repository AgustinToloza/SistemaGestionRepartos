#ifndef DOMICILIO_H_INCLUDED
#define DOMICILIO_H_INCLUDED

//*********************
//    TDA DOMICILIO
//*********************

//Definicion de la estructura
typedef struct Domicilio{
    char* localidad;
    char* calle;
    int numero;
}Domicilio;

// Typedef de puntero al tipo de dato
typedef Domicilio* DomicilioPtr;

//PRIMITIVAS

// Operación de creación (Constructor)
// Precondicion: el domicilio no fue creado
// Postcondicion: se crea un Domicilio con una localidad, calle y un numero
// Parametros:
// numero: entero que representa el numero de calle
// calle: string que representa el nombre de la calle
// localidad: string que representa el nombre de la localidad
// Devuelve un puntero a la estructura Domicilio en memoria dinamica
DomicilioPtr crearDomicilio(char* localidad, char* calle, int numero);

// Operación de destrucción (Destructor)
// Precondicion: se debe haber creado un Domicilio con crearDomicilio
// Postcondicion: se destruye el Domicilio y se liber la memoria que ocupaba
// Parametros:
// Domicilio: TDADomicilio a eliminar
// Devuelve NULL
DomicilioPtr eliminarDomicilio(DomicilioPtr domicilio);

// Operacion de obtencion de la localidad del domicilio
// Precondicion: se debe haber creado un Domicilio con crearDomicilio
// Postcondicion: se obtiene la localidad del domicilio
// Parametros:
// domicilio: TDAdomicilio del cual se obtiene la localidad
//Devuelve un string con la localidad del domicilio
char* getLocalidad(DomicilioPtr domicilio);

// Operacion de obtencion de la calle del domicilio
// Precondicion: se debe haber creado un Domicilio con crearDomicilio
// Postcondicion: se obtiene la calle del domicilio
// Parametros:
// domicilio: TDAdomicilio del cual se obtiene la calle
//Devuelve un string con la calle del domicilio
char* getCalle(DomicilioPtr domicilio);

// Operacion de obtencion del numero de la calle del domicilio
// Precondicion: se debe haber creado un Domicilio con crearDomicilio
// Postcondicion: se obtiene el numero de la calle
// Parametros:
// domicilio: TDAdomicilio del cual se obtiene el numero de la calle
// Devuelve un entero con el numero de la calle
int getNumeroDomicilio(DomicilioPtr domicilio);

// Operación de asignación de localidad
// Precondicion: domicilio debe haberse creado
// Postcondición: domicilio cambia con el nuevo valor de localidad
// Parámetros:
// domicilio: TDADomicilio al que se asignara el nuevo valor de localidad
// localidad: puntero a char representando el nuevo valor de localidad
// No devuelve valor.
void setLocalidad(DomicilioPtr domicilio, char* localidad);

// Operación de asignación de calle
// Precondicion: domicilio debe haberse creado
// Postcondición: domicilio cambia con el nuevo valor de calle
// Parámetros:
// domicilio: TDADomicilio al que se asignara el nuevo valor de calle
// calle: puntero a char representando el nuevo valor de calle
// No devuelve valor.
void setCalle(DomicilioPtr domicilio, char* calle);

// Operación de asignación de numero
// Precondicion: domicilio debe haberse creado
// Postcondición: domicilio cambia con el nuevo valor de numero
// Parámetros:
// domicilio: TDADimensiones al que se asignara el nuevo valor de numero
// numero: entero representando el nuevo valor de numero
// No devuelve valor.
void setNumeroDomicilio(DomicilioPtr domicilio, int numero);

#endif // DOMICILIO_H_INCLUDED
