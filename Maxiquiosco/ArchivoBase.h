#pragma once
#include <cstdio>


class ArchivoBase
{
protected:
    char _nombreArchivo[50];
    int _tamanoRegistro;

    FILE* AbrirArchivo(const char* modo);
    void CerrarArchivo(FILE* pArchivo);

public:
    ArchivoBase();
    ArchivoBase(const char* nombre, int tamanoRegistro);

};

