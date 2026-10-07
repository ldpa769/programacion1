// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 1

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Devuelve un double aleatorio entre minimo y maximo (2 decimales)
double aleatorioDouble(double minimo, double maximo) {
    double x = minimo + (rand() / (double)RAND_MAX) * (maximo - minimo);
    return (int)(x * 100 + 0.5) / 100.0;
}

// a. 100 voltajes entre 20.00 y 220.00
vector<double> generarVoltajes() {
    vector<double> v(100);
    for (int i = 0; i < 100; i++) v[i] = aleatorioDouble(20.00, 220.00);
    return v;
}

// b. 50 temperaturas entre 0.00 y 100.00
vector<double> generarTemperaturas() {
    vector<double> v(50);
    for (int i = 0; i < 50; i++) v[i] = aleatorioDouble(0.00, 100.00);
    return v;
}

// c. 30 caracteres alfanuméricos
vector<char> generarCaracteres() {
    const string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    vector<char> v(30);
    for (int i = 0; i < 30; i++) v[i] = alfabeto[rand() % alfabeto.length()];
    return v;
}

// d. 100 años enteros entre 1990 y 2025
vector<int> generarAnios() {
    vector<int> v(100);
    for (int i = 0; i < 100; i++) v[i] = 1990 + rand() % 36;
    return v;
}

// e. 32 velocidades entre 10.00 y 300.00
vector<double> generarVelocidades() {
    vector<double> v(32);
    for (int i = 0; i < 32; i++) v[i] = aleatorioDouble(10.00, 300.00);
    return v;
}

// f. 1000 distancias entre 1.00 y 1000.00
vector<double> generarDistancias() {
    vector<double> v(1000);
    for (int i = 0; i < 1000; i++) v[i] = aleatorioDouble(1.00, 1000.00);
    return v;
}

// Muestra cualquier vector, 10 elementos por línea
template <typename T>
void mostrar(const string& titulo, const vector<T>& v) {
    cout << "\n=== " << titulo << " (" << v.size() << " elementos) ===\n";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
        if ((i + 1) % 10 == 0) cout << "\n";
    }
    cout << "\n";
}

int main() {
    srand((unsigned)time(0));
    cout << fixed << setprecision(2);

    mostrar("Voltajes (V)", generarVoltajes());
    mostrar("Temperaturas", generarTemperaturas());
    mostrar("Caracteres alfanumericos", generarCaracteres());
    mostrar("Anios", generarAnios());
    mostrar("Velocidades", generarVelocidades());
    mostrar("Distancias", generarDistancias());
    return 0;
}
