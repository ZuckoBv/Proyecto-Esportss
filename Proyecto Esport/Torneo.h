#ifndef TORNEO_H_INCLUDED
#define TORNEO_H_INCLUDED

#include "modelos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ARCHIVOTORNEO "Torneo.bin"

void sistemaTorneo();
Torneo crearTorneo(const char nombreArchivoTorneo [], const char nombreArchivoVideojuego[]);
void cargarTorneoArchivo (const char nombreArchivoTorneo [], const char nombreArchivoVideojuego[]);
void mostrarTorneo (Torneo torneo);
void mostrarTorneosArchivo (const char nombreArchivoTorneo []);
int validarIdTorneo (const char nombreArchivoTorneo [], char idNuevoTorneo [] );
int buscarVideojuegoPorId(const char nombreArchivoVideojuego[], char idVideojuego[], Videojuego *juegoDestino);
void modificarTorneo (const char nombreArchivoTorneo [] , const char nombreArchivoVideojuego [], char idTorneo []);


#endif // TORNEO_H_INCLUDED
