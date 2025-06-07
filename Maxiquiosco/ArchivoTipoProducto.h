#pragma once
#include "TipoProducto.h"

class ArchivoTipoProducto {
private:
    const char* _nombre = "tipos_productos.dat";
    void inicializarArchivo();

public:
    ArchivoTipoProducto();

    bool guardar(const TipoProducto& tipo);
    bool listar();
    bool existeID(int id);
    TipoProducto buscarPorId(int id);
   /// bool modificarPorID(int id, const TipoProducto& nuevoTipo);
    ///bool bajaPorID(int id);
};
