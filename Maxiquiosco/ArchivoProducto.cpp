#include <iostream>
#include "ArchivoProducto.h"
#include "Producto.h"
#include "ValidadorInputs.h"

using namespace std;

ArchivoProducto::ArchivoProducto()
{
    strcpy(_nombreArchivo, _nombre);
    _tamanoRegistro = sizeof(Producto);
}

///Inicio de ABML
bool ArchivoProducto::AgregarRegistro(Producto &producto)
{
    FILE* pArchivo = AbrirArchivo("ab");
    if(pArchivo == nullptr)
        return false;
    fwrite(&producto, _tamanoRegistro, 1, pArchivo);
    CerrarArchivo(pArchivo);
    return true;
}
bool ArchivoProducto::BajaRegistro(int ID)
{
    FILE* pArchivo = AbrirArchivo("rb+");
    if(pArchivo == nullptr)
        return false;
    Producto producto;
    int posicion = 0;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado() && producto.getIDProducto() == ID)
        {
            cout << "Producto Encontrado: " << endl;
            producto.MostrarProductoEnConsola();
            producto.setEstado(false);
            fseek(pArchivo, posicion * _tamanoRegistro, SEEK_SET);
            fwrite(&producto, _tamanoRegistro, 1, pArchivo);
            CerrarArchivo(pArchivo);
            return true;
        }
        posicion++;
    }
    CerrarArchivo(pArchivo);
    return false;
}
bool ArchivoProducto::ModificarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb+");
    if(pArchivo == nullptr)
        return false;
    Producto producto;
    int posicion = 0;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado() && producto.getIDProducto() == ID)
        {
            bool esModificable = false;
            cout << "Producto Encontrado: " << endl;
            producto.MostrarProductoEnConsola();
            int aux;
            do
            {
                string opcion;
                cout << "Elija la opcion a Editar" << endl;
                cout << "1. Nombre\n2. Precio\n3. Stock actual\n4. Stock maximo\n0. No Modificar\nOpcion: ";
                getline(cin,opcion);
                if(!ValidadorInputs::EsUnDigito(opcion))
                {
                    aux = -1;
                    continue;
                }
                aux = stoi(opcion);
                switch(aux)
                {
                case 1:
                {   cout << "Nuevo nombre: ";
                    ///TODO: FALTA VALIDACION DE TAMAÑO
                    char nombre[50];
                    cin.getline(nombre,50);
                    producto.setNombreProducto(nombre);
                    esModificable = true;
                    break;
                }
                case 2:
                {
                    cout << "Nuevo precio: ";
                    float precio;
                    string precioInput;
                    getline(cin,precioInput);
                    if(!ValidadorInputs::SonSoloNumeros(precioInput))
                    {
                        cout << "Ingrese solo numeros" << endl;
                        aux = -1;
                        break;
                    }
                    precio = stoi(precioInput);
                    producto.setPrecioUnitario(precio);
                    esModificable = true;
                    break;
                }
                case 3:
                {
                    cout << "Nuevo Stock: ";
                    int stockActual;
                    string stockActualInput;
                    cin >> stockActualInput;
                    if(!ValidadorInputs::SonSoloNumeros(stockActualInput))
                    {
                        cout << "Ingrese solo numeros" << endl;
                        aux = -1;
                        break;
                    }
                    stockActual = stoi(stockActualInput);
                    producto.setStockActual(stockActual);
                    esModificable = true;
                    break;
                }
                case 4:
                {
                    cout << "Nuevo stock Maximo: ";
                    int stockMax;
                    string stockMaxInput;
                    cin >> stockMaxInput;
                    if(!ValidadorInputs::SonSoloNumeros(stockMaxInput))
                    {
                        cout << "Ingrese solo numeros" << endl;
                        aux = -1;
                        break;
                    }
                    stockMax = stoi(stockMaxInput);
                    producto.setStockMax(stockMax);
                    esModificable = true;
                    break;
                }
                case 0:
                    cout << "No se ha Modificado." << endl;
                    break;

                default:
                    cout << "Opcion Invalida." << endl;
                    aux = -1;
                    system("pause");
                    break;
                }
            }
            while (aux == -1);
            if(!esModificable)
            {
                return false;
            }
            fseek(pArchivo,posicion * _tamanoRegistro, SEEK_SET);
            fwrite(&producto, _tamanoRegistro, 1, pArchivo);
            CerrarArchivo(pArchivo);
            return true;
        }
        posicion++;
    }
    CerrarArchivo(pArchivo);
    return false;
}

