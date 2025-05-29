#include "ArchivoProducto.h"
#include <cstdio>
#include <iostream>

bool ArchivoProducto::guardar(const Producto& prod) {
    FILE* p = fopen(_nombre, "ab");
    if (p == nullptr) return false;
    fwrite(&prod, sizeof(Producto), 1, p);
    fclose(p);
    return true;
}

bool ArchivoProducto::listar() {
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) {
        std::cout << "No se pudo abrir el archivo." << std::endl;
        return false;
    }
    Producto prod;
    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getEstado()) {
            prod.mostrarProducto();
            std::cout << "---------------------" << std::endl;
        }
    }
    fclose(p);
    return true;
}

bool ArchivoProducto::existeID(int id) {
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) return false;
    Producto prod;
    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getIdProducto() == id && prod.getEstado()) {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

bool ArchivoProducto::bajaPorID(int id) {
    FILE* p = fopen(_nombre, "rb+");
    if (p == nullptr) return false;

    Producto prod;
    long pos = 0;
    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getIdProducto() == id && prod.getEstado()) {
            prod.setEstado(false);
            fseek(p, pos * sizeof(Producto), SEEK_SET);
            fwrite(&prod, sizeof(Producto), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }
    fclose(p);
    return false;
}

bool ArchivoProducto::modificarPorID(int id) {
    FILE* p = fopen(_nombre, "rb+");
    if (p == nullptr) return false;

    Producto prod;
    long pos = 0;
    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getIdProducto() == id && prod.getEstado()) {
            prod.mostrarProducto();

            int opcion;
            std::cout << "1. Nombre\n2. Precio\n3. Stock actual\n4. Stock maximo\nOpcion: ";
            std::cin >> opcion;
            std::cin.ignore();

            switch (opcion) {
                case 1: {
                    char nombre[20];
                    std::cout << "Nuevo nombre: ";
                    std::cin.getline(nombre, 20);
                    prod.setNombreProducto(nombre);
                    break;
                }
                case 2: {
                    float precio;
                    std::cout << "Nuevo precio: ";
                    std::cin >> precio;
                    prod.setPrecioUnitario(precio);
                    break;
                }
                case 3: {
                    int stock;
                    std::cout << "Nuevo stock actual: ";
                    std::cin >> stock;
                    prod.setStockActual(stock);
                    break;
                }
                case 4: {
                    int max;
                    std::cout << "Nuevo stock maximo: ";
                    std::cin >> max;
                    prod.setStockMax(max);
                    break;
                }
            }

            fseek(p, pos * sizeof(Producto), SEEK_SET);
            fwrite(&prod, sizeof(Producto), 1, p);
            fclose(p);
            return true;
        }
        pos++;
    }
    fclose(p);
    return false;
}
