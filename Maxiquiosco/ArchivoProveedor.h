#pragma once
#include "ArchivoBase.h"
#include "Proveedor.h"

class ArchivoProveedor : public ArchivoBase
{
private:
    const char* _nombre = "ArchivoProveedor.dat";

public:
    ArchivoProveedor();

    ///ABML
    bool AgregarRegistro(Proveedor& proveedor);
    bool BajaRegistro(int ID);
    bool ModificarRegistroPorID(int ID);
    bool ListarRegistroPorID(int ID);
    bool ListarRegistros();

    ///Operacion Interna
    int ObtenerProximoID();
    bool ExisteID(int ID);

    ///Operacion Para Compras
    Proveedor BuscarRegistroPorID(int ID);

};

