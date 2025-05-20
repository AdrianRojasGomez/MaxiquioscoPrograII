#include "TipoProducto.h"
#include <cstring>

    TipoProducto::TipoProducto()
    {
        _idTipoProducto = 0;
        std::strcpy(_clasificacionProducto,"");
    }
    TipoProducto::TipoProducto(int idTipoProducto, char * clasificacionProducto)
    {
        setIdTipoProducto(idTipoProducto);
        setClasificacionProducto(clasificacionProducto);
    }
    TipoProducto::TipoProducto(int idTipoProducto, std::string& clasificacionProducto)
    {
        setIdTipoProducto(idTipoProducto);
        setClasificacionProducto(clasificacionProducto);
    }

    int TipoProducto::getIdTipoProducto()
    {
        return _idTipoProducto;
    }
    void TipoProducto::setIdTipoProducto(int idTipoProducto)
    {
        _idTipoProducto = idTipoProducto;
    }
    char * TipoProducto::getClasificacionProducto()
    {
        return _clasificacionProducto;
    }
    void TipoProducto::setClasificacionProducto (char * clasificacionProducto)
    {
        std::strcpy(_clasificacionProducto, clasificacionProducto);
    }
    void TipoProducto::setClasificacionProducto (std::string& clasificacionProducto)
    {
        std::strcpy(_clasificacionProducto, clasificacionProducto.c_str());
    }
