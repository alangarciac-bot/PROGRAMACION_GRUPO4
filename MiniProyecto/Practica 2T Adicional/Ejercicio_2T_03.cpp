// PRÁCTICA ADICIONAL 2T
// Materia: Programación I, Paralelo 4
// Autor: Angel José Amaru Llojlla
// Carnet: 9986015
// Fecha creación: 19/05/2026
// Número de ejercicio: 3

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Función para limpiar el texto (remueve espacios, puntuación y convierte a minúsculas)
string limpiarCadena(const string& texto) {
    string resultado = "";
    for (char c : texto) {
        if (isalpha(c)) {
            // Conversión básica a minúsculas
            char limpio = tolower(c);
            
            // Tratamiento básico de tildes si el entorno las soporta de manera estándar extendida
            if (limpio == 'á') limpio = 'a';
            if (limpio == 'é') limpio = 'e';
            if (limpio == 'í') limpio = 'i';
            if (limpio == 'ó') limpio = 'o';
            if (limpio == 'ú') limpio = 'u';
            
            resultado += limpio;
        }
    }
    return resultado;
}

// Función booleana que determina si la expresión limpia es un palíndromo
bool esPalindromo(const string& texto) {
    string cadenaLimpia = limpiarCadena(texto);
    int inicio = 0;
    int fin = cadenaLimpia.length() - 1;

    while (inicio < fin) {
        if (cadenaLimpia[inicio] != cadenaLimpia[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}

int main() {
    string frase;
    cout << "Ingrese una palabra o frase: ";
    getline(cin, frase);

    if (esPalindromo(frase)) {
        cout << "Verdadero (Es palindromo)" << endl;
    } else {
        cout << "Falso (No es palindromo)" << endl;
    }

    return 0;
}