#include <iostream>
#include <cstring>
#include <string>
#include "Compra.h"


using namespace std;

Compra::Compra()
{
    _IDCompra = 0;
    _producto = Producto();
    _proveedor = Proveedor();
    _cantidadComprada = 0;
    _fechaCompra = Fecha();
    _importe = 0.0f;
    _estado = true;

}

Compra::Compra(int IDCompra, Producto producto, Proveedor proveedor, int cantidadComprada,
Fecha fecha, float importe, bool estado)
{
    setIDCompra(IDCompra);
    setProducto(producto);
    setProveedor(proveedor);
    setCantidadComprada(cantidadComprada);
    setFechaCompra(fecha);
    setImporte(importe);
    setEstado(estado);
}

void Compra::MostrarCompraEnConsola() const
{
    cout << "ID Compra: " << _IDCompra << endl;
    _producto.MostrarProducto();

    cout << "Cantidad Comprada: " << getCantidadComprada() << endl;

    _proveedor.MostrarProveedor();
    cout << "Fecha de la compra: " << _fechaCompra.getDia() << "/"
    << _fechaCompra.getMes() << "/" << _fechaCompra.getAnio() << endl;
    cout << "Importe de la Compra: " << _importe << endl;
}

void Compra::setIDCompra(int IDCompra)
{
    _IDCompra = IDCompra;
}
void Compra::setFechaCompra(Fecha fecha)
{
    _fechaCompra = fecha;
}

Fecha Compra::getFechaCompra() const
{
    return _fechaCompra;
}

void Compra::setCantidadComprada(int cantidad)
{
    _cantidadComprada = cantidad;
}

int Compra::getCantidadComprada() const
{
    return _cantidadComprada;
}

void Compra::setEstado(bool estado)
{
    _estado = estado;
}

void Compra::setImporte(float importe)
{
    _importe = importe;
}

int Compra::getIDCompra() const
{
    return _IDCompra;
}

float Compra::getImporte() const
{
    return _importe;
}

bool Compra::getEstado() const
{
    return _estado;
}
void Compra::setProducto(Producto producto)
{
    _producto = producto;
}

Producto Compra::getProducto()
{
    return _producto;
}

void Compra::setProveedor(Proveedor proveedor)
{
    _proveedor = proveedor;
}

Proveedor Compra::getProveedor()
{
    return _proveedor;
}
