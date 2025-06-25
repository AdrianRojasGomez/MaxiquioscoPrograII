#include <iostream>
#include "FuncionesReportes.h"
#include "Compra.h"
#include "Proveedor.h"
#include "Producto.h"
#include "ArchivoCompra.h"
#include "ArchivoProveedor.h"
#include "ArchivoProducto.h"

using namespace std;

void FuncionesReportes::MostrarValorTotalDelInventario()
{
    Producto producto;
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

