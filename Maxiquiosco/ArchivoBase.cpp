#include "ArchivoBase.h"
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

ArchivoBase::ArchivoBase()
{
    strcpy(_nombreArchivo, "\0");
    _tamanoRegistro = 0;
}

ArchivoBase::ArchivoBase(const char* nombre, int tamanoRegistro)
{
    strcpy(_nombreArchivo, nombre);
    _tamanoRegistro = tamanoRegistro;
}

FILE* ArchivoBase::AbrirArchivo(const char* modo)
{
    FILE* p = fopen(_nombreArchivo, modo);
    return p;
}
void ArchivoBase::CerrarArchivo(FILE* pArchivo)
{
    if (pArchivo != nullptr)
    {
        fclose(pArchivo);
    }
}
