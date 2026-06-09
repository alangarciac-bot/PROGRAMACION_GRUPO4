#include <iostream>
#include <fstream>
#include <cstring>
#include "estructuras.h"
#include "Julio.h"

using namespace std;

void adicionarEstudiante() {
    Postulante nuevo;    
    Postulante temporal;
    bool duplicado = false;

    cout << "Ingrese el CI: ";
    cin >> nuevo.ci;
    cin.ignore(); 
    
    cout << "Ingrese los nombres: ";
    cin.getline(nuevo.nombres, 30);
    
    cout << "Ingrese los apellidos: ";
    cin.getline(nuevo.apellidos, 30);

    //(CI DUPLICADOS)
    ifstream archivoLectura("ESTUDIANTES.BIN", ios::in | ios::binary);
    
    if (archivoLectura.is_open()) {
        while (archivoLectura.read(reinterpret_cast<char*>(&temporal), sizeof(Postulante))) {
            
            // Comparar CI
            if (temporal.ci == nuevo.ci) {
                cout << "El CI " << nuevo.ci << " ya esta registrado en el sistema." << endl;
                duplicado = true;
                break;
            }
            
            //Comparar Nombres y Apellidos
            if (strcmp(temporal.nombres, nuevo.nombres) == 0 && strcmp(temporal.apellidos, nuevo.apellidos) == 0) {
                cout << "ERROR: El estudiante " << nuevo.nombres << " " << nuevo.apellidos << " ya existe." << endl;
                duplicado = true;
                break;
            }
        }
        archivoLectura.close(); 
    }

    if (duplicado) {
        return; 
    }

    // PEDIR DATOS
    cout << "Ingrese la materia: ";
    cin.getline(nuevo.materia, 30);
    
    cout << "Ingrese el paralelo (numero): ";
    cin >> nuevo.paralelo;

    // GUARDAR EN EL ARCHIVO
    ofstream archivoEscritura("ESTUDIANTES.BIN", ios::app | ios::binary);
    
    if (archivoEscritura.is_open()) {
        archivoEscritura.write(reinterpret_cast<char*>(&nuevo), sizeof(Postulante));
        cout << "\nEstudiante registrado" << endl;
        archivoEscritura.close();
    } else {
        cout << "Error:No se pudo abrir el archivo para guardar." << endl;
    }
}
