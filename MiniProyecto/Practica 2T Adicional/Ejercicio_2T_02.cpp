// PRÁCTICA ADICIONAL 2T
// Materia: Programación I, Paralelo 4
// Autor: Angel José Amaru Llojlla
//Carnet: 9986015
// Fecha creación: 19/05/2026
// Número de ejercicio: 2

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar valores aleatorios de píxeles entre 0 y 255
void generarPixeles(vector<int>& pixeles, int n) {
    for (int i = 0; i < n; i++) {
        pixeles[i] = rand() % 256;
    }
}

// Función para agrupar en rangos de 10 unidades e imprimir resultados
void procesarRangosDeGrises(const vector<int>& pixeles) {
    // Hay 26 rangos posibles para abarcar de 0 a 255 en bloques de 10
    // Rangos: 0-9, 10-19, ..., 250-255
    vector<int> contadores(26, 0);

    for (int valor : pixeles) {
        int rango = valor / 10;
        if (rango >= 0 && rango < 26) {
            contadores[rango]++;
        }
    }

    // Mostrar histograma de frecuencias
    for (int i = 0; i < 26; i++) {
        int inicioRango = i * 10;
        int finRango = inicioRango + 9;
        if (finRango > 255) finRango = 255;

        // Validar pluralidad en la salida de texto
        if (contadores[i] == 1) {
            cout << inicioRango << "-" << finRango << ": " << contadores[i] << " pixel" << endl;
        } else {
            cout << inicioRango << "-" << finRango << ": " << contadores[i] << " pixeles" << endl;
        }
    }
}

int main() {
    srand(time(0));
    int n = 50; // Definimos un tamaño de muestra representativo
    vector<int> pixeles(n);

    generarPixeles(pixeles, n);

    cout << "--- Pixeles Generados ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << pixeles[i] << " ";
    }
    cout << "\n\n--- Distribución por Segmentos ---" << endl;

    procesarRangosDeGrises(pixeles);

    return 0;
}