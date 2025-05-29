#include <iostream>
#include "FuncionesProveedor.h"
#include "ArchivoProveedores.h"
#include "Proveedor.h"

using namespace std;

void FuncionesProveedor::AgregarProveedor()
{
    ArchivoProveedores archivoProveedores;
    int idProveedor, dni, cuit, numeroTelefono;
    char nombreProveedor[20], email[20], direccion [50];
    bool agregarOtro = true;

    do
    {
        cout << "Por favor ingrese los siguientes datos a continuacion: " << endl;
        cout << "ID del proveedor" << endl;
        cin >> idProveedor;
        cout << "DNI del proveedor" << endl;
        cin >> dni;
        cout << "CUIT del proveedor" << endl;
        cin >> cuit;
        cout << "Numero de telefono del proveedor, solo en numeros" << endl;
        cin >> numeroTelefono;
        cout << "Nombre y apellido del proveedor" << endl;
        cin.ignore();
        cin.getline(nombreProveedor, 20);
        cout << "Email del proveedor" << endl;
        cin.getline(email, 20);
        cout << "Direccion del proveedor" << endl;
        cin.getline(direccion, 50);

        Proveedor proveedor(idProveedor,dni,cuit,numeroTelefono,nombreProveedor,email,direccion);
        proveedor.MostrarProveedor();

        if(archivoProveedores.AgregarRegistro(proveedor))
        {
            cout << "REGISTRO DE PROVEEDOR EXITOSO." << endl;
            int decision = -1;
            do
            {
                cout << "Desea añadir otro Proveedor? \n1. SI    \n0. NO" << endl;
                cin >>decision;
                switch(decision)
                {
                case 1:
                    agregarOtro = true;
                    break;
                case 0:
                    agregarOtro = false;
                    break;
                default:
                    cout << "Ingrese una opcion valida" << endl;
                    break;
                }

            }
            while(decision != 1 && decision != 0);
        }
        else
        {
            cout << "ERROR EN LA CREACION DEL REGISTRO." << endl;
        }
    }
    while (agregarOtro);
}

void FuncionesProveedor::BajaLogicaProveedor()
{
    ArchivoProveedores archivoProveedores;
    int busquedaID;
    cout << "Ingrese el ID del proveedor para darle de baja" << endl;
    cin >> busquedaID;
    archivoProveedores.BajaRegistroPorID(busquedaID);
}

void FuncionesProveedor::ListarProveedorPorID()
{
    ArchivoProveedores archivoProveedores;
    int busquedaID;
    cout << "Ingrese el ID del proveedor para buscarlo" << endl;
    cin >> busquedaID;
    archivoProveedores.ListarRegistroPorID(busquedaID);
}

void FuncionesProveedor::ListarProveedores()
{
    ArchivoProveedores archivoProveedores;
    archivoProveedores.ListarRegistros();
}
