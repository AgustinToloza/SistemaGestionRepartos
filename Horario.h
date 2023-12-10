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

// Operación de creación (Constructor)
// Precondicion: el horario no ha sido creado
// Postcondición: se crea una estructura horario con hora y minutos
// Parámetros:
// hora: entero representando la hora
// minutos: entero representando los minutos
// Devuelve puntero a la estructura Horario en memoria dinámica
HorarioPtr crearHorario(int hora, int minutos);

// Operación de destrucción (Destructor)
// Precondicion: horario debe haberse creado con crearHora
// Postcondición: se destruye horario y se libera la memoria que ocupaba
// Parámetros:
// horario: TDAHorario a destruir
// Devuelve NULL
HorarioPtr destruirHorario(HorarioPtr horario);

// Operación de obtención de hora
// Precondicion: la estructura horario debe haberse creado
// Postcondición: se obtiene hora
// Parámetros:
// horario: TDAHorario del que se obtiene hora
// Devuelve un entero representando la hora
int getHora(HorarioPtr horario);

// Operación de obtención de los minutos
// Precondicion: la estructura horario debe haberse creado
// Postcondición: se obtienen los minutos
// Parámetros:
// horario: TDAHorario del que se obtienen los minutos
// Devuelve un entero representando los minutos
int getMinutos(HorarioPtr horario);

// Operación de asignación de hora
// Precondicion: la estructura horario debe haberse creado
// Postcondición: la estructura horario cambia con el nuevo valor de hora
// Parámetros:
// horario: TDAHorario al que se asignara el nuevo valor de hora
// hora: entero representando el nuevo valor de hora
// No devuelve valor.
void setHora(HorarioPtr horario, int hora);

// Operación de asignación de los minutos
// Precondicion: la estructura horario debe haberse creado
// Postcondición: la estructura horario cambia con el nuevo valor de los minutos
// Parámetros:
// horario: TDAHorario al que se asignara el nuevo valor de los minutos
// minutos: entero representando el nuevo valor de los minutos
// No devuelve valor.
void setMinutos(HorarioPtr horario, int minutos);

#endif // TDAHORARIO_H_INCLUDED
