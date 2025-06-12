#pragma once
#include "Compra.h"

class ArchivoCompras
{
private:
    char _nombreArchivo[50];
    int _tamanoRegistro;

public:
    ArchivoCompras();

    bool AgregarRegistro(Compra compra);
    void BajaRegistroPorID(int ID);
    void ModificarRegistroPorID(int ID);
    Compra BuscarRegistroPorID (int ID);
    void ListarRegistroPorID(int ID);
    void ListarRegistros();

};
