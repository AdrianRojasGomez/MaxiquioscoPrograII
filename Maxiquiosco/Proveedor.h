#pragma once

class Proveedor
{
public:
    Proveedor();
    Proveedor(int idProveedor, int dni, char * cuit, char * numeroTelefono,
               char * nombreProveedor, char * email, char * direccion);

    void MostrarProveedorEnColsola() const;
    void MostrarProveedor() const;
    int getIDProveedor();
    void setIDProveedor(int ID);

    int  getDNI();
    void setDNI(int dni);

    char *  getCUIT();
    void setCUIT(char* cuit);

    char * getNumeroTelefono();
    void setNumeroTelefono(char* numero);

    char * getNombreProveedor() ;
    void  setNombreProveedor(char* nombre);

    char * getEmail();
    void  setEmail( char* email);

    char * getDireccion();
    void  setDireccion( char* direccion);

    bool getEstado();
    void setEstado(bool estado);

    static const int TAMANO_CAMPO = 50;

private:
    int _idProveedor;
    int _dni;
    char _cuit[TAMANO_CAMPO];
    char _numeroTelefono[TAMANO_CAMPO];
    char _nombreProveedor[TAMANO_CAMPO];
    char _email[TAMANO_CAMPO];
    char _direccion [TAMANO_CAMPO];

    bool _estado;
};

