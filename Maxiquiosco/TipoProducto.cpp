#include <iostream>
#include <cstring>
#include "TipoProducto.h"

using namespace std;

TipoProducto::TipoProducto() {
    _idTipoProducto = 0;
    strcpy(_clasificacionProducto, "");
}

TipoProducto::TipoProducto(int id, const char* clasificacion)
{
    _idTipoProducto = id;
    strcpy(_clasificacionProducto, clasificacion);
}

void TipoProducto::setIDTipoProducto(int id)
{
    _idTipoProducto = id;
}

int TipoProducto::getIDTipoProducto() const
{
    return _idTipoProducto;
}

int TipoProducto::getTamTipoProducto() const
{
    return _tamTipoProducto;
}

const char* TipoProducto::getClasificacionProducto() const
{
    return _clasificacionProducto;
}

bool TipoProducto::EsValido() const
{
    return _idTipoProducto > 0;
}

void TipoProducto::MostrarTipoProductoEnConsola() const
{
    cout << "ID: " << getIDTipoProducto() << " - " << getClasificacionProducto()<< endl;
}
