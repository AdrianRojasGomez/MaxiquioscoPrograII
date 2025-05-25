#pragma once

#include "Fecha.h"

class Compra {
private:
    int _idCompra;
    Fecha _fechaCompra;
    int _idProducto;
    int _idProveedor;
    int _cantidadComprada;
    float _importeTotal;

public:
    Compra();
    Compra(int idCompra, int idProducto, int idProveedor, int cantidad, Fecha fecha, float precioUnitario);

    void setIdCompra(int idCompra);
    void setFechaCompra(Fecha fecha);
    void setIdProducto(int idProducto);
    void setIdProveedor(int idProveedor);
    void setCantidadComprada(int cantidad);

    int getIdCompra() const;
    Fecha getFechaCompra() const;
    int getIdProducto() const;
    int getIdProveedor() const;
    int getCantidadComprada() const;
    float getImporteTotal() const;

    void cargarCompra();
    void mostrarCompra() const;
};
