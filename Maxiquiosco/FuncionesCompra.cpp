#include <iostream>
#include <cstdio>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"
#include "FuncionesCompra.h"

using namespace std;

///AGREGAR COMPRA
void agregarCompra() {
    int id, idProveedor, cantidadComprada;
    float importe;
    Fecha fecha;

    cout << "Ingrese ID del producto: ";
    cin >> id;
    cout << "Ingrese ID del proveedor: ";
    cin>>idProveedor;
    cout << "Ingrese cantidad comprada: ";
    cin >> cantidadComprada;
    cout << "Ingrese importe de la compra: $";
    cin >> importe;
    cout << "Ingrese fecha de la compra (dia - mes - anio)";
    cin >> fecha;

    Compra compra(id, idProveedor, cantidadComprada, importe, fecha);

    FILE* archivo = fopen("ArchivoCompra.dat", "ab");
    if (archivo == NULL) {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }

    fwrite(&compra, sizeof(Compra), 1, archivo);
    fclose(archivo);

    cout << "Compra agregada con exito!" << endl;
}
///DAR DE BAJA LA COMPRA
void bajaCompraPorID(){
    int buscarCompra;
    cout << "Ingrese el ID de la compra a dar de baja:  ";
    cin >> buscarCompra;

    FILE* archivo = fopen("archivoCompra.dat", "rb+");
    if (archivo == NULL){
        cout << "Error al abrir el archivo! " << endl;
        return;
    }

    Compra compra;
    bool compraEncontrada = false;
    int pos = 0;

    while(fread(&compra, sizeof(Compra),1, archivo) == 1){
    if(compra.getIdCompra() == buscarCompra && compra.getEstado()) {
        compraEncontrada = true;
        break;
            }
       pos++;
       }

       if(!compraEncontrada){
        cout << " La compra solicitada no se encontro " << endl;
        fclose(archivo);
        return;
        }

       cout << "Compra encontrada:  " <<endl;
       compra.mostrarCompra();

         char confirmacion;
            cout << "\n¿Confirmar baja? (S/N): ";
            cin >> confirmacion;

        if (toupper(confirmacion) != 'S') {
            cout << "Baja cancelada." << endl;
            fclose(archivo);
            return;
    }
           compra.setEstado(false); /// Baja lógica

        fseek(archivo, pos * sizeof(Compra), SEEK_SET);
        fwrite(&compra, sizeof(Compra), 1, archivo);
        fclose(archivo);

        cout << "Compra dada de baja correctamente." << endl;
}
///MODIFICAR PRODUCTOS
void modificarProductoPorID() {
    int compraBuscada;
    cout << "Ingrese el numero de compra a modificar: ";
    cin >> compraBuscada;

    FILE* archivo = fopen("ArchivoCompra.dat", "rb+");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo." <<endl;
        return;
    }

    Compra compra;
    bool compraEncontrada = false;
    int pos = 0;

    while (fread(&compra, sizeof(Compra), 1, archivo) == 1) {
        if (compra.getIdCompra() == compraBuscada && compra.getEstado()) {
            compraEncontrada = true;
            break;
        }
        pos++;
    }

    if (!compraEncontrada) {
        cout << "La compra solicitada no se encontro" <<endl;
        fclose(archivo);
        return;
    }

    cout << "Compra:" <<endl;
    compra.mostrarCompra();

    int opcion;
    cout << "\nSeleccione que desea modificar:" <<endl;
    cout << "1. ID producto\n2. ID proveedor\n3. Cantidad comprada\n4. Importe de la compra\n5. Fecha\n0. Cancelar\n"<<endl<<"Opcion: ";
    cin >> opcion;
    cin.ignore();

    switch (opcion) {
        case 1: {
           int nuevoID;
            cout << "Nuevo ID producto: ";
            cin>>nuevoID;
            compra.setIdProducto(nuevoID);
            break;
        }
        case 2: {
            int idProveedor;
            cout << "Nuevo proveedor: ";
            cin >> idProveedor;
            compra.setIdProveedor(idProveedor);
            break;
        }
        case 3: {
            int cantidadNueva;
            cout << "Cantidad corregida: ";
            cin >> cantidadNueva;
            compra.setCantidad(cantidadNueva);
            break;
        }
        case 4: {
            float importeActual;
            cout << "Importe corregido: ";
            cin >> importeActual;
            compra.setImporte(importeActual);
            break;
        }
        case 5:
            int diaAct, mesAct, anioAct;
            cout << "Fecha corregida (dd mm aaaa): ";
            cin >> diaAct >> mesAct >> anioAct;
            Fecha nuevaFecha(diaAct, mesAct, anioAct);
            compra.setFecha(nuevaFecha);
        case 0:
            cout << "Modificación cancelada." <<endl;
            fclose(archivo);
            return;
        default:
            cout << "Opcion invalida." <<endl;
            fclose(archivo);
            return;
    }

    fseek(archivo, pos * sizeof(Compra), SEEK_SET);
    fwrite(&compra, sizeof(Compra), 1, archivo);
    fclose(archivo);

    cout << "Compra modificada con exito" <<endl;
}

///LISTAR COMPRAS
void listarCompras() {
    FILE* archivo = fopen("ArchivoCompra.dat", "rb");
    if (archivo == NULL) {
        cout << "No se pudo abrir el archivo de compras" <<endl;
        return;
    }

    Compra compras;
    cout << "--- LISTADO DE COMPRAS ---" <<endl;
    while (fread(&compra, sizeof(Compra), 1, archivo) == 1) {
        if (compra.getEstado()) {
            compra.mostrarCompras();
            cout << "---------------------------" <<endl;

        }

    }
     system("pause");
    fclose(archivo);
}
