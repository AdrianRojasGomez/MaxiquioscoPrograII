#pragma once

class MenuProducto
{
private:
        int _opcion;

public:
    MenuProducto();

    void MostrarMenu();

    int getOpcion();
    void setOpcion(int opcion);
};

