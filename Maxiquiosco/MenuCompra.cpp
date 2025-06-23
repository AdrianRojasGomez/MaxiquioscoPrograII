#include <iostream>
#include <string>
#include "MenuCompra.h"
#include "FuncionesCompra.h"
#include "ValidadorInputs.h"

using namespace std;

MenuCompra::MenuCompra()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuCompra::setOpcion(int opcion)
{
    _opcion = opcion;
}

int MenuCompra::getOpcion()
{
    return _opcion;
}

void MenuCompra::MostrarMenu()
{
    FuncionesCompra manager;
    do
    {
        string aux;
        system("cls");
        cout << "|========== COMPRAS   MAXIQUIOSCO =========|" << endl;
        cout << "| 1. AGREGAR COMPRAS"   <<"                     |" << endl;
        cout << "| 2. BAJA DE COMPRAS"   <<"                     |" << endl;
        cout << "| 3. MODIFICAR COMPRAS"   <<"                   |" << endl;
        cout << "| 4. LISTAR COMPRAS"   <<"                      |" << endl;
        cout << "| 5. LISTAR COMPRAS POR ID" <<"                 |" << endl;
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
            manager.AgregarCompra();
            system("pause");
            break;

        case 2:
            manager.BajaCompra();
            break;
        case 3:
            manager.ModificarCompra();
            system("pause");
            break;
        case 4:
            manager.ListarCompra();
            system("pause");
            break;
        case 5:
            manager.ListarCompraPorID();
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
