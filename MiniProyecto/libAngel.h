// Autor: Angel Jose Amaru Llojlla
// Parte A

void listarControlHabilitacion() {
    ifstream archivoEst("ESTUDIANTES.BIN", ios::binary);
    if (!archivoEst) {
        cout << "\nNo existen estudiantes registrados en el sistema." << endl;
        return;
    }

    structPostulante est;
    double sumaNotasHabilitacionTotal = 0;
    int contadorEstudiantesConNotas = 0;

    // Vectores temporales para separar a los estudiantes en pantalla según las reglas del proyecto
    vector<structPostulante> listaCasoA;
    vector<structNotasHabilitacion> notasCasoA;
    vector<double> promediosCasoA;

    vector<structPostulante> listaCasoB;
    vector<structNotasHabilitacion> notasCasoB;
    vector<double> promediosCasoB;

    // 1. Clasificar a los estudiantes
    while (archivoEst.read(reinterpret_cast<char*>(&est), sizeof(structPostulante))) {
        structNotasHabilitacion notas;
        if (buscarNotasEstudiante(est.ci, notas)) {
            // Calcular promedio aritmético: (N1 + N2 + N3) / 3
            double promedio = (notas.n1 + notas.n2 + notas.n3) / 3.0;
            sumaNotasHabilitacionTotal += promedio;
            contadorEstudiantesConNotas++;

            // Condición, Nota >= 60 en todas las evaluaciones
            if (notas.n1 >= 60 && notas.n2 >= 60 && notas.n3 >= 60) {
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
        
        // Detalle de notas individuales para justificar el estado en el reporte
        cout << "   -> [Detalle Notas Parciales: " 
             << "N1: " << notasCasoB[i].n1 << ", "
             << "N2: " << notasCasoB[i].n2 << ", "
             << "N3: " << notasCasoB[i].n3 << "]" << endl;
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
        cout << " PROMEDIO GENERAL DE NOTAS DE HABILITACION DEL CURSO: " << fixed << setprecision(2) << promedioGeneralCurso << " Bs." << endl;
    } else {
        cout << " PROMEDIO GENERAL DE NOTAS DE HABILITACION DEL CURSO: 0.00" << endl;
    }
    cout << "=========================================================================================" << endl;
