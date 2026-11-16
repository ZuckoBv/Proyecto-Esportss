#ifndef GESTIONVIDEOJUEGOS_H_INCLUDED
#define GESTIONVIDEOJUEGOS_H_INCLUDED

int cargarHardcodeadosAlArchivo(char nombreArchivoJuegos[]);
int obtenDimArchivoVideojuegos(char nombreArchivoJuegos[]);
Videojuego *cargarArregloHardcodeados(char nombreArchivoJuegos[], int cantidadHardcodeados);
Videojuego *crearArregloJuegos(char nombreArchivoJuegos[], int* dimensionArchi, Videojuego listaHardcodeados[]);
Videojuego *agregarJuegos(char nombreArchivoJuegos[], int* dimensionArchi, Videojuego arregloJuegos[]);
Videojuego *redimensionarArreglo(Videojuego *arregloJuegos, int nuevaDimension);
Videojuego agregarJuego(char nombreArchivoJuegos[], int nuevaDim);

#endif // GESTIONVIDEOJUEGOS_H_INCLUDED
