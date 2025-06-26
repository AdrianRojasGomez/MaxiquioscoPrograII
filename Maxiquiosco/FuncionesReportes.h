#pragma once
#include <string>


class FuncionesReportes
{
private:
    std::string _meses[12];

public:

    FuncionesReportes();

    void MostrarComprasTotalesPorProveedor();
    void MostrarComprasPorTipoDeProducto();
    void MostrarDistribucionMensualDeCompras();
    void MostrarValorTotalDelInventario();
    void MostrarSobreStock();
};
