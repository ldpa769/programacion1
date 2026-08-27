#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int NumAleatorio(int min, int max);

int main(){
    int n;
    double precioBase, montoConIVA, montoFinal;
    double sumaTotal = 0;
    double sumaIVA = 0;
    double sumaDescuentos = 0;
    double productoMasCaro = 0;
    double productoMasBarato = 999999; // valor inicial alto para comparar

    srand(time(0));

    cout << "Ingrese la cantidad de productos vendidos en el dia: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // Generamos el precio base aleatorio entre 10 y 10000
        precioBase = NumAleatorio(10, 10000);

        // El precio base YA incluye utilidad (87%) + IVA (13%) = 100%
        double utilidad = precioBase * 0.87;
        double iva = precioBase * 0.13;
        montoConIVA = utilidad + iva; // Es igual a precioBase

        double descuento = 0;

        // Si supera los 2500 Bs, se aplica 5% de descuento
        if (montoConIVA > 2500)
        {
            descuento = montoConIVA * 0.05;
            montoFinal = montoConIVA - descuento;
        }
        else
        {
            montoFinal = montoConIVA;
        }

        cout << "Producto " << i << ": Precio base = " << precioBase
             << " Bs | IVA = " << iva
             << " Bs | Descuento = " << descuento
             << " Bs | Total final = " << montoFinal << " Bs" << endl;

        // Acumulados
        sumaTotal += montoFinal;
        sumaIVA += iva;
        sumaDescuentos += descuento;

        // Producto mas caro y mas barato (segun monto final)
        if (montoFinal > productoMasCaro)
        {
            productoMasCaro = montoFinal;
        }
        if (montoFinal < productoMasBarato)
        {
            productoMasBarato = montoFinal;
        }
    }

    cout << "\n--- Reporte del dia ---" << endl;
    cout << "Suma total de dinero ingresado: " << sumaTotal << " Bs" << endl;
    cout << "Total acumulado de IVA (13%): " << sumaIVA << " Bs" << endl;
    cout << "Total descontado a clientes: " << sumaDescuentos << " Bs" << endl;
    cout << "Producto mas caro vendido: " << productoMasCaro << " Bs" << endl;
    cout << "Producto mas barato vendido: " << productoMasBarato << " Bs" << endl;

    return 0;
}

int NumAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}