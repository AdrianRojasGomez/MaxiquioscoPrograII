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
    void BajaRegistroPorID(int ID);
    void ModificarRegistroPorID(int ID);
    void ListarRegistroPorID(int ID);
    void ListarRegistros();

};

