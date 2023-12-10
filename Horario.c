#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "Horario.h"

HorarioPtr crearHorario(int hora, int minutos){
    HorarioPtr h = (HorarioPtr)obtenerMemoria(sizeof(Horario));
    h->hora = hora;
    h->minutos = minutos;

    return h;
}

HorarioPtr destruirHorario(HorarioPtr horario){
    free(horario);
    return NULL;
}

int getHora(HorarioPtr horario){
    return horario->hora;
}

int getMinutos(HorarioPtr horario){
    return horario->minutos;
}

void setHora(HorarioPtr horario, int hora){
    horario->hora = hora;
}

void setMinutos(HorarioPtr horario, int minutos){
    horario->minutos = minutos;
}
