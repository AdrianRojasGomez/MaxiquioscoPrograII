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
    strncpy(_clasificacionProducto, clasificacion, sizeof(_clasificacionProducto));
}

void TipoProducto::setIdTipoProducto(int id) { _idTipoProducto = id; }
void TipoProducto::setClasificacionProducto(const char* clasificacion) {
    strncpy(_clasificacionProducto, clasificacion, sizeof(_clasificacionProducto));
}

int TipoProducto::getIdTipoProducto() const { return _idTipoProducto; }
const char* TipoProducto::getClasificacionProducto() const { return _clasificacionProducto; }

void TipoProducto::mostrarTipo() const {
    cout << getClasificacionProducto() << " (ID: " << getIdTipoProducto() << ")" << endl;
}
