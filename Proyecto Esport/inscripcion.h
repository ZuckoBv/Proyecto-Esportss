#ifndef INSCRIPCION_H_INCLUDED
#define INSCRIPCION_H_INCLUDED
#include "usuario.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct stInscripcion
{
    char idInscripcion[10];
    char idTorneo[10];
    char idUsuario[10];
} Inscripcion;
void registrarInscripcion(char nombreArchivoInscripcion[],char nombreArchivoUsuario[],char nombreArchivoToreno[]);
void leerString(char arreglo[],int dim);
void administarInscripcion();
void seleccionarUsuario(char nombreArchivo[], char idUsuario[]);
void mostrarUsuarioArchivo(char nombreArchivo[]);
void leerString(char arreglo[],int dim);
void seleccionarTorneo(char nombreArchivo[], char idTorneo[]);
void mostrarInscripciones(char nombreArchivoInscripcion[],char nombreArchivoUsuario[],char nombreArchivoTorneo[]);
#endif // INSCRIPCION_H_INCLUDED
