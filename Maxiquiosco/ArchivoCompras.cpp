# include<iostream>
#include <cstring>
#include "Compra.h"
#include "ArchivoCompras.h"

using namespace std;

ArchivoCompras::ArchivoCompras()
{
    strcpy(_nombreArchivo, "ArchivoCompras.dat");
    _tamanoRegistro = sizeof(Compra);
}

bool ArchivoCompras::AgregarRegistro(Compra compra)
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura o creacion del archivo!" << endl;
        return false;
    }

    fwrite(&compra, _tamanoRegistro, 1, pArchivo);
    fclose(pArchivo);
    return true;

}

void ArchivoCompras::BajaRegistroPorID(int ID)
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb+");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Compra compra;
    bool encontrado = false;
    int pos = 0;
    while(fread(&compra, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado() && compra.getIdCompra() == ID)
        {
            cout << "Compra encontrado: " << endl;
            compra.mostrarCompra();
            compra.setEstado(false);
            encontrado = true;
            break;
        }

        pos++;
    }

    if(!encontrado)
    {
        cout << "No se ha conseguido el ID ingresado entre los ID de las Compras Activas." << endl;
    }

    fseek(pArchivo, pos * _tamanoRegistro, SEEK_SET);
    fwrite(&compra, sizeof(Compra),1,pArchivo);
    fclose(pArchivo);

    cout << "Compra dada de baja correctamente." << endl;
}


void ArchivoCompras::ModificarRegistroPorID(int ID)
{
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Compra compra;
    bool encontrado = false;
    int pos = 0;
    while(fread(&compra, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado() && compra.getIdCompra() == ID)
        {
            cout << "Compra encontrada: " << endl;
            compra.mostrarCompra();
            encontrado = true;
            break;
        }

        pos++;
    }

    if(!encontrado)
    {
        cout << "No se ha conseguido el ID ingresado entre los ID de Compras Activos." << endl;
    }
    int opcion;
    cout << "\nSeleccione que desea modificar:" <<endl;
    cout << "1. ID\n2. DNI\n3. CUIT\n4. Numero de Telefono\n5. Nombre del Compra\n6. Email\n7. Direccion \n0. Cancelar\nOpcion: ";
    cin >> opcion;
    cin.ignore();
    ///TODO: MODIFICAR LA COMPRA REALIZADA
    /*
        switch (opcion)
        {

        case 1:
            int nuevoID;
            cout << "Ingrese el nuevo ID";
            cin >> nuevoID;
            proveedor.setIDProveedor(nuevoID);
            break;
        case 2:
            int nuevoDNI;
            cout << "Ingrese el nuevo DNI";
            cin >> nuevoDNI;
            proveedor.setDNI(nuevoDNI);
            break;
        case 3:
            int nuevoCUIT;
            cout << "Ingrese el nuevo CUIT";
            cin >> nuevoCUIT;
            proveedor.setCUIT(nuevoCUIT);
            break;
        case 4:
            int nuevoTelefono;
            cout << "Ingrese el nuevo Telefono";
            cin >> nuevoTelefono;
            proveedor.setNumeroTelefono(nuevoTelefono);
            break;
        case 5:
            char nuevoNombre[20];
            cout << "Ingrese el nuevo Nombre del Proveedor";
            cin.getline(nuevoNombre, 20);
            proveedor.setNombreProveedor(nuevoNombre);
            break;
        case 6:
            char nuevoEmail[20];
            cout << "Ingrese el nuevo Email";
            cin.getline(nuevoEmail, 20);
            proveedor.setEmail(nuevoEmail);
            break;
        case 7:
            char nuevoDireccion[20];
            cout << "Ingrese la nueva Direccion";
            cin.getline(nuevoDireccion, 50);
            proveedor.setEmail(nuevoDireccion);
            break;
        default:
            cout << "Opcion invalida." <<endl;
            fclose(pArchivo);
            return;
        }

        */

    fseek(pArchivo, pos * _tamanoRegistro, SEEK_SET);
    fwrite(&compra, _tamanoRegistro, 1, pArchivo);
    pclose(pArchivo);

}


void ArchivoCompras::ListarRegistroPorID(int ID)
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
Compra compra;
    while(fread(&compra, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado() && compra.getIdCompra() == ID)
        {
            compra.mostrarCompra();
        }
    }
    cout << "=============================" << endl;
    fclose(pArchivo);

}

Compra ArchivoCompras::BuscarRegistroPorID (int ID)
{
    Compra compra;

    FILE * pArchivo;
    pArchivo = fopen (_nombreArchivo, "rb");
    if(pArchivo == nullptr)
        return compra;

    while(fread(&compra,sizeof(Compra),1,pArchivo) == 1)
    {
        if(compra.getIdCompra() == ID && compra.getEstado())
        {
            fclose(pArchivo);
            return compra;
        }
    }

    fclose(pArchivo);
    return Compra();
}



void ArchivoCompras::ListarRegistros()
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Compra compra;
    while(fread(&compra, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado())
        {
            compra.mostrarCompra();
        }
        cout << "---------------------------" << endl;
    }
    fclose(pArchivo);
}
