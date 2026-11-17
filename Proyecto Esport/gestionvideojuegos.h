#ifndef GESTIONVIDEOJUEGOS_H_INCLUDED
#define GESTIONVIDEOJUEGOS_H_INCLUDED

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "modelos.h"

#define ARCHIVOVIDEOJUEGO "Videojuegos.bin"

int cargarHardcodeadosAlArchivo(char nombreArchivoJuegos[]);
int obtenDimArchivoVideojuegos(char nombreArchivoJuegos[]);
Videojuego *cargarArregloHardcodeados(char nombreArchivoJuegos[], int cantidadHardcodeados);
Videojuego *crearArregloJuegos(char nombreArchivoJuegos[], int* dimensionArchi, Videojuego listaHardcodeados[]);
Videojuego *agregarJuegos(char nombreArchivoJuegos[], int* dimensionArchi, Videojuego arregloJuegos[]);
Videojuego *redimensionarArreglo(Videojuego *arregloJuegos, int nuevaDimension);
Videojuego agregarJuego(char nombreArchivoJuegos[], int nuevaDim);
void mostrarVideojuegosDisponibles (const char nombreArchivoVideojuego []);

#endif // GESTIONVIDEOJUEGOS_H_INCLUDED
