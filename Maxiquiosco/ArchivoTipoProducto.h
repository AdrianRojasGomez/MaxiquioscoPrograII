#pragma once
#include "ArchivoBase.h"
#include "TipoProducto.h"

class ArchivoTipoProducto : public ArchivoBase
{
private:
    const char* _nombre = "TipoProductos.dat";
    void InicializarArchivo();
    void ObtenerTipos(TipoProducto tipos[]);

public:
    ArchivoTipoProducto();
    bool ListarResistros();

    bool ExisteID(int ID);
    TipoProducto BuscarRegistroPorID(int ID);


};
