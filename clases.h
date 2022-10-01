#include <iomanip>
#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
#include "fecha.h"
#include "clases.h"
#include "Empleado.h"
#include "Presentismo.h"
#include <iomanip>

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
    void nombreDia(int);
///funciones
void CargaDatos(){
    Empleado obj;
    int leg, encontro;
    cout<<"INGRESAR LEGAJO "<<endl;
    cin>>leg;
    encontro=BuscarLegajo(leg);
    if(encontro==-2){
        obj.Cargar(leg);
        obj.setEstado(true);
        if(obj.GrabarEnDisco()==true){
          cout<<"SE GRABO CORRECTAMENTE"<<endl;
        }
    }
    else{
        cout<<"EMPLEADO YA SE ENCUENTRA DADO DE ALTA "<<endl;
    }
    system("pause>null");
    system("cls");
}

int BuscarLegajo(int leg){
    Empleado obj;
    int pos=0;
    while(obj.leerDisco(pos)==1){
        if(obj.getLegajo()==leg && obj.getEstado()==true){
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
    if(encontro>-1){
        if(obj.leerDisco(encontro)==1){
            obj.setEstado(false);
            obj.GrabarEnDisco(encontro);
            cout<<"SE GENERO LA BAJA DEL EMPLEADO "<<endl;
        }
    }
    else{
        cout<<"NO SE ENCONTRO EL LEGAJO"<<endl;
    }
    system("pause>null");
    system("cls");
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
            if((aux.getMinutosFaltantes()*-1)>0){
                char m[25];
                cout<<"INGRESAR MENSAJE POR INCUMPLIMIENTO DEL PRESENTIMOS "<<endl;
                cin.ignore();
                cin.getline(m,25);
                aux.setMSJ(m);
            }
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
            cout << "=================================================================================================" << endl;
                aux.leerDisco(pos);
            cout << left;
            cout << setw(10)  << " LEGAJO: ";
            cout << setw(10) << aux.getLegajo();
            cout << setw(11) << " APELLIDO: ";
            cout << setw(15)<< aux.getApellido();
            cout << setw(9) << " NOMBRE: ";
            cout << setw(15)<< aux.getNombre();
            cout << endl;
            cout << "=================================================================================================" << endl;


            pos=0;
            char vec[11];
            while(obj.leerDisco(pos)==1){
                if(obj.getLegajo()==leg && DentroDelRango(pos, vecsemana, mes, anio)==true){
                char t[2]="/";
                char h[2]=":";
                int din=obj.getFechaEntrada().getDia(), mei=obj.getFechaEntrada().getMes(), ain=obj.getFechaEntrada().getAnio();
                int hin=obj.getHoraEntrada().getHora(), minr=obj.getHoraEntrada().getMinutos();

                int dse=obj.getFechaSalida().getDia(), mse=obj.getFechaSalida().getMes(), ans=obj.getFechaSalida().getAnio();
                int hsa=obj.getHoraSalida().getHora(), mss=obj.getHoraSalida().getMinutos();
            cout << left;
            nombreDia(obj.getdia());
            cout << setw(2) << "   Entrada: " ;
            cout << setw(2) <<din<<t<<mei<<t<<ain;
            cout << setw(2) << "   Salida: ";
            cout << setw(2) <<dse<<t<<mse<<t<<ans;
            cout << setw(2) << "   Hora Entrada: ";
            cout << setw(2) <<hin<<h<<minr;
            cout << setw(2) << "   Salida: ";
            cout << setw(2) <<hsa<<h<<mss;
            cout << setw(15) << "  MENSAJE EMPLEADO: ";
            cout << setw(15) <<obj.getMSJ();
            cout << endl;
            total+=(obj.getMinutosFaltantes());
            }
        pos++;
        }
                cout<<"================================================================================================="<<endl;
                if(total<0){
                total=total*-1;
                cout<<"EL EMPLEADO ADEUDADA "<<total<<" MINUTOS. "<<endl<< endl;///marcar total de hora adeudadas
                }
                else{
                    cout<<"EL EMPLEADO NO ADEUDA HORAS"<<endl<< endl;
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

void nombreDia(int n){
    if(n==0){
        cout<<"Domingo...";
    }
    else{
        if(n==1){
            cout<<"Lunes.....";
        }
    else{
        if(n == 2){
            cout<<"Martes....";
    }
    else{
            if(n == 3){
            cout<<"Miercoles.";
    }
    else{
            if(n == 4){
                cout<<"Jueves....";
    }
    else{
            if(n == 5){
                cout<<"Viernes...";
    }
    else{
            if(n == 6){
            cout<<"Sabado....";
    }
    }}}}}}
    return;
}

#endif // CLASES_H_INCLUDED
