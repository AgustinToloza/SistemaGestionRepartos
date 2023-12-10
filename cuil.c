#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "util.h"
#include "Cuil.h"

CuilPtr crearCuil(char* genero,char numeroCuil[])
{
    CuilPtr cp=(CuilPtr)obtenerMemoria(sizeof(Cuil));
    char* gen=(char*)obtenerMemoria(sizeof(char)*(strlen(genero)+1));
    strcpy(gen,genero);
    strcpy(cp->numeroCuil,numeroCuil);
    cp->genero=gen;

    if(validarCuil(genero,numeroCuil)!=-1)
    {
        return cp;
    }
    else
    {
        printf("Error el cuil ingresado no es valido\n");
        exit(-1);
    }

    return NULL;
}

char* getGenero(CuilPtr cuil)
{
    return cuil->genero;
}


void setGenero(CuilPtr cuil,char* genero)
{
    cuil->genero=genero;
}

CuilPtr eliminarCuil(CuilPtr cuil)
{
    free(cuil);
    return NULL;
}

int calcularCuil(char numero[])
{
     int acumulador=0;
     char auxNum[11];
     int identificador=0;

    auxNum[0]=(numero[0]-'0')*('5'-'0');
    auxNum[1]=(numero[1]-'0')*('4'-'0');
    auxNum[2]=(numero[2]-'0')*('3'-'0');
    auxNum[3]=(numero[3]-'0')*('2'-'0');
    auxNum[4]=(numero[4]-'0')*('7'-'0');
    auxNum[5]=(numero[5]-'0')*('6'-'0');
    auxNum[6]=(numero[6]-'0')*('5'-'0');
    auxNum[7]=(numero[7]-'0')*('4'-'0');
    auxNum[8]=(numero[8]-'0')*('3'-'0');
    auxNum[9]=(numero[9]-'0')*('2'-'0');


   for(int i=0;i<10;i++)
   {
       acumulador=acumulador+auxNum[i];
   }
    identificador=acumulador;
    acumulador=acumulador/11;
    identificador=identificador-(round(acumulador)*11);

        if(identificador<11)
        {
            identificador=11-identificador;
        }else
        {
            identificador=identificador-11;
        }

    return identificador;
}

char* getNumeroCuil(CuilPtr cuil)
{
    return cuil->numeroCuil;
}

void setNumeroCuil(CuilPtr cuil,char numeroCuil[])
{
      cuil->numeroCuil[11]=numeroCuil[11];
}

int validarCuil(char* genero, char numeroCuil[])
{
    int identificador=0;
    int flag= -1;

    identificador=calcularCuil(numeroCuil);
    if((strcmp("masculino",genero)==0)&&(numeroCuil[0]=='2'&&(numeroCuil[1]=='0'||numeroCuil[1]=='3'))||(strcmp("Masculino",genero)==0)&&(numeroCuil[0]=='2'&&(numeroCuil[1]=='0'||numeroCuil[1]=='3')))
    {
        if(identificador==(numeroCuil[10]-'0'))
        {
            
            return flag=0;
        }
        else
        {
            return flag;
        }
    }
    if((strcmp("femenino",genero)==0)&&(numeroCuil[0]=='2'&&(numeroCuil[1]=='3'||numeroCuil[1]=='7'))||(strcmp("Femenino",genero)==0)&&(numeroCuil[0]=='2'&&(numeroCuil[1]=='3'||numeroCuil[1]=='7')))
    {

        if(identificador==(numeroCuil[10]-'0'))
        {
            
            return flag=0;
        }
        else
        {
            return flag;
        }
    }
    return flag;
}

void mostrarCuil(CuilPtr cuil)
{
   printf("%s,%s",getGenero(cuil),getNumeroCuil(cuil));
}
