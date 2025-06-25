#include <iostream>
#include "MenuCompra.h"
#include "MenuProducto.h"
#include "MenuProveedor.h"
#include "MenuReportes.h"
#include "ValidadorInputs.h"

using namespace std;

int main()
{
    string input;
    int opcion = -1;
    while(opcion != 0)
    {
        system("cls");
        cout << "|===========  MENU MAXIQUIOSCO  ===========|" << endl;
        cout << "| 1. MENU COMPRA" <<"                           |" << endl;
        cout << "| 2. MENU PRODUCTO" <<"                         |" << endl;
        cout << "| 3. MENU PROVEEDOR" <<"                        |" << endl;
        cout << "| 4. MENU REPORTES" <<"                         |" << endl;
        cout << "| 0. CERRAR PROGRAMA" <<"                       |" << endl;
        cout << "|==========================================|" << endl;
        cout << " \nSelecciona una opcion: ";
        getline(cin,input);
        if(!ValidadorInputs::EsUnDigito(input))
        {
            cout << "Ingrese una opcion valida del menu" << endl;
            opcion = -1;
            system("Pause");
            continue;
        }
        opcion = stoi(input);

        switch(opcion)
        {
        case 1:
            MenuCompra();
            break;
        case 2:
            MenuProducto();
            break;
        case 3:
            MenuProveedor();
            break;
        case 4:
            MenuReportes();
            break;
        case 0:
            return 0;
        default:
            cout<<"Opcion invalida, por favor intente nuevamente."<<endl;
        }
        system("pause");
    }
    return 0;
}
