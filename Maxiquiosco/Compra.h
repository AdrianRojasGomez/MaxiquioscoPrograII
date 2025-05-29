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
    bool _estado;

public:
    Compra();
    Compra(int idCompra, int idProducto, int idProveedor, int cantidad, Fecha fecha, float precioUnitario);

    void setIdCompra(int idCompra);
    void setFechaCompra(Fecha fecha);
    Fecha getFechaCompra() const;
    void setIdProducto(int idProducto);
    void setIdProveedor(int idProveedor);
    void setCantidadComprada(int cantidad);
    void setEstado(bool estado);
    void setImporteTotal(float importeTotal);

    int getIdCompra() const;
    int getIdProducto() const;
    int getIdProveedor() const;
    int getCantidadComprada() const;
    float getImporteTotal() const;
    bool getEstado() const;

    void cargarCompra();
    void mostrarCompra() const;
};
