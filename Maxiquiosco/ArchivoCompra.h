#pragma once
#include "ArchivoBase.h"
#include "Compra.h"

class ArchivoCompra : public ArchivoBase
{
private:
    const char* _nombre = "ArchivoCompra.dat";

public:
    ArchivoCompra();

    ///ABML
    bool AgregarRegistro(Compra compra);
    bool BajaRegistro(int ID);
    bool ModificarRegistroPorID(int ID);
    bool ListarRegistroPorID(int ID);
    bool ListarRegistros();

    ///Operacion Interna
    int ObtenerProximoID();
    bool ExisteID(int ID);

    ///Operacion Para Compras
    Compra BuscarRegistroPorID (int ID);
    bool ObtenerTotalUnidadesconFacturado();
    ///Operacion para Registros
    int ObtenerImporteTotalPorMes(int mes, int anio);
    int FiltrarComprasPorTipoProducto(int IDbusqueda, Compra* &comprasFiltradas);

};
