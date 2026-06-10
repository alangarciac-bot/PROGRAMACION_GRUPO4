// Materia: Programación I, Paralelo 4

// Grupo: 4

// Autor: Alan Samir Garcia Condori 

// Fecha creación: 09/06/2026

// Nombre del Miniproyecto: Sistema de Habilitación UCB

#include <iostream>
#include <fstream>
#include <cstdio> // Para usar remove() y rename()
#include "estructuras.h"
#include "Alan.h"

using namespace std;

// OPCIÓN 4 ADICIONAR NOTAS Y borrar anteriores
void adicionarNotas()
{
    int ciBuscado;
    bool existeEstudiante = false;
    Postulante est;

    cout << "Ingrese el CI del estudiante para anadir notas: ";
    cin >> ciBuscado;

    // se verifica si el estudiante existe
    ifstream archivoEst("ESTUDIANTES.BIN", ios::in | ios::binary);
    if (archivoEst.is_open())
    {
        while (archivoEst.read(reinterpret_cast<char *>(&est), sizeof(Postulante)))
        {
            if (est.ci == ciBuscado)
            {
                existeEstudiante = true;
                cout << "\nEstudiante encontrado: " << est.nombres << " " << est.apellidos << endl;
                break;
            }
        }
        archivoEst.close();
    }

    if (!existeEstudiante)
    {
        cout << "No existe un estudiante con el CI " << ciBuscado << "." << endl;
        return;
    }

    // Pedir las nuevas notas
    NotasPostulante nuevasNotas;
    nuevasNotas.ci = ciBuscado; // Vinculamos las notas al CI
    cout << "Ingrese Nota 1: ";
    cin >> nuevasNotas.nota1;
    cout << "Ingrese Nota 2: ";
    cin >> nuevasNotas.nota2;
    cout << "Ingrese Nota 3: ";
    cin >> nuevasNotas.nota3;

    // Archivo temporaL
    ifstream archivoNotasOri("NOTAS.BIN", ios::in | ios::binary);
    ofstream archivoNotasTemp("NOTAS_TEMP.BIN", ios::out | ios::binary);
    NotasPostulante notaTemp;

    if (archivoNotasOri.is_open())
    {
        while (archivoNotasOri.read(reinterpret_cast<char *>(&notaTemp), sizeof(NotasPostulante)))
        {
            // Copiamos al temporal todas las notas EXCEPTO las del CI que estamos actualizando
            if (notaTemp.ci != ciBuscado)
            {
                archivoNotasTemp.write(reinterpret_cast<char *>(&notaTemp), sizeof(NotasPostulante));
            }
        }
        archivoNotasOri.close();
    }

    archivoNotasTemp.write(reinterpret_cast<char *>(&nuevasNotas), sizeof(NotasPostulante));
    archivoNotasTemp.close();

    // Archivo Nuevo
    remove("NOTAS.BIN");
    rename("NOTAS_TEMP.BIN", "NOTAS.BIN");

    cout << "\n¡Notas registradas/actualizadas correctamente!" << endl;
}

// ==========================================
// OPCIÓN 3: ELIMINAR ESTUDIANTE
// ==========================================
void eliminarEstudiante()
{
    int ciBorrar;
    bool encontrado = false;
    Postulante est;

    cout << "Ingrese el CI del estudiante a eliminar: ";
    cin >> ciBorrar;

    ifstream archivoOri("ESTUDIANTES.BIN", ios::in | ios::binary);
    ofstream archivoTemp("EST_TEMP.BIN", ios::out | ios::binary);

    if (!archivoOri.is_open())
    {
        cout << "No hay estudiantes registrados." << endl;
        return;
    }

    // Copiar todos los estudiantes menos el que queremos borrar
    while (archivoOri.read(reinterpret_cast<char *>(&est), sizeof(Postulante)))
    {
        if (est.ci != ciBorrar)
        {
            archivoTemp.write(reinterpret_cast<char *>(&est), sizeof(Postulante));
        }
        else
        {
            encontrado = true;
        }
    }

    archivoOri.close();
    archivoTemp.close();

    remove("ESTUDIANTES.BIN");
    rename("EST_TEMP.BIN", "ESTUDIANTES.BIN");

    if (encontrado)
    {
        cout << "Estudiante con CI " << ciBorrar << " eliminado exitosamente del sistema." << endl;
    }
    else
    {
        cout << "No se encontro ningun estudiante con ese CI para eliminar." << endl;
    }
}
