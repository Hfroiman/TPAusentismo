#include "Empleado.h"
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>
#include "fecha.h"

void Empleado::Cargar(int leg){
    int S;
    if(leg==0){
        cout<<"INGRESAR NUMERO DE LEGAJO "<<endl;
        cin>>leg;
    }
    else{
        Legajo=leg;
        cout<<"INGRESAR NUMERO DE SECTOR (1. ADMINISTRACION- 2. PRODUCCION- 3. RRHH)"<<endl;
        cin>>S;
        while(S>5){
            cout<<"INGRESAR NUMERO DE SECTOR DEL 1 AL 5"<<endl;
            cin>>S;
        }
        Sector=S;
        cout<<"INGRESAR NUMERO DE DNI "<<endl;
        cin>>Dni;
        cout<<"INGRESAR APELLIDO "<<endl;
        cin>>Apellido;
        cout<<"INGRESAR NOMBRE"<<endl;
        cin>>Nombre;
        FechaActual.Mostrar(S);
        setEstado(true);
    }
}
void Empleado::Mostrar(){
    if(Estado==true){
        cout<<" NUMERO DE LEGAJO "<<endl;
        cout<<Legajo<<endl;
        cout<<" NUMERO DE SECTOR "<<endl;
        cout<<Sector<<endl;
        cout<<" NUMERO DE DNI "<<endl;
        cout<<Dni<<endl;
        cout<<" APELLIDO "<<endl;
        cout<<Apellido<<endl;
        cout<<" NOMBRE"<<endl;
        cout<<Nombre<<endl;
        FechaActual.Mostrar2();
    }
    else{
        cout<<"NO HAY REGISTROS"<<endl;
    }
}
bool Empleado::GrabarEnDisco(int pos){
    if(pos==0){
    FILE *p=fopen("Empleados.dat","ab");
    if(p==NULL){
    cout<<"ERROR DE ARCHIVO "<<endl;
    fclose(p);
    return false;
    }
        if(fwrite(this,sizeof(Empleado),1,p)==1){
            fclose(p);
            return true;
        }
    }
    else
    {
        FILE *p=fopen("Empleados.dat","rb+");
        if(p==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            fclose(p);
            return false;
        }
        fseek(p,pos*sizeof (Empleado),0);
        if(fwrite(this,sizeof(Empleado),1,p)==1) {
            fclose(p);
            return true;
        }
    }
}
bool Empleado::leerDisco(int pos){
    FILE *pu=fopen("Empleados.dat","rb");
    if(pu==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        fclose(pu);
        return false;
    }
    fseek(pu, pos*sizeof(Empleado),0);
    if (fread(this,sizeof(Empleado),1,pu)==1){
    fclose(pu);
    return true;
    }
}
