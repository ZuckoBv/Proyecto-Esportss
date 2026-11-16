#ifndef TORNEO_H_INCLUDED
#define TORNEO_H_INCLUDED

#include "modelos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void sistemaTorneo();
Torneo crearTorneo();
void cargarTorneoArchivo (const char nombreArchivo []);
void mostrarTorneo (Torneo torneo);
void mostrarTorneosArchivo (const char nombreArchivo []);

#endif // TORNEO_H_INCLUDED
