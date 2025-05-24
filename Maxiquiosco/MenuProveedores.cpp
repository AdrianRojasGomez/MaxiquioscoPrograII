#include <iostream>
#include "MenuProveedores.h"

using namespace std;

MenuProveedores::MenuProveedores()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuProveedores::MostrarMenu()
{
    while(_opcion != 0)
    {
        int aux;
        system("cls");
        cout << "|========= PROVEEDORES MAXIQUIOSCO =========|" << endl;
        cout << "| 1. AGREGAR PROVEEDORES" <<"                    |" << endl;
        cout << "| 2. BAJA DE PROVEEDORES" <<"                    |" << endl;
        cout << "| 3. MODIFICAR PROVEEDOR" <<"                    |" << endl;
        cout << "| 4. LISTAR PROVEEDOR POR ID" <<"                |" << endl;
        cout << "| 4. LISTAR TODOS LOS PROVEEDORES" <<"           |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR" <<"                |" << endl;
        cout << "|===========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        cin>>aux;
        setOpcion(aux);
        system("cls");

        switch(opcion)
        {
        case 1:
            //Cargar Proveedores;
            break;
        case 2:
            //Dar de Baja Proveedores;
            break;
        case 3:
            //Modificar Proveedor;
            break;
        case 4:
            //Listar proveedor POR ID
            break;
        case 5:
            //Listar todos los proveedores
            break;
        case 0:
            return 0;
        default:
            cout<<"Opcion invalida, por favor intente nuevamente."<<endl;
        }
        system("pause");
    }
}

int MenuProveedores::getOpcion()
{
    return _opcion;
}
void MenuProveedores::setOpcion(int opcion)
{
    _opcion = opcion;
}
