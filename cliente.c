#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cuil.h"
#include "Cliente.h"
#include "util.h"
#include "Lista.h"

ClientePtr crearCliente(char* nombre,char* apellido,DomicilioPtr domicilio,CuilPtr cuil,PtrLista lista)
{
    ClientePtr cc = (ClientePtr)obtenerMemoria(sizeof(Cliente));
    char* nom=(char*)obtenerMemoria(sizeof(char)*(strlen(nombre)+1));
    char* ape=(char*)obtenerMemoria(sizeof(char)*(strlen(apellido)+1));
    char* cal=(char*)obtenerMemoria(sizeof(char)*(strlen(domicilio->calle)+1));
    char* loc=(char*)obtenerMemoria(sizeof(char)*(strlen(domicilio->localidad)+1));
    strcpy(nom,nombre);
    strcpy(ape,apellido);
    strcpy(cal,domicilio->calle);
    strcpy(loc,domicilio->localidad);
    cc->domicilio=domicilio;
    cc->domicilio->calle = cal;
    cc->domicilio->localidad = loc;
    cc->apellido=ape;
    cc->nombre=nom;
    cc->cuil=cuil;

    agregarDatoLista(lista,cc);
    return cc;
}

ClientePtr eliminarCliente(ClientePtr cliente)
{
    free(cliente);
    return NULL;
}

char* getApellidoCliente(ClientePtr cliente)
{
    return cliente->apellido;
}

DomicilioPtr getDomicilioCliente(ClientePtr cliente)
{
    return cliente->domicilio;
}

char* getNombreCliente(ClientePtr cliente)
{
    return cliente->nombre;
}

CuilPtr getCuilCliente(ClientePtr cliente)
{
    return cliente->cuil;
}

void setApellidoCliente(ClientePtr cliente,char* apellido)
{
    cliente->apellido=apellido;
}

void setDomicilioCliente(ClientePtr cliente,DomicilioPtr domicilio)
{
    cliente->domicilio=domicilio;
}

void setNombreCliente(ClientePtr cliente,char* nombre)
{
    cliente->nombre=nombre;
}

void setCuilCliente(ClientePtr cliente,CuilPtr cuil)
{
    cliente->cuil=cuil;
}

void imprimirClienteLista(PtrLista lista){
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux)){
        ClientePtr puntCliente = (ClientePtr)getCabecera(listaAux);
        printf("\n--%d--\n", contador);
        printf("\nNOMBRE: %s",getNombreCliente(puntCliente));
        printf("\nAPELLIDO: %s",getApellidoCliente(puntCliente));
        DomicilioPtr domCliente = getDomicilioCliente(puntCliente);
        printf("\nLOCALIDAD: %s",getLocalidad(domCliente));
        printf("\nCALLE: %s",getCalle(domCliente));
        printf("\nNUMERO: %d\n",getNumeroDomicilio(domCliente));
        CuilPtr cuilCliente = getCuilCliente(puntCliente);
        printf("\nGENERO: %s",getGenero(cuilCliente));
        printf("\nNUMERO CUIL: %s\n",getNumeroCuil(cuilCliente));
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
}

int CuilClienteComparacion (PtrLista lista,char cuilNumero[])
{
    int flag=0;
    PtrLista listaAux=crearLista();
    agregarLista(listaAux,lista);
    int contador = (longitudLista(lista))-1;
    while(!listaVacia(listaAux))
    {
        ClientePtr puntCliente= (ClientePtr)getCabecera(listaAux);
        CuilPtr cuilCliente = getCuilCliente(puntCliente);
        if(strcmp(getNumeroCuil(cuilCliente),cuilNumero)==0)
        {
            return flag=-1;
        }
        contador --;
        PtrLista listaADestruir=listaAux;
        listaAux=getResto(listaAux);
        destruirLista(listaADestruir,false);
    }
    destruirLista(listaAux,false);
    printf("\n");
    return flag;
}

