#pragma once

class TipoProducto
{
private:
    int _idTipoProducto;
    int _tamTipoProducto;
    char _clasificacionProducto[50];


public:

    TipoProducto();
    TipoProducto(int id, const char* clasificacion);
    bool EsValido() const;
    void MostrarTipoProductoEnConsola() const;

    int getIDTipoProducto() const;
    void setIDTipoProducto(int id);
    int getTamTipoProducto() const;
    const char *getClasificacionProducto() const;

};

