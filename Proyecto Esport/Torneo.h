#ifndef TORNEO_H_INCLUDED
#define TORNEO_H_INCLUDED

#include "modelos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const char ARCHIVOTORNEO[]= "Torneo.bin";

void sistemaTorneo();
Torneo crearTorneo(const char nombreArchivoTorneo []);
void cargarTorneoArchivo (const char nombreArchivoTorneo []);
void mostrarTorneo (Torneo torneo);
void mostrarTorneosArchivo (const char nombreArchivoTorneo []);
int validarIdTorneo (const char nombreArchivoTorneo [], char idNuevoTorneo [] );

#endif // TORNEO_H_INCLUDED
