#include <iostream>
#include <cstdio>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"

using namespace std;

void agregarProducto() {
    int id, stock, stockMax, idTipo;
    char nombre[20], clasificacion[20];
    float precio;
    bool estado;

    cout << "Ingrese ID del producto: ";
    cin >> id;
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


    Producto prod(id, nombre, tipo, precio, stock, stockMax, estado);

    FILE* archivo = fopen("ArchivoProducto.dat", "ab");
    if (archivo == NULL) {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }

    fwrite(&prod, sizeof(Producto), 1, archivo);
    fclose(archivo);

    cout << "Producto agregado con Exito!" << endl;
}

void bajaProductoPorID(){
    int idBuscado;
    cout << "Ingrese el ID del producto a dar de baja:  ";
    cin >> idBuscado;

    FILE* archivo = fopen("archivoProducto.dat", "rb+");
    if (archivo == NULL){
        cout << "Error al abrir el archivo! " << endl;
        return;
    }

    Producto prod;
    bool encontrado = false;
    int pos = 0;

    while(fread(&prod, sizeof(Producto),1, archivo) ==1){
    if(prod.getIdProducto() == idBuscado && prod.getEstado()) {
        encontrado = true;
        break;
            }
       pos++;
       }

       if(!encontrado){
        cout << " Producto no encontrado o ya esta dado de baja " << endl;
        fclose(archivo);
        return;
        }

       cout << "Producto encontrado:  " <<endl;
       prod.mostrarProducto();

         char confirmacion;
            cout << "\n¿Confirmar baja? (S/N): ";
            cin >> confirmacion;

        if (toupper(confirmacion) != 'S') {
            cout << "Baja cancelada." << endl;
            fclose(archivo);
            return;
    }
           prod.setEstado(false); /// Baja lógica

        fseek(archivo, pos * sizeof(Producto), SEEK_SET);
        fwrite(&prod, sizeof(Producto), 1, archivo);
        fclose(archivo);

        cout << "Producto dado de baja correctamente." << endl;
}

void modificarProductoPorID() {
    int idBuscado;
    cout << "Ingrese el ID del producto a modificar: ";
    cin >> idBuscado;

    FILE* archivo = fopen("ArchivoProducto.dat", "rb+");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return;
    }

    Producto prod;
    bool encontrado = false;
    int pos = 0;

    while (fread(&prod, sizeof(Producto), 1, archivo) ==1) {
        if (prod.getIdProducto() == idBuscado && prod.getEstado()) {
            encontrado = true;
            break;
        }
        pos++;
    }

    if (!encontrado) {
        cout << "Producto no encontrado o esta dado de baja." <<endl;
        fclose(archivo);
        return;
    }

    cout << "Producto encontrado:" <<endl;
    prod.mostrarProducto();

    int opcion;
    cout << "\nSeleccione que desea modificar:" <<endl;
    cout << "1. Nombre\n2. Precio\n3. Stock actual\n4. Stock maximo\n0. Cancelar\nOpcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1: {
            char nuevoNombre[20];
            cout << "Nuevo nombre: ";
            cin.getline(nuevoNombre, 20);
            prod.setNombreProducto(nuevoNombre);
            break;
        }
        case 2: {
            float nuevoPrecio;
            cout << "Nuevo precio: ";
            cin >> nuevoPrecio;
            prod.setPrecioUnitario(nuevoPrecio);
            break;
        }
        case 3: {
            int nuevoStock;
            cout << "Nuevo stock actual: ";
            cin >> nuevoStock;
            prod.setStockActual(nuevoStock);
            break;
        }
        case 4: {
            int nuevoMax;
            cout << "Nuevo stock maximo: ";
            cin >> nuevoMax;
            prod.setStockMax(nuevoMax);
            break;
        }
        case 0:
            cout << "Modificación cancelada." <<endl;
            fclose(archivo);
            return;
        default:
            cout << "Opcion invalida." <<endl;
            fclose(archivo);
            return;
    }

    fseek(archivo, pos * sizeof(Producto), SEEK_SET);
    fwrite(&prod, sizeof(Producto), 1, archivo);
    fclose(archivo);

    cout << "Producto modificado con Exito." <<endl;
}

void listarProductos() {
    FILE* archivo = fopen("ArchivoProducto.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo de productos." <<endl;
        return;
    }

    Producto prod;
    cout << "--- LISTADO DE PRODUCTOS ---" <<endl;
    while (fread(&prod, sizeof(Producto), 1, archivo) ==1) {
        if (prod.getEstado()) {
            prod.mostrarProducto();
            cout << "---------------------------" <<endl;

        }

    }
     system("pause");
    fclose(archivo);
}
