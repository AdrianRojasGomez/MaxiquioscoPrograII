# TP Final Programación II - Grupo 12

**Carrera:** Técnico Universitario en Programación  
**Materia:** Programación II  
**Tema:** TP Final  

---

## Integrantes de la cátedra

- Tapia, Ariel – Profesor  
- Kloster, Daniel – Profesor  
- Wenner, Maximiliano – Ayudante  
- Lara Campos, Brian – Ayudante  
- Carbonari, Verónica – Ayudante  

## Integrantes del grupo 12

- Adrián Rojas  
- Esteban González  

---

## INTRODUCCIÓN

El presente proyecto tiene como objetivo el desarrollo de un sistema de gestión de archivos orientado a la administración de compras en un maxikiosco. El sistema permitirá mantener un registro organizado y eficiente de productos, proveedores y compras. A través de una interfaz basada en menús, los usuarios podrán gestionar stock, precios, tipos de productos y realizar consultas sobre movimientos históricos de compras.

---

## DESCRIPCIÓN DETALLADA DEL SISTEMA

### Funcionalidades principales

El sistema tiene como objetivo principal mantener actualizada y organizada la información de las siguientes entidades:

#### 1. Proveedores
Se gestiona un registro completo de los proveedores del maxikiosco, almacenando:

- Identificación (ID de proveedor, DNI y CUIT)
- Datos personales y de contacto (nombre, teléfono, email y dirección)  
- Archivo: `ArchivoProveedor.dat`

#### 2. Productos
Se administran todos los productos disponibles para la venta. Cada producto incluye:

- ID del producto  
- Nombre del producto  
- Tipo de producto (referenciado por ID)  
- Precio unitario  
- Stock actual y stock máximo  
- Archivo: `ArchivoProducto.dat`

#### 3. Tipos de Producto

Listado de categorías de productos (golosinas, bebidas, limpieza, etc.):

- ID único  
- Descripción  
- Archivo: `ArchivoTipoProducto.dat`

#### 4. Compras

Registro de compras realizadas por el maxikiosco:

- ID de compra  
- Producto adquirido  
- Proveedor  
- Fecha  
- Cantidad  
- Importe total  
- Archivo: `ArchivoCompras.dat`

---

### Archivos utilizados

- `ArchivoProveedor.dat`:  
  `idProveedor, dni, cuit, nombreProveedor, numeroTelefono, email, direccion`

- `ArchivoProducto.dat`:  
  `idProducto, nombreProducto, idTipoProducto, precioUnitario, stockActual`

- `ArchivoTipoProducto.dat`:  
  `idTipoProducto, tipoDeProducto`

- `ArchivoCompras.dat`:  
  `idCompra, idProveedor, idProducto, fechaCompra, cantidadComprada, importeTotal`

---

## MODULOS A DESARROLLAR

### Proveedor
```cpp
class Proveedor
{
public:
    Proveedor();
    Proveedor(int idProveedor, int dni, char * cuit, char * numeroTelefono,
    char * nombreProveedor, char * email, char * direccion);
    void MostrarProveedorEnColsola() const;
    void MostrarProveedor() const;
    int getIDProveedor();
    void setIDProveedor(int ID);
    static const int TAMANO_CAMPO = 50;
private:
    int _idProveedor, _dni;
    char _cuit[TAMANO_CAMPO], _numeroTelefono[TAMANO_CAMPO], _nombreProveedor[TAMANO_CAMPO]
    _email[TAMANO_CAMPO], char _direccion [TAMANO_CAMPO];
    bool _estado;
```

### Producto
```cpp
class Producto
{
public:
    Producto();
    Producto(int ID, int stockActual, int stockMax,
    const char *nombre, TipoProducto tipo, float precio, bool estado);
    TipoProducto getTipoProducto() const;
    void MostrarProductoEnConsola() const;
    void MostrarProducto() const;

    static const int TAMANO_NOMBRE = 50;
private:
    int _idProducto, _stockActual, _stockMax;
    char _nombreProducto[TAMANO_NOMBRE];
    TipoProducto _tipoProducto;
    float _precioUnitario;
    bool _estado;
};
```

