#pragma once
#include "ArchivoBase.h"
#include "Producto.h"

class ArchivoProducto : public ArchivoBase
{
private:
    const char* _nombre = "ArchivoProducto.dat";

public:
    ArchivoProducto();

    ///ABML
    bool AgregarRegistro(Producto& prod);
    bool BajaRegistro(int ID);
    bool ModificarRegistroPorID(int ID);
    bool ModificarStockporCompra(int ID, int cantidadComprada);
    bool ListarRegistroPorID(int ID);
    bool ListarRegistros();
    bool ListarProducto();

    ///Operacion Interna
    int ObtenerProximoID();
    bool ExisteID(int ID);

    ///Operacion Para Compras
    Producto BuscarRegistroPorID(int ID);

    ///Operaciones para Reportes
    int ObtenerObjetosTotales();
    int ObtenerValorDelInventarioActual();
    void MostrarProductoConSobreStock();

};

