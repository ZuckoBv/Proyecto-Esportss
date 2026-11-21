#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "modelos.h"

Administrador cargarAdministrador(char nombreArchivo[]);
Administrador* crearArregloDinamicoAdmin(int capacidad);
Administrador* redimensionarArregloAdmin(Administrador* arreglo, int* capacidad );
Administrador* agregarAdministrador(Administrador** arreglo,int* validos,int* capacidad, char nombreArchivo[]);
void cargarAdministradoresEnArchivo(char nombreArchivo[]);
int guardarAdministradoresEnArchivo(char nombreArchivo[],Administrador arreglo[],int validos);
int autenticarAdmin(char nombreArchivo[], char usuario[], char contrasenia[]);
void mostrarAdministradores(char nombreArchivo[]);
void menuAdministrador(char nombreArchivo[]);
void submenuAdministradores(char nombreArchivo[]);
int existeEnAdmin(char nombreArchivo[], char usuario[]);

#endif // ADMIN_H_INCLUDED



