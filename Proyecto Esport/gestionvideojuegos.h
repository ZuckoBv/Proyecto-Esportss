#ifndef GESTIONVIDEOJUEGOS_H_INCLUDED
#define GESTIONVIDEOJUEGOS_H_INCLUDED
#include "modelos.h"
#define ARCHIVOVIDEOJUEGO "Videojuegos.bin"
int cargarHardcodeadosAlArchivo();
int obtenDimArchivoVideojuegos();
Videojuego *cargarArregloHardcodeados(int cantidadHardcodeados);
Videojuego *crearArregloJuegos(int* dimensionArchi, Videojuego listaHardcodeados[]);
Videojuego *agregarJuegos(int* dimensionArchi, Videojuego arregloJuegos[]);
Videojuego *redimensionarArregloJuegos(Videojuego *arregloJuegos, int nuevaDimension);
Videojuego agregarJuego(int nuevaDim);

void mostrarJuegos(Videojuego arregloJuegos[], int dimension);
void mostrarVideojuegosArchivo(char nombreArchivo[]);
void modificarJuego(Videojuego arregloJuegos[], int dimension);
void mostrarUnJuego(Videojuego juego);

#endif // GESTIONVIDEOJUEGOS_H_INCLUDED
