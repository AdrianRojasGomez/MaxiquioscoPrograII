#include <iostream>
#include <cstdio>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"
#include "FuncionesCompra.h"
#include "fecha.h"
#include "Compra.h"
#include "ArchivoProducto.h"


using namespace std;


int obtenerProximoIDCompra() {
    FILE* p = fopen("ArchivoCompra.dat", "rb");
    if (p == nullptr) return 1; // Si no existe, empezamos desde 1

    Compra comp;
    int maxID = 0;

    while (fread(&comp, sizeof(Compra), 1, p) == 1) {
        if (comp.getEstado() && comp.getIdCompra() > maxID) {
            maxID = comp.getIdCompra();
        }
    }

    fclose(p);
    return maxID + 1;
}



///AGREGAR COMPRA
void agregarCompra() {

    int idProducto, idProveedor, cantidadComprada;
    int idCompra = obtenerProximoIDCompra();
    float importe;
    Fecha fecha;

    cout << "Ingrese ID del producto: ";
    cin >> idProducto;
    ArchivoProducto archivo;
    Producto prod = archivo.buscarPorID(idProducto);
    if (prod.getIdProducto() == 0) {
    cout << "Producto no encontrado." << endl;
    return;
}

    cout << "Producto encontrado: " << prod.getNombreProducto() << endl;

    cout << "Ingrese ID del proveedor: ";
    cin>>idProveedor;

    cout << "Ingrese cantidad comprada: ";
    cin >> cantidadComprada;

    cout << "Ingrese importe de la compra: $";
    cin >> importe;
    //llamamos a fecha para el ingreso
    cin >> fecha;

    Compra compra(idCompra, idProducto, prod.getNombreProducto(), idProveedor, cantidadComprada, fecha, importe);

    FILE* archivoCompra = fopen("ArchivoCompra.dat", "ab");
    if (archivoCompra == nullptr) {
        cout << "Error al abrir el archivo!" << endl;
        return;
    }

    fwrite(&compra, sizeof(Compra), 1, archivoCompra);
    fclose(archivoCompra);
    archivo.registrarCompraPorID(idProducto, cantidadComprada);
    cout << "Compra agregada con exito!" << endl;
}
///DAR DE BAJA LA COMPRA
void bajaCompraPorID(){
    int buscarCompra;
    cout << "Ingrese el ID de la compra a dar de baja:  ";
    cin >> buscarCompra;

    FILE* archivo = fopen("archivoCompra.dat", "rb+");
    if (archivo == nullptr){
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
void modificarCompraPorID() {
    int compraBuscada;
    cout << "Ingrese el numero de compra a modificar: ";
    cin >> compraBuscada;

    FILE* archivo = fopen("ArchivoCompra.dat", "rb+");
    if (archivo == nullptr) {
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
            compra.setCantidadComprada(cantidadNueva);
            break;
        }
        case 4: {
            float importeActual;
            cout << "Importe corregido: ";
            cin >> importeActual;
            compra.setImporteTotal(importeActual);
            break;
        }
        case 5: {
            int diaAct, mesAct, anioAct;
            cout << "Fecha corregida (dd mm aaaa): ";
            cin >> diaAct >> mesAct >> anioAct;
            Fecha nuevaFecha(diaAct, mesAct, anioAct);
            compra.setFechaCompra(nuevaFecha);
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

    Compra compra;
    cout << "--- LISTADO DE COMPRAS ---" <<endl;
    while (fread(&compra, sizeof(Compra), 1, archivo) == 1)
        {
        if (compra.getEstado()) {
            compra.mostrarCompra();
            cout << "---------------------------" <<endl;

        }

    }
     //system("pause");
    fclose(archivo);
}



