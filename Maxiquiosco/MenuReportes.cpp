#include <iostream>
#include <string>
#include "MenuReportes.h"
#include "FuncionesReportes.h"
#include "ValidadorInputs.h"

using namespace std;

MenuReportes::MenuReportes()
{
    setOpcion(-1);
    MostrarMenu();
}

void MenuReportes::setOpcion(int opcion)
{
    _opcion = opcion;
}

int MenuReportes::getOpcion()
{
    return _opcion;
}

void MenuReportes::MostrarMenu()
{
    FuncionesReportes manager;
    do
    {
string input;
        system("cls");
        cout << "|========== REPORTES  MAXIQUIOSCO =============|" << endl;
        cout << "| 1. COMPRAS TOTALES POR PROVEEDOR             |" << endl;
        cout << "| 2. COMPRAS POR TIPO DE PRODUCTO              |" << endl;
        cout << "| 3. DISTRIBUCION MENSUAL DE COMPRAS           |" << endl;
        cout << "| 4. VALOR TOTAL DEL INVENTARIO                |" << endl;
        cout << "| 5. SOBRESTOCK                                |" << endl;
        cout << "| 0. VOLVER AL MENU ANTERIOR                   |" << endl;
        cout << "|==============================================|" << endl;
        cout << "\nSelecciona una opcion: ";
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
            manager.MostrarComprasTotalesPorProveedor();
            break;
        case 2:
            manager.MostrarComprasPorTipoDeProducto();
            break;
        case 3:
            manager.MostrarDistribucionMensualDeCompras();
            break;
        case 4:
            manager.MostrarValorTotalDelInventario();
            break;
        case 5:
            manager.MostrarSobreStock();
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



