#pragma once

class MenuProducto
{
private:
    int _opcion;
    void setOpcion(int opcion);

public:
    MenuProducto();
    int getOpcion();
    void MostrarMenu();
};
