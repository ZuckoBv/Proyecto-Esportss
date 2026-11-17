#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "modelos.h"

Administrador cargarAdministrador();
Administrador* redimensionarArreglo(Administrador* arreglo, int validos);
Administrador* agregarAdministrador(Administrador* arreglo,int validos);
void cargarAdministradoresEnArchivo(char nombreArchivo[]);
int guardarAdministradoresEnArchivo(char nombreArchivo[],Administrador arreglo[],int validos);
int autenticarAdmin(char nombreArchivo[], char usuario[], char contrasenia[]);
#endif // ADMIN_H_INCLUDED



