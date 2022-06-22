#include <iomanip>
#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "fecha.h"
#include "clases.h"
#include "Empleado.h"
#include "Presentismo.h"

using namespace std;
///Prototipos
void CargaDatos();
    int BuscarLegajo(int leg);

void ListadoEmpleado(int);
void MostrarSector (int sector);
int CantRegistrosEmpleado();

void BajaEmpleado();
int BuscaCantDiasXmes(int f);
void AsistenciaDelMes();
void AsistenciaPersonal();
void ListadoAsistencia();
    void SeparadorSemanas(int semana, int *);
    bool DentroDelRango(int ,int *,int ,int);
///funciones
void CargaDatos(){
    Empleado obj;
    int leg, encontro;
    cout<<"INGRESAR LEGAJO "<<endl;
    cin>>leg;
    encontro=BuscarLegajo(leg);
    if(encontro==-2){
        obj.Cargar(leg);
        if(obj.GrabarEnDisco()==true){
          cout<<"SE GRABO CORRECTAMENTE"<<endl;
        }
    }
    else{
        cout<<"EMPLEADO YA SE ENCUENTRA DADO DE ALTA "<<endl;
    }
    system("cls");
}

int BuscarLegajo(int leg){
    Empleado obj;
    int pos=0;
    while(obj.leerDisco(pos)==1){
        if(obj.getLegajo()==leg){
            return pos;
        }
        pos++;
    }
    return -2;
}

void BajaEmpleado(){
    Empleado obj;
    int leg, encontro=0;
    cout<<"INGRESAR LEGAJO "<<endl;
    cin>>leg;
    encontro=BuscarLegajo(leg);
    if(obj.leerDisco(encontro)==1){
        obj.setEstado(false);
        obj.GrabarEnDisco(encontro);
        cout<<"SE GENERO LA BAJA DEL EMPLEADO "<<endl;
    }
}

void ListadoEmpleado(int sector){
    Empleado obj;
    int pos=0, contador=0;
    cout<<"============================== SECTOR ";
    MostrarSector(sector);
    cout<<" =============================="<<endl;
    cout <<"LEGAJO";
    cout << "\tAPELLIDO";
    cout << "\tNOMBRE";
    cout << "\t"<< "\t  DNI";
    cout << "\t"<< "\tFECHA ALTA" << endl;
    while(obj.leerDisco(pos++)==1){
        if(obj.getSector()==sector && obj.getEstado()==true){
                cout << obj.getLegajo();///lEGAJO
                cout << "\t" << obj.getApellido();
                cout << "\t" << "\t"<< obj.getNombre();
                cout << "\t"<< "\t" << obj.getDni();
                cout << "\t" << obj.getFechaAlta().getDia()<< "/"; cout << obj.getFechaAlta().getMes() << "/";
                cout << obj.getFechaAlta().getAnio();
                cout << endl;
                contador++;
        }
    }
    cout<<"================================================================================="<<endl;
    cout<<"HAY "<<contador<<" EMPLEADOS EN LA CATEGORIA."<<endl;
    system("pause>null");
    system("cls");
    return;
}

void MostrarSector (int sector){
    if(sector==1){
        cout<<"ADMINISTRACION";
        return;
    }
    else{
        if(sector==2){
        cout<<"PRODUCCION";
        return;
        }
        else{
            if(sector==3){
                cout<<"RRHH";
                return;
            }
            else{
                if(sector==4){
                    cout<<"COMPRAS";
                    return;
                }
                else{
                    cout<<"SISTEMAS Y OPERACIONES";
                    return;
                }
            }
        }
    }
}

int CantRegistrosEmpleado(){
    int cant, bytes;
    FILE *Po=fopen("Empleados.dat","rb");
    if(Po==NULL) {
            cout<<"ERROR DE ARCHIVO"<<endl;
            fclose(Po);
            return false;
        }
        fseek(Po,0,2);
        bytes=ftell(Po);
        cant=bytes/(sizeof(Empleado));
        fclose(Po);
        return cant;
}

