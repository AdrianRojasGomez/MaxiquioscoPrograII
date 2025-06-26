#include <iostream>
#include <cstring>
#include "ArchivoCompra.h"
#include "Compra.h"
#include "ArchivoProducto.h"
#include "ArchivoProveedor.h"
#include "Producto.h"
#include "Proveedor.h"
#include "ValidadorInputs.h"

using namespace std;

ArchivoCompra::ArchivoCompra()
{
    strcpy(_nombreArchivo, _nombre);
    _tamanoRegistro = sizeof(Compra);
}

///Inicio ABML
bool ArchivoCompra::AgregarRegistro(Compra compra)
{
    FILE * pArchivo = AbrirArchivo("ab");
    if(pArchivo == nullptr)
        return false;
    fwrite(&compra, _tamanoRegistro,1,pArchivo);
    CerrarArchivo(pArchivo);
    return true;
}
bool ArchivoCompra::BajaRegistro(int ID)
{
    FILE* pArchivo = AbrirArchivo("rb+");
    if(pArchivo)
        return false;
    Compra compra;
    int posicion = 0;
    while(fread(&compra,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado() && compra.getIDCompra())
        {
            cout << "Compra Encontrada: " << endl;
            compra.MostrarCompraEnConsola();
            compra.setEstado(false);
            fseek(pArchivo, posicion * _tamanoRegistro, SEEK_SET);
            fwrite(&compra, _tamanoRegistro, 1, pArchivo);
            CerrarArchivo(pArchivo);
            return true;
        }
        posicion++;
    }
    CerrarArchivo(pArchivo);
    return false;
}
bool ArchivoCompra::ModificarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb+");
    if(pArchivo == nullptr)
        return false;
    Compra compra;
    int posicion = 0;
    while(fread(&compra,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(!compra.getEstado() || compra.getIDCompra() != ID)
        {
            posicion++;
            continue;
        }
        bool esModificable = false;
        cout << "Compra Encontrada: " << endl;
        compra.MostrarCompraEnConsola();
        int aux;
        do
        {
            string opcion;
            cout << "Elija la opcion a Editar" << endl;
            cout << "1. Producto\n2. Proveedor\n3. Cantidad Comprada" << endl;
            cout << "\n4. Importe\n5. Fecha\n0. No Modificar\nOpcion: ";
            cin >> opcion;
            if(!ValidadorInputs::EsUnDigito(opcion))
            {
                aux = -1;
                continue;
            }
            aux = stoi(opcion);
            switch(aux)
            {
            case 1:
            {
                ArchivoProducto archivoProducto;
                Producto producto;
                int ID;
                cout << "Ingrese el ID del nuevo producto" << endl;
                cin >> opcion;
                if(!ValidadorInputs::SonSoloNumeros(opcion))
                {
                    cout << "Ingrese solo numeros" << endl;
                    aux = -1;
                    break;
                }
                ID = stoi(opcion);
                if(!archivoProducto.ExisteID(ID))
                {
                    cout << "Error: El ID no existe." << endl;
                    cout << "Compra no modificada." << endl;
                    aux = -1;
                    break;
                }
                producto = archivoProducto.BuscarRegistroPorID(ID);
                compra.setProducto(producto);
                esModificable = true;
            }
            case 2:
            {
                ArchivoProveedor archivoProveedor;
                Proveedor proveedor;
                int ID;
                cout << "Ingrese el ID del nuevo proveedor" << endl;
                cin >> opcion;
                if(!ValidadorInputs::SonSoloNumeros(opcion))
                {
                    cout << "Ingrese solo numeros" << endl;
                    aux = -1;
                    break;
                }
                ID = stoi(opcion);
                if(!archivoProveedor.ExisteID(ID))
                {
                    cout << "Error: El ID no existe." << endl;
                    cout << "Compra no modificada." << endl;
                    aux = -1;
                    break;
                }
                proveedor = archivoProveedor.BuscarRegistroPorID(ID);
                compra.setProveedor(proveedor);
                esModificable = true;
            }
            case 3:
            {
                int cantidadComprada;
                string cantidadCompradaInput;
                cout << "Ingrese la cantidad Comprada" << endl;
                cin >> cantidadCompradaInput;
                if(!ValidadorInputs::SonSoloNumeros(cantidadCompradaInput))
                {
                    cout << "Ingrese solo numeros" << endl;
                    aux = -1;
                    break;
                }
                cantidadComprada = stoi(cantidadCompradaInput);
                    compra.setCantidadComprada(cantidadComprada);
                    esModificable = true;
                    break;
                }
            case 4:
                {
                    int importe;
                    string importeInput;
                    cout << "Ingrese el importe a modificar" << endl;
                    cin >> importeInput;
                    if(!ValidadorInputs::SonSoloNumeros(importeInput))
                    {
                        cout << "Ingrese solo numeros" << endl;
                        aux = -1;
                        break;
                    }
                    importe = stoi(importeInput);
                    compra.setImporte(importe);
                    esModificable = true;
                    break;
                }
            case 5:
                {
                    Fecha fecha;
                    string fechaInput;
                    cout << "Ingrese el mes" << endl;
                    cin >> fechaInput;
                    if(!ValidadorInputs::MesValido(fechaInput))
                    {
                        cout << "Ingrese un Mes valido (Numeros del 1 al 12)" << endl;
                        aux = -1;
                        break;
                    }
                    int fechaMes;
                    fechaMes = stoi(fechaInput);
                    fecha.setMes(fechaMes);
                    cout << "Ingrese el del mes" << endl;
                    cin >> fechaInput;
                    if(!ValidadorInputs::DiaValido(fechaInput,fechaMes))
                    {
                        cout << "Ingrese un dia valido (Numeros del 1 al 31)" << endl;
                        aux = -1;
                        break;
                    }
                    int fechaDia;
                    fechaDia = stoi(fechaInput);
                    fecha.setMes(fechaDia);
                    cout << "Ingrese el anio" << endl;
                    cin >> fechaInput;
                    if(!ValidadorInputs::AnioValido(fechaInput))
                    {
                        cout << "Ingrese un dia valido" << endl;
                        aux = -1;
                        break;
                    }
                    int fechaAnio;
                    fechaAnio = stoi(fechaInput);
                    fecha.setMes(fechaAnio);

                    compra.setFechaCompra(fecha);
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
        fwrite(&compra, _tamanoRegistro, 1, pArchivo);
        CerrarArchivo(pArchivo);
        return true;
    }
    CerrarArchivo(pArchivo);
    return false;
}
bool ArchivoCompra::ListarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Compra compra;
    while(fread(&compra,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado() && compra.getIDCompra() == ID)
        {
            compra.MostrarCompraEnConsola();
        }
    }
    cout << "=============================" << endl;
    CerrarArchivo(pArchivo);
    return true;
}
bool ArchivoCompra::ListarRegistros()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Compra compra;
    while(fread(&compra,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(compra.getEstado())
        {
            compra.MostrarCompraEnConsola();
        }
        cout << "---------------------------" << endl;
    }
    CerrarArchivo(pArchivo);
    return true;
}
///Fin de ABML

int ArchivoCompra::ObtenerProximoID()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return 1;
    Compra compra;
    int maxID = 0;

    while(fread(&compra,_tamanoRegistro,1,pArchivo) == 1)
    {
        if (compra.getIDCompra() > maxID)
        {
            maxID = compra.getIDCompra();
        }
    }
    CerrarArchivo(pArchivo);
    return maxID + 1;
}

int ArchivoCompra::ObtenerImporteTotalPorMes(int mes, int anio)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return 1;
    Compra compra;
    int importePorMes = 0;

    while(fread(&compra,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(!compra.getEstado())
        {
            continue;
        }

        if(compra.getFechaCompra().getAnio() != anio ||
                compra.getFechaCompra().getMes() != mes)
        {
            continue;
        }
        importePorMes += compra.getImporte();
    }
    CerrarArchivo(pArchivo);
    return importePorMes;

}
