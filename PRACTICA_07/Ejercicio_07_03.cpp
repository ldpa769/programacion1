// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 3

#include <iostream>
#include <vector>
using namespace std;

vector<int> leerCalificaciones(int n) {
    vector<int> calificaciones(n);
    for (int i = 0; i < n; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> calificaciones[i];
    }
    return calificaciones;
}

int sumaTotal(const vector<int>& v) {
    int suma = 0;
    for (size_t i = 0; i < v.size(); i++) suma += v[i];
    return suma;
}

double promedio(const vector<int>& v) {
    return (double)sumaTotal(v) / v.size();
}

// desviacion[i] = calificaciones[i] - promedio
vector<double> calcularDesviaciones(const vector<int>& v, double prom) {
    vector<double> desviacion(v.size());
    for (size_t i = 0; i < v.size(); i++) desviacion[i] = v[i] - prom;
    return desviacion;
}

// varianza = suma(desviacion^2) / cantidad
double varianza(const vector<double>& desviacion) {
    double suma = 0;
    for (size_t i = 0; i < desviacion.size(); i++) suma += desviacion[i] * desviacion[i];
    return suma / desviacion.size();
}

void mostrarResultados(const vector<int>& calif, const vector<double>& desv) {
    cout << "\nCalificacion\tDesviacion\n";
    for (size_t i = 0; i < calif.size(); i++)
        cout << calif[i] << "\t\t" << desv[i] << endl;
}

int main() {
    int n;
    cout << "Cuantas calificaciones desea ingresar (N)? ";
    cin >> n;
    if (n <= 0) { cout << "N debe ser mayor a 0\n"; return 0; }

    vector<int> calificaciones = leerCalificaciones(n);
    double prom = promedio(calificaciones);
    vector<double> desviacion = calcularDesviaciones(calificaciones, prom);

    cout << "\nSuma total: " << sumaTotal(calificaciones) << endl;
    cout << "Promedio: " << prom << endl;
    mostrarResultados(calificaciones, desviacion);
    cout << "\nVarianza: " << varianza(desviacion) << endl;
    return 0;
}
