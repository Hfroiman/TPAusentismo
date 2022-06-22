#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string>


class Fecha{
    public:
        int  getDia();
        int  getMes();
        int  getAnio();
        int getHora();
        int getMinutos();
        //set
        void setDia(int d);
        void setMes(int m);
        void setAnio(int a);
        void setHora(int h);
        void setMinutos(int m);
             Fecha(int dia, int mes, int anio);
             Fecha();
        std::string toString();
        void Cargar();
        void CargarH();
        void Mostrar();
        void CargarHorario();
        void Mostrarhorario();
    private:
        int _dia, _mes, _anio;
        int hora;
        int minutos;

};
int BuscaCantDiasXmes(int f);
#endif // FECHA_H_INCLUDED
