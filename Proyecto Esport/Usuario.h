#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct stPersona
{
    char dni[15];
    char nombre[50];
    char telefono[20];
    char direccion[30];
} Persona;

typedef struct
{
    char idUsuario[15];
    char usuario[20];
    char contrasenia[20];
    Persona persona;
}Usuario;
int verificarId(char nombreArchivo[],char idUsario[]);
void leerString(char arreglo[],int dim);
Persona cargarPersona();
Usuario cargarUsaurio();
void cargarUsuarioArchivo(char nombreArchivo[]);
void mostrarUsuario(Usuario a);
void mostrarUsuarioArchivo(char nombreArchivo[]);
void sistemaUsuario();
void mostrarNombreUsuario(char nombreArchivo[]);
#endif // USUARIO_H_INCLUDED
