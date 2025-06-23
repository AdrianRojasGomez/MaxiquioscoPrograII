#include <iostream>
#include <cstring>
#include "ArchivoTipoProducto.h"
#include "TipoProducto.h"

using namespace std;

ArchivoTipoProducto::ArchivoTipoProducto()
{
    strcpy(_nombreArchivo, _nombre);
    _tamanoRegistro = sizeof(TipoProducto);
    InicializarArchivo();
}
void ArchivoTipoProducto::InicializarArchivo()
{

    FILE * pNuevoArchivo = AbrirArchivo("wb");
    if(pNuevoArchivo == nullptr)
    {
        cout << "Error Critico: No se pudo crear el archivo de tipos de Producto" << endl;
        return;
    }
    TipoProducto tipos[50];
    ObtenerTipos(tipos);
    fwrite(tipos,_tamanoRegistro, 50, pNuevoArchivo);
    CerrarArchivo(pNuevoArchivo);
}

void ArchivoTipoProducto::ObtenerTipos(TipoProducto tipos[])
{
    tipos[0]  = TipoProducto(1,  "Bebidas");
    tipos[1]  = TipoProducto(2,  "Comestibles");
    tipos[2]  = TipoProducto(3,  "Lacteos");
    tipos[3]  = TipoProducto(4,  "Carnes");
    tipos[4]  = TipoProducto(5,  "Limpieza");
    tipos[5]  = TipoProducto(6,  "Panaderia");
    tipos[6]  = TipoProducto(7,  "Verduras");
    tipos[7]  = TipoProducto(8,  "Frutas");
    tipos[8]  = TipoProducto(9,  "Congelados");
    tipos[9]  = TipoProducto(10, "Pescados");
    tipos[10] = TipoProducto(11, "Huevos");
    tipos[11] = TipoProducto(12, "Cereales");
    tipos[12] = TipoProducto(13, "Snacks");
    tipos[13] = TipoProducto(14, "Dulces");
    tipos[14] = TipoProducto(15, "Salsas");
    tipos[15] = TipoProducto(16, "Aceites");
    tipos[16] = TipoProducto(17, "Vinagres");
    tipos[17] = TipoProducto(18, "Condimentos");
    tipos[18] = TipoProducto(19, "Especias");
    tipos[19] = TipoProducto(20, "Infusiones");
    tipos[20] = TipoProducto(21, "Cafe");
    tipos[21] = TipoProducto(22, "Te");
    tipos[22] = TipoProducto(23, "Jugos");
    tipos[23] = TipoProducto(24, "Aguas");
    tipos[24] = TipoProducto(25, "Refrescos");
    tipos[25] = TipoProducto(26, "Bebidas Alcoholicas");
    tipos[26] = TipoProducto(27, "Bebidas Sin Alcohol");
    tipos[27] = TipoProducto(28, "Productos Panaderia");
    tipos[28] = TipoProducto(29, "Pasteleria");
    tipos[29] = TipoProducto(30, "Helados");
    tipos[30] = TipoProducto(31, "Abarrotes");
    tipos[31] = TipoProducto(32, "FrutosSecos");
    tipos[32] = TipoProducto(33, "Legumbres");
    tipos[33] = TipoProducto(34, "Harinas");
    tipos[34] = TipoProducto(35, "Azucar");
    tipos[35] = TipoProducto(36, "Sal");
    tipos[36] = TipoProducto(37, "Productos Dieteticos");
    tipos[37] = TipoProducto(38, "Suplementos");
    tipos[38] = TipoProducto(39, "Organicos");
    tipos[39] = TipoProducto(40, "Veganos");
    tipos[40] = TipoProducto(41, "SinGluten");
    tipos[41] = TipoProducto(42, "Higiene Personal");
    tipos[42] = TipoProducto(43, "Belleza");
    tipos[43] = TipoProducto(44, "Limpieza Hogar");
    tipos[44] = TipoProducto(45, "Mascotas");
    tipos[45] = TipoProducto(46, "Papeleria");
    tipos[46] = TipoProducto(47, "Electronica");
    tipos[47] = TipoProducto(48, "Ropa");
    tipos[48] = TipoProducto(49, "Calzado");
    tipos[49] = TipoProducto(50, "Ferreteria");
}

bool ArchivoTipoProducto::ListarResistros()
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
    {
      cout << "Error Critico: No se pudo Abrir el archivo de tipos de Producto" << endl;
      return false;
    }
    TipoProducto tipo;
    while (fread(&tipo, sizeof(TipoProducto), 1, pArchivo) == 1)
    {
        if(tipo.EsValido())
        {
            tipo.MostrarTipoProductoEnConsola();
        }
        cout << "----------------------------" << endl;
    }
    CerrarArchivo(pArchivo);
    return true;
}

bool ArchivoTipoProducto::ExisteID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
    {
        cout << "Error Critico: No se pudo Abrir el archivo de tipos de Producto" << endl;
        return false;
    }
    TipoProducto tipo;
    while (fread(&tipo, sizeof(TipoProducto), 1, pArchivo) == 1)
        {
        if (tipo.EsValido() &&tipo.getIDTipoProducto() == ID )
        {
            CerrarArchivo(pArchivo);
            return true;
        }
    }
    CerrarArchivo(pArchivo);
    return false;
}
TipoProducto ArchivoTipoProducto::BuscarRegistroPorID(int ID)
{
    FILE * pArchivo = AbrirArchivo("rb");
    if(pArchivo == nullptr)
    {
        cout << "Error Critico: No se pudo Abrir el archivo de tipos de Producto" << endl;
        return TipoProducto();
    }
    TipoProducto tipo;
    while (fread(&tipo, sizeof(TipoProducto), 1, pArchivo) == 1)
        {
        if (tipo.EsValido() &&tipo.getIDTipoProducto() == ID )
        {
            CerrarArchivo(pArchivo);
            return tipo;
        }
    }
    CerrarArchivo(pArchivo);
    return TipoProducto();
}
