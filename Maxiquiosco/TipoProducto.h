#pragma once
#include <string>

class TipoProducto
{
private:
    int _idTipoProducto;
    char _clasificacionProducto[50];


public:
    TipoProducto();
    TipoProducto(int idTipoProducto, char * clasificacionProducto);
    TipoProducto(int idTipoProducto, std::string& clasificacionProducto);

    int getIdTipoProducto();
    void setIdTipoProducto(int idTipoProducto);
    char * getClasificacionProducto();
    void setClasificacionProducto (char * clasificacionProducto);
    void setClasificacionProducto (std::string& clasificacionProducto);

};


