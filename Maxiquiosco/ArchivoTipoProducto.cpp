#include "ArchivoTipoProducto.h"
#include <cstdio>
#include <iostream>

using namespace std;

ArchivoTipoProducto::ArchivoTipoProducto() {
    inicializarArchivo();
}

void ArchivoTipoProducto::inicializarArchivo() {
    FILE* p = fopen(_nombre, "rb");
    if (p != nullptr) {
        fclose(p);
        return;
    }

    // No existe: crear con tipos por defecto
    FILE* archivoNuevo = fopen(_nombre, "wb");
    if (archivoNuevo == nullptr) {
        cout << "Error al crear el archivo de tipos." << endl;
        return;
    }

    TipoProducto tipos[5] = {
        TipoProducto(1, "Bebidas"),
        TipoProducto(2, "Comestibles"),
        TipoProducto(3, "Lacteos"),
        TipoProducto(4, "Carnes"),
        TipoProducto(5, "Limpieza")
    };

    fwrite(tipos, sizeof(TipoProducto), 5, archivoNuevo);
    fclose(archivoNuevo);
}

bool ArchivoTipoProducto::guardar(const TipoProducto& tipo) {
       FILE* p = fopen(_nombre, "ab");
    if (p == nullptr) return false;
    fwrite(&tipo, sizeof(TipoProducto), 1, p);
    fclose(p);
    return true;
}

bool ArchivoTipoProducto::listar() {
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) {
        cout << "No se pudo abrir el archivo de tipos." << endl;
        return false;
    }
    TipoProducto tipo;
    while (fread(&tipo, sizeof(TipoProducto), 1, p) == 1) {
        if (tipo.esValido()) {
                            tipo.mostrarTipo();

        }
    }
    cout << "-------------------------" << endl;
    fclose(p);
    return true;
}

bool ArchivoTipoProducto::existeID(int id) {
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) return false;
    TipoProducto tipo;
    while (fread(&tipo, sizeof(TipoProducto), 1, p) == 1) {
        if (tipo.getIdTipoProducto() == id && tipo.esValido()) {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

TipoProducto ArchivoTipoProducto::buscarPorId(int id) {
    FILE* p = fopen(_nombre, "rb");
    TipoProducto tipo;
    if (p == nullptr) return tipo;

    while (fread(&tipo, sizeof(TipoProducto), 1, p) == 1) {
        if (tipo.getIdTipoProducto() == id && tipo.esValido()) {
            fclose(p);
            return tipo;
        }
    }
    fclose(p);
    return TipoProducto(); // Devuelve vacío
}
/*
bool ArchivoTipoProducto::modificarPorID(int id, const TipoProducto& nuevoTipo) {
    FILE* p = fopen(_nombre, "rb+");
    if (p == nullptr) return false;
    TipoProducto tipo;
    int pos = 0;

    while (fread(&tipo, sizeof(TipoProducto), 1, p) == 1) {
        if (tipo.getIdTipoProducto() == id && tipo.esValido()) {
            fseek(p, pos * sizeof(TipoProducto), SEEK_SET);
            fwrite(&nuevoTipo, sizeof(TipoProducto), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }
    fclose(p);
    return false;
}*/
/*
bool ArchivoTipoProducto::bajaPorID(int id) {
    FILE* p = fopen(_nombre, "rb+");
    if (p == nullptr) return false;

    TipoProducto tipo;
    int pos = 0;

    while (fread(&tipo, sizeof(TipoProducto), 1, p) == 1) {
        if (tipo.getIdTipoProducto() == id && tipo.esValido()) {
            tipo.setIdTipoProducto(0); // Marcar como eliminado
            fseek(p, pos * sizeof(TipoProducto), SEEK_SET);
            fwrite(&tipo, sizeof(TipoProducto), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }

    fclose(p);
    return false;
}
*/