void AsistenciaPersonal(){
    Empleado obj;
    Presentismo aux;
    int leg, pos, opc=1,p;
    bool grabo;
    while(opc!=0){
    cout<<"INGRESAR LEGAJO A CARGAR "<<endl;
    cin>>leg;
        pos=BuscarLegajo(leg);
        if(pos>=0){
            aux.Cargar(leg);
            /*if(aux.getMinutosFaltantes()<0){
                char m;
                cout<<"INGRESAR MENSAJE POR INCUMPLIMIENTO DEL PRESENTIMOS "<<endl;
                cin>>m;
                aux.setMSJ(m);
            }*/
            grabo=aux.grabarDisco();
            if(grabo==true){
                cout<<"ASISTENCIA CARGADA CORRECTAMENTE "<<endl;
                system("pause");
            }
        }
        else{
            cout<<"NO FIGURA EL EMPLEADO EN LA BASE"<<endl;
            system("pause");
        }
        system("cls");
        cout<<"¿DESEA CARGAR OTRA ASISTENCIA? "<<endl;
        cout<<"1 -  SI"<<endl;
        cout<<"0 -  NO"<<endl;
        cin>>opc;
        system("cls");
    }
}

void ListadoAsistencia(){
    Presentismo obj;
    Empleado aux;
    int leg, pos, total=0;
    int semana, mes, anio;
    int vecsemana[2]{};
        cout<<"INGRESAR LEGAJO A CONSULTAR"<<endl;
        cin>>leg;
        pos=BuscarLegajo(leg);
        cout<<"INGRESAR SEMANA A CONSULTAR (1 - 2 - 3 - 4)"<<endl;
        cin>>semana;///poner tope hasta semana 4
        SeparadorSemanas(semana, vecsemana);
        cout<<"INGRESAR MES A CONSULTAR"<<endl;
        cin>>mes;
        cout<<"INGRESAR ANIO A CONSULTAR"<<endl;
        cin>>anio;
        if(pos>=0){
            cout<<"======================================= ASISTENCIA ";
            aux.leerDisco(pos);
            cout<<aux.getApellido();
            cout<<" ========================================================="<<endl<<endl;
            pos=0;
            cout <<"LEGAJO";
            cout << "\t"<< "\tINGRESO";
            cout << "\t"<< "\tEGRESO    " ;
            cout << "\tHORA INGRESO";
            cout << "\tHORA EGRESO";
            cout << "\tMENSAJE DEL EMPLEADO" << endl;
            while(obj.leerDisco(pos)==1){
                if(obj.getLegajo()==leg && DentroDelRango(pos, vecsemana, mes, anio)==true){
                    cout << obj.getLegajo();///lEGAJO
                    cout << "\t"<< "\t" << obj.getFechaEntrada().getDia()<< "/"; cout << obj.getFechaEntrada().getMes() << "/";
                    cout << obj.getFechaEntrada().getAnio();///ENTRDA FECHA
                    cout << "\t" << obj.getFechaSalida().getDia()<< "/"; cout << obj.getFechaSalida().getMes() << "/";
                    cout << obj.getFechaSalida().getAnio();///FECHA SALIDA
                    cout << "\t" <<"   "<<obj.getHoraEntrada().getHora()<<":"<<obj.getHoraEntrada().getMinutos();///HORA ENTRADA
                    cout << "\t"<< "\t" <<"   "<<obj.getHoraSalida().getHora()<<":"<<obj.getHoraSalida().getMinutos();///HORA SALIDA
                    cout << "\t"<< "\t" ; ///obj.getMensaje(); HACER EL GET Y LA PROPIEDAD
                    cout << endl;
                    total+=(obj.getMinutosFaltantes());
                }
                pos++;
            }
                cout<<"=================================================================================================================="<<endl;
                if(total<0){
                total=total*-1;
                cout<<"EL EMPLEADO ADEUDADA "<<total<<" MINUTOS. "<<endl;///marcar total de hora adeudadas
                }
                else{
                    cout<<"EL EMPLEADO NO ADEUDAD HORAS"<<endl;
                }
        }
        system("pause");
        system("cls");
}
void SeparadorSemanas(int semana, int *vec){
    if(semana==1){
        vec[0]=1;
        vec[1]=7;
    }
    else{
        if(semana==2){
            vec[0]=8;
            vec[1]=14;
        }
        else{
            if(semana==3){
                vec[0]=15;
                vec[1]=21;
            }
            else{
                vec[0]=22;
                vec[1]=31;
            }
        }
    }
    return;
}
bool DentroDelRango(int pos,int *vec,int mes,int anio){
    Presentismo obj;
    obj.leerDisco(pos);
    if(obj.getFechaEntrada().getDia()>=vec[0] && obj.getFechaEntrada().getDia()<=vec[1] && obj.getFechaEntrada().getMes()==mes && obj.getFechaEntrada().getAnio()==anio){
        return true;
    }
    else{
        return false;
    }
}

#endif // CLASES_H_INCLUDED
