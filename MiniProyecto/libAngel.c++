#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "estructuras.h"
#include "Angel.h"

using namespace std;

// Notas de un estudiante
bool buscarNotasEstudiante(int ciBuscado, NotasPostulante& notasEncontradas) {
    ifstream archivoNotas("NOTAS.BIN", ios::binary);
    if (!archivoNotas) {
        return false;
    }
    
    NotasPostulante temporal;
    while (archivoNotas.read(reinterpret_cast<char*>(&temporal), sizeof(NotasPostulante))) {
        if (temporal.ci == ciBuscado) {
            notasEncontradas = temporal;
            archivoNotas.close();
            return true;
        }
    }
    archivoNotas.close();
    return false;
}

// Adaptacion para el menú
void generarReporteHabilitacion() {
    ifstream archivoEst("ESTUDIANTES.BIN", ios::binary);
    if (!archivoEst) {
        cout << "\nNo existen estudiantes registrados en el sistema." << endl;
        return;
    }

    Postulante est;
    double sumaNotasHabilitacionTotal = 0;
    int contadorEstudiantesConNotas = 0;

    // Separacion de los estudiantes
    vector<Postulante> listaCasoA;
    vector<NotasPostulante> notasCasoA;
    vector<double> promediosCasoA;

    vector<Postulante> listaCasoB;
    vector<NotasPostulante> notasCasoB;
    vector<double> promediosCasoB;

    // 1. Clasificacio de los estudiantes
    while (archivoEst.read(reinterpret_cast<char*>(&est), sizeof(Postulante))) {
        NotasPostulante notas;
        
        if (buscarNotasEstudiante(est.ci, notas)) {
            // Calcular el promedio
            double promedio = (notas.nota1 + notas.nota2 + notas.nota3) / 3.0;
            sumaNotasHabilitacionTotal += promedio;
            contadorEstudiantesConNotas++;

            // Nota >= 60 en todas las evaluaciones
            if (notas.nota1 >= 60 && notas.nota2 >= 60 && notas.nota3 >= 60) {
                listaCasoA.push_back(est);
                notasCasoA.push_back(notas);
                promediosCasoA.push_back(promedio);
            } else {
                listaCasoB.push_back(est);
                notasCasoB.push_back(notas);
                promediosCasoB.push_back(promedio);
            }
        }
    }
    archivoEst.close();


    
    // ============================================================================
    // CASO A: Estudiantes Habilitados (Todas las notas individuales >= 60)
    // ============================================================================

    
    cout << "\n=========================================================================================" << endl;
    cout << "   CASO A: ESTUDIANTES CON TODAS LAS NOTAS INDIVIDUALES >= 60 (HABILITADOS)" << endl;
    cout << "=========================================================================================" << endl;
    cout << setw(10) << left << "CARNET" 
         << setw(15) << left << "NOMBRES" 
         << setw(15) << left << "APELLIDOS" 
         << setw(20) << left << "MATERIA" 
         << setw(10) << left << "PARALELO" 
         << setw(20) << left << "NOTA HABILITACION" 
         << setw(12) << left << "ESTADO" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < listaCasoA.size(); i++) {
        cout << setw(10) << left << listaCasoA[i].ci 
             << setw(15) << left << listaCasoA[i].nombres 
             << setw(15) << left << listaCasoA[i].apellidos 
             << setw(20) << left << listaCasoA[i].materia 
             << setw(10) << left << listaCasoA[i].paralelo 
             << setw(20) << left << fixed << setprecision(2) << promediosCasoA[i] 
             << setw(12) << left << "HABILITADO" << endl;
    }
    if (listaCasoA.empty()) {
        cout << " No se encontraron estudiantes en esta condicion." << endl;
    }

    // ============================================================================
    // CASO B: Estudiantes No Habilitados (Una o mas notas individuales < 60)
    // ============================================================================


    
    cout << "\n=========================================================================================" << endl;
    cout << "   CASO B: ESTUDIANTES CON UNA O MAS NOTAS INDIVIDUALES < 60 (NO HABILITADOS)" << endl;
    cout << "=========================================================================================" << endl;
    cout << setw(10) << left << "CARNET" 
         << setw(15) << left << "NOMBRES" 
         << setw(15) << left << "APELLIDOS" 
         << setw(20) << left << "MATERIA" 
         << setw(10) << left << "PARALELO" 
         << setw(20) << left << "NOTA HABILITACION" 
         << setw(12) << left << "ESTADO" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < listaCasoB.size(); i++) {
        cout << setw(10) << left << listaCasoB[i].ci 
             << setw(15) << left << listaCasoB[i].nombres 
             << setw(15) << left << listaCasoB[i].apellidos 
             << setw(20) << left << listaCasoB[i].materia 
             << setw(10) << left << listaCasoB[i].paralelo 
             << setw(20) << left << fixed << setprecision(2) << promediosCasoB[i] 
             << setw(12) << left << "NO HABILITADO" << endl;
        
        // Notas Individuales de cada estudiante
        cout << "   -> [Detalle Notas Parciales: " 
             << "N1: " << notasCasoB[i].nota1 << ", "
             << "N2: " << notasCasoB[i].nota2 << ", "
             << "N3: " << notasCasoB[i].nota3 << "]" << endl;
        cout << "   -> [MOTIVO: NOTA INDIVIDUAL < 60]" << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;
    }
    if (listaCasoB.empty()) {
        cout << " No se encontraron estudiantes en esta condicion." << endl;
    }

    // ============================================================================
    // REPORTE FINAL CONSOLIDADO (PROMEDIO GENERAL DEL CURSO)
    // ============================================================================

    
    cout << "\n=========================================================================================" << endl;
    if (contadorEstudiantesConNotas > 0) {
        double promedioGeneralCurso = sumaNotasHabilitacionTotal / contadorEstudiantesConNotas;
        cout << " PROMEDIO GENERAL DE NOTAS DE HABILITACION DEL CURSO: " << fixed << setprecision(2) << promedioGeneralCurso << endl;
    } else {
        cout << " PROMEDIO GENERAL DE NOTAS DE HABILITACION DEL CURSO: 0.00" << endl;
    }
    cout << "=========================================================================================" << endl;
}
