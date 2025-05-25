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
    bool encontrado = false;
    int pos = 0;
    while(fread(&proveedor, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            cout << "Proveedor encontrado: " << endl;
            proveedor.MostrarProveedor();
            proveedor.setEstado(false);
            encontrado = true;
            break;
        }

        pos++;
    }

    if(!encontrado)
    {
        cout << "No se ha conseguido el ID ingresado entre los ID de Proveedores Activos." << endl;
    }

    fseek(pArchivo, pos * _tamanoRegistro, SEEK_SET);
    fwrite(&proveedor, sizeof(Proveedor),1,pArchivo);
    fclose(pArchivo);

    cout << "Proveedor dado de baja correctamente." << endl;
}


void ArchivoProveedores::ModificarRegistroPorID(int ID)
{
    FILE *pArchivo;
    pArchivo = fopen(_nombreArchivo, "rb+");
    if(pArchivo == nullptr)
    {
        cout << "Ha ocurrido un error con la apertura archivo, verifique que el archivo exista." << endl;
        return;
    }
    Proveedor proveedor;
    bool encontrado = false;
    int pos = 0;
    while(fread(&proveedor, _tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            cout << "Proveedor encontrado: " << endl;
            proveedor.MostrarProveedor();
            encontrado = true;
            break;
        }

        pos++;
    }

    if(!encontrado)
    {
        cout << "No se ha conseguido el ID ingresado entre los ID de Proveedores Activos." << endl;
    }
    int opcion;
    cout << "\nSeleccione que desea modificar:" <<endl;
    cout << "1. ID\n2. DNI\n3. CUIT\n4. Numero de Telefono\n5. Nombre del Proveedor\n6. Email\n7. Direccion \n0. Cancelar\nOpcion: ";
    cin >> opcion;
    cin.ignore();

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
    fseek(pArchivo, pos * _tamanoRegistro, SEEK_SET);
    fwrite(&proveedor, _tamanoRegistro, 1, pArchivo);
    pclose(pArchivo);

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
