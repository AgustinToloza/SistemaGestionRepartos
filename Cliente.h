#ifndef TDACLIENTE_H_INCLUDED
#define TDACLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Cuil.h"
#include "Domicilio.h"
#include "Lista.h"
//*********************
//    TDA CLIENTE
//*********************

// estructura que define al tipo
typedef struct Cliente
{
    char* nombre;
    char* apellido;
    DomicilioPtr domicilio;
    CuilPtr cuil;
} Cliente;

// typedef de puntero al tipo de dato
typedef Cliente* ClientePtr;

/// PRIMITIVAS

/** \brief Operacion de creacion (constructor)
 * \Precondicion  el cliente no fue creado
 * \Postcondicion se crea el cliente con nombre,apellido,domicilio y cuil
 * \param puntero char representa el nombre
 * \param puntero char representa el apellido
 * \param puntero char representa el domicilio
 * \param puntero al TDACuil
 * \return puntero a la estructura crearCliente en memoria dinamica
 */
ClientePtr crearCliente(char* nombre,char* apellido,DomicilioPtr domicilio,CuilPtr cuil,PtrLista lista);
/** \brief Operacion de destruccion(destructor)
    \Precondicion cliente debe haberse creado con crearCliente
    \Postcondicion se elimina cliente y se libera la memoria que ocupaba
 *  \param TDACliente a eliminar
 *  \return NULL
 */
ClientePtr eliminarCliente(ClientePtr cliente);
/** \brief Operacion obtencion del nombre
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion se obtiene el nombre del cliente
 * \param TDAcliente del que se obtiene el nombre
 * \return Devuelve un puntero char representado el nombre
 */
char* getNombreCliente(ClientePtr cliente);
/** \brief Operacion obtencion del apellido
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion se obtiene el apellido del cliente
 * \param TDACliente del que se obtiene el apellido
 * \return Devuelve un puntero char representado el Apellido
 */
char* getApellidoCliente(ClientePtr cliente);
/** \brief Operacion obtencion del Domicilio
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion se obtiene el domicilio del cliente
 * \param TDACliente del que se obtiene el domicilio
 * \return Devuelve un puntero al TDA representado el domicilio
 */
DomicilioPtr getDomicilioCliente(ClientePtr cliente);

/** \brief Operacion obtencion del Cuil
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion se obtiene el cuil del cliente
 * \param TDACliente del que se obtiene el cuil
 * \return Devuelve un puntero al TDACuil
 */
CuilPtr getCuilCliente(ClientePtr cliente);
/** \brief Operacion asignacion del nombre
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion cliente cambia con el nuevo nombre del cliente
 * \param TDACliente al que se le asignara el nuevo nombre
 * \param puntero char representado el nuevo nombre del cliente
 * \return no devuelve valor
 */
void setNombreCliente(ClientePtr cliente, char* nombre);
/** \brief Operacion asignacion del apellido
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion cliente cambia con el nuevo apellido del cliente
 * \param TDACliente al que se le asignara el nuevo apellido
 * \param puntero char representado el nuevo apellido del cliente
 * \return no devuelve valor
 */
void setApellidoCliente(ClientePtr cliente, char* apellido);
/** \brief Operacion asignacion del domicilio
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion cliente cambia con el nuevo domicilio del cliente
 * \param TDACliente al que se le asignara el nuevo domicilio
 * \param TDA representado el nuevo domicilio del cliente
 * \return no devuelve valor
 */
void setDomicilioCliente(ClientePtr cliente, DomicilioPtr domicilio);
/** \brief Operacion asignacion del cuil
 * \Precondicion  el cliente debe haberse creado
 * \Postcondicion cliente cambia con el nuevo cuil del cliente
 * \param TDACliente al que se le asignara el nuevo cuil
 * \param TDACuil al que se le asignara el nuevo cuil
 * \return no devuelve valor
 */
void setCuilCliente(ClientePtr cliente, CuilPtr cuil);


#endif // CLIENTE_H_INCLUDED


