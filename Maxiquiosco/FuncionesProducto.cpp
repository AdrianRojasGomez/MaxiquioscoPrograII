#include <iostream>
#include <cstdio>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"
#include "ArchivoProducto.h"

using namespace std;

void agregarProducto() {
    ArchivoProducto archivo;
    int id, stock, stockMax, idTipo;
    char nombre[20], clasificacion[20];
    float precio;
    bool estado;

do {
    cout << "Ingrese ID del producto: ";
    cin >> id;
        if (archivo.existeID(id)) {
            cout << "Error --> Ya existe un producto con ese ID. Ingrese otro.\n";
        }
    } while (archivo.existeID(id));

    cout << "Ingrese nombre del producto: ";
    cin.ignore();
    cin.getline(nombre, 20);
    cout << "Ingrese precio unitario: ";
    cin >> precio;
    cout << "Ingrese stock actual: ";
    cin >> stock;
    cout << "Ingrese stock maximo: ";
    cin >> stockMax;
    cout << "Ingrese ID del tipo de producto: ";
    cin >> idTipo;
    cout << "Ingrese clasificacion del tipo: ";
    cin.ignore();
    cin.getline(clasificacion, 20);
    cout << "¿El producto esta activo? (1 = Si, 0 = No): ";
    cin >> estado;

    TipoProducto tipo(idTipo, clasificacion);
    Producto prod;

    prod.setIdProducto(id);
    prod.setTipoProducto(tipo);
    prod.setStockMax(stockMax);
    prod.setEstado(estado);


    if (!prod.setNombreProducto(nombre) ||
        !prod.setPrecioUnitario(precio) ||
        !prod.setStockActual(stock)) {
        cout << "Error en los datos del producto." << endl;
        return;
    }

    if (archivo.guardar(prod)) {
        cout << "Producto guardado con exito." << endl;
    } else {
        cout << "Error al guardar el producto." << endl;
    }
}

void bajaProductoPorID(){///baja logica
    ArchivoProducto archivo;
    int idBuscado;
    cout << "Ingrese el ID del producto a dar de baja:  ";
    cin >> idBuscado;
    if (archivo.bajaPorID(idBuscado)) {
        cout << "Producto dado de baja." << endl;
    } else {
        cout << "Producto no encontrado o ya dado de baja." << endl;
    }
}

void modificarProductoPorID() {
    ArchivoProducto archivo;
    int idBuscado;
    cout << "Ingrese el ID del producto a modificar: ";
    cin >> idBuscado;
    if (archivo.modificarPorID(idBuscado)) {
        cout << "Producto modificado." << endl;
    } else {
        cout << "Producto no encontrado o inactivo." << endl;
    }
}

void listarProductos() {
    ArchivoProducto archivo;
    archivo.listar();
}



