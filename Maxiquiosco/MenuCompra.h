#pragma once

class MenuCompra
{
private:
    int _opcion;
    void setOpcion(int opcion);

public:
    MenuCompra();
    int getOpcion();
    void MostrarMenu();
};
