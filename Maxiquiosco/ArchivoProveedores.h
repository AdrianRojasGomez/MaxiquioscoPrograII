#pragma once
#include "Proveedor.h"

class ArchivoProveedores
{
private:
    char _nombreArchivo[50];
    int _tamanoRegistro;


public:

    ArchivoProveedores();

    bool AgregarRegistro(Proveedor proveedor);
    void ListarRegistros();

};

