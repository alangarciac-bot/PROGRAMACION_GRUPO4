#include <iostream>
using namespace std;
struct structPostulante {
    int ci;
    char nombres[30];
    char apellidos[30];
    char materia[30];
    int paralelo;
};

void adicionarEstudiante();
void listadoControlHabilitacion();
void eliminarEstudiante();
void adicionarNotasHabilitacion();

int main() {
    int opcion;
    
    do {
        cout << "1. Adicionar Estudiante" << endl;
        cout << "2. Listado de Control de Habilitacion" << endl;
        cout << "3. Eliminar Estudiante" << endl;
        cout << "4. Adicionar Notas de Habilitacion" << endl;
        cout << "5. Salir del sistema" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                adicionarEstudiante();
                break;
            case 2:
                listadoControlHabilitacion();
                break;
            case 3:
                eliminarEstudiante();
                break;
            case 4:
                adicionarNotasHabilitacion();
                break;
            case 5:
                cout << "Saliendo del sistema." << endl;
                break;
            default:
                cout << "Error: Intente nuevamente." << endl;
        }
    } while(opcion != 5);
    return 0;
}
void adicionarEstudiante() {
    
    cout << "Adicionar Estudiante" << endl;
}

void listadoControlHabilitacion() {

    cout << "Listado de Control" << endl;
}

void eliminarEstudiante() {
    cout << "Eliminar Estudiante" << endl;
}

void adicionarNotasHabilitacion() {

    cout << "Adicionar Notas" << endl;
}
