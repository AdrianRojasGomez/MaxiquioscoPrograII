#include "Fecha.h"


    Fecha::Fecha()
    {
        _dia = 0;
        _mes = 0;
        _anio = 0;
    }
    Fecha::Fecha(int dia, int mes, int anio)
    {
        setDia(dia);
        setMes(mes);
        setAnio(anio);
    }

    int Fecha::getDia()
    {
        return _dia;
    }
    void Fecha::setDia(int dia)
    {
        _dia = dia;
    }
    int Fecha::getMes()
    {
        return _mes;
    }
    void Fecha::setMes(int mes)
    {
        _mes = mes;
    }
    int Fecha::getAnio()
    {
        return _anio;
    }
    void Fecha::setAnio(int anio)
    {
        _anio = anio;
    }



