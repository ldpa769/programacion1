// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Fecha creación: 24/09/2026
// Número de ejercicio: 6

#include <iostream>
#include <vector>
using namespace std;

const int TAM = 5;

vector<int> leerVector(const string& nombre) {
    vector<int> v(TAM);
    for (int i = 0; i < TAM; i++) {
        cout << nombre << "[" << i << "]: ";
        cin >> v[i];
    }
    return v;
}

// vector3 = vector1 + vector2
vector<int> sumar(const vector<int>& v1, const vector<int>& v2) {
    vector<int> v3(TAM);
    for (int i = 0; i < TAM; i++) v3[i] = v1[i] + v2[i];
    return v3;
}

void mostrarVector(const string& nombre, const vector<int>& v) {
    cout << nombre << ": ";
    for (int i = 0; i < TAM; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    vector<int> vector1 = leerVector("vector1");
    vector<int> vector2 = leerVector("vector2");
    vector<int> vector3 = sumar(vector1, vector2);

    mostrarVector("vector1", vector1);
    mostrarVector("vector2", vector2);
    mostrarVector("vector3 (suma)", vector3);
    return 0;
}
