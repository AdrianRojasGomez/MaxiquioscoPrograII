#include "ArchivoProducto.h"
#include <cstdio>
#include <iostream>
using namespace std;

bool ArchivoProducto::guardar(const Producto& prod) {
   int op;
    cout << "¿Desea Guardar el Producto? \n1. SI    \n0. NO" <<  endl;
    cin >> op;
    cin.ignore();

   if(op==1){
    FILE* p = fopen(_nombre, "ab");
    if (p == nullptr) return false;
    fwrite(&prod, sizeof(Producto), 1, p);
    fclose(p);
        system("cls");
         cout << "Producto guardado con exito.\n1." <<  endl;

         cout << "Detalles del producto creado:" << endl;
         cout << "- ID: " << prod.getIdProducto() <<  endl;
         cout << "- Nombre: " << prod.getNombreProducto() <<  endl;
          cout << "- Tipo: " << prod.getTipoProducto().getClasificacionProducto() <<  endl;
         cout << "- Precio: $" << prod.getPrecioUnitario() <<  endl;
         cout << "- Stock Max: " << prod.getStockMax() <<  endl;

    return true;
   }else{
     cout << "Ingreso de producto CANCELADO" <<  endl;
   }

}

bool ArchivoProducto::listar() {
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) {
         cout << "No se pudo abrir el archivo." <<  endl;
        return false;
    }
    Producto prod;
    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getEstado()) {
            prod.mostrarProducto();
             cout << "---------------------" <<  endl;
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
             cout << "1. Nombre\n2. Precio\n3. Stock actual\n4. Stock maximo\nOpcion: ";
             cin >> opcion;
             cin.ignore();

            switch (opcion) {
                case 1: {
                    char nombre[20];
                     cout << "Nuevo nombre: ";
                     cin.getline(nombre, 20);
                    prod.setNombreProducto(nombre);
                    break;
                }
                case 2: {
                    float precio;
                     cout << "Nuevo precio: ";
                     cin >> precio;
                    prod.setPrecioUnitario(precio);
                    break;
                }
                case 3: {
                    int stock;
                     cout << "Nuevo stock actual: ";
                     cin >> stock;
                    prod.setStockActual(stock);
                    break;
                }
                case 4: {
                    int max;
                     cout << "Nuevo stock maximo: ";
                     cin >> max;
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

int ArchivoProducto::obtenerProximoID() {
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) return 1; /// Si no existe el archivo, arrancamos desde 1

    Producto prod;
    int maxID = 0;

    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getEstado() && prod.getIdProducto() > maxID) {
            maxID = prod.getIdProducto();
        }
    }

    fclose(p);
    return maxID + 1;
}

bool ArchivoProducto::registrarCompraPorID(int idProducto, int cantidad) {
    FILE* p = fopen(_nombre, "rb+");
    if (p == nullptr) return false;

    Producto prod;
    int pos = 0;

    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
        if (prod.getIdProducto() == idProducto && prod.getEstado()) {
            prod.setStockActual(prod.getStockActual() + cantidad);
            fseek(p, pos * sizeof(Producto), SEEK_SET);
            fwrite(&prod, sizeof(Producto), 1, p);
            fclose(p);
            return true;
            cout <<" nuevo stock = " <<prod.getStockActual()<< endl;
        }
        pos++;
    }

    fclose(p);
    return false;
}

Producto ArchivoProducto::buscarPorID(int idProducto) ///Para registro de compra
{
    Producto prod;
    FILE* p = fopen(_nombre, "rb");
    if (p == nullptr) return prod;

    while (fread(&prod, sizeof(Producto), 1, p) == 1) {
            ///std::cout << "Leyendo producto con ID: " << prod.getIdProducto() << " Estado: " << prod.getEstado() << std::endl;
        if (prod.getIdProducto() == idProducto && prod.getEstado()) {
            fclose(p);
            return prod;
        }
    }

    fclose(p);
    return Producto();
}
