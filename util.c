#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "util.h"
#include "Chofer.h"
#include "Cliente.h"
#include "Vehiculo.h"
#include "Domicilio.h"
#include "Dimensiones.h"
#include "Fecha.h"
#include "Horario.h"
#include "Paquete.h"
#include "Cuil.h"
#include "Reparto.h"

void* obtenerMemoria(size_t tamanio){
    void* ptr=malloc(tamanio);
    if(ptr==NULL){
        printf("No se ha podido obtener memoria\n");
        exit(1);
    }
    return ptr;
}

int secondaryMenu(int option)
{
    option=0;
    system("cls");
    printf("--------------------------------------------\n\n");
    printf("*******MENU GENERAL*******\n");
    printf("\t--1-***Choferes***\n");
    printf("\t--2-***Clientes***\n");
    printf("\t--3-***Paquetes***\n");
    printf("\t--4-***Vehiculos***\n");
    printf("\t--5-***Repartos***\n");
    printf("\t--6-***SALIR***\n");
    printf("\n");
    printf("ingrese opcion: ");
    scanf("%d",&option);
    system("cls");
    system("pause");

    if(option>=6 || option < 1)
    {
        printf("Error opcion no valida");
         exit(-1);
    }

    return option;
}

void mainMenu()
{
    FILE* archivo;
    int option=0;
    int option2=0;
    int option3=0;
    int option4 = 0;
    char continues='S';
    int numAux;
    int numero;
    //chofer-cliente
    char nombre[15],apellido[20];
    char genero[10],numeroCuil[12],localidad[50],calle[20];
    //vehiculo
    char tipo[20];
    char modelo[15];
    char marca[15];
    char patente[25];
    //dimensiones
    int alto, ancho, peso;
    //fecha
    int dia, mes, anio;
    //horario
    int hora, minutos;
    bool estado;
    char motivoFallo[100];
    int numPaquete;
    char razon[150];

    bool flag1=false;
    bool todosPaquetesEntregados = false;
	bool esDiferente = false;
    int indice;
    int comprobar;
    int i;

    //punteros a los TDA
    choferPtr ch =(choferPtr)obtenerMemoria(sizeof(Chofer));
    ClientePtr cli =(ClientePtr)obtenerMemoria(sizeof(Cliente));
    vehiculoPtr vehic =(vehiculoPtr)obtenerMemoria(sizeof(Vehiculo));
    CuilPtr cuil=(CuilPtr)obtenerMemoria(sizeof(Cuil));
    DomicilioPtr dom=(DomicilioPtr)obtenerMemoria(sizeof(Domicilio));
    DimensionesPtr dim = (DimensionesPtr)obtenerMemoria(sizeof(Dimensiones));
    FechaPtr fecha = (FechaPtr)obtenerMemoria(sizeof(Fecha));
    HorarioPtr horario = (HorarioPtr)obtenerMemoria(sizeof(Horario));
    HorarioPtr horarioSalida = (HorarioPtr)obtenerMemoria(sizeof(Horario));
    HorarioPtr horarioRetorno = (HorarioPtr)obtenerMemoria(sizeof(Horario));
    PaquetePtr paq = (PaquetePtr)obtenerMemoria(sizeof(Paquete));
    RepartoPtr rep = (RepartoPtr)obtenerMemoria(sizeof(Reparto));
    PtrLista listaChofer = crearLista();
    PtrLista listaVehiculo = crearLista();
    PtrLista listaCliente = crearLista();
    PtrLista listaPaquete = crearLista();
    PtrLista listaReparto = crearLista();
    PtrLista listaRepartosActivos = crearLista();
    PtrLista listaRepartosInactivos = crearLista();
    PtrLista listaPaquetesEnDeposito = crearLista();
    PtrLista listaRepartosEntregados = crearLista();




    //Precarga datos
    levantarBaseVehiculos(listaVehiculo, archivo);
    cuil = crearCuil("masculino", "20409459308");
    dom =  crearDomicilio("Lanus", "tucuman", 2300);
    ch = crearChofer("Sebastian", "Sdrubolini", cuil, dom, listaChofer);
    cuil = crearCuil("masculino", "20107942336");
    dom = crearDomicilio("Lanus", "Cordoba", 1573);
    cli = crearCliente("Agus", "Tolo", dom, cuil, listaCliente);
    dom =  crearDomicilio("Lanus", "9 de julio", 3000);
    cuil = crearCuil("masculino", "23423537469");
    ch = crearChofer("Gonza", "TP", cuil, dom, listaChofer);
    dim = crearDimensiones(21, 21, 21);
    dom = crearDomicilio("Banfield", "Salta", 1654);
    horario = crearHorario(15, 30);
    fecha = crearFecha(17, 20, 2022);
    paq = crearPaquete(dim, dom, false, horario, fecha, motivoFallo, 21, listaPaquete, cli);
    dim = crearDimensiones(51, 51, 51);
    dom = crearDomicilio("Banfield", "Salta", 3000);
    horario = crearHorario(16, 0);
    fecha = crearFecha(17, 20, 2022);
    paq = crearPaquete(dim, dom, false, horario, fecha, motivoFallo, 51, listaPaquete, cli);

    do
    {
        switch(secondaryMenu(option))
        {
        case 1:
            printf("***Choferes**");                                            //MENU CHOFERES
            printf("\n***Choferes Actuales: %d", longitudLista(listaChofer));
            printf("\n1-Agregar choferes");
            printf("\n2-Modificar choferes");
            printf("\n3-Eliminar choferes");
            printf("\n4-Mostrar choferes");
            printf("\nIngrese opcion: ");
            scanf("%d",&option2);
            system("cls");
            if(option2==1)                                                     //CREAR CHOFERES
            {
                printf("Ingrese el nombre del chofer: ");
                scanf("%s",nombre);
                printf("\nIngrese el apellido del chofer: ");
                scanf("%s",apellido);
                printf("\nIngrese el genero del chofer (masculino/femenino): ");
                scanf("%s",genero);
				while((strcmp(genero,"masculino")!=0)&& (strcmp(genero,"femenino")!=0))
               {
                    printf("\nError Reingrese el genero del chofer: ");
                    scanf("%s", genero);
                }
                printf("\nIngrese el CUIL completo del chofer: ");
                scanf("%s",numeroCuil);
                cuil=crearCuil(genero,numeroCuil);
                while(validarCuil(genero,numeroCuil)==-1)
                {
                    printf("Error el cuil no es valido Reingrese: ");



                    scanf("%s",numeroCuil);
                }
                cuil=crearCuil(genero,numeroCuil);
                while(CuilChoferComparacion(listaChofer,numeroCuil)==-1)
                {
                    printf("\nError el cuil ya fue ingresado en otro chofer Reingrese: ");
                    scanf("%s",numeroCuil);


                }
                cuil=crearCuil(genero,numeroCuil);
				printf("---Cuil validado Correctamente---");
                printf("\nIngrese localidad del chofer: ");
                scanf("%s",localidad);
                printf("\nIngrese calle del chofer: ");
                scanf("%s",calle);
                printf("\nIngrese numero de la calle del chofer: ");
                scanf("%d",&numero);
                dom=crearDomicilio(localidad,calle,numero);
                ch=crearChofer(nombre,apellido,cuil,dom,listaChofer);

                //escribirArchivoChoferes(listaChofer,archivo);

                if(ch!=NULL)
                {
                  system("cls");
                  printf("\n***La carga fue ingresada con exito***\n\n");
                  flag1=true;
                }
            }
            if(option2==2){                                                  //MODIFICAR CHOFERES
                if(listaVacia(listaChofer)){
                    printf("\n***NO hay choferes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    do{
                    imprimirChoferLista(listaChofer);
                    printf("Ingrese el chofer a modificar: ");
                    scanf("%d", &indice);
                    system("cls");
                    choferPtr puntChofer = (choferPtr)getDatoLista(listaChofer,longitudLista(listaChofer)-1-indice);
                    printf("\n1-Modificar nombre del chofer");
                    printf("\n2-Modificar apellido del chofer");
                    printf("\n3-Modificar genero del chofer");
                    printf("\n4-Modificar CUIL completo del chofer");
                    printf("\n5-Modificar localidad del chofer");
                    printf("\n6-Modificar calle del chofer");
                    printf("\n7-Modificar numero de la calle del chofer");
                    printf("\n0-VOLVER AL MENU GENERAL");
                    printf("\nIngrese opcion: ");
                    scanf("%d",&option3);
                        switch(option3){
                            case 1:
                                printf("Ingrese nuevo nombre del chofer: ");
                                scanf("%s", nombre);
                                puntChofer->nombre = nombre;
                                break;
                            case 2:
                                printf("Ingrese nuevo apellido del chofer: ");
                                scanf("%s", apellido);
                                puntChofer->apellido = apellido;
                                break;
                            case 3:
                                printf("Ingrese nuevo genero del chofer(masculino/femenino): ");
                                scanf("%s", genero);
                                puntChofer->cuil->genero = genero;
							while((strcmp(genero,"masculino")!=0)&& (strcmp(genero,"femenino")!=0))
                            {
                                printf("\nError Reingrese el genero del chofer: ");
                                scanf("%s", genero);
                            }
                                puntChofer->cuil->genero = genero;
                                break;
                            case 4:
                                printf("Ingrese nuevo CUIL completo del chofer: ");
                                scanf("%s", numeroCuil);
                                cuil=crearCuil(genero,numeroCuil);
                            while(validarCuil(genero,numeroCuil)==-1)
                            {
                                printf("Error el cuil no es valido Reingrese: ");
                                scanf("%s",numeroCuil);
                            }
                            cuil=crearCuil(genero,numeroCuil);
                            while(CuilChoferComparacion(listaChofer,numeroCuil)==-1)
                            {
                                printf("\nError el cuil ya fue ingresado en otro chofer Reingrese: ");
                                scanf("%s",numeroCuil);
                            }
                            cuil=crearCuil(genero,numeroCuil);
							printf("---Cuil validado Correctamente---");
                                break;
                            case 5:
                                printf("Ingrese nueva localidad del chofer: ");
                                scanf("%s", localidad);
                                puntChofer->domicilio->localidad = localidad;
                                break;
                            case 6:
                                printf("Ingrese nueva calle del chofer: ");
                                scanf("%s", calle);
                                puntChofer->domicilio->calle;
                                break;
                            case 7:
                                printf("Ingrese nuevo numero de la calle chofer: ");
                                scanf("%d", &numero);
                                puntChofer->domicilio->numero = numero;
                                break;
                        }
                    }while(option3!=0);
                }
            }
            if(option2==3){                                                   //ELIMINAR CHOFERES
                if(listaVacia(listaChofer)){
                    printf("\n**NO hay choferes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    imprimirChoferLista(listaChofer);
                    printf("Ingrese el chofer a eliminar: ");
                    scanf("%d", &indice);
                    choferPtr puntChofer = removerDeLista(listaChofer,longitudLista(listaChofer)-1-indice);
                    puntChofer = eliminarChofer(puntChofer);
                    system("cls");
                }
            }
            if(option2==4){                                                 //MOSTRAR CHOFERES
                if(listaVacia(listaChofer))
                {
                  printf("\n***NO hay choferes cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    imprimirChoferLista(listaChofer);
                    system("pause");
                    system("cls");
                }
            }
        break;
        case 2:
            printf("***Clientes**");                                        //MENÚ CLIENTES
            printf("\n***Clientes Actuales: %d", longitudLista(listaCliente));
            printf("\n1-Agregar clientes");
            printf("\n2-Modificar clientes");
            printf("\n3-Eliminar clientes");
            printf("\n4-Mostrar clientes");
            printf("\nIngrese opcion: ");
            scanf("%d",&option2);
            system("cls");
            if(option2==1){                                                 //CREAR CLIENTES
                printf("\nIngrese el nombre del cliente: ");
                scanf("%s", nombre);
                printf("\nIngrese el apellido del cliente: ");
                scanf("%s", apellido);
                printf("\nIngrese la localidad del domicilio del cliente: ");
                scanf("%s", localidad);
                printf("\nIngrese la calle del domicilio del cliente: ");
                scanf("%s", calle);
                printf("\nIngrese el numero de la calle del domicilio del cliente: ");
                scanf("%d", &numero);
                printf("\nIngrese el genero del cliente(masculino/femenino): ");
                scanf("%s", genero);
                while((strcmp(genero,"masculino")!=0)&& (strcmp(genero,"femenino")!=0))
                {
                    printf("\nError Reingrese el genero del chofer: ");
                    scanf("%s", genero);
                }
                printf("\nIngrese el numero de cuil del cliente: ");
                scanf("%s", numeroCuil);
                cuil = crearCuil(genero,numeroCuil);
                while(validarCuil(genero,numeroCuil)==-1)
                {
                    printf("Error el cuil no es valido Reingrese: ");
                    scanf("%s",numeroCuil);
                }
                cuil=crearCuil(genero,numeroCuil);
                while(CuilClienteComparacion(listaCliente,numeroCuil)==-1)
                {
                     printf("\nError el cuil ya fue ingresado en otro chofer Reingrese: ");
                     scanf("%s",numeroCuil);
                }
                    cuil=crearCuil(genero,numeroCuil);
					printf("---Cuil validado Correctamente---");
                    dom = crearDomicilio(localidad,calle,numero);
                    cli = crearCliente(nombre,apellido,dom,cuil,listaCliente);


                if(cli!=NULL){
                    system("cls");
                    printf("\n***La carga fue ingresada con exito***\n\n");
                    flag1=true;
                }
             }
             if(option2==2){                                                  //MODIFICAR CLIENTES
                if(listaVacia(listaCliente)){
                    printf("\n***NO hay clientes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    do{
                    imprimirClienteLista(listaCliente);
                    printf("Ingrese el cliente a modificar: ");
                    scanf("%d", &indice);
                    ClientePtr puntCliente = (ClientePtr)getDatoLista(listaCliente,longitudLista(listaCliente)-1-indice);
                        printf("\n1-Modificar nombre del cliente");
                        printf("\n2-Modificar apellido del cliente");
                        printf("\n3-Modificar localidad del domicilio del cliente");
                        printf("\n4-Modificar calle del domicilio del cliente");
                        printf("\n5-Modificar numero de la calle del domicilio del cliente");
                        printf("\n6-Modificar genero del cliente");
                        printf("\n7-Modificar numero de cuil del cliente");
                        printf("\n0-VOLVER AL MENU GENERAL");
                        printf("\nIngrese opcion: ");
                        scanf("%d", &option3);
                        switch(option3){
                            case 1:
                                printf("Ingrese nuevo nombre del cliente: ");
                                scanf("%s", nombre);
                                puntCliente->nombre = nombre;
                                break;
                            case 2:
                                printf("Ingrese nuevo apellido del cliente: ");
                                scanf("%s", apellido);
                                puntCliente->apellido = apellido;
                                break;
                            case 3:
                                printf("Ingrese nueva localidad del domicilio del cliente: ");
                                scanf("%s", localidad);
                                puntCliente->domicilio->localidad = localidad;
                                break;
                            case 4:
                                printf("Ingrese nueva calle del domicilio del cliente: ");
                                scanf("%s", calle);
                                puntCliente->domicilio->calle = calle;
                                break;
                            case 5:
                                printf("Ingrese nuevo numero de la calle del comicilio del cliente: ");
                                scanf("%d", &numero);
                                puntCliente->domicilio->numero = numero;
                                break;
                            case 6:
                            printf("Ingrese nuevo genero del cliente(masculino/femenino): ");
                            scanf("%s", genero);
                            puntCliente->cuil->genero = genero;
                            while((strcmp(genero,"masculino")!=0)&& (strcmp(genero,"femenino")!=0))
                            {
                                printf("\nError Reingrese el genero del chofer: ");
                                scanf("%s", genero);
                            }
                                puntCliente->cuil->genero = genero;
                                break;
                            case 7:
                                printf("Ingrese nuevo Cuil del cliente: ");
                                scanf("%s", numeroCuil);
                                cuil=crearCuil(genero,numeroCuil);
                             while(validarCuil(genero,numeroCuil)==-1){
                                printf("Error el cuil no es valido Reingrese: ");
                                scanf("%s",numeroCuil);
                            }
                            cuil=crearCuil(genero,numeroCuil);
                            while(CuilClienteComparacion(listaCliente,numeroCuil)==-1)
                            {
                                printf("\nError el cuil ya fue ingresado en otro chofer Reingrese: ");
                                scanf("%s",numeroCuil);
                            }
                            cuil=crearCuil(genero,numeroCuil);
							printf("---Cuil validado Correctamente---");
                            system("pause");
                            break;

                    }
                    }while(option3!=0);
            }
            }
            if(option2==3){                                                   //ELIMINAR CLIENTES
                if(listaVacia(listaCliente)){
                    printf("\n**NO hay clientes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    imprimirClienteLista(listaCliente);
                    printf("Ingrese el cliente a eliminar: ");
                    scanf("%d", &indice);
                    ClientePtr puntCliente = removerDeLista(listaCliente,longitudLista(listaCliente)-1-indice);
                    puntCliente = eliminarCliente(puntCliente);
                    system("cls");
                }
            }
            if(option2==4){                                                     //MOSTRAR CLIENTE
                if(listaVacia(listaCliente))
                {
                  printf("\n***NO hay clientes cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    imprimirClienteLista(listaCliente);
                    system("pause");
                    system("cls");
                }
            }
            break;
        case 3:
            printf("***Paquetes**");                                            //MENÚ PAQUETES
            printf("\n***Paquetes Actuales: %d", longitudLista(listaPaquete));
            printf("\n1-Agregar paquetes");
            printf("\n2-Modificar paquetes");
            printf("\n3-Eliminar paquetes");
            printf("\n4-Mostrar paquetes");
            printf("\nIngrese opcion: ");
            scanf("%d",&option2);
            system("cls");
            if(option2==1){                                                 //CREAR PAQUETES
                 if (listaVacia(listaCliente)){
                    printf("\n***NO hay clientes para pedir paquetes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                 }else{
                    printf("\n***Elegir cliente:");
                    imprimirClienteLista(listaCliente);
                    scanf("%d",&indice);
                    ClientePtr cliente = (ClientePtr)getDatoLista(listaCliente,longitudLista(listaCliente)-1-indice);
                    system("cls");
                    printf("---DIMENSIONES DEL PAQUETE---");
                    printf("\nIngrese el alto: ");
                    scanf("%d",&alto);
                    printf("Ingrese el ancho: ");
                    scanf("%d",&ancho);
                    printf("Ingrese el peso: ");
                    scanf("%d",&peso);
                    printf("---DOMICILIO---");
                    printf("\nIngrese localidad: ");
                    scanf("%s",localidad);
                    printf("Ingrese calle: ");
                    scanf("%s",calle);
                    printf("Ingrese numero de la calle: ");
                    scanf("%d",&numero);
                    printf("---FECHA DE ENTREGA---");
                    printf("\nIngrese el dia: ");
                    scanf("%d",&dia);
                    while(dia > 31 || dia < 1){
                        printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL DIA: ");
                        scanf("%d",&dia);
                    }
                    printf("Ingrese el mes: ");
                    scanf("%d",&mes);
                    while(mes > 12 || mes < 1){
                        printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL MES: ");
                        scanf("%d",&mes);
                    }
                    printf("Ingrese el anio: ");
                    scanf("%d",&anio);
                    while(anio < 2022 || anio > 2050){
                        printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL ANIO: ");
                        scanf("%d",&anio);
                    }
                    printf("---HORA DE ENTREGA---");
                    printf("\nIngrese la hora: ");
                    scanf("%d",&hora);
                    while(hora > 23){
                        printf("HORA ERRONEA-INGRESE NUEVAMENTE LA HORA: ");
                        scanf("%d",&hora);
                    }
                    printf("Ingrese los minutos: ");
                    scanf("%d",&minutos);
                    while(minutos>59){
                        printf("HORA ERRONEA-INGRESE NUEVAMENTE LOS MINUTOS: ");
                        scanf("%d",&minutos);
                    }
                    printf("---NUMERO DEL PAQUETE--");
                    printf("\nIngrese el numero del paquete: ");
                    scanf("%d",&numPaquete);

                    for(i=0;i<longitudLista(listaPaquete);i++){
                        PaquetePtr puntPaquete = (PaquetePtr)getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-i);
                        while(puntPaquete->numPaquete == numPaquete){
                            printf("***HAY OTRO PAQUETE EXISTENTE CON EL MISMO NUMERO-INGRESE OTRO: ");
                            scanf("%d",&numPaquete);
                        }
                    }

                    estado = false;

                    dom=crearDomicilio(localidad,calle,numero);
                    dim=crearDimensiones(alto,ancho,peso);
                    fecha=crearFecha(dia,mes,anio);
                    horario=crearHorario(hora,minutos);
                    paq=crearPaquete(dim,dom,estado,horario,fecha,motivoFallo,numPaquete,listaPaquete,cliente);

                    if(paq!=NULL){
                        printf("\n***La carga fue ingresada con exito***\n\n");
                        system("pause");
                        system("cls");
                        flag1=true;
                        }
                    }
                }
            if(option2==2){                                                         //MODIFICAR PAQUETES
                if(listaVacia(listaPaquete)){
                    printf("\n***NO hay paquetes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    do{
                    imprimirPaqueteLista(listaPaquete);
                    printf("Ingrese el paquete a modificar: ");
                    scanf("%d", &indice);
                    system("cls");
                    PaquetePtr puntPaquete = (PaquetePtr)getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-indice);
                    printf("\n1-Modificar alto del paquete");
                    printf("\n2-Modificar ancho del paquete");
                    printf("\n3-Modificar peso del paquete");
                    printf("\n4-Modificar localidad del paquete");
                    printf("\n5-Modificar calle del paquete");
                    printf("\n6-Modificar numero de la calle del paquete");
                    printf("\n7-Modificar dia de la entrega del paquete");
                    printf("\n8-Modificar mes de la entrega del paquete");
                    printf("\n9-Modificar anio de la entrega del paquete");
                    printf("\n10-Modificar hora de la entrega del paquete");
                    printf("\n11-Modificar minutos de la entrega del paquete");
                    printf("\n12-Modificar numero del paquete");
                    printf("\n13-Modificar estado actual de la entrega del paquete");
                    printf("\n0-VOLVER AL MENU GENERAL");
                    printf("\nIngrese opcion: ");
                    scanf("%d",&option3);
                        switch(option3){
                            case 1:
                                printf("Ingrese nuevo alto del paquete: ");
                                scanf("%d", &alto);
                                puntPaquete->dimensiones->alto = alto;
                                break;
                            case 2:
                                printf("Ingrese nuevo ancho del paquete: ");
                                scanf("%d", &ancho);
                                puntPaquete->dimensiones->ancho = ancho;
                                break;
                            case 3:

                                printf("Ingrese nuevo peso del paquete: ");
                                scanf("%d", &peso);
                                puntPaquete->dimensiones->peso = peso;
                                break;
                            case 4:
                                printf("Ingrese nueva localidad del paquete: ");
                                scanf("%s", localidad);
                                puntPaquete->domicilio->localidad = localidad;
                                break;
                            case 5:
                                printf("Ingrese nueva calle del paquete: ");
                                scanf("%s", calle);
                                puntPaquete->domicilio->calle = calle;
                                break;
                            case 6:
                                printf("Ingrese nuevo numero de la calle del paquete: ");
                                scanf("%d", &numero);
                                puntPaquete->domicilio->numero = numero;
                                break;
                            case 7:
                                //set
                                printf("Ingrese nuevo dia de la entrega del paquete: ");
                                scanf("%d", &dia);
                                while(dia > 31 || dia < 1){
                                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL DIA: ");
                                    scanf("%d",&dia);
                                }
                                setDia(fecha,dia);
                                fecha=crearFecha(dia,mes,anio);
                                break;
                            case 8:
                                //
                                printf("Ingrese nuevo mes de la entrega del paquete: ");
                                scanf("%d", &mes);
                                while(mes > 12 || mes < 1){
                                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL MES: ");
                                    scanf("%d",&mes);
                                }
                                setMes(fecha,mes);
                                fecha=crearFecha(dia,mes,anio);
                                break;
                            case 9:
                                //
                                printf("Ingrese nuevo anio de la entrega del paquete: ");
                                scanf("%d", &anio);
                                while(anio < 2022 || anio > 2050){
                                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL ANIO: ");
                                    scanf("%d",&anio);
                                }
                                setAnio(fecha,anio);
                                fecha=crearFecha(dia,mes,anio);
                                puntPaquete->fecha = fecha;
                                break;
                            case 10:
                                printf("Ingrese nuevo hora de la entrega del paquete: ");
                                scanf("%d", &hora);
                                while(hora > 23){
                                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LA HORA: ");
                                    scanf("%d",&hora);
                                }
                                puntPaquete->horario->hora = hora;
                                break;
                            case 11:
                                printf("Ingrese nuevos minutos de la entrega del paquete: ");
                                scanf("%d", &minutos);
                                while(minutos>59){
                                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LOS MINUTOS: ");
                                    scanf("%d",&minutos);
                                }
                                puntPaquete->horario->minutos = minutos;
                                break;
                            case 12:
                                printf("Ingrese nuevo numero del paquete: ");
                                scanf("%d", &numPaquete);

                                for(i=0;i<longitudLista(listaPaquete);i++){
                                    PaquetePtr puntPaquete = (PaquetePtr)getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-i);
                                    while(puntPaquete->numPaquete == numPaquete){
                                        printf("***HAY OTRO PAQUETE EXISTENTE CON EL MISMO NUMERO-INGRESE OTRO: ");
                                        scanf("%d",&numPaquete);
                                    }
                                }

                                puntPaquete->numPaquete = numPaquete;
                                break;
                            case 13:
                                printf("Ingrese nuevo estado de la entrega del paquete (1-ACTIVO,0-INACTIVO: ");
                                scanf("%d",&numAux);
                                if(numAux==1){
                                    estado = true;
                                }else{
                                    estado = false;
                                }
                                puntPaquete->estado = estado;
                                break;
                        }
                    }while(option3!=0);
                }
            }
            if(option2==3){                                                     //ELIMINAR PAQUETES
                if(listaVacia(listaPaquete)){
                    printf("\n**NO hay paquetes cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    imprimirPaqueteLista(listaPaquete);
                    printf("Ingrese el paquete a eliminar: ");
                    scanf("%d", &indice);
                    PaquetePtr puntPaquete = removerDeLista(listaPaquete,longitudLista(listaPaquete)-1-indice);
                    puntPaquete = eliminarPaquete(puntPaquete);
                    system("cls");
                }
            }
            if(option2==4){                                                 //MOSTRAR PAQUETES
                if(listaVacia(listaPaquete))
                {
                  printf("\n***NO hay paquetes cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    imprimirPaqueteLista(listaPaquete);
                    system("pause");
                    system("cls");
                }
            }
            break;
        case 4:                                                                 //MENU VEHICULOS
            printf("***Vehiculos**");
            printf("\n***Vehiculos Actuales: %d", longitudLista(listaVehiculo));
            printf("\n1-Agregar Vehiculo");
            printf("\n2-Modificar Vehiculo");
            printf("\n3-Eliminar Vehiculo");
            printf("\n4-Mostrar Vehiculos");
            printf("\nIngrese opcion: ");
            scanf("%d",&option2);
            system("cls");
            if(option2==1)                                                  //AGREGAR VEHICULOS
            {
               printf("Ingrese tipo de vehiculo: ");
               scanf("%s",tipo);
               printf("Ingrese Marca del vehiculo: ");
               scanf("%s",marca);
               printf("Ingrese Modelo del vehiculo: ");
               scanf("%s",modelo);
               printf("Ingrese patente del vehiculo: ");
               scanf("%s",patente);
               vehic=crearVehiculo(tipo,modelo,marca,patente,listaVehiculo);
                if(vehic!=NULL)
                {
                  printf("La carga fue ingresada con exito\n");
                  escribirArchivoVehiculos(listaVehiculo, archivo);
                  flag1 = true;
                }
            }
            if(option2==2){                                              //MODIFICAR VEHICULOS
                if(listaVacia(listaVehiculo)){
                    printf("\n***NO hay vehiculos cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    imprimirVehiculoLista(listaVehiculo);
                    printf("Ingrese el vehiculo a modificar: ");
                    scanf("%d", &indice);
                    system("cls");
                    vehiculoPtr puntVehiculo = (vehiculoPtr)getDatoLista(listaVehiculo,longitudLista(listaVehiculo)-1-indice);
                    printf("\n1-Modificar tipo del vehiculo");
                    printf("\n2-Modificar modelo del vehiculo");
                    printf("\n3-Modificar marca del vehiculo");
                    printf("\n4-Modificar patente del vehiculo");
                    printf("\nIngrese opcion: ");
                    scanf("%d", &option3);
                    switch(option3){
                        case 1:
                            printf("Ingrese nuevo tipo del vehiculo: ");
                            scanf("%s",tipo);
                            puntVehiculo->tipo = tipo;
                            break;
                        case 2:
                            printf("Ingrese nuevo modelo del vehiculo: ");
                            scanf("%s",modelo);
                            puntVehiculo->modelo = modelo;
                            break;
                        case 3:
                            printf("Ingrese nueva marca del vehiculo: ");
                            scanf("%s",marca);
                            puntVehiculo->marca = marca;
                            break;
                        case 4:
                            printf("Ingrese nueva patente del vehiculo: ");
                            scanf("%s",patente);
                            puntVehiculo->patente = patente;
                            break;
                    }
                }
            }
            if(option2==3){                                             //ELIMINAR VEHICULOS
                if(listaVacia(listaVehiculo)){
                    printf("\n***NO hay vehiculos cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    imprimirVehiculoLista(listaVehiculo);
                    printf("Ingrese el vehiculo a eliminar: ");
                    scanf("%d", &indice);
                    vehiculoPtr puntVehiculo = removerDeLista(listaVehiculo,longitudLista(listaVehiculo)-1-indice);
                    puntVehiculo = eliminarVehiculo(puntVehiculo);
                    system("cls");
                }
            }
            if(option2==4){                                                 //MOSTRAR VEHICULOS
                if(listaVacia(listaVehiculo))
                {
                  printf("\n***NO hay vehiculos cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    imprimirVehiculoLista(listaVehiculo);
                    system("pause");
                    system("cls");
                }
            }
            break;
        case 5:
            printf("***Reparto**");                                            //MENÚ REPARTOS
            printf("\n***Repartos Actuales: %d", longitudLista(listaReparto));
            printf("\n1-Agregar repartos");
            printf("\n2-Modificar repartos");
            printf("\n3-Eliminar repartos");
            printf("\n4-Mostrar repartos");
            printf("\n5-Enviar Reparto");
            printf("\n6-Mostrar repartos completados");
            printf("\nIngrese opcion: ");
            scanf("%d",&option2);
            system("cls");
            if(option2==1){                                                     //CREAR REPARTOS
                printf("---CHOFERES---\n");
                imprimirChoferLista(listaChofer);
                printf("***(-1 para Salir) ELIJA UN CHOFER: ");
                scanf("%d", &option4);
                choferPtr puntChofer = (choferPtr)getDatoLista(listaChofer,longitudLista(listaChofer)-1-option4);
                esDiferente = true;

                do{
                    for(i=0;i<longitudLista(listaReparto);i++){
                        RepartoPtr puntReparto = (RepartoPtr)getDatoLista(listaReparto,longitudLista(listaReparto)-1-i);
                        while(puntChofer == puntReparto->chofer){
                            puntChofer = (choferPtr)getDatoLista(listaChofer,longitudLista(listaChofer)-1-option4);
                            if(puntChofer == puntReparto->chofer){
                                printf("***(-1 para Salir)HAY OTRO REPARTO EXISTENTE CON EL MISMO CHOFER-INGRESE OTRO: ");
                                scanf("%d", &option4);
                                esDiferente = false;
                            }else{
                                esDiferente = true;
                            }
                            if(option4==-1){

                                system("cls");
                                exit(0);
                            }
                        }
                    }
                }while(esDiferente == false && option!=-1);

                system("cls");
                printf("---VEHICULOS---\n");
                imprimirVehiculoLista(listaVehiculo);
                printf("***ELIJA UN VEHICULO: ");
                scanf("%d", &option4);
                system("cls");
                vehiculoPtr puntVehiculo = (vehiculoPtr)getDatoLista(listaVehiculo,longitudLista(listaVehiculo)-1-option4);
                printf("---FECHA DE SALIDA---");
                printf("\nIngrese el dia: ");
                scanf("%d",&dia);
                while(dia > 31 || dia < 1){
                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL DIA: ");
                    scanf("%d",&dia);
                }
                printf("Ingrese el mes: ");
                scanf("%d",&mes);
                while(mes > 12 || mes < 1){
                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL MES: ");
                    scanf("%d",&mes);
                }
                printf("Ingrese el anio: ");
                scanf("%d",&anio);
                while(anio < 2022 || anio > 2050){
                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL ANIO: ");
                    scanf("%d",&anio);
                }
                fecha = crearFecha(dia,mes,anio);

                for(i=0;i<longitudLista(listaReparto);i++){
                    RepartoPtr puntReparto = (RepartoPtr)getDatoLista(listaReparto,longitudLista(listaReparto)-1-i);
                    while(puntReparto->fecha == fecha){
                        printf("***HAY OTRO REPARTO EXISTENTE CON LA MISMA FECHA-INGRESE OTRA");
                        printf("\nIngrese el dia: ");
                        scanf("%d",&dia);
                        while(dia > 31 || dia < 1){
                            printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL DIA: ");
                            scanf("%d",&dia);
                        }
                        printf("Ingrese el mes: ");
                        scanf("%d",&mes);
                        while(mes > 12 || mes < 1){
                            printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL MES: ");
                            scanf("%d",&mes);
                        }
                        printf("Ingrese el anio: ");
                        scanf("%d",&anio);
                        while(anio < 2022 || anio > 2050){
                            printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL ANIO: ");
                            scanf("%d",&anio);
                        }
                        fecha = crearFecha(dia,mes,anio);
                        system("cls");
                    }
                }

                printf("---HORA DE SALIDA---");
                printf("\nIngrese la hora: ");
                scanf("%d",&hora);
                while(hora > 23){
                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LA HORA: ");
                    scanf("%d",&hora);
                }
                printf("Ingrese los minutos: ");
                scanf("%d",&minutos);
                while(minutos>59){
                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LOS MINUTOS: ");
                    scanf("%d",&minutos);
                }
                horarioSalida = crearHorario(hora,minutos);
                printf("---HORA DE RETORNO---");
                printf("\nIngrese la hora: ");
                scanf("%d",&hora);
                while(hora > 23){
                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LA HORA: ");
                    scanf("%d",&hora);
                }
                printf("Ingrese los minutos: ");
                scanf("%d",&minutos);
                while(minutos>59){
                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LOS MINUTOS: ");
                    scanf("%d",&minutos);
                }
                horarioRetorno = crearHorario(hora,minutos);
                //PaquetePtr puntPaquete = (PaquetePtr)getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4);

                rep = crearReparto(puntChofer,puntVehiculo,fecha,horarioSalida,horarioRetorno,listaPaquete,listaReparto);

                if(rep!=NULL){
                    printf("\n***La carga fue ingresada con exito***\n\n");
                    flag1=true;
                }
            }
            if(option2==2){                                                         //MODIFICAR REPARTOS
                if(listaVacia(listaReparto)){
                    printf("\n***NO hay repartos cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    do{
                    imprimirRepartoLista(listaReparto);
                    printf("Ingrese el reparto a modificar: ");
                    scanf("%d", &indice);
                    system("cls");
                    RepartoPtr puntReparto = (RepartoPtr)getDatoLista(listaReparto,longitudLista(listaReparto)-1-indice);
                    printf("\n1-Modificar chofer del reparto");
                    printf("\n2-Modificar vehiculo del reparto");
                    printf("\n3-Modificar paquetes del reparto");
                    printf("\n4-Modificar dia de la entrega del reparto");
                    printf("\n5-Modificar mes de la entrega del reparto");
                    printf("\n6-Modificar anio de la entrega del reparto");
                    printf("\n7-Modificar hora de salida del reparto");
                    printf("\n8-Modificar minutos de horario de salida del reparto");
                    printf("\n9-Modificar hora de retorno del reparto");
                    printf("\n10-Modificar minutos de horario de retorno del reparto");
                    printf("\n0-VOLVER AL MENU GENERAL");
                    printf("\nIngrese opcion: ");
                    scanf("%d",&option3);
                        switch(option3){
                            case 1:
                                imprimirChoferLista(listaChofer);
                                printf("Ingrese nuevo chofer del reparto: ");
                                scanf("%d", &option4);
                                choferPtr puntChofer = (choferPtr)getDatoLista(listaChofer,longitudLista(listaChofer)-1-option4);

                                do{
                                    for(i=0;i<longitudLista(listaReparto);i++){
                                        RepartoPtr puntReparto = (RepartoPtr)getDatoLista(listaReparto,longitudLista(listaReparto)-1-i);




                                        if(option4!=-1){
                                            puntChofer = (choferPtr)getDatoLista(listaChofer,longitudLista(listaChofer)-1-option4);
                                            if(puntChofer == puntReparto->chofer){
                                                printf("***(-1 para Salir)HAY OTRO REPARTO EXISTENTE CON EL MISMO CHOFER-INGRESE OTRO: ");
                                                scanf("%d", &option4);
                                                esDiferente = false;
                                            }else{
                                                esDiferente = true;
                                            }
                                        }
                                        else{
                                            system("cls");
                                            exit(0);
                                        }
                                    }
                                }while(esDiferente == false && option!=-1);

                                if(esDiferente){
                                    puntReparto->chofer = puntChofer;
                                }
                                system("cls");
                                break;
                            case 2:
                                imprimirVehiculoLista(listaVehiculo);
                                printf("Ingrese nuevo vehiculo del reparto: ");
                                scanf("%d", &option4);
                                system("cls");
                                vehiculoPtr puntVehiculo = (vehiculoPtr)getDatoLista(listaVehiculo,longitudLista(listaVehiculo)-1-option4);
                                puntReparto->vehiculo = puntVehiculo;
                                break;
                            case 3:
                                for(i=0;i<longitudPila(puntReparto->pilaPaquete);i++){
                                    PaquetePtr puntPaquete = (PaquetePtr)desapilar(puntReparto->pilaPaquete);
                                    puntPaquete->apilado = false;
                                }
                                printf("***SE BORRARON TODOS LOS PAQUETES DEL REPARTO SELECCIONADO CON EXITO***\n");

                                PtrLista listaAuxiliarPilaPaquete = crearLista();
                                puntReparto->listaPaquetes = listaAuxiliarPilaPaquete;
                                PtrPila pilaPaquete = crearPila();
                                int option4 = 0;

                                printf("---PAQUETES---\n");
                                while(option4!=-1){
                                    imprimirPaqueteListaAApilar(listaPaquete);
                                    printf("***INGRESE EL PAQUETE A ASIGNAR AL REPARTO: ");
                                    printf("\nDesea seguir agregando paquetes (-1 para cerrar reparto): ");
                                    scanf("%d", &option4);
                                    if(option4!=-1){
                                        PaquetePtr paquetemod = getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4);
                                        paquetemod->apilado = true;
                                        apilar(pilaPaquete,getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4));
                                        agregarDatoLista(listaAuxiliarPilaPaquete,getDatoLista(listaPaquete,longitudLista(listaPaquete)-1-option4));
                                    }
                                    system("cls");
                                }

                                setPilaPaquete(puntReparto,pilaPaquete);
                                break;
                            case 4:
                                printf("Ingrese nuevo dia de la entrega del reparto: ");
                                scanf("%d", &dia);
                                while(dia > 31 || dia < 1){
                                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL DIA: ");
                                    scanf("%d",&dia);
                                }
                                setDia(fecha,dia);
                                fecha=crearFecha(dia,mes,anio);
                                break;
                            case 5:
                                printf("Ingrese nuevo mes de la entrega del reparto: ");
                                scanf("%d", &mes);
                                while(mes > 12 || mes < 1){
                                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL MES: ");
                                    scanf("%d",&mes);
                                }
                                setMes(fecha,mes);
                                fecha=crearFecha(dia,mes,anio);
                                break;
                            case 6:
                                printf("Ingrese nuevo anio de la entrega del reparto: ");
                                scanf("%d", &anio);
                                while(anio < 2022 || anio > 2050){
                                    printf("FECHA ERRONEA-INGRESE NUEVAMENTE EL ANIO: ");
                                    scanf("%d",&anio);
                                }
                                setAnio(fecha,anio);
                                fecha=crearFecha(dia,mes,anio);
                                puntReparto->fecha = fecha;
                                break;
                            case 7:
                                printf("Ingrese nuevo hora de salida del reparto: ");
                                scanf("%d", &hora);
                                while(hora > 23){
                                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LA HORA: ");
                                    scanf("%d",&hora);
                                }
                                puntReparto->horarioSalida->hora = hora;
                                break;
                            case 8:
                                printf("Ingrese nuevos minutos de horario de salida del reparto: ");
                                scanf("%d", &minutos);
                                while(minutos>59){
                                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LOS MINUTOS: ");
                                    scanf("%d",&minutos);
                                }
                                //horarioSalida = crearHorario(hora,minutos);
                                //puntReparto->horarioSalida = horarioSalida;
                                puntReparto->horarioSalida->minutos = minutos;
                                break;
                            case 9:
                                printf("Ingrese nuevo hora de retorno del reparto: ");
                                scanf("%d", &hora);
                                while(hora > 23){
                                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LA HORA: ");
                                    scanf("%d",&hora);
                                }
                                puntReparto->horarioRetorno->hora = hora;
                                break;
                            case 10:
                                printf("Ingrese nuevos minutos de horario de retorno del reparto: ");
                                scanf("%d", &minutos);
                                while(minutos>59){
                                    printf("HORA ERRONEA-INGRESE NUEVAMENTE LOS MINUTOS: ");
                                    scanf("%d",&minutos);
                                }
                                puntReparto->horarioRetorno->minutos = minutos;
                                break;
                        }
                    }while(option3!=0);
                }
            }
            if(option2==3){                                                     //ELIMINAR REPARTOS
                if(listaVacia(listaReparto)){
                    printf("\n**NO hay repartos cargados en el sistema***\n\n");
                    system("pause");
                    system("cls");
                }else{
                    imprimirRepartoLista(listaReparto);
                    printf("Ingrese el reparto a eliminar: ");
                    scanf("%d", &indice);
                    RepartoPtr puntReparto = removerDeLista(listaReparto,longitudLista(listaReparto)-1-indice);
                    puntReparto = eliminarReparto(puntReparto);
                    system("cls");
                }
            }
            if(option2==4){                                                 //MOSTRAR REPARTOS
                if(listaVacia(listaReparto))
                {
                  printf("\n***NO hay repartos cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    imprimirRepartoLista(listaReparto);
                    system("pause");
                    system("cls");
                }
            }
            if(option2==5){                                                                 //ENVIO DE REPARTOS
                if(listaVacia(listaReparto) && listaVacia(listaRepartosActivos))
                {
                  printf("\n***NO hay repartos cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    printf("\n***Repartos Activos Actuales: %d", longitudLista(listaRepartosActivos));
                    printf("\n1-Enviar Reparto");
                    printf("\n2-Manejar Reparto Activo");
                    printf("\nIngrese opcion: ");
                    scanf("%d", &option4);
                    if(option4==1){
                        imprimirRepartoLista(listaReparto);
                        printf("\n**ELEJIR REPARTO A ENVIAR: ");
                        scanf("%d", &indice);
                        system("cls");
                        RepartoPtr puntReparto2 = removerDeLista(listaReparto,longitudLista(listaReparto)-1-indice);
                        puntReparto2->enviado = true;
                        agregarDatoLista(listaRepartosActivos,puntReparto2);

                        printf("\n");
                        system("pause");
                        system("cls");
                    }
                    if(option4==2){
                        if(listaVacia(listaRepartosActivos))
                            {
                              printf("\n***NO hay repartos activos en el sistema***\n\n");
                              system("pause");
                              system("cls");

                            }else{
                            imprimirRepartoLista(listaRepartosActivos);
                                printf("\n**ELEJIR REPARTO PARA REPORTAR PAQUETE ");
                                scanf("%d", &indice);
                                system("cls");
                                RepartoPtr puntReparto = (RepartoPtr)getDatoLista(listaRepartosActivos,longitudLista(listaRepartosActivos)-1-indice);
                                todosPaquetesEntregados = true;
                            for(int i=0;i<=longitudPila(puntReparto->pilaPaquete);i++){
                                paq = desapilar(puntReparto->pilaPaquete);
                                printf("Se entrego el paquete?\n");
                                printf("\n0-NO,1-SI: ");
                                scanf("%d", &option4);
                                if(option4 == 0){
                                    paq->estado = false;
                                    paq->apilado = false;
                                    printf("Especifique razon por la que no se entrego (Usar guiones en lugar de espacios) : ");
                                    scanf("%s", razon);
                                    strcpy(paq->motivoFallo,razon);
                                    todosPaquetesEntregados = false;
                                }else{
                                    paq->estado = true;                                         //agregar actualizacion de paquete en la lista
                                }
                            }
                            if(todosPaquetesEntregados==true){
                                printf("\n***SE HAN ENTREGADO TODOS LOS PAQUETES CON EXITO***");
                            }else{
                                printf("\n***SE COMPLETO EL REPARTO PERO NO SE ENTREGARON TODOS LOS PAQUETES***");
                            }

                            puntReparto->completado = true;
                            RepartoPtr puntReparto2 = removerDeLista(listaRepartosActivos,longitudLista(listaRepartosActivos)-1-indice);
                            agregarDatoLista(listaRepartosEntregados,puntReparto2);
                            printf("\n");
                            system("pause");
                            system("cls");
                        }
                    }
                }
            }
            if(option2==6){
                if(listaVacia(listaRepartosEntregados))
                {
                  printf("\n***NO hay repartos cargados en el sistema***\n\n");
                  system("pause");
                  system("cls");

                }else{
                    imprimirRepartoLista(listaRepartosEntregados);
                    system("pause");
                    system("cls");
                }

            }
            break;
        }

}while(continues=='S');
}

