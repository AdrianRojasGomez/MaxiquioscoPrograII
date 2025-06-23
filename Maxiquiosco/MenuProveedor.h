#pragma once

class MenuProveedor
{
private:
    int _opcion;
    void setOpcion(int opcion);

public:
    MenuProveedor();
    int getOpcion();
    void MostrarMenu();
};
