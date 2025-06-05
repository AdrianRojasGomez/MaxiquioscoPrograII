#include <iostream>
#include "MenuProducto.h"
#include "FuncionesProducto.h"

using namespace std;

MenuProducto::MenuProducto()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuProducto::MostrarMenu()
{
    FuncionesProducto funciones;
    while(_opcion != 0)
    {
        int aux;
        system("cls");
        cout << "|========== PRODUCTOS MAXIQUIOSCO =========|" << endl;
        cout << "| 1. AGREGAR PRODUCTOS" <<"                     |" << endl;
        cout << "| 2. BAJA DE PRODUCTOS" <<"                     |" << endl;
        cout << "| 3. MODIFICAR PRODUCTOS" <<"                   |" << endl;
        cout << "| 4. LISTAR PRODUCTOS" <<"                      |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR" <<"               |" << endl;
        cout << "|==========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        cin >> aux;
        setOpcion(aux);
        system("cls");

        switch (_opcion) {
            case 1:
                funciones.agregarProducto();
                system("pause");
                break;
            case 2:
                funciones.bajaProductoPorID();
                system("pause");
                break;
            case 3:
                funciones.modificarProductoPorID();
                system("pause");
                break;
            case 4:
               funciones.listarProductos();
                system("pause");
                break;
            case 0:
                break;
            default:
                cout << "Opción inválida." << endl;
                system("pause");
                break;
        }
    }
}

int MenuProducto::getOpcion()
{
    return _opcion;
}

void MenuProducto::setOpcion(int opcion)
{
    _opcion = opcion;
}
