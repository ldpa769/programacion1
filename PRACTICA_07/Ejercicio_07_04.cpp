// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 4

#include <iostream>
#include <vector>
using namespace std;

vector<int> leerVector(int n, const string& nombre) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cout << nombre << "[" << i << "]: ";
        cin >> v[i];
    }
    return v;
}

// resultado[i] = a[i] * b[i]
vector<int> multiplicar(const vector<int>& a, const vector<int>& b) {
    vector<int> resultado(a.size());
    for (size_t i = 0; i < a.size(); i++) resultado[i] = a[i] * b[i];
    return resultado;
}

void mostrarVector(const string& nombre, const vector<int>& v) {
    cout << nombre << ": ";
    for (size_t i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Dimension N de los vectores: ";
    cin >> n;
    if (n <= 0) { cout << "N debe ser mayor a 0\n"; return 0; }

    vector<int> a = leerVector(n, "A");
    vector<int> b = leerVector(n, "B");
    vector<int> c = multiplicar(a, b);

    mostrarVector("A", a);
    mostrarVector("B", b);
    mostrarVector("A * B", c);
    return 0;
}
