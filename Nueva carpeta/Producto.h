#pragma once

#include <cstring>
#include "TipoProducto.h"

class Producto {
private:
    int _idProducto;
    int _stockActual;
    int _stockMax;
    char _nombreProducto[20];
    TipoProducto _tipoProducto;
    float _precioUnitario;
    bool _estado;

public:
    Producto();
    Producto(int id, const char* nombre, TipoProducto tipo, float precio, int stock, int stockMax, bool estado);

    void setIdProducto(int id);
    bool setNombreProducto(const char* nombre);
    void setTipoProducto(TipoProducto tipo);
    bool setPrecioUnitario(float precio);
    bool setStockActual(int stock);
    void setStockMax(int stockMax);
    void setEstado(bool estado);

    int getIdProducto() const;
    const char* getNombreProducto() const;
    TipoProducto getTipoProducto() const;
    float getPrecioUnitario() const;
    int getStockActual() const;
    int getStockMax() const;
    bool getEstado() const;

    void mostrarProducto() const;
};

