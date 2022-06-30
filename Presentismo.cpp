#include "Presentismo.h"
#include <iostream>
# include<cstdlib>
# include<cstring>
using namespace std;

int zeller(int anio, int mes, int dia);

void Presentismo::Cargar(int leg){
    int f=1,minutos=60,jornadaok=8, hingreso=6, hsalida=14, total=0;
    float hsfaltantes, mfaltantes;
    Legajo=leg;
    cout<<"INGRESAR ENTRADA"<<endl;
    FechaEntrada.Cargar(leg);
    HoraEntrada.CargarH();
    cout<<"INGRESAR SALIDA"<<endl;
    FechaSalida.Cargar(leg);
    HoraSalida.CargarH();

    int num;
    num=zeller(getFechaEntrada().getAnio(), getFechaEntrada().getMes(), getFechaEntrada().getDia());
    setdia(num);

    hsfaltantes=((getHoraSalida().getHora()-getHoraEntrada().getHora())-jornadaok)*minutos;
    mfaltantes=(getHoraSalida().getMinutos()-getHoraEntrada().getMinutos());
    total=hsfaltantes+(mfaltantes);
    setMinutosFaltantes(total);
}
int zeller(int anio, int mes, int dia){

        int a = (14 - mes) / 12;
        int y = anio - a;
        int m = mes + 12 * a - 2;

        int d = (dia + y + y/4 - y/100 + y/400 + (31*m)/12)% 7;

        return d;
}

void Presentismo::Mostrar(){
    if(Estado==true){
    int h;
    cout<<"Legajo"<<getLegajo()<<endl;
    cout<<"fecha entrada"<<getFechaEntrada().getDia()<<"/"<<getFechaEntrada().getMes()<<endl;
    cout<<"fecha Salida"<<getFechaSalida().getDia()<<"/"<<getFechaSalida().getMes()<<endl;
    cout<<"hora entrada"<<getHoraEntrada().getHora()<<":"<<getHoraEntrada().getMinutos()<<endl;
    cout<<"hora salida"<<getHoraSalida().getHora()<<":"<<getHoraSalida().getMinutos()<<endl;
    cout<<"numero de dia"<<getdia();
    cout<<""<<endl;
    cin>>h;
    }
    else{
        cout<<"No hay registro "<<endl;
    }
}

bool Presentismo::grabarDisco(int pos){
    if(pos==0){
    FILE *p=fopen("Presentismo.dat","ab");
    if(p==nullptr){
    cout<<"ERROR DE ARCHIVO "<<endl;
    fclose(p);
    return false;
    }
        if(fwrite(this,sizeof(Presentismo),1,p)==1){
            fclose(p);
            return true;
        }
    }
    else
    {
        FILE *p=fopen("Presentismo.dat","rb+");
        if(p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            fclose(p);
            return false;
        }
        fseek(p,pos*sizeof (Presentismo),0);
        if(fwrite(this,sizeof(Presentismo),1,p)==1) {
            fclose(p);
            return true;
        }
    }
}
bool Presentismo::leerDisco(int pos){
    FILE *pu=fopen("Presentismo.dat","rb");
    if(pu==nullptr){
        cout<<"ERROR DE ARCHIVO"<<endl;
        fclose(pu);
        return false;
    }
    fseek(pu, pos*sizeof(Presentismo),0);
    if (fread(this,sizeof(Presentismo),1,pu)==1){
    fclose(pu);
    return true;
    }
}
