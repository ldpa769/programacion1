// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 5

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

// Combina: primero todos los elementos de A y luego los de B (tamaño 2N)
vector<int> combinar(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    for (size_t i = 0; i < a.size(); i++) c.push_back(a[i]);
    for (size_t i = 0; i < b.size(); i++) c.push_back(b[i]);
    return c;
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
    vector<int> c = combinar(a, b);

    mostrarVector("A", a);
    mostrarVector("B", b);
    mostrarVector("Combinado", c);
    return 0;
}
