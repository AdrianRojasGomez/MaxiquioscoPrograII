#include <iostream>
#include <string>
#include "MenuProveedor.h"
#include "FuncionesProveedor.h"
#include "ValidadorInputs.h"

using namespace std;

MenuProveedor::MenuProveedor()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuProveedor::setOpcion(int opcion)
{
    _opcion = opcion;
}

int MenuProveedor::getOpcion()
{
    return _opcion;
}

void MenuProveedor::MostrarMenu()
{
    FuncionesProveedor manager;
    do
    {
        string aux;
        system("cls");
        cout << "|========== PROVEEDOR MAXIQUIOSCO =========|" << endl;
        cout << "| 1. AGREGAR PROVEEDOR" <<"                     |" << endl;
        cout << "| 2. BAJA DE PROVEEDOR" <<"                     |" << endl;
        cout << "| 3. MODIFICAR PROVEEDOR" <<"                   |" << endl;
        cout << "| 4. LISTAR PROVEEDORES" <<"                    |" << endl;
        cout << "| 5. LISTAR PROVEEDOR POR ID" <<"               |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR" <<"               |" << endl;
        cout << "|==========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        cin >> aux;

        if(!ValidadorInputs::EsUnDigito(aux))
        {
            _opcion = -1;
            system("Pause");
            continue;
        }
        int auxNumero = stoi(aux);
        setOpcion(auxNumero);

        switch(_opcion)
        {
        case 1:
            manager.AgregarProveedor();
            system("pause");
            break;

        case 2:
            manager.BajaProveedor();
            break;
        case 3:
            manager.ModificarRegistro();
            system("pause");
            break;
        case 4:
            manager.ListarProveedores();
            system("pause");
            break;
        case 5:
            manager.ListarProveedorPorID();
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
