#pragma once

class MenuProveedores
{
private:
        int _opcion;

public:
    MenuProveedores();

    void MostrarMenu();

    int getOpcion();
    void setOpcion(int opcion);
};

