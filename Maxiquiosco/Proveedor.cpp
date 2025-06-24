#include "Proveedor.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

Proveedor::Proveedor()
{
    _idProveedor = 0;
    _dni = 0;
    strcpy(_cuit,"");
    strcpy(_numeroTelefono,"");
    strcpy(_nombreProveedor,"");
    strcpy(_email,"");
    strcpy(_direccion,"");
    _estado = false;
}

Proveedor::Proveedor(int idProveedor, int dni, char * cuit, char * numeroTelefono,
                     char * nombreProveedor, char * email, char * direccion)
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

void Proveedor::MostrarProveedorEnColsola() const
{
        cout << "ID Proveedor: " << _idProveedor <<endl;
        cout << "DNI: " << _dni <<endl;
        cout << "CUIT: " << _cuit <<endl;
        cout << "N# de Telefono: " << _numeroTelefono <<endl;
        cout << "Nombre del Proveedor: " << _nombreProveedor <<endl;
        cout << "Email: " << _email <<endl;
        cout << "Direccion: " << _direccion <<endl;
}
void Proveedor::MostrarProveedor() const
{
        cout << "ID Proveedor: " << _idProveedor << " - CUIT: " << _cuit <<" - Nombre del Proveedor: " << _nombreProveedor <<endl;
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
char *  Proveedor::getCUIT()
{
    return _cuit;
}
void Proveedor::setCUIT(char * cuit)
{
    strcpy(_cuit, cuit);
}

char *  Proveedor::getNumeroTelefono()
{
    return _numeroTelefono;
}
void Proveedor::setNumeroTelefono(char * numeroTelefono)
{
    strcpy(_numeroTelefono,numeroTelefono);
}
char * Proveedor::getNombreProveedor()
{
    return _nombreProveedor;
}
void  Proveedor::setNombreProveedor(char* nombreProveedor)
{
    strcpy(_nombreProveedor, nombreProveedor);
}
char * Proveedor::getEmail()
{
    return _email;
}
void  Proveedor::setEmail( char* email)
{
    strcpy(_email,email);
}
char * Proveedor::getDireccion()
{
    return _direccion;
}
void  Proveedor::setDireccion( char* direccion)
{
    strcpy(_direccion,direccion);
}
bool Proveedor::getEstado()
{
    return _estado;
}
void Proveedor::setEstado(bool estado)
{
    _estado = estado;
}
