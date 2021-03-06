#ifndef PRESENTISMO_H_INCLUDED
#define PRESENTISMO_H_INCLUDED
#include <cstring>
#include "fecha.h"


class Presentismo{
private:
    Fecha FechaEntrada;
    Fecha FechaSalida;
    Fecha HoraEntrada;
    Fecha HoraSalida;
    int Dia;
    int MinutosFaltantes;
    char MSJ[25];
    int Legajo;
    bool Estado=true;
public:
    ///Gets
    Fecha getFechaEntrada(){return FechaEntrada;}
    Fecha getFechaSalida(){return FechaSalida;}
    Fecha getHoraSalida(){return HoraSalida;}
    Fecha getHoraEntrada(){return HoraEntrada;}
    int getdia(){return Dia;}
    int getMinutosFaltantes (){return MinutosFaltantes;}
    char *getMSJ(){return MSJ;}
    int getLegajo(){return Legajo;}

    ///Sets
    void setFechaEntrada (Fecha f){FechaEntrada=f;}
    void setFechaSalida (Fecha i){FechaEntrada=i;}
    void setHoraSalida (Fecha s){HoraSalida=s;}
    void setHoraIngreso (Fecha i){HoraEntrada=i;}
    void setMinutosFaltantes(int m){MinutosFaltantes=m;}
    void setdia(int d){Dia=d;}
    void setMSJ(char *ms){strcpy(MSJ,ms);}
    void setLegajo(int leg){Legajo=leg;}
    ///FUNCIONE LOCALES
    void Cargar(int leg);
    void Mostrar();
    bool grabarDisco(int pos=0);
    bool leerDisco(int);
};

#endif // PRESENTISMO_H_INCLUDED
