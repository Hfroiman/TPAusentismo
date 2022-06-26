#include <iostream>
#include "fecha.h"
#include "clases.h"
#include "Empleado.h"
#include "Menus.h"
#include "Presentismo.h"


using namespace std;
int main(){
    int opc, Eleccion, opcDatos, cat;
    Presentismo obj;
    Empleado aux;
    Bienvenida();
     while(true){
        cout<<"============== MENU =============="<<endl;
        cout<<"1. ALTAS/BAJAS DE PERSONAL   "<<endl;
        cout<<"2. CARGA DE ASISTENCIA       "<<endl;
        cout<<"3. CONSULTAS     "<<endl;
        cout<<"=================================="<<endl;
        cout<<"0. FIN DEL PROGRAMA"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                    Eleccion=MenuAltaBaja();
                    if(Eleccion==1){
                        CargaDatos();///CARGAR ALTA
                    }
                    else{
                        if(Eleccion==2){
                            BajaEmpleado();//GENERAR BAJA
                        }
                    }
                break;
            case 2:
                AsistenciaPersonal();
                break;
            case 3:
                if(MenuConsultas()==1){
                    cat=MenuDatosDelPersonal();
                    ListadoEmpleado(cat);
                }
                else{
                    if(MenuConsultas()==2){
                        ListadoAsistencia();
                    }
                    else{
                        if(MenuConsultas()==3){
                        }
                    }
                }
            break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                cout<<"ESTAS SEGURO?"<<endl;
                cout<<"NO - 1"<<endl;
                cout<<"SI - 0"<<endl;
                cin>>opc;
                return 0;
        }
        system("pause");
    }
return 0;
}
///TDOD OK
