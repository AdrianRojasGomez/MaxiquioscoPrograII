#pragma once
#include <iostream>

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    void setDia(int dia);
    int getMes();
    void setMes(int mes);
    int getAnio();
    void setAnio(int anio);

friend std::istream& operator>>(std::istream& in, Fecha& f);

};

