#include <iostream>
#include <cstring>
#include "FuncionesProveedor.h"
#include "Proveedor.h"
#include "ArchivoProveedor.h"
#include "ValidadorInputs.h"
using namespace std;

void FuncionesProveedor::AgregarProveedor()
{
    ArchivoProveedor archivoProveedor;
    int ID = archivoProveedor.ObtenerProximoID();
    int dni;
    char cuit[Proveedor::TAMANO_CAMPO], numeroTelefono[Proveedor::TAMANO_CAMPO],
         nombre[Proveedor::TAMANO_CAMPO], email[Proveedor::TAMANO_CAMPO], direccion[Proveedor::TAMANO_CAMPO];

    string input;

    ///DNI
    cout << "Ingrese el DNI del Proveedor.\nSolo numeros, maximo 50 Caracteres." << endl;
    cout << ">> ";
    cin.ignore();
    getline (cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input) || !ValidadorInputs::TamanoPermitido(input,Proveedor::TAMANO_CAMPO))
    {
        cout << "Error: Ingrese solo los numeros del DNI, y asegurese que no sean mas de 50 caracteres" <<endl;
        return;
    }
    dni = stoi(input);

    ///CUIT
    cout << "Ingrese el CUIT del Proveedor.\nSolo numeros, maximo 50 Caracteres." << endl;
    cout << ">> ";
    getline (cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input) || !ValidadorInputs::TamanoPermitido(input,Proveedor::TAMANO_CAMPO))
    {
        cout << "Error: Ingrese solo los digitos del CUIT, con un maximo de 50 caracteres" << endl;
        return;
    }
    strcpy(cuit,input.c_str());
    ///NUM TELEFONO
    cout << "Ingrese el NUMERO DE TELEFONO del Proveedor.\nSolo numeros, maximo 50 Caracteres." << endl;
    cout << ">> ";
    getline (cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input) || !ValidadorInputs::TamanoPermitido(input,Proveedor::TAMANO_CAMPO))
    {
        cout << "Error: Ingrese solo los digitos del NUMERO DE TELEFONO, con un maximo de 50 caracteres" << endl;
        return;
    }
    strcpy(numeroTelefono,input.c_str());

    ///NOMBRE
    cout << "Ingrese el NOMBRE del Proveedor.\nSolo numeros, maximo 50 Caracteres." << endl;
    cout << ">> ";
    getline (cin,input);
    if(!ValidadorInputs::TamanoPermitido(input,Proveedor::TAMANO_CAMPO))
    {
        cout << "Error: Ingrese el NOMBRE con un maximo de 50 caracteres"  << endl;
        return;
    }
    strcpy(nombre,input.c_str());

    ///EMAIL
    cout << "Ingrese el EMAIL del Proveedor.\nSolo numeros, maximo 50 Caracteres." << endl;
    cout << ">> ";
    getline (cin,input);
    if(!ValidadorInputs::TamanoPermitido(input,Proveedor::TAMANO_CAMPO))
    {
        cout << "Error: Ingrese el EMAIL con un maximo de 50 caracteres" << endl;
        return;
    }
    strcpy(email,input.c_str());

    ///DIRECCION
    cout << "Ingrese la DIRECCION del Proveedor.\nSolo numeros, maximo 50 Caracteres." << endl;
    cout << ">> ";
    getline (cin,input);
    if(!ValidadorInputs::TamanoPermitido(input,Proveedor::TAMANO_CAMPO))
    {
        cout << "Error: Ingrese el DIRECCION con un maximo de 50 caracteres" << endl;
        return;
    }
    strcpy(direccion,input.c_str());
    Proveedor proveedor(ID,dni,cuit,numeroTelefono,nombre,email,direccion);

    system("cls");
    cout << "Detalles del Proveedor a Agregar..." << endl;
    proveedor.MostrarProveedorEnColsola();
    archivoProveedor.AgregarRegistro(proveedor);
}

void FuncionesProveedor::BajaProveedor()
{
    ArchivoProveedor archivoProveedor;
    string input;
    int IDbuscado;
    cout << "Ingrese el ID del proveedor que desea modificar. " << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese Solo numeros el ID" << endl;
        system("pause");
        return;
    }
    IDbuscado = stoi(input);
    if(!archivoProveedor.ModificarRegistroPorID(IDbuscado))
    {
        cout << "Producto No encontrado o Inactivo." << endl;
        system("pause");
        return;
    }
    cout << "Producto modificado satisfactoriamente" << endl;
    system("pause");
}

void FuncionesProveedor::ModificarRegistro()
{
    ArchivoProveedor archivoProveedor;
    int busquedaID;
    cout << "Ingrese el ID del proveedor para buscarlo" << endl;
    cin >> busquedaID;
    archivoProveedor.ModificarRegistroPorID(busquedaID);
}

void FuncionesProveedor::ListarProveedorPorID()
{
    ArchivoProveedor archivo;
    string input;
    int ID;
    cout << "Ingrese el ID a buscar." << endl;
    cout << ">> ";
    cin >> input;
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese Solo numeros el ID" <<endl;
        system("Pause");
        return;
    }
    else
    {
        ID = stoi(input);
    }
    archivo.ListarRegistroPorID(ID);
}

void FuncionesProveedor::ListarProveedores()
{
    ArchivoProveedor archivoProveedor;
    archivoProveedor.ListarRegistros();
}

void PrecargarProveedoresDeDocumento()
{

}

