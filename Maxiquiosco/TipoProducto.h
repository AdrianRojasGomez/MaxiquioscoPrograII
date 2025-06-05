#pragma once
#include <string>

class TipoProducto {
private:
    int _idTipoProducto, _tamTipoProducto;
    char _clasificacionProducto[30];

public:

    TipoProducto();
    TipoProducto(int id, const char* clasificacion);
    void mostrarTipo() const;
    bool esValido() const;
    bool esIgual(const TipoProducto& otro) const;

    void setIdTipoProducto(int id);
    int getIdTipoProducto() const;
    const char* getClasificacionProducto() const;

};
