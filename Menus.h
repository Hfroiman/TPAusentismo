#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include <iostream>
using namespace std;

void Bienvenida (){
        cout<<"===================== BIENVENIDOS ==================="<<endl;
        cout<<"                       GRUPO 20"<<endl;
        cout<<"            SISTEMA DE GESTION DE ASISTENCIA"<<endl;
        cout<<"====================================================="<<endl;
        system("pause");
        system("cls");
        return;
}

int MenuAltaBaja(){
    int opc;
        system("cls");
        cout<<"==================== MENU ========================="<<endl;
        cout<<"1. GENERAR ALTA DE EMPLEADO "<<endl;
        cout<<"2. GENERAR BAJA DE EMPLEADO "<<endl;
        cout<<"==================================================="<<endl;
        cout<<"0. VOLVER"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        system("pause>null");
        return opc;
}

int MenuConsultas(){
    int opc;
        system("cls");
        cout<<"==================== CONSULTAS ===================="<<endl;
        cout<<"1. DATOS DEL PERSONAL "<<endl;
        cout<<"2. ASISTENCIA DEL MES "<<endl;
        ///cout<<"2.   "<<endl;
        cout<<"==================================================="<<endl;
        cout<<"0. VOLVER"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        system("pause>null");
        return opc;
}

int MenuDatosDelPersonal(){
    int opc;
        system("cls");
        cout<<"============== DATOS DEL PERSONAL ================"<<endl;
        cout<<"                    CATEGORIA"<<endl;
        cout<<"=================================================="<<endl;
        cout<<"1. ADMINISTRACION "<<endl;
        cout<<"2. PRODUCCION "<<endl;
        cout<<"3. RRHH  "<<endl;
        cout<<"4. COMPRAS  "<<endl;
        cout<<"5. SISTEMAS Y OPERACIONES  "<<endl;
        cout<<"==================================================="<<endl;
        cout<<"0. VOLVER"<<endl;
        cout<<"OPCION: ";
        cin>>opc;
        system("cls");
        system("pause>null");
        return opc;
}

#endif // MENUS_H_INCLUDED
