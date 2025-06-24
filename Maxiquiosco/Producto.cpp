#include <iostream>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"

using namespace std;

Producto::Producto()
{
    _idProducto = 0;
    _stockActual = 0;
    _stockMax = 0;
    strcpy(_nombreProducto, "");
    _precioUnitario = 0.0f;
    _estado = false;
}

Producto::Producto(int ID, int stockActual, int stockMax,
                   const char *nombre, TipoProducto tipo, float precio, bool estado)
{
    setIDProducto(ID);
    setStockActual(stockActual);
    setStockMax(stockMax);
    setNombreProducto(nombre);
    setTipoProducto(tipo);
    setPrecioUnitario(precio);
    setEstado(estado);
}

void Producto::setIDProducto(int ID)
{
    _idProducto = ID;
}

void Producto::setStockActual(int stock)
{
    _stockActual = stock;
}

void Producto::setStockMax(int stockMax)
{
    _stockMax = stockMax;
}

void Producto::setNombreProducto(const char* nombre)
{
    if(nombre == nullptr)
    {
        cout << "Error: El nombre Ingresado es nulo, verifique el ingreso." << endl;
        return;
    }
    ///Como _nombreProducto es un array fijo. Un caracter ocupa 1 byte.
    else if (strlen(nombre) >= sizeof(_nombreProducto))
    {
        cout << "Error: El nombre Ingresado es muy grande, verifique el ingreso.." << endl;
        return;
    }
    strcpy(_nombreProducto, nombre);
}

void Producto::setTipoProducto(TipoProducto tipo)
{
    _tipoProducto = tipo;
}

void Producto::setPrecioUnitario(float precio)
{
    if (precio <= 0)
    {
        cout << "Error: El precio es menor o igual a 0, verifique el ingreso." << endl;
        return;
    }
    _precioUnitario = precio;
}

void Producto::setEstado(bool estado)
{
    _estado = estado;
}

void Producto::MostrarProductoEnConsola() const
{
    cout << "ID Producto: " << _idProducto <<endl;
    cout << "Nombre: " << _nombreProducto <<endl;
    cout << "Categoria de Producto ";
    _tipoProducto.MostrarTipoProductoEnConsola();
    cout << "Precio Unitario: $" << _precioUnitario <<endl;
    cout << "Stock Actual: " << _stockActual << "/  Stock Maximo: " << _stockMax <<endl;
    if (_estado)
        cout << "Activo"<<endl;
    else
        cout << "Dado de baja"<<endl;
}

int Producto::getStockMax() const
{
    return _stockMax;
}

int Producto::getIDProducto() const
{
    return _idProducto;
}

TipoProducto Producto::getTipoProducto() const
{
    return _tipoProducto;
}
const char* Producto::getNombreProducto() const
{
    return _nombreProducto;
}
float Producto::getPrecioUnitario() const
{
    return _precioUnitario;
}
bool Producto::getEstado() const
{
    return _estado;
}

int Producto::getTAMANO_NOMBRE() const
{
    return TAMANO_NOMBRE;
}

int Producto::getStockActual() const
{
    return _stockActual;
}
