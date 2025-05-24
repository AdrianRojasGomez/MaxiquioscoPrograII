#include <cstring>
#include <iostream>
#include "Proveedor.h"

using namespace std;

Proveedor::Proveedor()
{
    _idProveedor = 0;
    _dni = 0;
    _cuit = 0;
    _numeroTelefono = 0;
    std::strcpy(_nombreProveedor,"");
    std::strcpy(_email,"");
    std::strcpy(_direccion,"");
    _estado = false;
}

Proveedor::Proveedor(int idProveedor, int dni, int cuit, int numeroTelefono, char * nombreProveedor, char * email, char * direccion)
{
    setIDProveedor(idProveedor);
    setDNI(dni);
    setCUIT(cuit);
    setNumeroTelefono(numeroTelefono);
    setNombreProveedor(nombreProveedor);
    setEmail(email);
    setDireccion(direccion);
    setEstado(true);
}

void Proveedor::MostrarProveedor()
{
        cout << "ID Proveedor: " << _idProveedor <<endl;
        cout << "DNI: " << _dni <<endl;
        cout << "CUIT: " << _cuit <<endl;
        cout << "N° de Telefono: " << _numeroTelefono <<endl;
        cout << "Nombre del Proveedor: " << _nombreProveedor <<endl;
        cout << "Email: " << _email <<endl;
        cout << "Direccion: " << _direccion <<endl;
}


int Proveedor::getIDProveedor()
{
    return _idProveedor;
}
void Proveedor::setIDProveedor(int ID)
{
    _idProveedor = ID;
}

int  Proveedor::getDNI()
{
    return _dni;
}
void Proveedor::setDNI(int dni)
{
    _dni = dni;
}

int  Proveedor::getCUIT()
{
    return _cuit;
}
void Proveedor::setCUIT(int cuit)
{
    _cuit = cuit;
}

int  Proveedor::getNumeroTelefono()
{
    return _numeroTelefono;
}
void Proveedor::setNumeroTelefono(int numeroTelefono)
{
    _numeroTelefono = numeroTelefono;
}

char * Proveedor::getNombreProveedor()
{
    return _nombreProveedor;
}
void  Proveedor::setNombreProveedor(char* nombreProveedor)
{
    std::strcpy(_nombreProveedor, nombreProveedor);
}

char * Proveedor::getEmail()
{
    return _email;
}
void  Proveedor::setEmail( char* email)
{
    std::strcpy(_email,email);
}

char * Proveedor::getDireccion()
{
    return _direccion;
}
void  Proveedor::setDireccion( char* direccion)
{
    std::strcpy(_direccion,direccion);
}

bool Proveedor::getEstado()
{
    return _estado;
}
void Proveedor::setEstado(bool estado)
{
    _estado = estado;
}
