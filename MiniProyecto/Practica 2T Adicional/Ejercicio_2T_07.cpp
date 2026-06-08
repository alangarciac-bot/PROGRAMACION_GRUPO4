// PRÁCTICA ADICIONAL 2T
// Materia: Programación I, Paralelo 4
// Autor: Angel José Amaru Llojlla
// Carnet: 9986015
// Fecha creación: 25/05/2026
// Número de ejercicio: 7

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para llenar las temperaturas aleatoriamente entre 20 y 40 grados
void monitorearTemperaturas(double monitoreo[5][24]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 24; j++) {
            // Valores con punto decimal entre 20.0 y 40.0
            monitoreo[i][j] = 20 + (rand() % 201) / 10.0;
        }
    }
}

// Función requerida para evaluar alarmas médicas basadas en un umbral crítico
void VerificarAlertas(const vector<string>& pacientes, const double monitoreo[5][24], double umbral) {
    cout << "--- ALERTAS CRITICAS (Umbral superior a " << umbral << "°C) ---" << endl;
    bool algunaAlerta = false;

    for (int i = 0; i < 5; i++) {
        int contadorInfracciones = 0;
        for (int j = 0; j < 24; j++) {
            if (monitoreo[i][j] > umbral) {
                contadorInfracciones++;
            }
        }

        // Si superó el umbral clínico en más de 3 ocasiones
        if (contadorInfracciones > 3) {
            cout << "! Paciente: " << pacientes[i] << " supero el umbral un total de " 
                 << contadorInfracciones << " veces en el dia." << endl;
            algunaAlerta = true;
        }
    }

    if (!algunaAlerta) {
        cout << "No se registraron alertas graves basadas en el umbral seleccionado." << endl;
    }
}

int main() {
    srand(time(0));

    // Estructuras de control sugeridas por el enunciado
    vector<string> pacientes = {
        "Ana Torroja",
        "Juan Luna",
        "Sergio Murillo",
        "Liliana Espinoza",
        "Mercedes Lima"
    };
    
    double monitoreo[5][24];
    double umbralClinico;

    monitorearTemperaturas(monitoreo);

    cout << "Ingrese el umbral térmico de control preventivo (°C): ";
    cin >> umbralClinico;
    cout << endl;

    VerificarAlertas(pacientes, monitoreo, umbralClinico);

    return 0;
}