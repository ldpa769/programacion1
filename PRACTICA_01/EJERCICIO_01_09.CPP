// Materia: Programación I, Paralelo 4
// Autor: LUIS DANIEL PUYAL ARTEAGA
// Carrera del Estudiante: ING. MECATRONICA
// Fecha creación: 12/08/2026
#include <iostream>
using namespace std;
int main() {
    long long N;
    cout << "Ingresa un numero entero positivo N: ";
    cin >> N;
    long long numeroInvertido = 0;
    long long auxiliar = N;
    int cerosAlFinal = 0;

    while (auxiliar % 10 == 0) {
        cerosAlFinal++;
        auxiliar /= 10;
    }

    while (N > 0) {
        int digito = N % 10;
        numeroInvertido = (numeroInvertido * 10) + digito;
        N /= 10;
    }

    while (numeroInvertido > 0) {
        int d = numeroInvertido % 10;
        numeroInvertido /= 10;

        cout << "\nCuadricula de " << d << " x " << d << ":" << endl;

        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                cout << "* ";
            }
            cout << endl;
        }
    }

     for (int k = 0; k < cerosAlFinal; k++) {
        cout << "\nCuadricula de 0 x 0:\n(Digito 0: sin cuadricula)" << endl;
    }

    return 0;
}