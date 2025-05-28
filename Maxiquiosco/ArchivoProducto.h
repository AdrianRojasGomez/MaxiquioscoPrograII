#pragma once
#include "Producto.h"

class ArchivoProducto {
private:
    const char* _nombre = "ArchivoProducto.dat";

public:
    bool guardar(const Producto& prod);
    bool listar();
    bool bajaPorID(int id);
    bool modificarPorID(int id);
    bool existeID(int id);
};

