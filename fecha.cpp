#include "fecha.h"
#include "Presentismo.h"
#include <ctime>
#include <iostream>
using namespace std;

int  Fecha::getDia(){
    return _dia;
}
int  Fecha::getMes(){
    return _mes;
}
int  Fecha::getAnio(){
    return _anio;
}
    int Fecha::getHora(){
    return hora;
}
    int Fecha::getMinutos(){
    return minutos;
}
void Fecha::setDia(int dia){
    _dia = dia;
}
void Fecha::setMes(int mes){
    _mes = mes;
}
void Fecha::setAnio(int anio){
    _anio = anio;
}
    void Fecha::setHora(int h){
    hora=h;
    }
    void Fecha::setMinutos(int m){
    minutos=m;
    }
Fecha::Fecha(int dia, int mes, int anio){
    _dia = dia;
    _mes = mes;
    _anio = anio;
}
Fecha::Fecha(){
    time_t rawtime;
    struct tm timeinfo;

    time (&rawtime);
    timeinfo = *(localtime (&rawtime));

    _dia = timeinfo.tm_mday;
    _mes = timeinfo.tm_mon + 1;
    _anio = timeinfo.tm_year + 1900;
}
string Fecha::toString(){
    string fecha;
    fecha = to_string(_dia) + "/" + to_string(_mes) + "/" + to_string(_anio);
    return fecha;
}
bool YaCargado(int d,int m,int a,int leg);

void Fecha::Cargar(int leg){
    int d,m,a, maxmes=12, dia;
    bool cargado=true;
    while(cargado==true){
        cout<<"INGRESAR ANIO "<<endl;
        cin>>a;
        cout<<"INGRESAR MES "<<endl;
        cin>>m;
        while(m>maxmes){
            cout<<"EL MES DEBE SER EN EL RANGO DE 1 A 12 "<<endl;
            cin>>m;
        }
        dia=BuscaCantDiasXmes(m);//GG
        cargado=YaCargado(dia,m,a,leg);
        if(cargado==false){
            setDia(dia);
            setMes(m);
            setAnio(a);
        }
        else{
            cout<<"FECHA YA CARGADA ANTERIORMENTE, INGRESAR FECHA CORRECTA "<<endl;
            system("pause > null");
        }
    }
}

bool YaCargado(int d,int m,int a,int leg){
    Presentismo obj;
    int pos=0;
    while(obj.leerDisco(pos)==1){
        if(obj.getLegajo()==leg && obj.getFechaEntrada().getAnio()==a && obj.getFechaEntrada().getMes()==m && obj.getFechaEntrada().getDia()==d){
            return true;
        }
        pos++;
    }
    return false;
}

void Fecha::CargarH(){
    int h;
        cout<<"INGRESAR HORA "<<endl;///HORAS DESDE 0 A 24
        cin>>h;
        while(h>23 || h<0){
            cout<<"INGRESAR HORA, EN RANGO DE 0 A 23 HS "<<endl;
            cin>>h;
        }
        setHora(h);
        cout<<"INGRESAR MINUTOS "<<endl;//MINUTOS 0 A 60
        cin>>h;
        while(h>60 || h<0){
            cout<<"INGRESAR MINUTOS, EN RANGO DE 0 A 60"<<endl;
            cin>>h;
        }
        setMinutos(h);
}

int BuscaCantDiasXmes(int f){
    int d;
    if(f==4 ||f==6 ||f==9 || f==11){
        cout<<"INGRESAR DIA "<<endl;
        cin>>d;
        while(d>30){
        cout<<"INGRESAR DIA, RANGO DE 1 A 30"<<endl;
        cin>>d;
        }
        return d;
    }
    else{
        if(f==2){
            cout<<"INGRESAR DIA "<<endl;
            cin>>d;
            while(d>28){
            cout<<"INGRESAR DIA, RANGO DE 1 A 28"<<endl;
            cin>>d;
            }
            return d;
        }
        else{
            cout<<"INGRESAR DIA "<<endl;
            cin>>d;
            while(d>31){
            cout<<"INGRESAR DIA, RANGO DE 1 A 31"<<endl;
            cin>>d;
            }
            return d;
        }
    }
}

void Fecha::Mostrar2(){
        cout<<" ANIO "<<endl;
        cout<<getAnio()<<endl;
        cout<<" MES "<<endl;
        cout<<getMes()<<endl;
        cout<<" DIA "<<endl;
        cout<<getDia()<<endl;
        cout<<" HORA "<<endl;
        cout<<getHora()<<endl;
        cout<<" MINUTOS "<<endl;
        cout<<getMinutos()<<endl;
}
///fecha para alta
void Fecha::Mostrar(int){
    cout << "FECHA: "<< getDia()<< "/"<< getMes()<< "/"<< getAnio()<<endl;
    ///cout << "HORA: "<< getHora()<< ":"<< getMinutos()<<endl;
}
