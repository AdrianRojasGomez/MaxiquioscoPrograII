#pragma once

class MenuCompras
{
private:
    int _opcion;
    void setOpcion(int opcion);

public:
    MenuCompras();
    int getOpcion();
    void MostrarMenu();
};
