#include <iostream>
#include <cstdio>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"
#include "ArchivoProducto.h"
#include "FuncionesProducto.h"
#include "ArchivoTipoProducto.h"

using namespace std;

void FuncionesProducto::agregarProducto() {
    ArchivoProducto archivo;
    ArchivoTipoProducto archivoTipos;
    int stockMax, idTipo;
    float precio;
    int  stock =0;
    char nombre[20];
    bool estado =1;
    int id = archivo.obtenerProximoID();

    cout << "Ingrese nombre del producto: ";
    cin.ignore();
    cin.getline(nombre, 20);

    TipoProducto tipoSeleccionado;

    bool tipoValido = false;
    cout << "Ingrese ID del tipo de producto: "<<endl;
    archivoTipos.listar();
        do {
                    cout << "Ingrese un ID : ";
                    cin >> idTipo;
                    tipoSeleccionado = archivoTipos.buscarPorId(idTipo);
                    if (tipoSeleccionado.getIdTipoProducto() != 0) {
                        tipoValido = true;
                        cout << "Tipo seleccionado: " << tipoSeleccionado.getClasificacionProducto() << endl;
                    } else {
                        cout << "Error: Tipo con ID " << idTipo << " no existe. Intente nuevamente." << endl;
                    }
            } while (!tipoValido);

    cout << "Ingrese precio unitario: ";
    cin >> precio;
    cout << "Ingrese stock maximo: ";
    cin >> stockMax;

    Producto prod;
    prod.setIdProducto(id);
    prod.setNombreProducto(nombre);
    prod.setPrecioUnitario(precio);
    prod.setTipoProducto(tipoSeleccionado);
    prod.setStockMax(stockMax);
    prod.setEstado(estado);
   system("cls");
        cout << "Detalles del producto :" <<endl;
        cout << "- ID: " << prod.getIdProducto() << endl;
        cout << "- Nombre: " << prod.getNombreProducto() << endl;
        cout << "- Precio: $" << prod.getPrecioUnitario() << endl;
        cout << "- Stock Max: " << prod.getStockMax() << endl;
        cout << "- Tipo: " << prod.getTipoProducto().getClasificacionProducto() << endl;

   archivo.guardar(prod);
}

void FuncionesProducto::bajaProductoPorID(){///baja logica
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

void FuncionesProducto::modificarProductoPorID() {
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

void FuncionesProducto::listarProductos() {
    ArchivoProducto archivo;
    archivo.listar();
}



