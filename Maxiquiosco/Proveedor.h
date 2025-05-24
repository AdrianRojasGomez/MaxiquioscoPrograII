#pragma once

class Proveedor
{
private:

    int _idProveedor;
    int _dni;
    int _cuit;
    int _numeroTelefono;

    char _nombreProveedor[20];
    char _email[20];
    char _direccion [50];

    bool _estado;

public:
    Proveedor();
    Proveedor(int idProveedor, int dni, int cuit, int numeroTelefono, char * nombreProveedor, char * _email, char * direccion);

    void AgregarProveedores();

    int getIDProveedor();
    void setIDProveedor(int ID);

    int  getDNI();
    void setDNI(int dni);

    int  getCUIT();
    void setCUIT(int cuit);

    int  getNumeroTelefono();
    void setNumeroTelefono(int numero);

    char * getNombreProveedor() ;
    void  setNombreProveedor(char* nombre);

    char * getEmail();
    void  setEmail( char* email);

    char * getDireccion();
    void  setDireccion( char* direccion);

    bool getEstado();
    void setEstado(bool estado);


};
