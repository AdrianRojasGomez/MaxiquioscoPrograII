#include <iostream>
#include "MenuCompra.h"

using namespace std;

MenuCompra::MenuCompra()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuCompra::MostrarMenu(){
    while(_opcion != 0)
    {
        int aux;
        system("cls");
        cout << "|=========== COMPRAS MAXIQUIOSCO ==========|" << endl;
        cout << "| 1. AGREGAR COMPRA" <<"                        |" << endl;
        cout << "| 2. BAJA DE COMPRA" <<"                        |" << endl;
        cout << "| 3. MODIFICAR COMPRA" <<"                      |" << endl;
        cout << "| 4. LISTAR COMPRAS" <<"                        |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR" <<"               |" << endl;
        cout << "|==========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        cin>>aux;
        setOpcion(aux);
        system("cls");

         switch (_opcion) {
            case 1:
                agregarCompra();
                system("pause");
                break;
            case 2:
                bajaCompraPorID();
                break;
            case 3:
                modificarCompraPorID();
                break;
            case 4:
                listarCompras();
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

int MenuCompra::getOpcion()
{
    return _opcion;
}
void MenuCompra::setOpcion(int opcion)
{
    _opcion = opcion;
}
