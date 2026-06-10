
// Materia: Programación I, Paralelo 4

// Grupo: 4

// Autor:  Julio Angel Rodriguez Marca 

// Fecha creación: 08/06/2026

// Nombre del Miniproyecto: Sistema de Habilitación UCB

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
struct Postulante {
    int ci;
    char nombres[30];
    char apellidos[30];
    char materia[30];
    int paralelo;
};

struct NotasPostulante {
    int ci;
    float nota1;
    float nota2;
    float nota3;
};
#endif
