#include <iostream>
#include <string>
#include <cstring>
#include "TipoProducto.h"

using namespace std;

TipoProducto::TipoProducto() {
    _idTipoProducto = 0;
    strcpy(_clasificacionProducto, "");
}

TipoProducto::TipoProducto(int id, const char* clasificacion) {
    _idTipoProducto = id;
    strncpy(_clasificacionProducto, clasificacion, sizeof(_clasificacionProducto) - 1);
    _clasificacionProducto[sizeof(_clasificacionProducto) - 1] = '\0'; // Asegurar terminación nula
}

void TipoProducto::setIdTipoProducto(int id) {
    _idTipoProducto = id;
}

int TipoProducto::getIdTipoProducto() const {
    return _idTipoProducto;
}

const char* TipoProducto::getClasificacionProducto() const {
    return _clasificacionProducto;
}

void TipoProducto::mostrarTipo() const {
    cout << "ID: " << getIdTipoProducto() << " - " << getClasificacionProducto()<< endl;
}
bool TipoProducto::esValido() const {
    return _idTipoProducto > 0;
}

