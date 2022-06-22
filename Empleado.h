#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
#include <cstring>
#include "fecha.h"
class Empleado{
private:
    Fecha FechaActual;
    int Legajo, Sector, Dni;
    char Nombre[25];
    char Apellido[25];
    bool Estado;
public:
    ///Gets
    Fecha getFechaAlta(){return FechaActual;}
    int getLegajo(){return Legajo;}
    int getDni(){return Dni;}
    int getSector(){return Sector;}
    const char *getNombre(){return Nombre;}
    const char *getApellido(){return Apellido;}
    bool getEstado(){return Estado;}
    ///Sets
    void setEstado(bool e){Estado=e;}
    void setSector(int s){Sector=s;}
    void setLegajo(int leg){Legajo=leg;}
    void setDni(int d){Dni=d;}
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setApellido(const char *a){strcpy(Apellido,a);}
    ///Funciones Locales
    void Cargar(int leg=0);
    void Mostrar();
    bool GrabarEnDisco(int pos=0);
    bool leerDisco(int);
};
#endif // EMPLEADO_H_INCLUDED