### TipoProducto
```cpp
#pragma once

class TipoProducto
{
private:
    int _idTipoProducto, _tamTipoProducto;
    char _clasificacionProducto[50];
public:

    TipoProducto();
    TipoProducto(int id, const char* clasificacion);
    bool EsValido() const;
    void MostrarTipoProductoEnConsola() const;

    int getIDTipoProducto() const;
    void setIDTipoProducto(int id);
    int getTamTipoProducto() const;
    const char * getClasificacionProducto() const;
};
```

### Compra
```cpp
class Compra
{
public:
    Compra();
    Compra(int IDCompra, Producto producto, Proveedor proveedor,
    int cantidadComprada, Fecha fecha, float importe, bool estado);

    void setFechaCompra(Fecha fecha);
    Fecha getFechaCompra() const;
    void setProducto(Producto producto);
    Producto getProducto();
    void setProveedor(Proveedor proveedor);
    Proveedor getProveedor();

    void MostrarCompraEnConsola() const;
    static const int TAMANO_CAMPO = 20;
private:
    int _IDCompra, _cantidadComprada;
    Fecha _fechaCompra;
    Producto _producto;
    Proveedor _proveedor;
    float _importe;
    bool _estado;

};
```

### Fecha
```cpp
int _dia, _mes, _anio;
bool CargarFecha();
```

---

## Menús

### MenuCompra
```cpp
Compra _compra;
void MostrarMenu();
void ListarCompra();
void CargarCompra();
void ModificarCompra();
void BorrarCompra();
```

### MenuProducto
```cpp
Producto _producto;
void MostrarMenu();
void listarProducto();
void ListarProductosConStockMaximo();
void CargaProducto();
void ModificarProducto();
void ModificarStockMax();
void BorrarProducto();
```

### MenuProveedor
```cpp
Proveedor _proveedor;
void MostrarMenu();
void ListarProveedor();
void CargaProveedor();
void ModificarProveedor();
void BorrarProveedor();
```

### MenuReportes
```cpp
FILE* _archivo;
void MostrarMenu();
bool ComprasPorProveedor(int idProveedor);
bool ComprasTipoProducto(int idTipoProducto);
bool ComprasPorFecha(int dia, int mes, int anio);
```

---

## Archivos y Métodos

### ArchivoBase
```cpp
char * _nombreArchivo[50];
int _tamanoRegistro;
FILE* AbrirArchivo(const char* modo),void CerrarArchivo(FILE* pArchivo);



### ArchivoCompras
```cpp
string _nombreArchivo;
int _idCompra, _idProveedor, _idProducto, _fechaCompra, _cantidadComprada, importeTotal;
LeerArchivo(), EscribirProducto(), ModificarProducto(), EliminarProducto();
```

### ArchivoProducto
```cpp
string _nombreArchivo;
int _idProducto, _nombreProducto, _idTipoProducto, _precioUnitario, _stockActual;
LeerArchivo(), EscribirProducto(), ModificarProducto(), EliminarProducto();
```

### ArchivoProveedor
```cpp
string _nombreArchivo;
int _idProveedor, _dni, _cuit, _nombreProveedor, _numeroTelefono, _email, _direccion;
LeerArchivo(), EscribirProducto(), ModificarProducto(), EliminarProducto();
```

### ArchivoTipoProducto
```cpp
string _nombreArchivo;
int _idTipoProducto;
char _tipoProducto[50];
LeerArchivo(), ObtenerID();
```

---

## REPORTES DEL SISTEMA

### Compras totales por proveedor

- Total de unidades compradas  
- Monto total facturado por proveedor

### Compras por tipo de producto

- Total de unidades adquiridas  
- Suma total de importes por tipo

### Distribución mensual de compras

- Suma de importes de compras por mes (enero a diciembre) dentro de un período

### Valor total de inventario

- Cálculo: `stockActual * precioUnitario` por cada producto
