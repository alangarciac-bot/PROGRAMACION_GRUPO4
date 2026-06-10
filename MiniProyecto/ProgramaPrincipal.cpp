// Materia: Programación I, Paralelo 4

// Grupo: 4

// Autor:  Julio Angel Rodriguez Marca

// Fecha creación: 07/06/2026

// Nombre del Miniproyecto: Sistema de Habilitación UCB
#include <iostream>
#include <cstdlib>
#include "estructuras.h"
#include "Julio.h"
#include "Angel.h"
#include "Alan.h"

using namespace std;

int main() {
    int opcion;
    bool salir = false;

    while (!salir) {
        system("cls");
        
        cout << "==========================================================" << endl;
        cout << "      SISTEMA DE CONTROL DE HABILITACION - UCB" << endl;
        cout << "==========================================================" << endl;
        cout << "1. Adicionar Estudiante" << endl;
        cout << "2. Listado de Control de Habilitacion" << endl;
        cout << "3. Eliminar Estudiante" << endl;
        cout << "4. Adicionar Notas de Habilitacion" << endl;
        cout << "5. Salir del Sistema" << endl;
        cout << "==========================================================" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n--- ADICIONAR ESTUDIANTE ---" << endl;
                adicionarEstudiante(); 
                break;
            
            case 2:
                cout << "\n--- REPORTE DE HABILITACION ---" << endl;
                generarReporteHabilitacion(); 
                break;
            
            case 3:
                cout << "\n--- ELIMINAR ESTUDIANTE ---" << endl;
                eliminarEstudiante(); 
                break;
            
            case 4:
                cout << "\n--- ADICIONAR NOTAS ---" << endl;
                adicionarNotas(); 
                break;
            
            case 5:
                cout << "\nSaliendo del sistema..." << endl;
                salir = true;
                break;
            
            default:
                cout << "\nOpcion invalida. Intente de nuevo." << endl;
                break;
        }
        if (!salir) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}
