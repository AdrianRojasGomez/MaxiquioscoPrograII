#pragma once
#include <string>

class ValidadorInputs
{
public:
    static bool EsUnDigito(const std::string &input);
    static bool SonSoloNumeros(const std::string &input);
    static bool EsFloat(const std::string &input);
    static bool TamanoPermitido(const std::string &input, int limite);
    static bool MesValido(const std::string &input);
    static bool DiaValido(const std::string &input, int mes);
    static bool AnioValido(const std::string &input);


};

