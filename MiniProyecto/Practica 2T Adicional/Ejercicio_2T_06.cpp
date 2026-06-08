// PRÁCTICA ADICIONAL 2T
// Materia: Programación I, Paralelo 4
// Autor: Angel José Amaru Llojlla
// Carnet: 9986015
// Fecha creación: 23/05/2026
// Número de ejercicio: 6

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para simular las notas de los 3 parciales para los 20 estudiantes
void inicializarNotas(double notas[20][3]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 3; j++) {
            // Notas enteras de simulación entre 10 y 100
            notas[i][j] = 10 + (rand() % 91);
        }
    }
}

// Función para calcular promedios individuales, promedio del grupo y ubicar al estudiante destacado
void procesarGestionNotas(const double notas[20][3]) {
    double sumaMediasTotales = 0;
    double mejorPromedio = -1;
    int indiceMejorEstudiante = 0;

    cout << "--- Promedio Simple por Estudiante ---" << endl;
    for (int i = 0; i < 20; i++) {
        double sumaParciales = 0;
        for (int j = 0; j < 3; j++) {
            sumaParciales += notas[i][j];
        }
        double promedioEstudiante = sumaParciales / 3.0;
        sumaMediasTotales += promedioEstudiante;

        cout << "Estudiante Nro " << i + 1 << ": " << promedioEstudiante << endl;

        if (promedioEstudiante > mejorPromedio) {
            mejorPromedio = promedioEstudiante;
            indiceMejorEstudiante = i + 1; // Ajustado a índice de lista (1-base)
        }
    }

    cout << "\n=========================================" << endl;
    cout << "             REPORTE FINAL" << endl;
    cout << "=========================================" << endl;
    cout << "Promedio General del Curso: " << (sumaMediasTotales / 20.0) << endl;
    cout << "Estudiante Destacado (Nro Lista): " << indiceMejorEstudiante << " con " << mejorPromedio << endl;
}

int main() {
    srand(time(0));
    double notas[20][3];

    inicializarNotas(notas);
    procesarGestionNotas(notas);

    return 0;
}