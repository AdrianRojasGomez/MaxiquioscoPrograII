#pragma once
#include "Fecha.h"
#include "Producto.h"
#include "Proveedor.h"

class Compra
{
public:
    Compra();
    Compra(int IDCompra, Producto producto, Proveedor proveedor,
    int cantidadComprada, Fecha fecha, float importe, bool estado);

    void setIDCompra(int idCompra);
    void setFechaCompra(Fecha fecha);
    Fecha getFechaCompra() const;

    void setCantidadComprada(int cantidad);
    void setEstado(bool estado);
    void setImporte(float importe);

    int getIDCompra() const;

    int getCantidadComprada() const;
    float getImporte() const;
    bool getEstado() const;

    void setProducto(Producto producto);
    Producto getProducto();
    void setProveedor(Proveedor proveedor);
    Proveedor getProveedor();

    void MostrarCompraEnConsola() const;

    static const int TAMANO_CAMPO = 20;

private:
    int _IDCompra;
    Fecha _fechaCompra;
    Producto _producto;
    Proveedor _proveedor;
    int _cantidadComprada;
    float _importe;
    bool _estado;

};

