#ifndef TDACUIL_H_INCLUDED
#define TDACUIL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//*********************
//    TDA CUIL
//*********************

// estructura que define al tipo
typedef struct Cuil
{
    char* genero;
    char numeroCuil[12];
} Cuil;

// typedef de puntero al tipo de dato
typedef Cuil* CuilPtr;

/// PRIMITIVAS

/** \brief Operacion de creacion (constructor)
 * \Precondicion  el cuil no fue creado
 * \Postcondicion se crea el cuil con genero,DNI e identificador
 * \param puntero char representa al genero
 * \param entero representa al DNI
 * \param entero representa al identificador
 * \return puntero a la estructura crearCuil en memoria dinamica
 */
CuilPtr crearCuil(char* genero,char numero[]);

/** \brief Operacion de destruccion(destructor)
    \Precondicion cuil debe haberse creado con crearCuil
    \Postcondicion se elimina cuil y se libera la memoria que ocupaba
 *  \param TDACuil a eliminar
 *  \return NULL
 */
CuilPtr eliminarCuil(CuilPtr cuil);

/** \brief Operacion obtencion del genero
 * \Precondicion  el cuil debe haberse creado
 * \Postcondicion se obtiene el genero del cuil
 * \param TDACuil del que se obtiene el genero
 * \return Devuelve un puntero char representado el genero
 */
char* getGenero(CuilPtr cuil);

/** \brief Operacion obtencion del cuil
 * \Precondicion  el cuil debe haberse creado
 * \Postcondicion se obtiene los numeros del cuil
 * \param TDACuil del que se obtiene el numero
 * \return Devuelve un puntero char representado el cuil
 */
char* getNumero(CuilPtr cuil);

/** \brief Operacion asignacion del genero
 * \Precondicion  el cuil debe haberse creado
 * \Postcondicion cuil cambia con el nuevo genero del cuil
 * \param TDACuil al que se le asignara el nuevo genero
 * \param puntero char representado el nuevo genero del cuil
 * \return no devuelve valor
 */
void setGenero(CuilPtr cuil, char* genero);

/** \brief Operacion asignacion del numero cuil
 * \Precondicion  el cuil debe haberse creado
 * \Postcondicion cuil cambia con el nuevo numero del cuil
 * \param TDACuil al que se le asignara el nuevo numero
 * \param array de chars con el numero del cuil
 * \return no devuelve valor
 */
void setNumeroCuil(CuilPtr cuil, char numeroCuil[]);

/** \brief Operacion que calcula al cuil
 * \Precondicion el array con el numero del cuil debe haberse ingresado
 * \Postcondicion se obtiene el valor del cuil
 * \param array de chars con el numero del cuil
 * \return entero representando al identificador
 */
int calcularCuil(char numero[]);
/** \brief Operacion de validacion del cuil
 * \Precondicion el cuil debe haberse creado
 * \Postcondicion valida que el cuil ingresado sea correcto
 * \param array de chars con el numero del cuil
 * \param puntero char que representa al genero
 * \return flag=-1 si es falso, flag=0 si es verdadero
 */
int validarCuil(char* genero, char numeroCuil[]);

/** \brief Operacion de mostrar
 * \param puntero al TDACUIL
 * \Precondicion el cuil debe haberse creado
 * \Postcondicion muestra el cuil
 * \return void
 */
void mostrarCuil(CuilPtr cuil);
#endif // CUIL_H_INCLUDED
