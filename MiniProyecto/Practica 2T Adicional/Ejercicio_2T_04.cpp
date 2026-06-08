// PRÁCTICA ADICIONAL 2T
// Materia: Programación I, Paralelo 4
// Autor: Angel José Amaru Llojlla
// Carnet: 9986015
// Fecha creación: 11/05/2026
// Número de ejercicio: 4

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para inicializar la matriz cuadrada con números aleatorios entre A y B
void llenarMatriz(vector<vector<int>>& matriz, int n, int a, int b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = a + rand() % (b - a + 1);
        }
    }
}

// Función para mostrar la matriz por pantalla
void imprimirMatriz(const vector<vector<int>>& matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para calcular la suma de la primera columna
int sumarPrimeraColumna(const vector<vector<int>>& matriz, int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += matriz[i][0];
    }
    return suma;
}

// Función para calcular el producto total de la primera fila
long long productoPrimeraFila(const vector<vector<int>>& matriz, int n) {
    long long producto = 1;
    for (int j = 0; j < n; j++) {
        producto *= matriz[0][j];
    }
    return producto;
}

// Función para encontrar el menor valor de la matriz y su ubicación exacta
void encontrarMenorValor(const vector<vector<int>>& matriz, int n) {
    int menor = matriz[0][0];
    int filaMenor = 0;
    int colMenor = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
                filaMenor = i;
                colMenor = j;
            }
        }
    }
    cout << "Menor valor encontrado: " << menor << " en la posicion [Fila: " << filaMenor << ", Columna: " << colMenor << "]" << endl;
}

int main() {
    srand(time(0));
    int n, a, b;

    cout << "Ingrese el tamaño N de la matriz cuadrada (N x N): ";
    cin >> n;
    cout << "Ingrese el limite inferior del rango (A): ";
    cin >> a;
    cout << "Ingrese el limite superior del rango (B): ";
    cin >> b;

    if (a > b) {
        cout << "Error: El limite A no puede ser mayor que B." << endl;
        return 1;
    }

    vector<vector<int>> matriz(n, vector<int>(n));

    llenarMatriz(matriz, n, a, b);
    cout << "\n--- Matriz Generada ---" << endl;
    imprimirMatriz(matriz, n);

    cout << "\n--- Resultados Metricos ---" << endl;
    cout << "Suma de la primera columna: " << sumarPrimeraColumna(matriz, n) << endl;
    cout << "Producto de la primera fila: " << productoPrimeraFila(matriz, n) << endl;
    encontrarMenorValor(matriz, n);

    return 0;
}