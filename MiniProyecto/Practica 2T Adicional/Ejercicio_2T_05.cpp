// PRÁCTICA ADICIONAL 2T
// Materia: Programación I, Paralelo 4
// Autor: Angel José Amaru Llojlla
// Carnet: 9986015
// Fecha creación: 01/06/2026
// Número de ejercicio: 5

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para inicializar los datos de venta semanales
void simularVentas(double ventas[4][7]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            // Simulación de importes de venta diarios
            ventas[i][j] = 100 + (rand() % 900); 
        }
    }
}

// Función obligatoria: VentasPorSucursal
void VentasPorSucursal(const double ventas[4][7]) {
    cout << "\n--- Total de Ventas por Sucursal ---" << endl;
    for (int i = 0; i < 4; i++) {
        double totalSucursal = 0;
        for (int j = 0; j < 7; j++) {
            totalSucursal += ventas[i][j];
        }
        cout << "Sucursal " << i + 1 << ": $" << totalSucursal << endl;
    }
}

// Función obligatoria: VentasPorDia
void VentasPorDia(const double ventas[4][7]) {
    const string dias[7] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};
    cout << "\n--- Total de Ventas por Dia de la Semana ---" << endl;
    for (int j = 0; j < 7; j++) {
        double totalDia = 0;
        for (int i = 0; i < 4; i++) {
            totalDia += ventas[i][j];
        }
        cout << dias[j] << ": $" << totalDia << endl;
    }
}

int main() {
    srand(time(0));
    double ventas[4][7];

    simularVentas(ventas);

    // Impresión de la matriz para referencia visual
    cout << "--- Matriz de Ventas Reales (4 Sucursales x 7 Dias) ---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Suc. " << i + 1 << ":\t";
        for (int j = 0; j < 7; j++) {
            cout << ventas[i][j] << "\t";
        }
        cout << endl;
    }

    // Ejecución de los módulos requeridos
    VentasPorSucursal(ventas);
    VentasPorDia(ventas);

    return 0;
}