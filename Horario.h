#ifndef TDAHORARIO_H_INCLUDED
#define TDAHORARIO_H_INCLUDED

//*******************************************************
// Interfaz de TDAHorario
//*******************************************************

// Estructura que define al tipo
typedef struct Horario {
    int hora;
    int minutos;
} Horario;

// Typedef de puntero al tipo de dato
typedef Horario* HorarioPtr;

// Primitivas

// Operaci�n de creaci�n (Constructor)
// Precondicion: el horario no ha sido creado
// Postcondici�n: se crea una estructura horario con hora y minutos
// Par�metros:
// hora: entero representando la hora
// minutos: entero representando los minutos
// Devuelve puntero a la estructura Horario en memoria din�mica
HorarioPtr crearHorario(int hora, int minutos);

// Operaci�n de destrucci�n (Destructor)
// Precondicion: horario debe haberse creado con crearHora
// Postcondici�n: se destruye horario y se libera la memoria que ocupaba
// Par�metros:
// horario: TDAHorario a destruir
// Devuelve NULL
HorarioPtr destruirHorario(HorarioPtr horario);

// Operaci�n de obtenci�n de hora
// Precondicion: la estructura horario debe haberse creado
// Postcondici�n: se obtiene hora
// Par�metros:
// horario: TDAHorario del que se obtiene hora
// Devuelve un entero representando la hora
int getHora(HorarioPtr horario);

// Operaci�n de obtenci�n de los minutos
// Precondicion: la estructura horario debe haberse creado
// Postcondici�n: se obtienen los minutos
// Par�metros:
// horario: TDAHorario del que se obtienen los minutos
// Devuelve un entero representando los minutos
int getMinutos(HorarioPtr horario);

// Operaci�n de asignaci�n de hora
// Precondicion: la estructura horario debe haberse creado
// Postcondici�n: la estructura horario cambia con el nuevo valor de hora
// Par�metros:
// horario: TDAHorario al que se asignara el nuevo valor de hora
// hora: entero representando el nuevo valor de hora
// No devuelve valor.
void setHora(HorarioPtr horario, int hora);

// Operaci�n de asignaci�n de los minutos
// Precondicion: la estructura horario debe haberse creado
// Postcondici�n: la estructura horario cambia con el nuevo valor de los minutos
// Par�metros:
// horario: TDAHorario al que se asignara el nuevo valor de los minutos
// minutos: entero representando el nuevo valor de los minutos
// No devuelve valor.
void setMinutos(HorarioPtr horario, int minutos);

#endif // TDAHORARIO_H_INCLUDED
