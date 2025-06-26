#include <iostream>
#include <string>
#include "FuncionesReportes.h"
#include "Compra.h"
#include "Proveedor.h"
#include "Producto.h"
#include "ArchivoCompra.h"
#include "ArchivoProveedor.h"
#include "ArchivoProducto.h"
#include "ValidadorInputs.h"

using namespace std;

FuncionesReportes::FuncionesReportes()
{
    _meses[0] = "Enero";
    _meses[1] = "Febrero";
    _meses[2] = "Marzo";
    _meses[3] = "Abril";
    _meses[4] = "Mayo";
    _meses[5] = "Junio";
    _meses[6] = "Julio";
    _meses[7] = "Agosto";
    _meses[8] = "Septiembre";
    _meses[9] = "Octubre";
    _meses[10] = "Noviembre";
    _meses[11] = "Diciembre";
}

void FuncionesReportes::MostrarComprasTotalesPorProveedor()
{
    ArchivoCompra archivoCompra;

    archivoCompra.ObtenerTotalUnidadesconFacturado();
}

void FuncionesReportes::MostrarComprasPorTipoDeProducto()
{


}
void FuncionesReportes::MostrarDistribucionMensualDeCompras()
{
    ArchivoCompra archivoCompra;
    string input;
    int anio;
    const int meses = 12;
    int compras[meses];

    cout << "Indique el Anio del que quiere el reporte" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::AnioValido(input))
    {
        cout << "Ingrese un anio valido" << endl;
        return;
    }
    anio = stoi(input);
    int total = 0;
    int importeMayor = 0;
    for(int i = 0; i < meses; i++)
    {
        compras[i] = archivoCompra.ObtenerImporteTotalPorMes(i+1,anio);
        total += compras[i];
    }

    if(total == 0)
    {
        cout << "=====================================" << endl;
        cout << "NO SE REPORTARON COMPRAS ESTE AÑO" << endl;
        cout << "INTENTE CON OTRO AÑO"                 << endl;
        cout << "=====================================" << endl;
        system("Pause");
        return;
    }

    for (int i = 0; i < meses; i++)
    {
        if(i == 0 || compras[i] > importeMayor)
        {
            importeMayor = compras[i];
        }
    }
    const int anchoBarra = 40;
    const int anchoMes = 12;

    for (int i = 0; i < meses; i++)
    {
        string mes = _meses[i];
        int largoMes = mes.length();
        int espacios = anchoMes - largoMes;
        cout << mes;

        for (int e = 0; e < espacios; e++)
            cout << " ";

        cout << ": [";

        int bloques = (compras[i] * anchoBarra) / importeMayor;
        int vacios = anchoBarra - bloques;

        for (int j = 0; j < bloques; j++)
            cout << "=";
        for (int j = 0; j < vacios; j++)
            cout << " ";

        cout << "]   $" << compras[i] << endl << endl;
    }
    system("pause");

}

void FuncionesReportes::MostrarValorTotalDelInventario()
{
    ArchivoProducto archivoProducto;
    int objetosTotales = archivoProducto.ObtenerObjetosTotales();
    int valorInventario = archivoProducto.ObtenerValorDelInventarioActual();

    cout << "=================================" << endl;
    cout << "El valor total del inventario es de :$";
    cout << valorInventario << "." << endl;
    cout << "En el inventario hay un total de " << objetosTotales << " objetos." << endl;
    cout << "=================================" << endl;
    system("Pause");

}

void FuncionesReportes::MostrarSobreStock()
{
    ArchivoProducto archivoProducto;

    archivoProducto.MostrarProductoConSobreStock();
}
