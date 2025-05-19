#include <iostream>

using namespace std;

int main()
{
    int opc = -1;
    while(opc != 0)
    {
        system("cls");
        cout << "========== COMPRAS MAXIQUIOSCO ==========" << endl;
        cout << "1. AGREGAR PROVEEDOR " << endl;
        cout << "2. AGREGAR PRODUCTO" << endl;
        cout << "3. AGREGAR COMPRA" << endl;
        cout << "4. GENERAR REPORTES" << endl;
        cout << "0. CERRAR PROGRAMA" << endl;
        cout << "==============================" << endl;
        cout << "Seleccionar una opcion " << endl;
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            ///Logica Agregar Proveedor();
            break;
        case 2:
            ///Logica Agregar Producto();
            break;
        case 3:
            ///Logica Agregar Compra();
            break;
        case 4:
            ///Logica Generar Reportes();
            break;
        case 0:
            return 0;
        default:
            cout<<"Opcion invalida, por favor intente nuevamente."<<endl;
        }
        system("pause");
    }
    return 0;
}
