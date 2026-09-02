// Materia: Programación I, Paralelo 4
// Autor: Luis Daniel Puyal Arteaga
// Carrera del estudiante: Ing. mecatronica
// Fecha creación: 28/08/2026

#include <iostream>

using namespace std;


double leerNotaValida(string etiqueta) {
    double nota;

    do {
        cout << etiqueta;
        cin >> nota;

        if (nota < 0 || nota > 100) {
            cout << "Nota invalida. Debe estar entre 0 y 100. Intente de nuevo." << endl;
        }
    } while (nota < 0 || nota > 100);

    return nota;
}


double calcularPromedioParciales(double p1, double p2, double p3) {
    return (p1 + p2 + p3) / 3.0;
}


bool cumpleRequisitoExamen(double p1, double p2, double p3) {
    return (p1 >= 60 && p2 >= 60 && p3 >= 60);
}


double calcularNotaFinal(double promedioParciales, double examen) {
    return (promedioParciales * 0.5) + (examen * 0.5);
}


bool estaAprobado(double notaFinal) {
    return (notaFinal >= 51);
}

int main() {
    int n;

    cout << "=== ANALISIS DE RENDIMIENTO ACADEMICO - UCB ===" << endl;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    int aprobados = 0;
    int reprobados = 0;
    double sumaNotasFinales = 0.0;

    for (int i = 1; i <= n; i++) {
        cout << "\n--- Estudiante " << i << " ---" << endl;

        double p1 = leerNotaValida("Ingrese NOTA PARCIAL 1: ");
        double p2 = leerNotaValida("Ingrese NOTA PARCIAL 2: ");
        double p3 = leerNotaValida("Ingrese NOTA PARCIAL 3: ");

        double promedioParciales = calcularPromedioParciales(p1, p2, p3);
        double notaFinal;
        double examen = 0.0;
        bool puedeRendirExamen = cumpleRequisitoExamen(p1, p2, p3);

        if (puedeRendirExamen) {
            examen = leerNotaValida("Ingrese NOTA EXAMEN FINAL: ");
            notaFinal = calcularNotaFinal(promedioParciales, examen);
        } else {
            
            notaFinal = promedioParciales;
        }

        bool aprobado = puedeRendirExamen && estaAprobado(notaFinal);

        cout << "\nResultados del estudiante " << i << ":" << endl;
        cout << "NOTA PARCIAL 1: " << p1 << endl;
        cout << "NOTA PARCIAL 2: " << p2 << endl;
        cout << "NOTA PARCIAL 3: " << p3 << endl;

        if (puedeRendirExamen) {
            cout << "NOTA EXAMEN FINAL: " << examen << endl;
        } else {
            cout << "NOTA EXAMEN FINAL: No rindio (no cumplio el requisito minimo)" << endl;
        }

        cout << "NOTA FINAL: " << notaFinal << endl;

        if (aprobado) {
            cout << "Estado: APROBADO" << endl;
            aprobados++;
        } else {
            cout << "Estado: REPROBADO" << endl;
            reprobados++;
        }

        sumaNotasFinales += notaFinal;
    }

    double porcentajeAprobados = (static_cast<double>(aprobados) / n) * 100.0;
    double porcentajeReprobados = (static_cast<double>(reprobados) / n) * 100.0;
    double promedioNotasFinales = sumaNotasFinales / n;

    cout << "\n=== RESUMEN GENERAL ===" << endl;
    cout << "Porcentaje de aprobados: " << porcentajeAprobados << "%" << endl;
    cout << "Porcentaje de reprobados: " << porcentajeReprobados << "%" << endl;
    cout << "Promedio de notas finales: " << promedioNotasFinales << endl;

    return 0;
}
