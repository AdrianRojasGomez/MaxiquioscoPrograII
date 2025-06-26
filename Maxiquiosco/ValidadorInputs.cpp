#include <iostream>
#include <string>
#include <cstring>
#include "ValidadorInputs.h"

using namespace std;


bool ValidadorInputs::EsUnDigito(const string &input)
{
    if (input.empty())
    {
        return false;
    }
    if(input.length() != 1)
    {
        cout << "Error: Ingrese un solo digito." << endl;
        return false;
    }

    if (input[0] >= '0' && input[0] <= '9')
    {
        ///DEBUG MSG: cout << "Ingreso Aprobado." << endl;
        return true;
    }

    cout << "Error: Ingrese un solo digito." << endl;
    return false;

}

bool ValidadorInputs::SonSoloNumeros(const string &input)
{

    if (input.empty())
    {
        return false;
    }

    char *cadena = new char[input.size() + 1];
    strcpy(cadena, input.c_str());

    int i = 0;
    while (cadena[i] != '\0')
    {
        if (cadena[i] < '0' || cadena[i] > '9')
        {
            delete[] cadena;
            return false;
        }
        ++i;
    }
    delete[] cadena;
    ///DEBUG MSG: cout << "Ingreso Aprobado." << endl;
    return true;
}

bool ValidadorInputs::EsFloat(const string &input)
{
    if (input.empty())
    {
        return false;
    }

    char *cadena = new char[input.size() + 1];
    std::strcpy(cadena, input.c_str());

    int  i                = 0;
    bool hayPunto         = false;
    bool hayDigitos       = false;
    bool hayDigitosDesp   = false;

    ///Chequear signos y puntos
    if (cadena[i] == '+' || cadena[i] == '-') {
        ++i;
    }

    while (cadena[i] != '\0')
    {
        if (cadena[i] == '.') {
            if (hayPunto || cadena[i + 1] == '\0') {
                delete[] cadena;
                return false;
            }
            hayPunto = true;
        }
        else if (cadena[i] >= '0' && cadena[i] <= '9') {
            hayDigitos = true;
            if (hayPunto) {
                hayDigitosDesp = true;
            }
        }
        else {
            delete[] cadena;
            return false;
        }
        ++i;
    }
    delete[] cadena;
    return hayDigitos && (!hayPunto || hayDigitosDesp);
}

bool ValidadorInputs::TamanoPermitido(const string &input, int limite)
{
    if (input.empty())
    {
        return false;
    }
    /// Levanta warning pero es porque size() devuelve un tipo de dato size_t
    /// pero igual devuelve uno por cada caracter, entonces al compararlo con el limite funciona
    /// perfecto. Podriamos castearlo a size_t el limite pero da igual.
    if(input.size() > limite)
    {
        return false;
    }
    return true;
}

bool ValidadorInputs::MesValido(const string &input)
{
    if (input.empty())
    {
        return false;
    }

    if(!SonSoloNumeros(input))
    {
        return false;
    }
    int mes = stoi(input);
     if(mes < 1 || mes > 12)
        return false;
    else
        return true;
}

bool ValidadorInputs::DiaValido(const std::string &input, int mes)
{
    if (input.empty())
    {
        return false;
    }
    if(!SonSoloNumeros(input))
        return false;

    int dia = std::stoi(input);

    if(mes < 1 || mes > 12)
        return false;

    int maxDias;

    switch (mes)
    {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            maxDias = 31;
            break;

        case 4: case 6: case 9: case 11:
            maxDias = 30;
            break;

        case 2:
            maxDias = 29;
            break;
    }

    if(dia < 1 || dia > maxDias)
        return false;
    else
        return true;
}

bool ValidadorInputs::AnioValido(const string &input)
{
    if (input.empty())
    {
        return false;
    }

    if(!SonSoloNumeros(input))
        return false;

    if(input.empty() || input.size() > 4)
        return false;

    int anio = stoi(input);

    if(anio < 1900 || anio > 2100)
        return false;
    else
        return true;
}