bool ArchivoProducto::ModificarStockporCompra(int ID, int cantidadComprada)
{
    FILE* pArchivo = AbrirArchivo("rb+");
    if(pArchivo == nullptr)
        return false;
    Producto producto;
    int posicion = 0;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(!producto.getEstado() || producto.getIDProducto() != ID)
        {
            posicion++;
            continue;
        }
        producto.setStockActual(producto.getStockActual() + cantidadComprada);
        fseek(pArchivo,posicion * _tamanoRegistro, SEEK_SET);
        fwrite(&producto, _tamanoRegistro,1,pArchivo);
        CerrarArchivo(pArchivo);
        return true;
    }
    CerrarArchivo(pArchivo);
    return false;
}

bool ArchivoProducto::ListarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Producto producto;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado() && producto.getIDProducto() == ID)
        {
            producto.MostrarProductoEnConsola();
        }
    }
    cout << "=============================" << endl;
    CerrarArchivo(pArchivo);
    return true;
}
bool ArchivoProducto::ListarRegistros()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Producto producto;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado())
        {
            producto.MostrarProductoEnConsola();
        }
        cout << "---------------------------" << endl;
    }
    CerrarArchivo(pArchivo);
    return true;
}
///Fin de ABML

int ArchivoProducto::ObtenerProximoID()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return 1;
    Producto producto;
    int maxID = 0;

    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if (producto.getIDProducto() > maxID)
        {
            maxID = producto.getIDProducto();
        }
    }
    CerrarArchivo(pArchivo);
    return maxID + 1;
}

Producto ArchivoProducto::BuscarRegistroPorID(int ID)
{
    Producto producto;
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return producto;

    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado() && producto.getIDProducto() == ID)
        {
            CerrarArchivo(pArchivo);
            return producto;
        }
    }
    ///Si no lo encuentra, devuelve uno vacio.
    CerrarArchivo(pArchivo);
    return Producto();
}

bool ArchivoProducto::ExisteID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if (pArchivo == nullptr)
        return false;
    Producto producto;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado() && producto.getIDProducto() == ID)
        {
            CerrarArchivo(pArchivo);
            return true;
        }
    }
    CerrarArchivo(pArchivo);
    return false;
}

bool ArchivoProducto::ListarProducto()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Producto producto;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(producto.getEstado())
        {
            producto.MostrarProducto();
        }
        cout << "---------------------------" << endl;
    }
    CerrarArchivo(pArchivo);
    return true;
}

int ArchivoProducto::ObtenerObjetosTotales()
{
    FILE * pArchivo = AbrirArchivo("rb");
    Producto producto;
    int objetosTotales = 0;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(!producto.getEstado())
        {
            cout << "Debug: Producto "<< producto.getIDProducto() << " dado de baja" << endl;
            continue;
        }
        objetosTotales += producto.getStockActual();
    }
    CerrarArchivo(pArchivo);
    return objetosTotales;

}
int ArchivoProducto::ObtenerValorDelInventarioActual()
{
    FILE * pArchivo = AbrirArchivo("rb");
    Producto producto;
    int valorInventario = 0;
    int objetosTotales = 0;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(!producto.getEstado())
        {
            cout << "Debug: Producto "<< producto.getIDProducto() << " dado de baja" << endl;
            continue;
        }
        objetosTotales += producto.getStockActual();
        valorInventario += producto.getStockActual()*producto.getPrecioUnitario();
    }
    CerrarArchivo(pArchivo);
    return valorInventario;
}

void ArchivoProducto::MostrarProductoConSobreStock()
{
    FILE * pArchivo = AbrirArchivo("rb");
    Producto producto;
    int objetosTotales = 0;
    bool haySobrestock = false;
    while(fread(&producto,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(!producto.getEstado() ||
        producto.getStockActual() <= producto.getStockMax())
        {
            continue;
        }
        int sobrestock = (-1) * (producto.getStockMax() - producto.getStockActual());
        haySobrestock = true;
        cout << "=====================================" << endl;
        cout << producto.getNombreProducto() << endl;
        cout << "Tiene un sobrestock de " << sobrestock << " unidades." << endl;
    }
        cout << "=====================================" << endl;
        if(!haySobrestock)
        {
            cout << "No Hay Sobrestock de productos." << endl;
            cout << "=====================================" << endl;
        }
        CerrarArchivo(pArchivo);
        system("Pause");
}
