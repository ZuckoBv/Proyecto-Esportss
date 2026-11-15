#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string.h>


typedef struct stPersona
{
    char dni[15];
    char nombre[50];
    char telefono[20];
    char direccion[30];
    char rol[15];
} Persona;

typedef struct
{
    char usuario[20];
    char contrasenia[20];
    Persona persona;
}Usuario;

void leerString(char arreglo,int dim);
void cargarPersona();
void cargarUsaurio();
void cargarUsuarioArchivo(char nombreArchivo);
#endif // USUARIO_H_INCLUDED
