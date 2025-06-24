#include <iostream>
#include "FuncionesProducto.h"
#include "Producto.h"
#include "TipoProducto.h"
#include "ArchivoProducto.h"
#include "ArchivoTipoProducto.h"
#include "ValidadorInputs.h"

using namespace std;

void FuncionesProducto::AgregarProducto()
{
    TipoProducto tipoSeleccionado;
    ArchivoProducto archivoProducto;
    ArchivoTipoProducto archivoTipoProducto;

    int ID = archivoProducto.ObtenerProximoID();
    int stockMax, IDTipoProducto;
    float precio;
    int stock = 0;
    char nombre[Producto::TAMANO_NOMBRE];
    bool estado = true;

    string input;
    int aux;
    ///NOMBRE
    cout << "Ingrese el Nombre del Producto" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::TamanoPermitido(input,Producto::TAMANO_NOMBRE))
    {
        cout << "Ingrese un nombre con una longitud Valida" <<endl;
        return;
    }
    strcpy(nombre,input.c_str());

    ///TIPO DE PRODUCTO
    bool tipoValido = false;

    archivoTipoProducto.ListarResistros();
    do
    {
        cout << "Ingrese el ID del tipo de Producto. " << endl;
        cout << ">> ";
        getline(cin,input);
        if(!ValidadorInputs::SonSoloNumeros(input))
        {
            cout << "Error: Ingrese Solo numeros para el ID del tipo de Producto" <<endl;
            continue;
        }
        aux = stoi(input);
        tipoSeleccionado = archivoTipoProducto.BuscarRegistroPorID(aux);
        if(tipoSeleccionado.getIDTipoProducto() != 0)
        {
            tipoValido = true;
            cout << "Tipo seleccionado: " << tipoSeleccionado.getClasificacionProducto() << endl;
        }
        else
        {
            cout << "Error: Tipo con ID " << aux << " no existe. Intente nuevamente." << endl;
        }
    }
    while(!tipoValido);

    ///PRECIO
    cout << "Ingrese el Precio Unitario. " << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::EsFloat(input))
    {
        cout << "Error: Ingrese un precio valido para el campo Precio unitario" <<endl;
        return;
    }
    precio = stof(input);
    ///STOCK MAXIMO
    cout << "Ingrese el Stock Maximo Permitido. " << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese Solo numeros para el stock maximo" <<endl;
        return;
    }
    stockMax = stoi(input);
    Producto producto(ID,stock,stockMax,nombre,tipoSeleccionado,precio,estado);

    system("cls");
    cout << "Detalles del producto a Agregar..." << endl;
    producto.MostrarProductoEnConsola();

    archivoProducto.AgregarRegistro(producto);
}

void FuncionesProducto::BajaProducto()
{
    ArchivoProducto archivo;
    Producto producto;
    string input;
    int IDbuscado;
    cout << "Ingrese el ID del producto que desea dar de baja. " << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese Solo numeros el ID" << endl;
        system("pause");
        return;
    }
    IDbuscado = stoi(input);
    if(!archivo.BajaRegistro(IDbuscado))
    {
        cout << "Producto No encontrado o dado de baja anteriormente." << endl;
        system("pause");
        return;
    }
    cout << "Producto dado de baja satifactoriamente" << endl;
    system("pause");
}

void FuncionesProducto::ModificarProducto()
{
    ArchivoProducto archivo;
    string input;
    int IDbuscado;
    cout << "Ingrese el ID del producto que desea modificar. " << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese Solo numeros el ID" << endl;
        system("pause");
        return;
    }
    IDbuscado = stoi(input);
    if(!archivo.ModificarRegistroPorID(IDbuscado))
    {
        cout << "Producto No encontrado o Inactivo." << endl;
        system("pause");
        return;
    }
    cout << "Producto modificado satisfactoriamente" << endl;
    system("pause");
}

void FuncionesProducto::ListarProducto()
{
    ArchivoProducto archivo;
    system("cls");
    archivo.ListarRegistros();
}

void FuncionesProducto::ListarProductoPorID()
{
    ArchivoProducto archivo;
    string input;
    int ID;
    cout << "Ingrese el ID a buscar." << endl;
    cout << ">> ";
    getline(cin,input);
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
    system("cls");
    archivo.ListarRegistroPorID(ID);
}
