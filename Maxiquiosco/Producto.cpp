#include <iostream>
#include <cstring>
#include <cctype>
#include "Producto.h"

using namespace std;

Producto::Producto() {
    _idProducto = 0;
    _stockActual = 0;
    _stockMax = 0;
    strcpy(_nombreProducto, "");
    _precioUnitario = 0.0;
    _estado = false;
}

Producto::Producto(int id, const char* nombre, TipoProducto tipo, float precio, int stock, int stockMax, bool estado) {
    _idProducto = id;
    setNombreProducto(nombre);
    _tipoProducto = tipo;
   setPrecioUnitario(precio);
    setStockActual(stock);
    _stockMax = stockMax;
       _estado = estado;
}

void Producto::setIdProducto(int id) { _idProducto = id; }

bool Producto::setNombreProducto(const char* nombre) {

    if (nombre == nullptr || strlen(nombre) == 0 || isspace(nombre[0])) /// isspace valida que el primer caracter no sea espacio
        {
        return false;
        }
        strncpy(_nombreProducto, nombre, sizeof(_nombreProducto));
        return true;
}

void Producto::setTipoProducto(TipoProducto tipo) { _tipoProducto = tipo; }

bool Producto::setPrecioUnitario(float precio) {

    if (precio <= 0)
        return false;
    _precioUnitario = precio;
    return true;
}
bool Producto::setStockActual(int stock) {

    if (stock < 0 || stock > _stockMax)
        return false;
    _stockActual = stock;
    return true;
}

void Producto::setStockMax(int stockMax) { _stockMax = stockMax; }

void Producto::setEstado(bool estado) { _estado = estado; }

int Producto::getIdProducto() const { return _idProducto; }
const char* Producto::getNombreProducto() const { return _nombreProducto; }
TipoProducto Producto::getTipoProducto() const { return _tipoProducto; }
float Producto::getPrecioUnitario() const { return _precioUnitario; }
int Producto::getStockActual() const { return _stockActual; }
int Producto::getStockMax() const { return _stockMax; }
bool Producto::getEstado() const { return _estado; }

void Producto::mostrarProducto() const {
    cout << "ID Producto: " << _idProducto <<endl;
    cout << "Nombre: " << _nombreProducto <<endl;
    cout << "Categoria de Producto ";
    _tipoProducto.mostrarTipo();
    cout << "Precio Unitario: $" << _precioUnitario <<endl;
    cout << "Stock Actual: " << _stockActual << "/  Stock Maximo: " << _stockMax <<endl;
    cout << "Estado: " << (_estado ? "Activo" : "Inactivo") <<endl;
}
