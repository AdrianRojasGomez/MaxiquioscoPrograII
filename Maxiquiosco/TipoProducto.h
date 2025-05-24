#pragma once

#include <string>

class TipoProducto {
private:
    int _idTipoProducto;
    char _clasificacionProducto[20];

public:
    TipoProducto();
    TipoProducto(int id, const char* clasificacion);

    void setIdTipoProducto(int id);
    void setClasificacionProducto(const char* clasificacion);

    int getIdTipoProducto() const;
    const char* getClasificacionProducto() const;

    void mostrarTipo() const;
};

