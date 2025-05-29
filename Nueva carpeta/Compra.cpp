#include <iostream>
#include <cstring>
#include <string>
#include "Compra.h"


using namespace std;

Compra::Compra() {
    _idCompra = 0;
    _idProducto = 0;
    _idProveedor = 0;
    _cantidadComprada = 0;
    _fechaCompra = Fecha();
    _importeTotal = 0;
}

Compra::Compra(int idCompra, int idProducto, int idProveedor, int cantidad, Fecha fecha, float precioUnitario) {
    _idCompra = idCompra;
    _idProducto = idProducto;
    _idProveedor = idProveedor;
    _cantidadComprada = cantidad;
    _fechaCompra = fecha;
    _importeTotal = precioUnitario * cantidad;
}

    void Compra::setIdCompra(int idCompra) {
        _idCompra = idCompra;
        }
    void Compra::setFechaCompra(Fecha fecha) {
        _fechaCompra = fecha;
        }
    void Compra::setIdProducto(int idProducto) {
        _idProducto = idProducto;
        }
    void Compra::setIdProveedor(int idProveedor) {
        _idProveedor = idProveedor;
        }
    void Compra::setCantidadComprada(int cantidad) {
        _cantidadComprada = cantidad;
        }

    int Compra::getIdCompra() const {
    return _idCompra;
}

    Fecha Compra::getFechaCompra() const {
    return _fechaCompra;
}

    int Compra::getIdProducto() const {
    return _idProducto;
}

    int Compra::getIdProveedor() const {
    return _idProveedor;
}

    int Compra::getCantidadComprada() const {
    return _cantidadComprada;
}

    float Compra::getImporteTotal() const {
    return _importeTotal;
}
void Compra::cargarCompra() {
    cout << "Ingrese Id de comprobante de la compra: ";
    cin >> _idCompra;

    cout << "Ingrese fecha de la compra: ";
    ;
///aca iria cargarFecha()
    cout << "Ingrese Id del producto: ";
    cin >> _idProducto;

    cout << "Ingrese Id del proveedor: ";
    cin >> _idProveedor;

    cout << "Ingrese cantidad commprada del producto: ";
    cin >> _cantidadComprada;

    cout << "Importe total: ";
    cin >> _importeTotal;
}

void Compra::mostrarCompra() const {
    cout << "ID de la compra: " << _idCompra << endl;
    cout << "ID del producto: " << _idProducto << endl;
    cout << "ID del proveedor: " << _idProveedor << endl;
    cout << "Cantidad comprada: " << _cantidadComprada << endl;
    cout << "Fecha de la compra: ";
    /// aca iria la funcion de mostrarFecha()
    cout << "Importe total: $" << _importeTotal << endl;
}
