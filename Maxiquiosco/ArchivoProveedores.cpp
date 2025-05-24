# include<iostream>
#include <cstring>
#include "Proveedor.h"
#include "ArchivoProveedores.h"

using namespace std;

ArchivoProveedores::ArchivoProveedores()
{
    strcpy(_nombreArchivo, "ArchivoProveedor.dat");
    _tamanoRegistro = sizeof(Proveedor);
}

bool ArchivoProveedores::AgregarRegistro(Proveedor proveedor)
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo, "ab");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura o creacion del archivo!" << endl;
        return false;
    }

    fwrite(&proveedor, _tamanoRegistro, 1, pArchivo);
    fclose(pArchivo);
    return true;

}

void ArchivoProveedores::BajaRegistroPorID(int ID)
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb+");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Proveedor proveedor;
    bool baja = false;
    while(fread(&proveedor, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            proveedor.setEstado(false);
            cout << "El Proveedor: " << proveedor.getNombreProveedor() << " con el ID: #" << proveedor.getIDProveedor()
             << " ha sido dado de baja correctamente" << endl;
             baja = true;
             break;
        }
    }
    if(!baja)
    {
        cout << "No se ha conseguido el ID ingresado entre los ID de Proveedores Activos." << endl;
    }
    fclose(pArchivo);
}

void ArchivoProveedores::ListarRegistroPorID(int ID)
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo,"rb");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Proveedor proveedor;
    while(fread(&proveedor, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            proveedor.MostrarProveedor();
        }
    }
    cout << "=============================" << endl;
    fclose(pArchivo);

}


void ArchivoProveedores::ListarRegistros()
{
    FILE * pArchivo;
    pArchivo = fopen(_nombreArchivo, "rb");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Proveedor proveedor;
    while(fread(&proveedor, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado())
        {
            proveedor.MostrarProveedor();
        }
        cout << "---------------------------" << endl;
    }
    fclose(pArchivo);
}
