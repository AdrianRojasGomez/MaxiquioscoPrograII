#include <iostream>
#include <string>
#include "MenuProducto.h"
#include "FuncionesProducto.h"
#include "ValidadorInputs.h"

using namespace std;

MenuProducto::MenuProducto()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuProducto::setOpcion(int opcion)
{
    _opcion = opcion;
}

int MenuProducto::getOpcion()
{
    return _opcion;
}

void MenuProducto::MostrarMenu()
{
    FuncionesProducto manager;
    do
    {
        string input;
        system("cls");
        cout << "|========== PRODUCTOS MAXIQUIOSCO =========|" << endl;
        cout << "| 1. AGREGAR PRODUCTOS" <<"                     |" << endl;
        cout << "| 2. BAJA DE PRODUCTOS" <<"                     |" << endl;
        cout << "| 3. MODIFICAR PRODUCTOS" <<"                   |" << endl;
        cout << "| 4. LISTAR PRODUCTOS" <<"                      |" << endl;
        cout << "| 5. LISTAR PRODUCTOS POR ID" <<"               |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR" <<"               |" << endl;
        cout << "|==========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        getline(cin,input);
        if(!ValidadorInputs::EsUnDigito(input))
        {
            _opcion = -1;
            system("Pause");
            continue;
        }
        int opcion = stoi(input);
        setOpcion(opcion);

        switch(_opcion)
        {
        case 1:
            manager.AgregarProducto();
            system("pause");
            break;

        case 2:
            manager.BajaProducto();
            system("pause");
            break;
        case 3:
            manager.ModificarProducto();
            system("pause");
            break;
        case 4:
            manager.ListarProducto();
            system("pause");
            break;
        case 5:
            manager.ListarProductoPorID();
            system("pause");
            break;
        case 0:
            break;
        default:
            cout << "Opcion Invalida." << endl;
            system("pause");
            break;
        }
    }
    while (_opcion != 0);

}


