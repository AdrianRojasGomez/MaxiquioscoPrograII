#pragma once

class MenuReportes
{
private:
    int _opcion;
    void setOpcion(int opcion);

public:
    MenuReportes();
    int getOpcion();
    void MostrarMenu();
};
