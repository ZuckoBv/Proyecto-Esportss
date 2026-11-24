#ifndef MODELOS_H_INCLUDED
#define MODELOS_H_INCLUDED
#define ACCESO_FALLIDO 0
#define ACCESO_ADMIN 1
#define SALIR_SISTEMA -1

// Estructuras de Juegos, Administradores, Fechas y Torneos
typedef struct stVideojuego {
    char idJuego[10]; // Código único del juego (ej. "LOL", "CS2")
    char nombre[50];
    char genero[30];
    char plataforma[20];
    int activo;
} Videojuego;

typedef struct stAdministrador {
    char usuario[20]; // Usuario para el login
    char contrasenia[20];
    char nombreCompleto[50];
    char rol[20]; // Ej: "Organizador", "Staff"
} Administrador;

typedef struct stFecha {
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct stTorneo {
    char idTorneo[10];
    char nombre[50];
    Videojuego juego;
    int capacidadMaxima;
    int cuposDisponibles;
    Fecha fechaInicio;
    float premioTotal;
    char estado[15]; // "Abierto", "En Curso", "Finalizado"
} Torneo;


#endif // MODELOS_H_INCLUDED
