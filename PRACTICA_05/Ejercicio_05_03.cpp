// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 09/09/2026
// Número de ejercicio: 3

#include <iostream>
using namespace std;

double CalcularPrecioTotal(double precioBase, double impuesto = 0.13){
    return precioBase + (precioBase * impuesto);
}

int main(){
    double precio;

    cout << "Ingrese el precio base del producto: ";
    cin >> precio;

    // Usa el IVA boliviano por defecto (13%)
    cout << "Precio total con IVA por defecto (13%): "
         << CalcularPrecioTotal(precio) << endl;

    double impuestoPersonalizado;
    cout << "Ingrese un porcentaje de impuesto (ej. 0.10 para 10%): ";
    cin >> impuestoPersonalizado;

    cout << "Precio total con impuesto personalizado: "
         << CalcularPrecioTotal(precio, impuestoPersonalizado) << endl;

    return 0;
}
