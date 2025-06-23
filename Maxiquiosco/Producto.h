#pragma once
#include <cstring>
#include "TipoProducto.h"

class Producto
{
public:
    Producto();
    Producto(int ID, int stockActual, int stockMax,
             const char *nombre, TipoProducto tipo, float precio, bool estado);

    void setIDProducto(int id);
    void setStockActual(int stock);
    void setStockMax(int stockMax);
    void setNombreProducto(const char* nombre);
    void setTipoProducto(TipoProducto tipo);
    void setPrecioUnitario(float precio);

    int getTAMANO_NOMBRE() const;
    int getIDProducto() const;
    int getStockActual() const;
    int getStockMax() const;
    TipoProducto getTipoProducto() const;
    const char* getNombreProducto() const;
    float getPrecioUnitario() const;
    bool getEstado() const;
    void setEstado(bool estado);

    void MostrarProductoEnConsola() const;

    static const int TAMANO_NOMBRE = 50;
private:
    int _idProducto;
    int _stockActual;
    int _stockMax;
    char _nombreProducto[TAMANO_NOMBRE];
    TipoProducto _tipoProducto;
    float _precioUnitario;
    bool _estado;


};
