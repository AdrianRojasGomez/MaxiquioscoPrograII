#pragma once
#include "Fecha.h"

class Compra {
private:
    int _idCompra;
    Fecha _fechaCompra;
    int _idProducto;
    int _idProveedor;
    int _cantidadComprada;
    float _importeTotal;
    bool _estado;
    char _idNombreProducto[20];

public:
    Compra();
    Compra(int idCompra, int idProducto,const char* idNombreProducto, int idProveedor, int cantidad, Fecha fecha, float precioUnitario);

    void setIdCompra(int idCompra);
    void setFechaCompra(Fecha fecha);
    Fecha getFechaCompra() const;
    void setIdProducto(int idProducto);
    bool setidNombreProducto(const char* idNombreProducto);

    void setIdProveedor(int idProveedor);
    void setCantidadComprada(int cantidad);
    void setEstado(bool estado);
    void setImporteTotal(float importeTotal);

    int getIdCompra() const;
    int getIdProducto() const;
    const char* getidNombreProducto() const;
    int getIdProveedor() const;
    int getCantidadComprada() const;
    float getImporteTotal() const;
    bool getEstado() const;
    char getidNombreProducto();
    void cargarCompra();
    void mostrarCompra() const;
};
