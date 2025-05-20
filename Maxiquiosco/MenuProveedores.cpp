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
        cout << "| 3. MODIFICAR PROVEEDORES" <<"                  |" << endl;
        cout << "| 4. LISTAR PROVEEDORES" <<"                     |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR" <<"                |" << endl;
        cout << "|===========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        cin>>aux;
        setOpcion(aux);
        system("cls");
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
