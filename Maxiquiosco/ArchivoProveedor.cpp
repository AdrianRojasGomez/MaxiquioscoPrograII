# include<iostream>
#include <cstring>
#include "Proveedor.h"
#include "ArchivoProveedor.h"
#include "ValidadorInputs.h"

using namespace std;

ArchivoProveedor::ArchivoProveedor()
{
    strcpy(_nombreArchivo,_nombre);
    _tamanoRegistro = sizeof(Proveedor);
}

///Inicio ABML
bool ArchivoProveedor::AgregarRegistro(Proveedor& proveedor)
{
    FILE* pArchivo = AbrirArchivo("ab");
    if(pArchivo == nullptr)
        return false;
    fwrite(&proveedor, _tamanoRegistro, 1, pArchivo);
    CerrarArchivo(pArchivo);
    return true;
}
bool ArchivoProveedor::BajaRegistro(int ID)
{
    FILE* pArchivo = AbrirArchivo("rb+");
    if(pArchivo == nullptr)
        return false;
    Proveedor proveedor;
    int posicion = 0;
    while(fread(&proveedor,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            cout << "Proveedor Encontrado: " << endl;
            proveedor.MostrarProveedorEnColsola();
            proveedor.setEstado(false);
            fseek(pArchivo, posicion * _tamanoRegistro, SEEK_SET);
            fwrite(&proveedor, _tamanoRegistro, 1, pArchivo);
            CerrarArchivo(pArchivo);
            return true;
        }
        posicion++;
    }
    CerrarArchivo(pArchivo);
    return false;
}
bool ArchivoProveedor::ModificarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Proveedor proveedor;
    int posicion = 0;
    while(fread(&proveedor,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            bool esModificable = false;
            cout << "Producto Encontrado: " << endl;
            proveedor.MostrarProveedorEnColsola();
            int aux;
            do
            {
                string opcion;
                cout << "Elija la opcion a Editar" << endl;
                cout << "1. DNI\n2. CUIT\n3. Num. Telefono\n4. Nombre del Proveedor" << endl;
                cout << "5. Email\n6. Direccion Fisica\n0. No Modificar\nOpcion: ";
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
                    int dni;
                    string dniInput;
                    cin >> dniInput;
                    if(!ValidadorInputs::SonSoloNumeros(dniInput))
                    {
                        cout << "Error: Ingrese solo numeros" << endl;
                        aux = -1;
                        break;
                    }
                    dni = stoi(dniInput);
                    proveedor.setDNI(dni);
                    esModificable = true;
                    break;
                }
                case 2:
                {
                    char cuit[Proveedor::TAMANO_CAMPO];
                    string cuitInput;
                    cin >> cuitInput;
                    if(!ValidadorInputs::TamanoPermitido(cuitInput, Proveedor::TAMANO_CAMPO)|| !ValidadorInputs::SonSoloNumeros(cuitInput))
                    {
                        cout << "Error: Ingrese solo los digitos del CUIT, con un maximo de 50 caracteres" << endl;
                        aux = -1;
                        break;
                    }
                    strcpy(cuit, cuitInput.c_str());
                    proveedor.setCUIT(cuit);
                    esModificable = true;
                    break;
                }
                case 3:
                {
                    char telefono[Proveedor::TAMANO_CAMPO];
                    string telefonoInput;
                    cin >> telefonoInput;
                    if(!ValidadorInputs::TamanoPermitido(telefonoInput, Proveedor::TAMANO_CAMPO) || !ValidadorInputs::SonSoloNumeros(telefonoInput))
                    {
                        cout << "Error: Asegurese de solo introducir numeros y un total menor a 50 digitos" << endl;
                        aux = -1;
                        break;
                    }
                    strcpy(telefono, telefonoInput.c_str());
                    proveedor.setNumeroTelefono(telefono);
                    esModificable = true;
                    break;
                }
                case 4:
                {
                    char nombre[Proveedor::TAMANO_CAMPO];
                    string nombreInput;
                    cin >> nombreInput;
                    if(!ValidadorInputs::TamanoPermitido(nombreInput, Proveedor::TAMANO_CAMPO))
                    {
                        cout << "Error: Asegurese que el nombre sea menor a 50 Caracteres" << endl;
                        aux = -1;
                        break;
                    }
                    strcpy(nombre, nombreInput.c_str());
                    proveedor.setNombreProveedor(nombre);
                    esModificable = true;
                    break;
                }
                case 5:
                {
                    char email[Proveedor::TAMANO_CAMPO];
                    string emailInput;
                    cin >> emailInput;
                    if(!ValidadorInputs::TamanoPermitido(emailInput, Proveedor::TAMANO_CAMPO))
                    {
                        cout << "Error: Asegurese que el email sea menor a 50 Caracteres" << endl;
                        aux = -1;
                        break;
                    }
                    strcpy(email, emailInput.c_str());
                    proveedor.setEmail(email);
                    esModificable = true;
                    break;
                }
                case 6:
                {
                    char direccion[Proveedor::TAMANO_CAMPO];
                    string direccionInput;
                    cin >> direccionInput;
                    if(!ValidadorInputs::TamanoPermitido(direccionInput, Proveedor::TAMANO_CAMPO))
                    {
                        cout << "Error: Asegurese que la direccion sea menor a 50 caracteres" << endl;
                        aux = -1;
                        break;
                    }
                    strcpy(direccion, direccionInput.c_str());
                    proveedor.setEmail(direccion);
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
            fwrite(&proveedor, _tamanoRegistro, 1, pArchivo);
            CerrarArchivo(pArchivo);
            return true;
        }
        posicion++;
    }
    CerrarArchivo(pArchivo);
    return false;
}

bool ArchivoProveedor::ListarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Proveedor proveedor;
    while(fread(&proveedor,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado() && proveedor.getIDProveedor() == ID)
        {
            proveedor.MostrarProveedorEnColsola();
        }
    }
    cout << "=============================" << endl;
    CerrarArchivo(pArchivo);
}
bool ArchivoProveedor::ListarRegistros()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return false;
    Proveedor proveedor;
    while(fread(&proveedor,_tamanoRegistro,1,pArchivo) == 1)
    {
        if(proveedor.getEstado())
        {
            proveedor.MostrarProveedorEnColsola();
        }
        cout << "---------------------------" << endl;
    }
    CerrarArchivo(pArchivo);
}

///Operacion Interna
int ArchivoProveedor::ObtenerProximoID()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
        return 1;
    Proveedor proveedor;
    int maxID = 0;

    while(fread(&proveedor,_tamanoRegistro,1,pArchivo) == 1)
    {
        if (proveedor.getIDProveedor() > maxID)
        {
            maxID = proveedor.getIDProveedor();
        }
    }
    CerrarArchivo(pArchivo);
    return maxID + 1;
}
bool ArchivoProveedor::ExisteID(int ID)
{

}

///Operacion Para Compras
Proveedor ArchivoProveedor::BuscarRegistroPorID(int ID)
{

}
