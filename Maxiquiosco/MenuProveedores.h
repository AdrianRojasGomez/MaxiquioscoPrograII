#pragma once
#include "FuncionesProveedor.h"

class MenuProveedores
{
private:
        int _opcion;
        FuncionesProveedor _objFunciones;

public:
    MenuProveedores();

    void MostrarMenu();

    int getOpcion();
    void setOpcion(int opcion);
};

