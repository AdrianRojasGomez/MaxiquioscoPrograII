#include <iostream>
#include <cstdio>
#include <cstring>
#include "Producto.h"
#include "TipoProducto.h"
#include "FuncionesCompra.h"
#include "Fecha.h"
#include "Compra.h"
#include "ArchivoProducto.h"
#include "ArchivoProveedor.h"
#include "ArchivoCompra.h"
#include "ValidadorInputs.h"

using namespace std;


///AGREGAR COMPRA
void FuncionesCompra::AgregarCompra()
{
    ArchivoProducto archivoProducto;
    Producto producto;
    ArchivoProveedor archivoProveedor;
    Proveedor proveedor;
    ArchivoCompra archivocompra;

    int idCompra = archivocompra.ObtenerProximoID();
    int idProducto, idProveedor, cantidadComprada;
    float importe;
    int dia,mes,anio;
    Fecha fecha;
    bool estado = true;

    string input;
    // Buscar producto
    cout << "Ingrese ID del producto:" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Por favor ingrese solo numeros" << endl;
        system("Pause");
        return;
    }
    idProducto = stoi(input);
    if(!archivoProducto.ExisteID(idProducto))
    {
        cout << "Error: Producto no encontrado." << endl;
        return;
    }
    producto = archivoProducto.BuscarRegistroPorID(idProducto);
    cout << "Producto encontrado: "  << endl;
    producto.MostrarProductoEnConsola();

    //Buscar proveedor
    cout << "Ingrese ID del proveedor:" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Por favor ingrese solo numeros" << endl;
        system("Pause");
        return;
    }
    idProveedor = stoi(input);
    if(!archivoProveedor.ExisteID(idProveedor))
    {
        cout << "Error: Proveedor no encontrado." << endl;
        return;
    }
    proveedor = archivoProveedor.BuscarRegistroPorID(idProveedor);
    cout << "Proveedor encontrado: " << endl;
    proveedor.MostrarProveedorEnColsola();

    //Datos De la Compra
    cout << "Ingrese cantidad comprada:" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese solo numeros en la cantidad comprada." << endl;
        return;
    }
    cantidadComprada = stoi(input);
    cout << "Ingrese el importe de la compra:" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::EsFloat(input))
    {
        cout << "Error: Ingrese solo cantidades validas en el importe de la compra." << endl;
        return;
    }
    importe = stof(input);
    cout << "Ingrese la fecha de la compra:" << endl;
    cout << "Mes (Numero del 1 al 12):" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::MesValido(input))
    {
        cout << "Error: Ingrese un Mes Valido." << endl;
        return;
    }
    mes = stoi(input);
    fecha.setMes(mes);
    cout << "Dia: (Numero del 1 al 31)" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::DiaValido(input,mes))
    {
        cout << "Error: Ingrese un Dia Valido." << endl;
        return;
    }
    dia = stoi(input);
    fecha.setDia(dia);
    cout << "Anio: (Formato AAAA)" << endl;
    cout << ">> ";
    getline(cin,input);
    if(!ValidadorInputs::AnioValido(input))
    {
        cout << "Error: Ingrese un Anio Valido." << endl;
        return;
    }
    anio = stoi(input);
    fecha.setAnio(anio);


    // Crear y guardar la compra
    Compra compra(idCompra,producto,proveedor,cantidadComprada,fecha,importe,estado);
    if(!archivocompra.AgregarRegistro(compra))
    {
        cout << "Error: No se pudo realizar la compra" << endl;
        return;
    }
    archivoProducto.ModificarStockporCompra(producto.getIDProducto(), compra.getCantidadComprada());
    cout << "Compra agregada con exito!" << endl;
    compra.MostrarCompraEnConsola();
}

///DAR DE BAJA LA COMPRA
void FuncionesCompra::BajaCompra()
{
    ArchivoCompra archivo;
    string input;
    int idCompra;
    cout << "Ingrese el ID de la compra a dar de baja:  ";
    cin >> input;
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese un ID valido." << endl;
        return;
    }
    idCompra = stoi(input);
    if(!archivo.BajaRegistro(idCompra));
    {
        cout << "Compra No encontrado o dado de baja anteriormente." << endl;
        system("pause");
    }
    cout << "Compra dada de baja satifactoriamente" << endl;
    system("pause");
}

///MODIFICAR PRODUCTOS
void FuncionesCompra::ModificarCompra()
 {
    ArchivoCompra archivo;
    string input;
    int IDbuscado;
    cout << "Ingrese el ID de la compra que desea modificar. " << endl;
    cout << ">> ";
    cin>>input;
    if(!ValidadorInputs::SonSoloNumeros(input))
    {
        cout << "Error: Ingrese Solo numeros el ID" << endl;
        system("pause");
        return;
    }
    IDbuscado = stoi(input);
    if(!archivo.ModificarRegistroPorID(IDbuscado))
    {
        cout << "Compra No encontrada o Inactiva." << endl;
        system("pause");
        return;
    }
    cout << "Compra modificada satisfactoriamente" << endl;
    system("pause");
}

///LISTAR COMPRAS
void FuncionesCompra::ListarCompra() {
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
            compra.MostrarCompraEnConsola();
            cout << "---------------------------" <<endl;

        }

    }
     system("pause");
    fclose(archivo);
}

void FuncionesCompra::ListarCompraPorID()
{

}


